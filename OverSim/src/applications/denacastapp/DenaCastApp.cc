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
 * @file DenaCastApp.cc
 * @author Behnam Ahmadifar, Yasser Seyyedi
 */

// edited by vinita

#include "DenaCastApp.h"
#include <GlobalStatistics.h>
#include <GlobalNodeList.h>
#include <PeerInfo.h>
#include <LocalVariables.h>

Define_Module(DenaCastApp);


void DenaCastApp::initializeApp(int stage)
{
	if (stage != MIN_STAGE_APP)
		return;
	//initialize parameters
	numOfBFrame = par("numOfBFrame");
	bufferMapExchangePeriod = par("bufferMapExchangePeriod");
	gopSize = par("gopSize");
    if(globalNodeList->getPeerInfo(thisNode.getAddress())->getTypeID() == 2)
    	isVideoServer = true;
    else
    	isVideoServer = false;
    startUpBuffering = par ("startUpBuffering");
    Fps = par("Fps");
    double windowOfIntrest = par("windowOfIntrest");
    chunkSize = par ("chunkSize");
    bufferSize = windowOfIntrest*Fps/chunkSize;
    if(bufferSize%chunkSize > 0)
    		bufferSize += chunkSize - (bufferSize%chunkSize);
	numOfBFrame = par("numOfBFrame");
    rateControl = par("rateControl");
    measuringTime = par("measuringTime");
    receiverSideSchedulingNumber = par("receiverSideSchedulingNumber");
    senderSideSchedulingNumber = par("senderSideSchedulingNumber");
    averageChunkLength = par("averageChunkLength");

    //initialize global variables
    playbackPoint = -1;
    playingState = BUFFERING;
    bufferMapExchangeStart = false;
    schedulingSatisfaction = false;
    lastSentChunk = 0;
    lastReceivedChunk = 0;
    meshPullActive = true;

	//initialize self messages
	bufferMapTimer = new cMessage("bufferMapTimer");
	requestChunkTimer = new cMessage("requestChunkTimer");
	playingTimer = new cMessage("playingTimer");
	sendFrameTimer = new cMessage("sendFrameTimer");
	meshPullTimer = new cMessage("meshPullTimer");

	if(!isVideoServer)
		bc = check_and_cast<BaseCamera*>(simulation.getModuleByPath("CDN-Server[1].tier2.mpeg4camera"));

	LV = check_and_cast<LocalVariables*>(getParentModule()->getSubmodule("localvariables"));

	//statistics
	stat_startupDelay = 0;
	stat_startSendToPlayer = 0;
	stat_startBuffering = 0;
	stat_startBufferMapExchange = 0;
	stat_TotalReceivedSize = 0;
	stat_RedundentSize = 0;

    firstChunkReceived = false;
    firstChunkTime = 0.0;
    stat_FirstFrameToPlayerTime = 0.0;

    sumPlaybackLag = 0.0;
    frameCount = 0;
    stat_PlaybackLag = 0.0;

	// setting server and clients display string
	if(isVideoServer)
		getParentModule()->getParentModule()->setDisplayString("i=device/server;i2=block/circle_s");
	else
		getParentModule()->getParentModule()->setDisplayString("i=device/wifilaptop_vs;i2=block/circle_s");
}
void DenaCastApp::handleTimerEvent(cMessage* msg)
{
	if(msg == sendFrameTimer)
	{
		selectSenderSideScheduling();
	}
	else if(msg == requestChunkTimer)
	{
		if(playingState != STOP)
			schedulingSatisfaction = true;
	}
	else if(msg == bufferMapTimer)
	{
		bufferMapExchange();
	}
	else if(msg == playingTimer)
	{
		if(playingState == PLAYING)
		{
			sendFrameToPlayer();
		}
		else if (playingState == BUFFERING)
		{	// check if we have video equal to startup buffering
			checkForPlaying();
		}
		scheduleAt(simTime()+1/(double)Fps,playingTimer);

	}
	else if (msg == meshPullTimer) {
		// Periodically check if chunks need to be pulled over mesh.
		if (meshPullActive || !LV->hasTreeboneParent || lastReceivedChunk*chunkSize < playbackPoint) {
			meshPullActive = true;
			selectRecieverSideScheduling();
		}
		else {
			// check for loss between playback point and lastReceivedChunk
			int inCompleteChunks = 0;
			int playbackIndex = playbackPoint/chunkSize - LV->hostBufferMap->chunkNumbers[0];
			int lastReceivedChunkIndex = lastReceivedChunk - LV->hostBufferMap->chunkNumbers[0];
			if (playbackIndex >= 0 && playbackIndex < bufferSize && lastReceivedChunkIndex >= 0 && lastReceivedChunkIndex < bufferSize) {
				for (int i=playbackIndex; i<lastReceivedChunkIndex; i++)
					if (!LV->hostBufferMap->buffermap[i])
						inCompleteChunks++;
				if (inCompleteChunks > 10)
					selectRecieverSideScheduling();
			}
		}
		scheduleAt(simTime()+10/(double)Fps,meshPullTimer);
	}
	else
		delete msg;

}
void DenaCastApp::handleLowerMessage(cMessage* msg)
{
	if (dynamic_cast<VideoMessage*>(msg) != NULL)
	{
		VideoMessage* VideoMsg=dynamic_cast<VideoMessage*>(msg);
		if(VideoMsg->getCommand() == CHUNK_REQ)
		{
			requesterNode rN;
			rN.tAddress = VideoMsg->getSrcNode();
			rN.chunkNo = VideoMsg->getChunk().getChunkNumber();
			senderqueue.insert(std::make_pair<double,requesterNode>(VideoMsg->getDeadLine(),rN));
			selectSenderSideScheduling();
			delete msg;
		}
		else if(VideoMsg->getCommand() == CHUNK_RSP && !isVideoServer)
		{
			if (!firstChunkReceived) {
				firstChunkReceived =true;
				firstChunkTime = simTime().dbl();
			}
			if(!bufferMapExchangeStart)
			{
				scheduleAt(simTime(),requestChunkTimer);
				scheduleAt(simTime(),playingTimer);
				scheduleAt(simTime()+bufferMapExchangePeriod+uniform(0,0.25),bufferMapTimer);
				stat_startBufferMapExchange = simTime().dbl() + bufferMapExchangePeriod;
				stat_startBuffering = simTime().dbl();
				bufferMapExchangeStart=true;
				int shiftnum = 0;
				if(VideoMsg->getChunk().getChunkNumber() > 0)
					shiftnum = VideoMsg->getChunk().getChunkNumber();
				shiftnum-=2;
				for(int i=0 ; i<shiftnum ; i++)
					LV->videoBuffer->shiftChunkBuf();
				LV->updateLocalBufferMap();
			}

			bool redundantState = false;
			if(VideoMsg->getChunk().isComplete() && !VideoMsg->hasBitError())
			{
				int shiftnum = VideoMsg->getChunk().getChunkNumber() - LV->videoBuffer->chunkBuffer[bufferSize-1].getChunkNumber();
				for(int i=0 ; i<shiftnum ; i++)
					LV->videoBuffer->shiftChunkBuf();
				LV->updateLocalBufferMap();

				if(LV->hostBufferMap->findChunk(VideoMsg->getChunk().getChunkNumber()))
				{
					stat_RedundentSize += VideoMsg->getChunk().getChunkByteLength();
					redundantState = true;
				}
				stat_TotalReceivedSize += VideoMsg->getChunk().getChunkByteLength();
				Chunk InputChunk = VideoMsg->getChunk();
				InputChunk.setHopCout(InputChunk.getHopCount()+1);
				LV->videoBuffer->setChunk(InputChunk);
				LV->updateLocalBufferMap();

				// keep track of the chunks which are pushed, indicating active parent.
				if (VideoMsg->getIsPushed()) {
					lastReceivedChunk = InputChunk.getChunkNumber();
					meshPullActive = false;
				}
				else
					deleteElement(VideoMsg->getChunk().getChunkNumber(),sendFrames);

				if(isMeasuring(VideoMsg->getChunk().getLastFrameNo()))
				{
					globalStatistics->addStdDev("DenaCastApp: end to end delay", simTime().dbl() - VideoMsg->getChunk().getCreationTime());
					globalStatistics->addStdDev("DenaCastApp: Hop Count", VideoMsg->getChunk().getHopCount());
					if(VideoMsg->getChunk().getLastFrameNo() < playbackPoint)
						LV->addToLateArivalLoss(VideoMsg->getChunk().getLateArrivalLossSize(playbackPoint));
				}

				if (!redundantState) {
					// Push the received chunk to children.
					for (unsigned int i=0; i < LV->treeboneChildren.size(); i++) {
						handleChunkRequest(LV->treeboneChildren[i],LV->videoBuffer->lastSetChunk,true);
						lastSentChunk = LV->videoBuffer->lastSetChunk;
					}
				}
			}
			delete msg;
		}
		else if(VideoMsg->getCommand() == NEIGHBOR_LEAVE) {
			deleteNeighbor(VideoMsg->getSrcNode());
			if (LV->hasTreeboneParent && VideoMsg->getSrcNode() == LV->treeboneParent)
				meshPullActive = true;
			delete VideoMsg;
		}
		else if(VideoMsg->getCommand() == LEAVING)
		{
			playingState = STOP;
			schedulingSatisfaction = false;
			delete VideoMsg;
		}
		else
			delete VideoMsg;
	}
	else if(dynamic_cast <BufferMapMessage*> (msg) != NULL)
	{
		BufferMapMessage* BufferMap_Recieved=dynamic_cast<BufferMapMessage*>(msg);
		if(!bufferMapExchangeStart && !isVideoServer)
		{
				scheduleAt(simTime(),requestChunkTimer);
				scheduleAt(simTime(),playingTimer);
				scheduleAt(simTime()+bufferMapExchangePeriod,bufferMapTimer);
				scheduleAt(simTime(), meshPullTimer);
				stat_startBufferMapExchange = simTime().dbl() + bufferMapExchangePeriod;
				stat_startBuffering = simTime().dbl();
				bufferMapExchangeStart = true;
				if (LV->hasTreeboneParent)
					meshPullActive = false;
				if (meshPullActive) {
					int shiftnum = 0;
					if(BufferMap_Recieved->getBuffermap().getLastSetChunk() > 0)
						shiftnum = BufferMap_Recieved->getBuffermap().getLastSetChunk();
					if(shiftnum%gopSize > 0 && chunkSize%gopSize !=0)
						shiftnum += gopSize - (shiftnum%gopSize);
					else
						shiftnum -= 2;
					for(int i=0 ; i<shiftnum ; i++)
						LV->videoBuffer->shiftChunkBuf();
				}
				LV->updateLocalBufferMap();
		}
		notInNeighbors.clear();
		updateNeighborBMList(BufferMap_Recieved);

		if(schedulingSatisfaction && meshPullActive)
			selectRecieverSideScheduling();
		delete msg;
	}
	else
		delete msg;
}
void DenaCastApp::handleUpperMessage(cMessage* msg)
{
	if (dynamic_cast<VideoMessage*>(msg) != NULL)
	{
		VideoMessage* VideoMsg=dynamic_cast<VideoMessage*>(msg);
		if (VideoMsg->getCommand() == CAMERA_MSG)
		{
			if(!bufferMapExchangeStart)
			{
				scheduleAt(simTime()+bufferMapExchangePeriod,bufferMapTimer);
				bufferMapExchangeStart=true;
			}
			LV->videoBuffer->setFrame(VideoMsg->getVFrame());
			LV->updateLocalBufferMap();
			delete msg;

			if (lastSentChunk != LV->videoBuffer->lastSetChunk) {
				// Push the generated chunk at server camera to children
				for (unsigned int i=0; i < LV->treeboneChildren.size(); i++) {
					handleChunkRequest(LV->treeboneChildren[i],LV->videoBuffer->lastSetChunk,true);
				}
				lastSentChunk = LV->videoBuffer->lastSetChunk;
			}
		}
	}
	else
		delete msg;
}

void DenaCastApp::updateNeighborBMList(BufferMapMessage* BufferMap_Recieved)
{
	bool find = false;
	for(unsigned int i=0 ; i<neighborsBufferMaps.size();i++)
		if(neighborsBufferMaps[i].tAddress == BufferMap_Recieved->getSrcNode())
		{
			neighborsBufferMaps[i].buffermap = BufferMap_Recieved->getBuffermap();
			neighborsBufferMaps[i].totalBandwidth = BufferMap_Recieved->getTotalBandwidth();
			find = true;
			break;
		}
	if(!find)
	{
		nodeBufferMap neighbourBM;
		neighbourBM.buffermap.setValues(chunkSize);
		neighbourBM.tAddress = BufferMap_Recieved->getSrcNode();
		neighbourBM.totalBandwidth =  BufferMap_Recieved->getTotalBandwidth();
		neighbourBM.requestCounter = 0;
		neighbourBM.buffermap = BufferMap_Recieved->getBuffermap();
		//neighbourBM.timeout = simTime().dbl();
		neighborsBufferMaps.push_back(neighbourBM);
	}
}
void DenaCastApp::deleteElement(int frameNum, std::vector<int>& sendframes)
{
	for (unsigned int i=0; i!=sendframes.size(); i++)
	{
		if (sendframes[i] == frameNum)
		{
			sendframes.erase(sendframes.begin()+i,sendframes.begin()+1+i);
			break;
		}
	}
}


void DenaCastApp::checkForPlaying()
{
	int bitCounter = 0;
	for(int i=0 ; i + LV->hostBufferMap->chunkNumbers[0] < LV->hostBufferMap->getLastSetChunk() + 1 ; i++)
		if(LV->hostBufferMap->buffermap[i])
				bitCounter++;
	bitCounter *= chunkSize;
	if(bitCounter > Fps*startUpBuffering)
	{
		playingState = PLAYING;
		stat_startSendToPlayer = simTime().dbl();
		stat_startupDelay = simTime().dbl() - stat_startBuffering;
		stat_FirstFrameToPlayerTime = stat_startSendToPlayer - firstChunkTime;
		playbackPoint = LV->hostBufferMap->chunkNumbers[0]*chunkSize;
	}
}
void DenaCastApp::sendFrameToPlayer()
{

	VideoFrame vf;
	if (LV->hostBufferMap->findChunk(playbackPoint/chunkSize))
		vf = LV->videoBuffer->getFrame(playbackPoint);
	vf.setFrameNumber(playbackPoint);
	VideoMessage* playermessage = new VideoMessage("PlayerMessage");
	playermessage->setCommand(PLAYER_MSG);
	playermessage->setVFrame(vf);
	send(playermessage,"to_upperTier");
	if(vf.getFrameType() == 'N')
		checkAvailability_RateControlLoss();
	else {
		// Stat Collection for Playback Lag
		sumPlaybackLag+=simTime().dbl() - vf.getCreationTime();
		frameCount++;
	}
	playbackPoint++;
	sendframeCleanUp();

}

void DenaCastApp::sendframeCleanUp()
{
	bool hasExpiredFrame = true;
	while (hasExpiredFrame)
	{
		hasExpiredFrame = false;
		for (unsigned int i=0; i!=sendFrames.size(); i++)
			if (sendFrames[i] < LV->videoBuffer->chunkBuffer[0].chunk[0].getFrameNumber())
				hasExpiredFrame = true;
		for (unsigned int i=0; i!=sendFrames.size(); i++)
		{
			if(sendFrames.size() < i)
				break;
			if(sendFrames[i] < LV->videoBuffer->chunkBuffer[0].chunk[0].getFrameNumber())
				sendFrames.erase(sendFrames.begin()+i,sendFrames.begin()+1+i);
		}
	}
}
bool DenaCastApp::isInVector(TransportAddress& Node, std::vector <TransportAddress> &list)
{
	for (unsigned int i=0; i!=list.size(); i++)
	{
		if (list[i] == Node)
		{
			return true;
		}
	}
	return false;
}
void DenaCastApp::checkAvailability_RateControlLoss()
{
	if(playbackPoint/Fps > measuringTime)
		return;
	bool find = false;
	for(unsigned int i = 0; i < requestedChunks.size(); i++)
	{
		if(requestedChunks[i] == playbackPoint)
		{
			requestedChunks.erase(requestedChunks.begin()+i,requestedChunks.begin()+1+i);
			find = true;
			break;
		}
	}
	if(!find)
	{
		std::map <int,int>::iterator frameIt = bc->frameInfo.begin();
		frameIt = bc->frameInfo.find(playbackPoint);
		LV->addToAvailability_RateControlLoss(frameIt->second);
	}
}

void DenaCastApp::bufferMapExchange()
{
	if(playingState != STOP)
	{
		if(LV->videoBuffer->lastSetChunk == 0)
			scheduleAt(simTime()+bufferMapExchangePeriod,bufferMapTimer);
		else
		{
			BufferMap BM;
			BM.setValues(bufferSize);
			LV->videoBuffer->updateBufferMap(&BM);
			BufferMapMessage *BufferMapmsg = new BufferMapMessage("BufferMap_exchange");
			BufferMapmsg->setBuffermap(BM);
			BufferMapmsg->setBitLength(BUFFERMAPMESSAGE_L(msg)+LV->hostBufferMap->getBitLength());
			send (BufferMapmsg,"to_lowerTier");
			scheduleAt(simTime()+bufferMapExchangePeriod,bufferMapTimer);
		}
	}
}
bool DenaCastApp::isMeasuring(int frameNo)
{
	if(frameNo/Fps > measuringTime)
		return true;
	else
		return false;
}
void DenaCastApp::countRequest(TransportAddress& node)
{
	for(unsigned int i = 0; i < neighborsBufferMaps.size(); i++)
	{
		if(neighborsBufferMaps[i].tAddress == node)
		{
			neighborsBufferMaps[i].requestCounter -= 1;
		}
	}
}
void DenaCastApp::deleteNeighbor(TransportAddress& node)
{
	for(unsigned int i=0 ; i<neighborsBufferMaps.size() ; i++)
		if(neighborsBufferMaps[i].tAddress == node)
		{
			neighborsBufferMaps.erase(neighborsBufferMaps.begin()+i,neighborsBufferMaps.begin()+1+i);
			break;
		}
}
void DenaCastApp::finishApp()
{
	cancelAndDelete(bufferMapTimer);
	cancelAndDelete(requestChunkTimer);
	cancelAndDelete(playingTimer);
	cancelAndDelete(sendFrameTimer);
	cancelAndDelete(meshPullTimer);
	//statistics
	if(stat_startupDelay != 0)
	{
		globalStatistics->addStdDev("DenaCastApp: Startup Delay", stat_startupDelay);
		globalStatistics->recordOutVector("DenaCastApp: Startup Delay_vec", stat_startupDelay);
	}
	if(stat_startSendToPlayer != 0)
		globalStatistics->addStdDev("DenaCastApp: start to send to player time", stat_startSendToPlayer);
	if(stat_startBuffering != 0)
		globalStatistics->addStdDev("DenaCastApp: start to buffering time", stat_startBuffering);
	if(stat_startBufferMapExchange != 0)
		globalStatistics->addStdDev("DenaCastApp: start exchanging bufferMap", stat_startBufferMapExchange);
	if(stat_TotalReceivedSize != 0)
		globalStatistics->addStdDev("DenaCastApp: Frame Redundancy",stat_RedundentSize/stat_TotalReceivedSize *100);

	if(stat_FirstFrameToPlayerTime != 0)
		globalStatistics->addStdDev("DenaCastApp: First Frame received to player time", stat_FirstFrameToPlayerTime);

	// Stat Collection for Playback lag : taking average of all frame's playback lag.
	if (frameCount >0) {
		stat_PlaybackLag = sumPlaybackLag/frameCount;
		globalStatistics->addStdDev("DenaCastApp: Playback Lag", stat_PlaybackLag);
	}
}
