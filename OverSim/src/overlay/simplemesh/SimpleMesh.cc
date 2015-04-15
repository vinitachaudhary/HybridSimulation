//
// Copyright (C) 2010 DenaCast All Rights Reserved.
// http://www.denacast.com
// The DenaCast was designed and developed at the DML(Digital Media Lab http://dml.ir/)
// under supervision of Dr. Behzad Akbari (http://www.modares.ac.ir/ece/b.akbari)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

/**
 * @file SimpleMesh.cc
 * @author Yasser Seyyedi, Behnam Ahmadifar
 */

// edited by vinita

#include <SimpleInfo.h>
#include "SimpleMesh.h"
#include <GlobalStatistics.h>
#include "DenaCastTrackerMessage_m.h"
#include "VideoMessage_m.h"
#include "SimpleMeshMessage_m.h"


Define_Module(SimpleMesh);

void SimpleMesh::initializeOverlay(int stage)
{
	if (stage != MIN_STAGE_OVERLAY)
		return;
	isRegistered = false;
    if(globalNodeList->getPeerInfo(thisNode.getAddress())->getTypeID() == 2)
    	isSource = true;
    else
    	isSource = false;
    passiveNeighbors = par("passiveNeighbors");
    activeNeighbors = par("activeNeighbors");
	neighborNotificationPeriod = par("neighborNotificationPeriod");
	neighborNum = passiveNeighbors + activeNeighbors;

	videoAverageRate = par("videoAverageRate");
	adaptiveNeighboring = par("adaptiveNeighboring");
	serverGradualNeighboring = par("serverGradualNeighboring");

	if(isSource)
	{
		neighborNum = activeNeighbors;
		getParentModule()->getParentModule()->setName("CDN-Server");
	}

	sessionLength = atof(ev.getConfig()->getConfigValue("sim-time-limit"));
	DenaCastOverlay::initializeOverlay(stage);

	if(adaptiveNeighboring)
			neighborNum = (int)(upBandwidth/(videoAverageRate*1024));

	WATCH(neighborNum);
	WATCH(downBandwidth);
	WATCH(upBandwidth);

	stat_TotalDownBandwidthUsage = 0;
	stat_TotalUpBandwidthUsage = 0;

    stat_joinREQ = 0;
	stat_joinREQBytesSent = 0;
	stat_joinRSP = 0;
	stat_joinRSPBytesSent = 0;
	stat_joinACK = 0;
	stat_joinACKBytesSent = 0;
	stat_joinDNY = 0;
	stat_joinDNYBytesSent = 0;
	stat_disconnectMessages = 0;
	stat_disconnectMessagesBytesSent = 0;
	stat_addedNeighbors = 0;
	stat_nummeshJoinRequestTimer = 0;

	firstPeerAdded = false;
	stat_peerSelectionTime = 0.0;
	peerJoinTime = simTime().dbl();
	stat_peerSelectionToFirstChunkTime = 0.0;
	peerSelectionTime = 0.0;

	parentLeft = false;
	parentLeftTime = 0.0;
	sum_ParentReselectionTime =0.0;
	stat_parentReselectionTime = 0.0;
	countParentLeft = 0;

	neighborLeft = false;
	neighborLeftTime = 0.0;
	sum_NeighborReselectionTime = 0;
	stat_neighborReselectionTime = 0.0;
	countNeighborLeft = 0;
}

void SimpleMesh::joinOverlay()
{
	trackerAddress  = *globalNodeList->getRandomAliveNode(1);
	remainNotificationTimer = new cMessage ("remainNotificationTimer");
	scheduleAt(simTime()+neighborNotificationPeriod,remainNotificationTimer);
	subscriptionExpiryTimer = new cMessage ("subscriptionExpiryTimer");
	scheduleAt(simTime()+5,subscriptionExpiryTimer);

	aliveNotificationTimer = new cMessage ("aliveNotificationTimer");
	scheduleAt(simTime()+2,aliveNotificationTimer);
	checkNeighborTimeout = new cMessage ("checkNeighborTimeout");
	scheduleAt(simTime()+3,checkNeighborTimeout);

	std::stringstream ttString;
	ttString << thisNode;
	getParentModule()->getParentModule()->getDisplayString().setTagArg("tt",0,ttString.str().c_str());
	lastAliveMsgTime = simTime();
	if(!isSource)
	{
		meshJoinRequestTimer = new cMessage("meshJoinRequestTimer");
		scheduleAt(simTime(),meshJoinRequestTimer);
		treebonePromotionCheckTimer = new cMessage ("treebonePromotionCheckTimer");
		scheduleAt(simTime(),treebonePromotionCheckTimer);
		resubscriptionTimer = new cMessage("resubscriptionTimer");
		isolationRecoveryTimer = new cMessage("isolationRecoveryTimer");
		scheduleAt(simTime()+6,isolationRecoveryTimer);
		parentRequestTimer = new cMessage("parentRequestTimer");
		scheduleAt(simTime()+2, parentRequestTimer);

		highDegreePreemptTimer = new cMessage("highDegreePreemptTimer");
		scheduleAt(simTime()+5, highDegreePreemptTimer);
		lowDelayJumpTimer = new cMessage("lowDelayJumpTimer");
		scheduleAt(simTime()+5, lowDelayJumpTimer);
	}
	else
	{
		serverNeighborTimer = new cMessage("serverNeighborTimer");
		if(serverGradualNeighboring)
			scheduleAt(simTime()+uniform(15,25),serverNeighborTimer);
		selfRegister();
		LV->isTreebone = true;
		LV->treeLevel = 0;
		stat_num_treebone++;
	}
	findingNewParent = false;
	setOverlayReady(true);
}

void SimpleMesh::handleTimerEvent(cMessage* msg)
{
	if(msg == meshJoinRequestTimer)
	{
		if(LV->neighborMap.size() < std::min(neighborNum,passiveNeighbors))
		{
			if (LV->PartialView.size() > 0) {
				SimpleMeshMessage* joinRequest = new SimpleMeshMessage("joinRequest");
				joinRequest->setCommand(JOIN_REQUEST);
				joinRequest->setSrcNode(thisNode);
				joinRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				neighborInfoToMsg(joinRequest, neighborNum - LV->neighborMap.size(),
						LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());

				int limit = passiveNeighbors;
				std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->PartialView.begin();

				for (; nodeIt != LV->PartialView.end() && limit > 0; ++nodeIt, limit--) {
					if (LV->neighborMap.find(nodeIt->first) == LV->neighborMap.end())
						sendMessageToUDP(nodeIt->first,joinRequest->dup());
				}
				delete joinRequest;
			}
			else
				meshJoinTrackerMsg();
		}
		scheduleAt(simTime()+2,meshJoinRequestTimer);
	}
	else if (msg == parentRequestTimer) {
		if (!LV->hasTreeboneParent) {

			SimpleMeshMessage* joinRequest = new SimpleMeshMessage("joinRequest");
			joinRequest->setCommand(JOIN_REQUEST);
			joinRequest->setSrcNode(thisNode);
			joinRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));
			neighborInfoToMsg(joinRequest, neighborNum - LV->neighborMap.size(),
					LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());

			std::map <TransportAddress, neighborInfo>::iterator nodeIt;
			bool requestSent = false;
			for (nodeIt = LV->InView.begin(); nodeIt != LV->InView.end(); ++nodeIt) {
				if (nodeIt->second.remainedNeighbor > 0 && nodeIt->second.isTreebone && nodeIt->second.treeLevel != -1 ) {
					sendMessageToUDP(nodeIt->first,joinRequest->dup());
					requestSent = true;
				}
			}
			delete joinRequest;

			if (!requestSent && LV->isTreebone) {
				SimpleMeshMessage* moveRequest = new SimpleMeshMessage("moveRequest");
				moveRequest->setCommand(MOVE_REQUEST);
				moveRequest->setSrcNode(thisNode);
				moveRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));

				for (nodeIt = LV->InView.begin(); nodeIt != LV->InView.end(); ++nodeIt) {
					if (nodeIt->second.treeLevel > 0 && !nodeIt->second.isTreebone)
							sendMessageToUDP(nodeIt->first,moveRequest->dup());
				}
				delete moveRequest;
			}
		}
		scheduleAt(simTime()+1,parentRequestTimer);
	}
	else if(msg == remainNotificationTimer)
	{
		DenaCastTrackerMessage* remainNotification = new DenaCastTrackerMessage("remainNotification");
		remainNotification->setCommand(REMAIN_NEIGHBOR);
		remainNotification->setRemainNeighbor(neighborNum - LV->neighborMap.size());
		remainNotification->setSrcNode(thisNode);
		sendMessageToUDP(trackerAddress,remainNotification);
		scheduleAt(simTime()+2,remainNotificationTimer);

	}
	else if (msg == serverNeighborTimer)
	{
		if(isSource)
		{
			if(neighborNum < passiveNeighbors + activeNeighbors)
			{
				neighborNum +=1;
				cancelEvent(remainNotificationTimer);
				scheduleAt(simTime(),remainNotificationTimer);
				scheduleAt(simTime()+uniform(15,25),serverNeighborTimer);
			}
		}
//		else
//		{
//			neighborNum +=1;
//			remainedNeighbor = neighborNum - neighbors.size();
//			cancelEvent(remainNotificationTimer);
//			scheduleAt(simTime(),remainNotificationTimer);
//		}
	}
	else if (msg == treebonePromotionCheckTimer) {
		if (!LV->isTreebone) {
			if (simTime() <= 0.1*sessionLength) {
				//Early Promotion
				double earlyPromotionProbability = 1/((double)( 0.3* (sessionLength - joinTime.dbl()) + 1 - (simTime()-joinTime).dbl()));
				double randomNum = uniform(0,1);

				//std::cout<<"rn : "<<randomNum<<" prob : "<<earlyPromotionProbability<<endl;
				if (randomNum <= earlyPromotionProbability)
					LV->isTreebone=true;
			}
			else {
				if (simTime().dbl() - joinTime.dbl() >= 0.3* (sessionLength - joinTime.dbl()))
					LV->isTreebone = true;
			}
			if (LV->isTreebone && isRegistered) {
				DenaCastTrackerMessage* treebonePromoted = new DenaCastTrackerMessage("treebonePromoted");
				treebonePromoted->setCommand(TREEBONE_PROMOTION);
				treebonePromoted->setRemainNeighbor(neighborNum - LV->neighborMap.size());
				treebonePromoted->setSrcNode(thisNode);
				sendMessageToUDP(trackerAddress,treebonePromoted);
				//std::cout<<"Treebone Promotion"<<endl;

				if (!LV->hasTreeboneParent) {
					cancelEvent(parentRequestTimer);
					scheduleAt(simTime(),parentRequestTimer);
				}

				stat_num_treebone++;
			}
			else
				scheduleAt(simTime()+1,treebonePromotionCheckTimer);
		}
	}
	else if (msg == subscriptionExpiryTimer) {
		std::map <TransportAddress, neighborInfo>::iterator tempIt, nodeIt = LV->PartialView.begin();

		ScampMessage* alive = new ScampMessage("alive_scamp");
		alive->setCommand(ALIVE_SCAMP);
		alive->setSrcNode(thisNode);
		alive->setBitLength(SIMPLEMESHMESSAGE_L(msg));
		neighborInfoToMsg(alive, neighborNum-LV->neighborMap.size(),
				LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
		alive->setTTL(simTime().dbl()+5.0);

		while (nodeIt != LV->PartialView.end()) {
			if (nodeIt->second.TTL <= simTime().dbl()) {
				tempIt=nodeIt;
				++nodeIt;
				seenForwardedSubs.erase(tempIt->first);
				LV->PartialView.erase(tempIt);
			}
			else {
				sendMessageToUDP(nodeIt->first,alive->dup());
				++nodeIt;
			}
		}
		delete alive;
		scheduleAt(simTime()+5, subscriptionExpiryTimer);
	}
	else if (msg == resubscriptionTimer) {
		resubscriptionProcess();
		scheduleAt(simTime()+5, resubscriptionTimer);
	}
	else if (msg == isolationRecoveryTimer) {
		if ((simTime() - lastAliveMsgTime).dbl() >= 6.0) {
			resubscriptionProcess();
		}
		scheduleAt(simTime()+6,isolationRecoveryTimer);
	}
	else if (msg == aliveNotificationTimer) {
		std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->neighborMap.begin();
		SimpleMeshMessage* alive = new SimpleMeshMessage("alive");
		alive->setCommand(ALIVE);
		alive->setSrcNode(thisNode);
		alive->setBitLength(SIMPLEMESHMESSAGE_L(msg));
		neighborInfoToMsg(alive, neighborNum-LV->neighborMap.size(),
				LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
		for (;nodeIt != LV->neighborMap.end(); ++nodeIt) {
			sendMessageToUDP(nodeIt->first,alive->dup());
		}
		delete alive;
		scheduleAt(simTime()+2, aliveNotificationTimer);
	}
	else if (msg == checkNeighborTimeout) {
		std::map <TransportAddress, neighborInfo>::iterator tempIt, nodeIt = LV->neighborMap.begin();

		while (nodeIt != LV->neighborMap.end()) {
			if (simTime().dbl() - nodeIt->second.timeOut > 5) {
				tempIt=nodeIt;
				++nodeIt;
				disconnectProcess(tempIt->first);
			}
			else {
				++nodeIt;
			}
		}
		scheduleAt(simTime()+3, checkNeighborTimeout);
	}
	else if (msg == highDegreePreemptTimer) {
		if (LV->isTreebone) {
			SimpleMeshMessage* moveRequest = new SimpleMeshMessage("moveRequest");
			moveRequest->setCommand(MOVE_REQUEST);
			moveRequest->setSrcNode(thisNode);
			moveRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));

			if (LV->hasTreeboneParent && LV->neighborMap[LV->treeboneParent].numChildren < LV->treeboneChildren.size()) {
				findingNewParent = true;
				sendMessageToUDP(LV->treeboneParent,moveRequest->dup());
			}
			else if (!LV->InView.empty()) {
				std::map <TransportAddress, neighborInfo>::iterator nodeIt;
				for (nodeIt = LV->InView.begin(); nodeIt != LV->InView.end(); ++nodeIt) {
					if (nodeIt->second.isTreebone && nodeIt->second.treeLevel!=-1 &&
						nodeIt->second.treeLevel < LV->treeLevel &&	nodeIt->second.numChildren < LV->treeboneChildren.size()) {
						findingNewParent = true;
						sendMessageToUDP(nodeIt->first,moveRequest->dup());
					}
				}
			}
			delete moveRequest;
		}
		scheduleAt(simTime()+5, highDegreePreemptTimer);
	}
	else if (msg == lowDelayJumpTimer) {
		if (LV->hasTreeboneParent) {
			std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->InView.begin();

			if (!LV->InView.empty()) {
				for (nodeIt = LV->InView.begin(); nodeIt != LV->InView.end(); ++nodeIt)
					if (nodeIt->second.isTreebone && nodeIt->second.treeLevel!=-1 &&
						(nodeIt->second.treeLevel < (LV->treeLevel - 1)) && nodeIt->second.remainedNeighbor > 0)
						break;
			}

			if (nodeIt != LV->InView.end()) {
				findingNewParent = true;
				SimpleMeshMessage* joinRequest = new SimpleMeshMessage("joinRequest");
				joinRequest->setCommand(JOIN_REQUEST);
				joinRequest->setSrcNode(thisNode);
				joinRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				neighborInfoToMsg(joinRequest, neighborNum - LV->neighborMap.size(),
						LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
				sendMessageToUDP(nodeIt->first, joinRequest);
			}
		}
		scheduleAt(simTime()+5, lowDelayJumpTimer);
	}
	else
		DenaCastOverlay::handleAppMessage(msg);
}
void SimpleMesh::handleUDPMessage(BaseOverlayMessage* msg)
{
	if (dynamic_cast<DenaCastTrackerMessage*>(msg) != NULL)
	{
		DenaCastTrackerMessage* trackerMsg = check_and_cast<DenaCastTrackerMessage*>(msg);
		if(trackerMsg->getCommand() == NEIGHBOR_RESPONSE)
		{
			SimpleMeshMessage* joinRequest = new SimpleMeshMessage("joinRequest");
			joinRequest->setCommand(JOIN_REQUEST);
			joinRequest->setSrcNode(thisNode);
			joinRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));
			neighborInfoToMsg(joinRequest, neighborNum - LV->neighborMap.size(),
					LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());

			int limit = std::min(neighborNum,passiveNeighbors);
			limit = std::min(limit,(int)trackerMsg->getNeighborsArraySize());

			for(unsigned int i=0 ; i <trackerMsg->getNeighborsArraySize() && limit>0 ; i++, limit--)
				if(LV->neighborMap.find(trackerMsg->getNeighbors(i)) == LV->neighborMap.end())
					sendMessageToUDP(trackerMsg->getNeighbors(i),joinRequest->dup());
			delete joinRequest;

			neighborInfo nF(0, simTime().dbl(), true, -1, 0);

			ScampMessage* newSubscription = new ScampMessage("newSubscription");
			newSubscription->setCommand(NEW_SUBSCRIPTION);
			newSubscription->setSrcNode(thisNode);
			newSubscription->setBitLength(SIMPLEMESHMESSAGE_L(msg));
			newSubscription->setToForward(false);
			neighborInfoToMsg(newSubscription, neighborNum, false, -1, LV->treeboneChildren.size());
			newSubscription->setTTL(simTime().dbl()+5.0);

			for (unsigned int i=0; i<trackerMsg->getNeighborsArraySize(); i++) {

				if (i<trackerMsg->getTreeNeighborSize())
					nF.isTreebone = true;
				else
					nF.isTreebone = false;

				LV->InView.insert(std::make_pair<TransportAddress, neighborInfo> (trackerMsg->getNeighbors(i),nF));
				if (i == trackerMsg->getNeighborsArraySize()-1) {
					newSubscription->setToForward(true);
					nF.TTL = simTime().dbl() + 5.0;
					LV->PartialView.insert(std::make_pair<TransportAddress, neighborInfo> (trackerMsg->getNeighbors(i),nF));
				}

				sendMessageToUDP(trackerMsg->getNeighbors(i),newSubscription->dup());
			}
			delete newSubscription;
			cancelEvent(resubscriptionTimer);
			scheduleAt(simTime()+5,resubscriptionTimer);
		}
		delete trackerMsg;
	}
	else if (dynamic_cast<SimpleMeshMessage*>(msg) != NULL)
	{
		SimpleMeshMessage* simpleMeshmsg = check_and_cast<SimpleMeshMessage*>(msg);
		if (simpleMeshmsg->getCommand() == JOIN_REQUEST)
		{
			if(LV->neighborMap.size() < neighborNum)
			{
				//LV->neighbors.push_back(simpleMeshmsg->getSrcNode());
				neighborInfo nF(simpleMeshmsg->getRemainNeighbor(), simTime().dbl(),
						simpleMeshmsg->getIsTreebone(), simpleMeshmsg->getTreeLevel(), simpleMeshmsg->getNumChildren());
				LV->neighborMap.insert(std::make_pair<TransportAddress, neighborInfo> (simpleMeshmsg->getSrcNode(),nF));

				SimpleMeshMessage* joinResponse = new SimpleMeshMessage("joinResponse");
				joinResponse->setCommand(JOIN_RESPONSE);
				joinResponse->setSrcNode(thisNode);
				joinResponse->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				neighborInfoToMsg(joinResponse, neighborNum - LV->neighborMap.size(),
						LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinResponse);

				stat_joinRSP += 1;
				stat_joinRSPBytesSent += joinResponse->getByteLength();
			}
			else
			{
				SimpleMeshMessage* joinDeny = new SimpleMeshMessage("joinDeny");
				joinDeny->setCommand(JOIN_DENY);
				joinDeny->setSrcNode(thisNode);
				joinDeny->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinDeny);

				stat_joinDNY += 1;
				stat_joinDNYBytesSent += joinDeny->getByteLength();
			}
		}
		else if (simpleMeshmsg->getCommand() == JOIN_RESPONSE)
		{
			if(LV->neighborMap.size() < neighborNum )
			{
				//LV->neighbors.push_back(simpleMeshmsg->getSrcNode());
				neighborInfo nF(simpleMeshmsg->getRemainNeighbor(), simTime().dbl(),
								simpleMeshmsg->getIsTreebone(), simpleMeshmsg->getTreeLevel(), simpleMeshmsg->getNumChildren());
				LV->neighborMap.insert(std::make_pair<TransportAddress, neighborInfo> (simpleMeshmsg->getSrcNode(),nF));

				if (neighborLeft) {
					neighborLeft = false;
					sum_NeighborReselectionTime+=simTime().dbl() - neighborLeftTime;
				}

				if(!isRegistered)
					selfRegister();

				if (!firstPeerAdded) {
					firstPeerAdded = true;
					peerSelectionTime = simTime().dbl();
					stat_peerSelectionTime = peerSelectionTime - peerJoinTime;
				}

				SimpleMeshMessage* joinAck = new SimpleMeshMessage("joinAck");
				joinAck->setCommand(JOIN_ACK);
				joinAck->setSrcNode(thisNode);
				joinAck->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				joinAck->setAddAsChild(false);

				if (nF.isTreebone && (!LV->hasTreeboneParent || (LV->hasTreeboneParent && findingNewParent))) {
					LV->hasTreeboneParent = true;
					if (parentLeft) {
						parentLeft = false;
						sum_ParentReselectionTime+=simTime().dbl() - parentLeftTime;
					}
					joinAck->setAddAsChild(true);
					showOverlayNeighborArrow(simpleMeshmsg->getSrcNode(), false,
													"m=m,50,0,50,0;ls=red,1");

					if (findingNewParent && LV->hasTreeboneParent && nF.treeLevel!=-1 && ((nF.treeLevel+1) < LV->treeLevel)) {
						SimpleMeshMessage* disconnectMsg = new SimpleMeshMessage("disconnect");
						disconnectMsg->setCommand(DISCONNECT);
						disconnectMsg->setSrcNode(thisNode);
						disconnectMsg->setBitLength(SIMPLEMESHMESSAGE_L(msg));
						sendMessageToUDP(LV->treeboneParent,disconnectMsg);
						findingNewParent = false;
					}
					LV->treeboneParent = simpleMeshmsg->getSrcNode();
					if (nF.treeLevel != -1)
						LV->treeLevel = nF.treeLevel + 1;
				}
				else {
					showOverlayNeighborArrow(simpleMeshmsg->getSrcNode(), false,
														 "m=m,50,0,50,0;ls=green,1");
				}


				neighborInfoToMsg(joinAck, neighborNum - LV->neighborMap.size(),
						LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinAck);

				stat_joinACK += 1;
				stat_joinACKBytesSent += joinAck->getByteLength();
			}
			else
			{
				SimpleMeshMessage* joinDeny = new SimpleMeshMessage("joinDeny");
				joinDeny->setCommand(JOIN_DENY);
				joinDeny->setSrcNode(thisNode);
				joinDeny->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinDeny);

				stat_joinDNY += 1;
				stat_joinDNYBytesSent += joinDeny->getByteLength();
			}
		}
		else if(simpleMeshmsg->getCommand() == JOIN_ACK)
		{
			if(LV->neighborMap.size() <= neighborNum)
			{
				if(!isRegistered)
					selfRegister();
				stat_addedNeighbors += 1;

				/*std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->neighborMap.find(simpleMeshmsg->getSrcNode());

				nodeIt->second.isTreebone = simpleMeshmsg->getIsTreebone();
				nodeIt->second.treeLevel = simpleMeshmsg->getTreeLevel();
				nodeIt->second.remainedNeighbor = simpleMeshmsg->getRemainNeighbor();
				nodeIt->second.timeOut = simTime().dbl();
				nodeIt->second.numChildren = simpleMeshmsg->getNumChildren();*/

				neighborInfo nF(simpleMeshmsg->getRemainNeighbor(), simTime().dbl(), simpleMeshmsg->getIsTreebone(),
								simpleMeshmsg->getTreeLevel(), simpleMeshmsg->getNumChildren());
				LV->neighborMap[simpleMeshmsg->getSrcNode()]=nF;

				if (simpleMeshmsg->getAddAsChild())
					LV->treeboneChildren.push_back(simpleMeshmsg->getSrcNode());
				else
					showOverlayNeighborArrow(simpleMeshmsg->getSrcNode(), false,
													 "m=m,50,0,50,0;ls=green,1");
			}
			else
			{
				SimpleMeshMessage* joinDeny = new SimpleMeshMessage("joinDeny");
				joinDeny->setCommand(JOIN_DENY);
				joinDeny->setSrcNode(thisNode);
				joinDeny->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinDeny);
				/*if(isInVector(simpleMeshmsg->getSrcNode(),LV->neighbors))
					deleteVector(simpleMeshmsg->getSrcNode(),LV->neighbors);
				*/
				if (LV->neighborMap.find(simpleMeshmsg->getSrcNode()) != LV->neighborMap.end())
					LV->neighborMap.erase(simpleMeshmsg->getSrcNode());
				deleteOverlayNeighborArrow(simpleMeshmsg->getSrcNode());

				stat_joinDNY += 1;
				stat_joinDNYBytesSent += joinDeny->getByteLength();
			}
		}
		else if(simpleMeshmsg->getCommand() == JOIN_DENY)
		{
			/*if(isInVector(simpleMeshmsg->getSrcNode(),LV->neighbors))
				deleteVector(simpleMeshmsg->getSrcNode(),LV->neighbors);
			*/
			if (LV->neighborMap.find(simpleMeshmsg->getSrcNode()) != LV->neighborMap.end())
				LV->neighborMap.erase(simpleMeshmsg->getSrcNode());
			deleteOverlayNeighborArrow(simpleMeshmsg->getSrcNode());

			if (LV->hasTreeboneParent && LV->treeboneParent == simpleMeshmsg->getSrcNode()) {
				LV->hasTreeboneParent = false;
			}
		}
		else if(simpleMeshmsg->getCommand() == DISCONNECT)
		{
			disconnectProcess(simpleMeshmsg->getSrcNode());
		}
		else if (simpleMeshmsg->getCommand() == ALIVE) {
			neighborInfo nF(simpleMeshmsg->getRemainNeighbor(), simTime().dbl(),
							simpleMeshmsg->getIsTreebone(), simpleMeshmsg->getTreeLevel(), simpleMeshmsg->getNumChildren());
			LV->neighborMap[simpleMeshmsg->getSrcNode()]=nF;
			if (LV->hasTreeboneParent && LV->treeboneParent == simpleMeshmsg->getSrcNode() && nF.treeLevel != -1)
				LV->treeLevel = nF.treeLevel+1;
		}
		else if (simpleMeshmsg->getCommand() == MOVE_REQUEST) {
			if (LV->hasTreeboneParent) {
				SimpleMeshMessage* moveResponse = new SimpleMeshMessage("moveResponse");
				moveResponse->setCommand(MOVE_RESPONSE);
				moveResponse->setSrcNode(LV->treeboneParent);
				moveResponse->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),moveResponse);
			}
		}
		else if (simpleMeshmsg->getCommand() == MOVE_RESPONSE) {
			if (findingNewParent || !LV->hasTreeboneParent) {
				SimpleMeshMessage* joinRequest = new SimpleMeshMessage("joinRequest");
				joinRequest->setCommand(JOIN_REQUEST);
				joinRequest->setSrcNode(thisNode);
				joinRequest->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				neighborInfoToMsg(joinRequest, neighborNum - LV->neighborMap.size(),
						LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinRequest);
			}
		}
		delete simpleMeshmsg;
	}

	else if (dynamic_cast<ScampMessage*>(msg) != NULL)
	{
		ScampMessage* scampMsg = check_and_cast<ScampMessage*>(msg);

		if (scampMsg->getCommand() == NEW_SUBSCRIPTION) {
			neighborInfo nF(scampMsg->getRemainNeighbor(), simTime().dbl(), scampMsg->getIsTreebone(),
							scampMsg->getTreeLevel(), scampMsg->getTTL(), scampMsg->getNumChildren());
			LV->PartialView[scampMsg->getSrcNode()] = nF;

			if (scampMsg->getToForward()) {
				LV->InView[scampMsg->getSrcNode()] = nF;

				ScampMessage* forwardSubscription = new ScampMessage("forwardSubscription");
				forwardSubscription->setCommand(FORWARD_SUBSCRIPTION);
				forwardSubscription->setSrcNode(thisNode);
				forwardSubscription->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				forwardSubscription->setNodeToBeSubscribed(scampMsg->getSrcNode());
				neighborInfoToMsg(forwardSubscription, scampMsg->getRemainNeighbor(),
						scampMsg->getIsTreebone(), scampMsg->getTreeLevel(), scampMsg->getNumChildren());
				forwardSubscription->setTTL(scampMsg->getTTL());

				std::map <TransportAddress, neighborInfo>::iterator nodeIt;

				for (nodeIt = LV->PartialView.begin(); nodeIt != LV->PartialView.end(); ++nodeIt)
					sendMessageToUDP(nodeIt->first, forwardSubscription->dup());

				delete forwardSubscription;
			}
		}

		else if (scampMsg->getCommand() == FORWARD_SUBSCRIPTION && scampMsg->getNodeToBeSubscribed() != thisNode) {
			std::map<TransportAddress, int>::iterator nodeIter;
			nodeIter = seenForwardedSubs.find(scampMsg->getNodeToBeSubscribed());

			if (nodeIter == seenForwardedSubs.end())
				seenForwardedSubs.insert(std::make_pair<TransportAddress, int> (scampMsg->getNodeToBeSubscribed(),1));
			else
				nodeIter->second++;

			if (nodeIter->second < 10 && LV->PartialView.find(scampMsg->getNodeToBeSubscribed()) == LV->PartialView.end()) {
				double randomNumDbl = uniform(0,1);
				double keepProbablility = 1/((double)(1+LV->PartialView.size()));

				if (randomNumDbl <= keepProbablility) {
					neighborInfo nF(scampMsg->getRemainNeighbor(), simTime().dbl(), scampMsg->getIsTreebone(),
									scampMsg->getTreeLevel(), scampMsg->getTTL(), scampMsg->getNumChildren());
					LV->PartialView[scampMsg->getNodeToBeSubscribed()]=nF;

					ScampMessage* subscriptionAck = new ScampMessage("subscriptionAck");
					subscriptionAck->setCommand(SUBSCRIPTION_ACK);
					subscriptionAck->setSrcNode(thisNode);
					subscriptionAck->setBitLength(SIMPLEMESHMESSAGE_L(msg));
					neighborInfoToMsg(subscriptionAck, neighborNum - LV->neighborMap.size(),
										LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
					sendMessageToUDP(scampMsg->getNodeToBeSubscribed(), subscriptionAck);
				}
				else if (LV->PartialView.size() > 0) {
					std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->PartialView.begin();
					int randomNum = intuniform(1,LV->PartialView.size());
					for(int i=1; i<randomNum ; i++)
						++nodeIt;

					scampMsg->setSrcNode(thisNode);

					sendMessageToUDP(nodeIt->first, scampMsg->dup());
				}
			}
		}

		else if (scampMsg->getCommand() == SUBSCRIPTION_ACK) {
			neighborInfo nF(scampMsg->getRemainNeighbor(), simTime().dbl(), scampMsg->getIsTreebone(),
					scampMsg->getTreeLevel(), scampMsg->getNumChildren());
			LV->InView[scampMsg->getSrcNode()]=nF;
		}

		else if (scampMsg->getCommand() == ALIVE_SCAMP) {
			neighborInfo nF(scampMsg->getRemainNeighbor(), simTime().dbl(),
							scampMsg->getIsTreebone(), scampMsg->getTreeLevel(), scampMsg->getNumChildren());
			LV->InView[scampMsg->getSrcNode()]=nF;

			lastAliveMsgTime = simTime();
		}
		else if (scampMsg->getCommand() == UNSUBSCRIBE) {
			LV->PartialView.erase(scampMsg->getSrcNode());
			seenForwardedSubs.erase(scampMsg->getSrcNode());

			if (scampMsg->getNodeToBeSubscribed() != scampMsg->getSrcNode()) {
				neighborInfo nF(scampMsg->getRemainNeighbor(), simTime().dbl(),scampMsg->getIsTreebone(),
								scampMsg->getTreeLevel(), scampMsg->getTTL(), scampMsg->getNumChildren());
				LV->PartialView[scampMsg->getNodeToBeSubscribed()]=nF;

				ScampMessage* subscriptionAck = new ScampMessage("subscriptionAck");
				subscriptionAck->setCommand(SUBSCRIPTION_ACK);
				subscriptionAck->setSrcNode(thisNode);
				subscriptionAck->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				neighborInfoToMsg(subscriptionAck, neighborNum - LV->neighborMap.size(),
									LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
				sendMessageToUDP(scampMsg->getNodeToBeSubscribed(), subscriptionAck);
			}
		}
		delete scampMsg;
	}
	else
		DenaCastOverlay::handleUDPMessage(msg);
}

void SimpleMesh::handleNodeGracefulLeaveNotification()
{
	neighborNum = 0;
	selfUnRegister();
	std::cout << "time: " << simTime()<< "  "<<getParentModule()->getParentModule()->getFullName() <<  std::endl;

	std::map <TransportAddress, neighborInfo>::iterator inViewIt, partialViewIt;
	partialViewIt = LV->PartialView.begin();

	ScampMessage* unsubscribe = new ScampMessage("unsubscribe");
	unsubscribe->setCommand(UNSUBSCRIBE);
	unsubscribe->setSrcNode(thisNode);
	unsubscribe->setBitLength(SIMPLEMESHMESSAGE_L(msg));

	if (LV->PartialView.size() > 0) {
		for (inViewIt = LV->InView.begin(); inViewIt != LV->InView.end(); ++inViewIt, ++partialViewIt) {
			if (partialViewIt == LV->PartialView.end())
				partialViewIt = LV->PartialView.begin();
			unsubscribe->setNodeToBeSubscribed(partialViewIt->first);
			neighborInfoToMsg(unsubscribe, partialViewIt->second.remainedNeighbor,
					partialViewIt->second.isTreebone, partialViewIt->second.treeLevel, partialViewIt->second.numChildren);
			unsubscribe->setTTL(partialViewIt->second.TTL);

			sendMessageToUDP(inViewIt->first, unsubscribe->dup());
		}
	}
	else {
		unsubscribe->setNodeToBeSubscribed(thisNode);		// for invalid
		for (inViewIt = LV->InView.begin(); inViewIt != LV->InView.end(); ++inViewIt) {
			sendMessageToUDP(inViewIt->first, unsubscribe->dup());
		}
	}

	delete unsubscribe;

	SimpleMeshMessage* disconnectMsg = new SimpleMeshMessage("disconnect");
	disconnectMsg->setCommand(DISCONNECT);
	disconnectMsg->setSrcNode(thisNode);
	disconnectMsg->setBitLength(SIMPLEMESHMESSAGE_L(msg));
	/*for (unsigned int i=0; i != LV->neighbors.size(); i++)
	{
		sendMessageToUDP(LV->neighbors[i],disconnectMsg->dup());
		deleteOverlayNeighborArrow(LV->neighbors[i]);*/

	std::map <TransportAddress, neighborInfo>::iterator neighborIt;
	for (neighborIt = LV->neighborMap.begin(); neighborIt != LV->neighborMap.end(); ++neighborIt) {
		sendMessageToUDP(neighborIt->first,disconnectMsg->dup());
		deleteOverlayNeighborArrow(neighborIt->first);
		stat_disconnectMessages += 1;
		stat_disconnectMessagesBytesSent += disconnectMsg->getByteLength();
	}
	VideoMessage* videoMsg = new VideoMessage();
	videoMsg->setCommand(LEAVING);
	send(videoMsg,"appOut");
	delete disconnectMsg;
}

bool SimpleMesh::isInVector(TransportAddress& Node, std::vector <TransportAddress> &neighbors)
{
	for (unsigned int i=0; i!=neighbors.size(); i++)
	{
		if (neighbors[i] == Node)
		{
			return true;
		}
	}
	return false;
}
void SimpleMesh::deleteVector(TransportAddress Node,std::vector <TransportAddress> &neighbors)
{
	for (unsigned int i=0; i!=neighbors.size(); i++)
	{
		if(neighbors[i].isUnspecified())
		{
			neighbors.erase(neighbors.begin()+i,neighbors.begin()+1+i);
			break;
		}
	}
	if(Node.isUnspecified())
		return;
	for (unsigned int i=0; i!=neighbors.size(); i++)
	{

		if (Node == neighbors[i])
		{
			neighbors.erase(neighbors.begin()+i,neighbors.begin()+1+i);
			break;
		}
	}
}

void SimpleMesh::selfRegister()
{
	DenaCastTrackerMessage* selfReg = new DenaCastTrackerMessage("selfRegister");
	selfReg->setCommand(SELF_REGISTER);
	selfReg->setSrcNode(thisNode);
	selfReg->setIsServer(isSource);
	selfReg->setRemainNeighbor(passiveNeighbors);
	sendMessageToUDP(trackerAddress,selfReg);
	isRegistered = true;
}
void SimpleMesh::selfUnRegister()
{
	if(isRegistered)
	{
		DenaCastTrackerMessage* selfUnReg = new DenaCastTrackerMessage("selfUnRegister");
		selfUnReg->setCommand(SELF_UNREGISTER);
		selfUnReg->setSrcNode(thisNode);
		selfUnReg->setIsServer(isSource);
		sendMessageToUDP(trackerAddress,selfUnReg);
		isRegistered = false;
	}
}
void SimpleMesh::disconnectProcess(TransportAddress Node)
{
	deleteVector(Node,LV->treeboneChildren);
	deleteOverlayNeighborArrow(Node);
	LV->PartialView.erase(Node);
	LV->InView.erase(Node);

	if (LV->hasTreeboneParent && LV->treeboneParent == Node) {
		if (!parentLeft) {
			parentLeft = true;
			parentLeftTime = simTime().dbl();
			countParentLeft++;
		}
		LV->hasTreeboneParent = false;
		LV->treeLevel = -1;
		cancelEvent(parentRequestTimer);
		scheduleAt(simTime(),parentRequestTimer);
	}
	else if(!isSource && LV->neighborMap.find(Node)!=LV->neighborMap.end())
	{
		if (!neighborLeft) {
			neighborLeft = true;
			neighborLeftTime = simTime().dbl();
			countNeighborLeft++;
		}
		cancelEvent(meshJoinRequestTimer);
		scheduleAt(simTime(),meshJoinRequestTimer);
	}
	LV->neighborMap.erase(Node);
	VideoMessage* videoMsg = new VideoMessage();
	videoMsg->setCommand(NEIGHBOR_LEAVE);
	videoMsg->setSrcNode(Node);
	send(videoMsg,"appOut");
}

void SimpleMesh::neighborInfoToMsg (SimpleMeshMessage* msg, int _remainedNeighbor,
					bool _isTreebone, int _treeLevel, int _numChildren) {
	msg->setRemainNeighbor(_remainedNeighbor);
	msg->setIsTreebone(_isTreebone);
	msg->setTreeLevel(_treeLevel);
	msg->setNumChildren(_numChildren);
}

void SimpleMesh::neighborInfoToMsg (ScampMessage* msg, int _remainedNeighbor,
					bool _isTreebone, int _treeLevel, int _numChildren) {
	msg->setRemainNeighbor(_remainedNeighbor);
	msg->setIsTreebone(_isTreebone);
	msg->setTreeLevel(_treeLevel);
	msg->setNumChildren(_numChildren);
}

void SimpleMesh::resubscriptionProcess() {
	if (LV->PartialView.size() > 0 ) {
		std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->PartialView.begin();
		int randomNum = intuniform(1,LV->PartialView.size());
		for(int i=1; i<randomNum ; i++)
			++nodeIt;

		ScampMessage* newSubscription = new ScampMessage("newSubscription");
		newSubscription->setCommand(NEW_SUBSCRIPTION);
		newSubscription->setSrcNode(thisNode);
		newSubscription->setBitLength(SIMPLEMESHMESSAGE_L(msg));
		newSubscription->setToForward(true);
		neighborInfoToMsg(newSubscription, neighborNum-LV->neighborMap.size(),
				LV->isTreebone, LV->treeLevel, LV->treeboneChildren.size());
		newSubscription->setTTL(simTime().dbl()+5.0);

		sendMessageToUDP(nodeIt->first,newSubscription);
	}
}

void SimpleMesh::meshJoinTrackerMsg() {
	DenaCastTrackerMessage* NeighborReq = new DenaCastTrackerMessage("NeighborReq");
	NeighborReq->setCommand(NEIGHBOR_REQUEST);
	NeighborReq->setNeighborSize(neighborNum - LV->neighborMap.size());
	NeighborReq->setSrcNode(thisNode);
	NeighborReq->setIsServer(false);
	NeighborReq->setIsTreebone(LV->isTreebone);

	sendMessageToUDP(trackerAddress,NeighborReq);
}

void SimpleMesh::finishOverlay()
{
	cancelAndDelete(subscriptionExpiryTimer);
	cancelAndDelete(aliveNotificationTimer);
	cancelAndDelete(checkNeighborTimeout);
	if(!isSource) {
    	cancelAndDelete(meshJoinRequestTimer);
    	cancelAndDelete(treebonePromotionCheckTimer);
    	cancelAndDelete(resubscriptionTimer);
    	cancelAndDelete(isolationRecoveryTimer);
    	cancelAndDelete(parentRequestTimer);
    	cancelAndDelete(highDegreePreemptTimer);
    	cancelAndDelete(lowDelayJumpTimer);
	}
	else
		cancelAndDelete(serverNeighborTimer);
	globalStatistics->addStdDev("SimpleMesh: JOIN::REQ Messages", stat_joinREQ);
	globalStatistics->addStdDev("SimpleMesh: JOIN::REQ Bytes sent", stat_joinREQBytesSent);
	globalStatistics->addStdDev("SimpleMesh: JOIN::RSP Messages", stat_joinRSP);
	globalStatistics->addStdDev("SimpleMesh: JOIN::RSP Bytes sent", stat_joinRSPBytesSent);
	globalStatistics->addStdDev("SimpleMesh: JOIN::ACK Messages", stat_joinACK);
	globalStatistics->addStdDev("SimpleMesh: JOIN::ACK Bytes sent", stat_joinACKBytesSent);
	globalStatistics->addStdDev("SimpleMesh: JOIN::DNY Messages", stat_joinDNY);
	globalStatistics->addStdDev("SimpleMesh: JOIN::DNY Bytes sent", stat_joinDNYBytesSent);
	globalStatistics->addStdDev("SimpleMesh: DISCONNECT:IND Messages", stat_disconnectMessages);
	globalStatistics->addStdDev("SimpleMesh: DISCONNECT:IND Bytes sent", stat_disconnectMessagesBytesSent);
	globalStatistics->addStdDev("SimpleMesh: Neighbors added", stat_addedNeighbors);
	globalStatistics->addStdDev("SimpleMesh: Number of JOINRQ selfMessages", stat_nummeshJoinRequestTimer);
	globalStatistics->addStdDev("SimpleMesh: Download bandwidth", downBandwidth);
	globalStatistics->addStdDev("SimpleMesh: Upload bandwidth", upBandwidth);

	globalStatistics->addStdDev("SimpleMesh: Treebone Nodes : ", stat_num_treebone);

	if (!isSource) {
		if (stat_peerSelectionTime > 0) {
			globalStatistics->addStdDev("SimpleMesh: Peer Selection Time", stat_peerSelectionTime);

			if (firstChunkTime > 0) {
				stat_peerSelectionToFirstChunkTime = firstChunkTime - peerSelectionTime;
				globalStatistics->addStdDev("SimpleMesh: Peer Selection to First Chunk Received Time", stat_peerSelectionToFirstChunkTime);
			}
		}

		if (countParentLeft > 0 && sum_ParentReselectionTime>0) {
			stat_parentReselectionTime = sum_ParentReselectionTime/countParentLeft;
			std::stringstream buf;
			buf << "SimpleMesh: Average Parent Reselection time for parents leaving " << countParentLeft;
			std::string s = buf.str();
			globalStatistics->addStdDev(s.c_str(), stat_parentReselectionTime);
			globalStatistics->addStdDev("SimpleMesh: Parent Reselection Time", stat_parentReselectionTime);
		}

		if (countNeighborLeft > 0 && sum_NeighborReselectionTime>0) {
			stat_neighborReselectionTime = sum_NeighborReselectionTime/countNeighborLeft;
			std::stringstream buf;
			buf << "SimpleMesh: Average Neighbor Reselection time for neighbors leaving " << countNeighborLeft;
			std::string s = buf.str();
			globalStatistics->addStdDev(s.c_str(), stat_neighborReselectionTime);
			globalStatistics->addStdDev("SimpleMesh: Neighbor Reselection Time", stat_neighborReselectionTime);
		}
	}

	setOverlayReady(false);
}

int SimpleMesh::stat_num_treebone = 0;
