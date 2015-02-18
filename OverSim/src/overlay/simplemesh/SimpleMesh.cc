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

	//sessionLength = par("sessionLength");
	sessionLength = atof(ev.getConfig()->getConfigValue("sim-time-limit"));
	DenaCastOverlay::initializeOverlay(stage);

	if(adaptiveNeighboring)
			neighborNum = (int)(upBandwidth/(videoAverageRate*1024));
	//std::cout<<"upBw : "<<upBandwidth<<" neighbor num : "<<neighborNum<<endl;

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
}

void SimpleMesh::joinOverlay()
{
	trackerAddress  = *globalNodeList->getRandomAliveNode(1);
	remainNotificationTimer = new cMessage ("remainNotificationTimer");
	scheduleAt(simTime()+neighborNotificationPeriod,remainNotificationTimer);
	std::stringstream ttString;
	ttString << thisNode;
	getParentModule()->getParentModule()->getDisplayString().setTagArg("tt",0,ttString.str().c_str());
	if(!isSource)
	{
		meshJoinRequestTimer = new cMessage("meshJoinRequestTimer");
		scheduleAt(simTime(),meshJoinRequestTimer);
		treebonePromotionCheckTimer = new cMessage ("treebonePromotionCheckTimer");
		scheduleAt(simTime(),treebonePromotionCheckTimer);
	}
	else
	{
		serverNeighborTimer = new cMessage("serverNeighborTimer");
		if(serverGradualNeighboring)
			scheduleAt(simTime()+uniform(15,25),serverNeighborTimer);
		selfRegister();
		LV->isTreebone = true;
		LV->treeLevel = 0;
	}
	setOverlayReady(true);
}

void SimpleMesh::handleTimerEvent(cMessage* msg)
{
	if(msg == meshJoinRequestTimer)
	{
		if(LV->neighborMap.size() == 0)
		{
			DenaCastTrackerMessage* NeighborReq = new DenaCastTrackerMessage("NeighborReq");
			NeighborReq->setCommand(NEIGHBOR_REQUEST);
			NeighborReq->setNeighborSize(neighborNum - LV->neighborMap.size());
			NeighborReq->setSrcNode(thisNode);
			NeighborReq->setIsServer(false);

			sendMessageToUDP(trackerAddress,NeighborReq);
			scheduleAt(simTime()+2,meshJoinRequestTimer);
		}
		else
			scheduleAt(simTime()+20,meshJoinRequestTimer);
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
		if (!LV->isTreebone && isRegistered && !isSource) {
			if (simTime() <= 0.1*sessionLength) {
				//Early Promotion
				double earlyPromotionProbability = 1/( 0.3* (sessionLength - joinTime) + 1 - (simTime()-joinTime));
				double randomNum = uniform(0,1);
				if (randomNum <= earlyPromotionProbability)
					LV->isTreebone=true;
			}
			else {
				if (simTime() - joinTime >= 0.3* (sessionLength - joinTime))
					LV->isTreebone = true;
			}
			if (LV->isTreebone) {
				DenaCastTrackerMessage* treebonePromoted = new DenaCastTrackerMessage("treebonePromoted");
				treebonePromoted->setCommand(TREEBONE_PROMOTION);
				treebonePromoted->setRemainNeighbor(neighborNum - LV->neighborMap.size());
				treebonePromoted->setSrcNode(thisNode);
				sendMessageToUDP(trackerAddress,treebonePromoted);
			}
			else
				scheduleAt(simTime()+1,treebonePromotionCheckTimer);
		}
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
			joinRequest->setRemainNeighbor(neighborNum - LV->neighborMap.size());
			joinRequest->setTreeLevel(LV->treeLevel);
			joinRequest->setIsTreebone(LV->isTreebone);
			int limit = 0;
			if(trackerMsg->getNeighborsArraySize() < neighborNum - LV->neighborMap.size())
				limit = trackerMsg->getNeighborsArraySize();
			else
				limit = neighborNum - LV->neighborMap.size();
			for(unsigned int i=0 ; i <trackerMsg->getNeighborsArraySize() ; i++)
				if(limit-- > 0 && LV->neighborMap.find(trackerMsg->getNeighbors(i)) == LV->neighborMap.end())
					sendMessageToUDP(trackerMsg->getNeighbors(i),joinRequest->dup());
			delete joinRequest;
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
				neighborInfo nF;
				nF.isTreebone = simpleMeshmsg->getIsTreebone();
				nF.remainedNeighbor = simpleMeshmsg->getRemainNeighbor();
				nF.timeOut = simTime().dbl();
				nF.treeLevel = simpleMeshmsg->getTreeLevel();
				LV->neighborMap.insert(std::make_pair<TransportAddress, neighborInfo> (simpleMeshmsg->getSrcNode(),nF));

				SimpleMeshMessage* joinResponse = new SimpleMeshMessage("joinResponse");
				joinResponse->setCommand(JOIN_RESPONSE);
				joinResponse->setSrcNode(thisNode);
				joinResponse->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				joinResponse->setRemainNeighbor(neighborNum - LV->neighborMap.size());
				joinResponse->setTreeLevel(LV->treeLevel);
				joinResponse->setIsTreebone(LV->isTreebone);
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
				neighborInfo nF;
				nF.isTreebone = simpleMeshmsg->getIsTreebone();
				nF.remainedNeighbor = simpleMeshmsg->getRemainNeighbor();
				nF.timeOut = simTime().dbl();
				nF.treeLevel = simpleMeshmsg->getTreeLevel();
				LV->neighborMap.insert(std::make_pair<TransportAddress, neighborInfo> (simpleMeshmsg->getSrcNode(),nF));

				if(!isRegistered)
					selfRegister();

				SimpleMeshMessage* joinAck = new SimpleMeshMessage("joinAck");
				joinAck->setCommand(JOIN_ACK);
				joinAck->setSrcNode(thisNode);
				joinAck->setBitLength(SIMPLEMESHMESSAGE_L(msg));
				joinAck->setAddAsChild(false);

				if (!LV->hasTreeboneParent && nF.isTreebone) {
					LV->hasTreeboneParent = true;
					LV->treeLevel = nF.treeLevel + 1;
					LV->treeboneParent = simpleMeshmsg->getSrcNode();
					joinAck->setAddAsChild(true);
					showOverlayNeighborArrow(simpleMeshmsg->getSrcNode(), false,
													"m=m,50,0,50,0;ls=red,1");
				}
				else
					showOverlayNeighborArrow(simpleMeshmsg->getSrcNode(), false,
														 "m=m,50,0,50,0;ls=green,1");

				joinAck->setRemainNeighbor(neighborNum - LV->neighborMap.size());
				joinAck->setTreeLevel(LV->treeLevel);
				joinAck->setIsTreebone(LV->isTreebone);
				sendMessageToUDP(simpleMeshmsg->getSrcNode(),joinAck);

				//std::cout<<"treeLevel : "<<LV->treeLevel<<endl;

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

				std::map <TransportAddress, neighborInfo>::iterator nodeIt = LV->neighborMap.find(simpleMeshmsg->getSrcNode());

				nodeIt->second.isTreebone = simpleMeshmsg->getIsTreebone();
				nodeIt->second.treeLevel = simpleMeshmsg->getTreeLevel();
				nodeIt->second.remainedNeighbor = simpleMeshmsg->getRemainNeighbor();
				nodeIt->second.timeOut = simTime().dbl();

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
		}
		else if(simpleMeshmsg->getCommand() == DISCONNECT)
		{
			disconnectProcess(simpleMeshmsg->getSrcNode());
		}
		delete simpleMeshmsg;
	}
	else
		DenaCastOverlay::handleUDPMessage(msg);
}
void SimpleMesh::handleNodeGracefulLeaveNotification()
{
	neighborNum = 0;
	selfUnRegister();
	std::cout << "time: " << simTime()<< "  "<<getParentModule()->getParentModule()->getFullName() <<  std::endl;

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
	//deleteVector(Node,LV->neighbors);
	if (LV->neighborMap.find(Node) != LV->neighborMap.end())
		LV->neighborMap.erase(Node);
	deleteOverlayNeighborArrow(Node);
	if(!isSource)
	{
		cancelEvent(meshJoinRequestTimer);
		scheduleAt(simTime(),meshJoinRequestTimer);
	}
	VideoMessage* videoMsg = new VideoMessage();
	videoMsg->setCommand(NEIGHBOR_LEAVE);
	videoMsg->setSrcNode(Node);
	send(videoMsg,"appOut");
}
void SimpleMesh::finishOverlay()
{
	if(!isSource) {
    	cancelAndDelete(meshJoinRequestTimer);
    	if (!LV->isTreebone)
    		cancelAndDelete(treebonePromotionCheckTimer);
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
	setOverlayReady(false);
}
