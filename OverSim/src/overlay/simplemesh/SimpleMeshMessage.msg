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


//
//@author Yasser Seyyedi, Behnam Ahmadifar
//

cplusplus {{
#include <TransportAddress.h>
#include <CommonMessages_m.h>

// constants for message length in bit
static const int SIMPLEMESHCOMMAND_L = 8;
#define SIMPLEMESHMESSAGE_L(msg) ( TRANSPORTADDRESS_L + SIMPLEMESHCOMMAND_L + BASEOVERLAY_L(msg))

}}           // noncobject means it's not a message class.
class BaseOverlayMessage;
class noncobject TransportAddress;

enum SIMPLEMESHCommand
{
    JOIN_REQUEST = 0;    // JOIN_REQUEST-Message
    JOIN_RESPONSE = 1;    // JOIN_RESPONSE-Message
    JOIN_ACK = 2;   	 // JOIN_ACK-Message
    JOIN_DENY = 3;    // JOIN_DENY-Message
    DISCONNECT = 4;    // DISCONNECT-Message
    ALIVE = 5;
    NEW_SUBSCRIPTION = 7;
    FORWARD_SUBSCRIPTION = 8;
    SUBSCRIPTION_ACK = 9;
    UNSUBSCRIBE = 10;
}
//	join message in SimpleMesh 
//  @author Behnam Ahmadifar, Yasser Seyyedi
//
packet SimpleMeshMessage extends BaseOverlayMessage
{
	int command @enum(SIMPLEMESHCommand);
	TransportAddress srcNode;  // address of the node that sent the message
	bool isTreebone; 			// true if node belongs to treebone
	int remainNeighbor;			// number of remaining neighbor node can accept
	int treeLevel;				// node depth in tree
	bool addAsChild;			// true if node wants to be added as child
}

packet ScampMessage extends BaseOverlayMessage {
 	int command @enum(SIMPLEMESHCommand);
	TransportAddress srcNode;  // address of the node that sent the message
	bool toForward; 			// true if new subscription message must be forwarded after receiving 
	bool isTreebone; 			// true if node belongs to treebone
	int remainNeighbor;			// number of remaining neighbor node can accept
	int treeLevel;				// node depth in tree
	double TTL;					// time to live for subscription messages
	TransportAddress nodeToBeSubscribed;  // address of the node that is to be subscribed in case of Forward Subscriptions
}