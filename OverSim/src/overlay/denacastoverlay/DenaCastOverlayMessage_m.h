//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/denacastoverlay/DenaCastOverlayMessage.msg.
//

#ifndef _DENACASTOVERLAYMESSAGE_M_H_
#define _DENACASTOVERLAYMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <TransportAddress.h>
#include <CommonMessages_m.h>


static const int SEQNO_L = 8;
static const int LENGTH_L = 16;
static const int COMMAND_L = 1;


#define ENCAPVIDEOMESSAGE_PACKET_L(msg) (BASEOVERLAY_L(msg) + SEQNO_L + LENGTH_L)
#define ENCAPVIDEOMESSAGE_L(msg) (BASEOVERLAY_L(msg))
#define ENCAPBUFFERMAP_L(msg) (BASEOVERLAY_L(msg)) 
#define ERRORRECOVERYMESSAGE_L(msg) (SEQNO_L + BASEOVERLAY_L(msg) + CHUNKNUMBER_L + TRANSPORTADDRESS_L + LENGTH_L + COMMAND_L)
// }}



/**
 * Class generated from <tt>overlay/denacastoverlay/DenaCastOverlayMessage.msg</tt> by opp_msgc.
 * <pre>
 * message EncapVideoMessage extends BaseOverlayMessage
 * {
 *  	int seqNo;	
 *  	int length; 
 *  	int redundant; 
 * }
 * </pre>
 */
class EncapVideoMessage : public ::BaseOverlayMessage
{
  protected:
    int seqNo_var;
    int length_var;
    int redundant_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EncapVideoMessage&);

  public:
    EncapVideoMessage(const char *name=NULL, int kind=0);
    EncapVideoMessage(const EncapVideoMessage& other);
    virtual ~EncapVideoMessage();
    EncapVideoMessage& operator=(const EncapVideoMessage& other);
    virtual EncapVideoMessage *dup() const {return new EncapVideoMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSeqNo() const;
    virtual void setSeqNo(int seqNo_var);
    virtual int getLength() const;
    virtual void setLength(int length_var);
    virtual int getRedundant() const;
    virtual void setRedundant(int redundant_var);
};

inline void doPacking(cCommBuffer *b, EncapVideoMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, EncapVideoMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/denacastoverlay/DenaCastOverlayMessage.msg</tt> by opp_msgc.
 * <pre>
 * message ErrorRecoveryMessage extends BaseOverlayMessage
 * {
 * 	int seqNo;	
 * 	int chunkNo; 
 * 	int length; 
 * 	int packetLength; 
 * 	TransportAddress srcNode; 
 * }
 * </pre>
 */
class ErrorRecoveryMessage : public ::BaseOverlayMessage
{
  protected:
    int seqNo_var;
    int chunkNo_var;
    int length_var;
    int packetLength_var;
    ::TransportAddress srcNode_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ErrorRecoveryMessage&);

  public:
    ErrorRecoveryMessage(const char *name=NULL, int kind=0);
    ErrorRecoveryMessage(const ErrorRecoveryMessage& other);
    virtual ~ErrorRecoveryMessage();
    ErrorRecoveryMessage& operator=(const ErrorRecoveryMessage& other);
    virtual ErrorRecoveryMessage *dup() const {return new ErrorRecoveryMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSeqNo() const;
    virtual void setSeqNo(int seqNo_var);
    virtual int getChunkNo() const;
    virtual void setChunkNo(int chunkNo_var);
    virtual int getLength() const;
    virtual void setLength(int length_var);
    virtual int getPacketLength() const;
    virtual void setPacketLength(int packetLength_var);
    virtual TransportAddress& getSrcNode();
    virtual const TransportAddress& getSrcNode() const {return const_cast<ErrorRecoveryMessage*>(this)->getSrcNode();}
    virtual void setSrcNode(const TransportAddress& srcNode_var);
};

inline void doPacking(cCommBuffer *b, ErrorRecoveryMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ErrorRecoveryMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/denacastoverlay/DenaCastOverlayMessage.msg</tt> by opp_msgc.
 * <pre>
 * message EncapBufferMap extends BaseOverlayMessage
 * {
 * }
 * </pre>
 */
class EncapBufferMap : public ::BaseOverlayMessage
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EncapBufferMap&);

  public:
    EncapBufferMap(const char *name=NULL, int kind=0);
    EncapBufferMap(const EncapBufferMap& other);
    virtual ~EncapBufferMap();
    EncapBufferMap& operator=(const EncapBufferMap& other);
    virtual EncapBufferMap *dup() const {return new EncapBufferMap(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, EncapBufferMap& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, EncapBufferMap& obj) {obj.parsimUnpack(b);}


#endif // _DENACASTOVERLAYMESSAGE_M_H_
