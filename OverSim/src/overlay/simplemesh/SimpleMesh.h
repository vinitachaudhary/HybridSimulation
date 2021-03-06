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
 * @file SimpleMesh.h
 * @author Yasser Seyyedi, Behnam Ahmadifar
 */

// edited by vinita

#ifndef SIMPLEMESH_H_
#define SIMPLEMESH_H_

#include <omnetpp.h>
#include <OverlayKey.h>
#include <TransportAddress.h>
#include <GlobalNodeList.h>
#include "SimpleMeshMessage_m.h"
#include <DenaCastOverlay.h>


class SimpleMesh : public DenaCastOverlay
{
protected:
    bool isSource;/**< whether this node is server*/
    int activeNeighbors;/**< Neighbor that node connects to them*/
    int passiveNeighbors; /**< Neighbors that node let them connect to it*/
    int neighborNum; /**< Sum of active and passive neighbors*/
    double neighborNotificationPeriod; /**< period to notify tracker about number of current neighbor*/
    double videoAverageRate; /**< average video bit rate for calculating neighbor num*/
    bool adaptiveNeighboring; /**< true if we want to have adaptive neighbors*/
    bool isRegistered; /**< if this node registered in the tracker */
    bool serverGradualNeighboring; /**< true if gradual neighbor is required for source node*/
    TransportAddress trackerAddress; /**< Transport address of tracker node */
    std::map <TransportAddress,double> neighborTimeOut; /**<Timeout for neighbors - to check for failed nodes>*/

    int sessionLength;		// Session length of simulation
    simtime_t joinTime;		// time when node joined the overlay - for measurement of node's age
    simtime_t lastAliveMsgTime; 	// time when last alive message was received
    bool findingNewParent;			// true if node if trying to connect with a new parent and leaving current parent.

    // maps the nodes to the number of times their forwarded subscription is seen by this node
    std::map<TransportAddress, int> seenForwardedSubs;

    /**
     * Register node in the tracker
     */
    void selfRegister();
    /**
     * Unregister node in the tracker
     */
    void selfUnRegister();
    /**
     * for leaving this method do this process for node that want to leave with notification
     * @param TransportAdress
     */
    void disconnectProcess(TransportAddress node);

	/*
	 * Helper function to avoid redundancy to set values of SimpleMeshMessage
	 */
    void neighborInfoToMsg (SimpleMeshMessage* msg, int _remainedNeighbor,
    		bool _isTreebone, int _treeLevel, int _numChildren);

    /*
	 * Helper function to avoid redundancy to set values of ScampMessage
	 */
	void neighborInfoToMsg (ScampMessage* msg, int _remainedNeighbor,
			bool _isTreebone, int _treeLevel, int _numChildren);

	void resubscriptionProcess();		// Procedure for a node to resubscribe to a random node in PartialView

    //selfMessages
    cMessage* meshJoinRequestTimer; /**< self message for scheduling neighboring*/
    cMessage* remainNotificationTimer; /**< self message for scheduling send notification to server*/
    cMessage* serverNeighborTimer; /**< for gradual neighboring this self message plan for this job */

    cMessage* treebonePromotionCheckTimer;	// timer to check if the node can be promoted to treebone
    cMessage* subscriptionExpiryTimer; 		// timer to remove expired subscription from Partial View
    cMessage* resubscriptionTimer;			// timer to resubscribe
    cMessage* isolationRecoveryTimer;		// timer to check if node has been isolated from group
    cMessage* aliveNotificationTimer;		// timer to send alive notification to neighbors.
    cMessage* checkNeighborTimeout;			// timer to check for alive neighbors and remove the neighbors which left.
    cMessage* parentRequestTimer;			// timer to check if the node has a treebone parent otherwise find one

    cMessage* highDegreePreemptTimer; 		// timer for high degree preemption adaptation
    cMessage* lowDelayJumpTimer;			// timer for low delay jump adaptation

    // statistics
	uint32_t stat_TotalUpBandwidthUsage;
	uint32_t stat_TotalDownBandwidthUsage;

    uint32_t stat_joinREQ; /**< number of sent join request messages */
	uint32_t stat_joinREQBytesSent;  /**< number of sent bytes of join request messages */
	uint32_t stat_joinRSP; /**< number of sent join response messages */
	uint32_t stat_joinRSPBytesSent; /**< number of sent bytes of join response messages */
	uint32_t stat_joinACK; /**< number of sent join acknowledge messages */
	uint32_t stat_joinACKBytesSent; /**< number of sent bytes of join acknowledge messages */
	uint32_t stat_joinDNY; /**< number of sent join deny messages */
	uint32_t stat_joinDNYBytesSent; /**< number of sent bytes of join deny messages */
	uint32_t stat_disconnectMessages; /**< number of sent disconnect messages */
	uint32_t stat_disconnectMessagesBytesSent; /**< number of sent bytes of disconnect messages */
	uint32_t stat_addedNeighbors; /**< number of added neighbors during life cycle of this node */
	uint32_t stat_nummeshJoinRequestTimer; /**< number of meshJoinRequestTimer self messages */

	bool firstPeerAdded;	// whether the node has connected to peers for the first time.
	double peerJoinTime;		// Time when node is created.
	double peerSelectionTime;	// Time when peer selects its first neighbor.
	double stat_peerSelectionTime; /**< time taken by node to connect to peers at startup */
	double stat_peerSelectionToFirstChunkTime; // time taken by node after selecting a peer till it receives its first chunk.

	bool parentLeft;	// whether a parent has left recently. For calculation of Parent Reselection Time.
	double parentLeftTime;	// Time when the last parent left.
	double sum_ParentReselectionTime;	// sums the parent reselection time for each parent leave.
	double stat_parentReselectionTime;	// average time taken by node to reselect its parents.
	int countParentLeft;	// Total count of number of parents disconnecting.

	bool neighborLeft;	// whether a parent has left recently. For calculation of Parent Reselection Time.
	double neighborLeftTime;	// Time when the last parent left.
	double sum_NeighborReselectionTime;	// sums the parent reselection time for each parent leave.
	double stat_neighborReselectionTime;	// average time taken by node to reselect its parents.
	int countNeighborLeft;	// Total count of number of parents disconnecting.

	static int stat_num_treebone;  // number of treebone nodes in the overlay.

public:

    /**
     * initializes base class-attributes
     *
     * @param stage the init stage
     */
	virtual void initializeOverlay(int stage);
    /**
     * Writes statistical data and removes node from bootstrap oracle
     */
	virtual void finishOverlay();
	virtual void handleTimerEvent(cMessage* msg);
	virtual void handleUDPMessage(BaseOverlayMessage* msg);
	virtual void joinOverlay();

    /**
     *notify its neighbors that it is going to leave the mesh
     */
	virtual void handleNodeGracefulLeaveNotification();

    /**
     * Search neighbor list with specific TransportAddress to see
     * if they are neighbor or not
     *
     * @param Node the TransportAddress
     * @param vector<TransportAddress> neighbor list
     */
    bool isInVector(TransportAddress& Node, std::vector <TransportAddress> &neighbors);

    /**
     * Delete the node from its neighbors list
     *
     * @param Node the TransportAddress
     * @param vector<TransportAddress> neighbor list
     */
    void deleteVector(TransportAddress Node,std::vector <TransportAddress> &neighbors);

    void meshJoinTrackerMsg();		// To request neighbors from tracker for the first time
};

#endif /* SIMPLEMESH_H_ */

