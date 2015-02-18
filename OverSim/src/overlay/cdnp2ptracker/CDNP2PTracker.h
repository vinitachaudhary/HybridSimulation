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
 * @file CDNP2PTracker.h
 * @author Yasser Seyyedi, Behnam Ahmadifar
 */

// edited by vinita

#ifndef CDNP2PTRACKER_H_
#define CDNP2PTRACKER_H_

#include <BaseOverlay.h>
#include "DenaCastTrackerMessage_m.h"

/**<
 * a struct that contains node information
 *
 */
struct nodeInfo
{
	TransportAddress tAddress;		/**< address of node */
	int remainedNeighbor;		/**< number of remained neighbor that node could accept*/
	double timeOut;             /**< Time out for neighbor notification*/
	bool isTreebone;			// true if the node is in treebone
};
class CDNP2PTracker : public BaseOverlay
{
public:
	virtual void initializeOverlay(int stage);
	virtual void finishOverlay();
	virtual void handleUDPMessage(BaseOverlayMessage* msg);
	virtual void handleTimerEvent(cMessage* msg);
	virtual void joinOverlay();
protected:
    bool connectedMesh;	/**< if we have multiple server connects mesh that form under them*/
    /**
     * fill the list with node that are going to send to requested peer
     * @param list list to be sent
     * @param nodeList treeboneList or peerList
     * @param node the node that request in order to exclude from list
     * @param size how many peer should be insert in the list
     */
    void FillList(std::vector <TransportAddress>& list, std::multimap <int,nodeInfo> nodeList,
    		TransportAddress& node, unsigned int size);
    /*
     * check a given vector that contains a node
     * @param node the given node
     * @param list the given list
     * @param treeNeighborSize the number of maximum treebone nodes that can be filled in list
     * @return Boolean true if the list contains node
     */
    bool isInVector(TransportAddress& Node, std::vector <TransportAddress> &list);
    /*
     * calculate the size of node that tracker should return to requested node
     * @param neighborSize number of node that a peer requested
     * @param sourceNode the server that node is member of
     * @param treeNeighborSize the function calculates this parameter as the no. of treebone nodes it can return
     * @param meshNeighborSize the function calculates this parameter as the no. of mesh nodes it can return
     * @return integer number of node that a sever could return
     */
    int calculateSize(unsigned int neighborSize, TransportAddress& sourceNode,
    		unsigned int& treeNeighborSize, unsigned int& meshNeighborSize);
    /**
     * specify whether it is the time to connect meshes under servers (time to return nodes from other meshes)
     * @return Boolean true if it is time
     */
    bool satisfactionConnected();
    /**
     * find the server number that a node is member of
     * @param node the address of node to check
     * @return integer the server index number
     */
    int getServerNumber(TransportAddress& node);
    /*
     * function to assign a server to the given node
     * @param node the given node
     */
    void SetServerNumber(TransportAddress& node);

    /*
     * function to check time out of peers in overlay
     * @param treeboneList or peerList
     */
    void checkPeersTimeOuts(std::multimap <int,nodeInfo>);
    /**< map contains all mesh peer that send at least one message to server
     * integer = serverID, TransportAddress = peer TransportAddress
     * */

    cMessage* checkPeerTimer;	// Periodic self message to check peer timeouts

    std::multimap <int,nodeInfo> peerList;

	// multimap of serverID to peers in Treebone
    std::multimap <int,nodeInfo> treeboneList;
    /**< map contains all peer that send at least one message to server
     * TransportAddress = Peer TransportAddress , integer = serverID
     * */
    std::map <TransportAddress,int> peerServers;
    unsigned int serverNum; /**< number of servers currently in the network*/

};
#endif /* CDNP2PTRACKER_H_ */
