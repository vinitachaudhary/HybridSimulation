//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/simplemesh/SimpleMeshMessage.msg.
//

#ifndef _SIMPLEMESHMESSAGE_M_H_
#define _SIMPLEMESHMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <TransportAddress.h>
#include <CommonMessages_m.h>


static const int SIMPLEMESHCOMMAND_L = 8;
#define SIMPLEMESHMESSAGE_L(msg) ( TRANSPORTADDRESS_L + SIMPLEMESHCOMMAND_L + BASEOVERLAY_L(msg))
// }}



/**
 * Enum generated from <tt>overlay/simplemesh/SimpleMeshMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum SIMPLEMESHCommand
 * {
 *     JOIN_REQUEST = 0;    
 *     JOIN_RESPONSE = 1;    
 *     JOIN_ACK = 2;   	 
 *     JOIN_DENY = 3;    
 *     DISCONNECT = 4;    
 *     ALIVE = 5;
 * }
 * </pre>
 */
enum SIMPLEMESHCommand {
    JOIN_REQUEST = 0,
    JOIN_RESPONSE = 1,
    JOIN_ACK = 2,
    JOIN_DENY = 3,
    DISCONNECT = 4,
    ALIVE = 5
};

/**
 * Class generated from <tt>overlay/simplemesh/SimpleMeshMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet SimpleMeshMessage extends BaseOverlayMessage
 * {
 * 	int command @enum(SIMPLEMESHCommand);
 * 	TransportAddress srcNode;  
 * }
 * </pre>
 */
class SimpleMeshMessage : public ::BaseOverlayMessage
{
  protected:
    int command_var;
    ::TransportAddress srcNode_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SimpleMeshMessage&);

  public:
    SimpleMeshMessage(const char *name=NULL, int kind=0);
    SimpleMeshMessage(const SimpleMeshMessage& other);
    virtual ~SimpleMeshMessage();
    SimpleMeshMessage& operator=(const SimpleMeshMessage& other);
    virtual SimpleMeshMessage *dup() const {return new SimpleMeshMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getCommand() const;
    virtual void setCommand(int command_var);
    virtual TransportAddress& getSrcNode();
    virtual const TransportAddress& getSrcNode() const {return const_cast<SimpleMeshMessage*>(this)->getSrcNode();}
    virtual void setSrcNode(const TransportAddress& srcNode_var);
};

inline void doPacking(cCommBuffer *b, SimpleMeshMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SimpleMeshMessage& obj) {obj.parsimUnpack(b);}


#endif // _SIMPLEMESHMESSAGE_M_H_
