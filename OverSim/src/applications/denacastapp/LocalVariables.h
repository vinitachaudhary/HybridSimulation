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
 * @file LocalVariables.h
 * @author Yasser Seyyedi, Behnam Ahmadifar
 */

// edited by vinita

#ifndef LOCALVARIABLES_H_
#define LOCALVARIABLES_H_

#include <omnetpp.h>
#include "VideoBuffer.h"
#include <TransportAddress.h>

struct neighborInfo
{
	int remainedNeighbor;		/**< number of remained neighbor that node could accept*/
	double timeOut;             /**< Time out for neighbor notification*/
	bool isTreebone;			// true if the node is in treebone
	int treeLevel;				// node depth in the tree - source at level 0
	double TTL;					// time to live for subscription message
	int numChildren;			// number of children node currently has

	neighborInfo() : remainedNeighbor(0), isTreebone(false), treeLevel(-1), numChildren(0){};
	neighborInfo(int _remainedNeighbor, double _timeOut, bool _isTreebone, int _treeLevel, int _numChildren) :
		remainedNeighbor(_remainedNeighbor), timeOut(_timeOut),
		isTreebone(_isTreebone), treeLevel(_treeLevel), numChildren(_numChildren) {};
	neighborInfo(int _remainedNeighbor, double _timeOut, bool _isTreebone, int _treeLevel, double _ttl, int _numChildren) :
			remainedNeighbor(_remainedNeighbor), timeOut(_timeOut), isTreebone(_isTreebone),
			treeLevel(_treeLevel), TTL(_ttl), numChildren(_numChildren) {};

};

class LocalVariables: public cSimpleModule
{
public:
	/**
	 * For initiation of the variables
	 */
	virtual void initialize();
    /**
     * gives out current node download bandwidth
     *
     * @return download bandwidth of this node
     */
    double getDownBandwidth(){return downBandwidth;}
    /**
     * gives out current node upload bandwidth
     *
     * @return upload bandwidth of this node
     */
    double getUpBandwidth(){return upBandwidth;}
    /**
     * Update the node BufferMap based on video buffer
     */
    void updateLocalBufferMap();
    /**
     * set download bandwidth (by overlay)
     * @param DB download bandwidth
     */
    void setDownBandwidth(double DB);
    /**
     * set upload bandwidth (by overlay)
     */
    void setUpBandwidth(double UB);
    /**
     * get the value of late arrival loss (by player)
     * @return double late arrival loss size
     */
	virtual double getLateArivalLoss(){return stat_lateArrivalLossSize;}
	/**
     * get the value of availability and rate control loss (by player)
     * @return double sum of availability and rate control loss size
	 */
	virtual double getAvailability_RateControlLoss(){return stat_availability_RateControlLoss;}
	/**
	 * add values to statistics of loss due to availability and rate control in APP
	 * @param double Avail_RateControl availability rate control parameter
	 */
	virtual void addToAvailability_RateControlLoss(double Avail_RateControl);
	/**
	 * add value to statistics of loss due to late arrival
	 * @param LateArrivalLoss
	 */
	virtual void addToLateArivalLoss(double LateArivalLoss);

    VideoBuffer* videoBuffer; /**<Create new buffer for existing host to keep latest Chunks */
    BufferMap* hostBufferMap; /**<Create our own Buffer map to announce other neighbors */
    //std::vector <TransportAddress> neighbors;
    std::map <TransportAddress, neighborInfo> neighborMap;	/**< Map from node's neighbors' TransportAddresses to their information*/
    bool isTreebone;					// true if node member of treebone
    bool hasTreeboneParent;				// true if node has a treebone parent
    TransportAddress treeboneParent;	// TransportAddress of treebone parent
    std::vector <TransportAddress> treeboneChildren;	// Vector of transportAddress of treebone children
    int treeLevel;			// node depth in tree, -1 for invalid

    std::map <TransportAddress, neighborInfo> PartialView;		// for SCAMP protocol - partial list of nodes to which this node sends gossip messages to
    std::map <TransportAddress, neighborInfo> InView;			// for SCAMP protocol - list of nodes from which this node receives gossip messages from

protected:
    int windowOfIntrest; /**< size of window of interest in second*/
	int Fps; /**< Frame per second*/
	int chunkSize; /**< number of frames in a chunk*/
	int gopSize; /**<Number of frames per Group of Picture */
    int numOfBFrame; /**<Number of B frames between 'I' and 'P' or between two 'P' frames */
    int bufferSize; /** number of chunks in the video buffer */
    double downBandwidth; /**< The download bandwidth that node initially has*/
    double upBandwidth; /**< The upload bandwidth that node initially has*/
	double stat_lateArrivalLossSize; /**< statistic that is all losses due late arrival */
	double stat_availability_RateControlLoss; /**< statistics that is all losses due to availability or rate control */
};

#endif /* LOCALVARIABLES_H_ */
