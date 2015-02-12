//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/denacastapp/VideoMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "VideoMessage_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("VideoCommand");
    if (!e) enums.getInstance()->add(e = new cEnum("VideoCommand"));
    e->insert(CAMERA_MSG, "CAMERA_MSG");
    e->insert(PLAYER_MSG, "PLAYER_MSG");
    e->insert(CHUNK_REQ, "CHUNK_REQ");
    e->insert(CHUNK_RSP, "CHUNK_RSP");
    e->insert(NEIGHBOR_LEAVE, "NEIGHBOR_LEAVE");
    e->insert(LEAVING, "LEAVING");
);

Register_Class(VideoMessage);

VideoMessage::VideoMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->command_var = 0;
    this->deadLine_var = 0;
}

VideoMessage::VideoMessage(const VideoMessage& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

VideoMessage::~VideoMessage()
{
}

VideoMessage& VideoMessage::operator=(const VideoMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->command_var = other.command_var;
    this->dstNode_var = other.dstNode_var;
    this->srcNode_var = other.srcNode_var;
    this->deadLine_var = other.deadLine_var;
    this->chunk_var = other.chunk_var;
    this->VFrame_var = other.VFrame_var;
    return *this;
}

void VideoMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->command_var);
    doPacking(b,this->dstNode_var);
    doPacking(b,this->srcNode_var);
    doPacking(b,this->deadLine_var);
    doPacking(b,this->chunk_var);
    doPacking(b,this->VFrame_var);
}

void VideoMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->command_var);
    doUnpacking(b,this->dstNode_var);
    doUnpacking(b,this->srcNode_var);
    doUnpacking(b,this->deadLine_var);
    doUnpacking(b,this->chunk_var);
    doUnpacking(b,this->VFrame_var);
}

int VideoMessage::getCommand() const
{
    return command_var;
}

void VideoMessage::setCommand(int command_var)
{
    this->command_var = command_var;
}

TransportAddress& VideoMessage::getDstNode()
{
    return dstNode_var;
}

void VideoMessage::setDstNode(const TransportAddress& dstNode_var)
{
    this->dstNode_var = dstNode_var;
}

TransportAddress& VideoMessage::getSrcNode()
{
    return srcNode_var;
}

void VideoMessage::setSrcNode(const TransportAddress& srcNode_var)
{
    this->srcNode_var = srcNode_var;
}

double VideoMessage::getDeadLine() const
{
    return deadLine_var;
}

void VideoMessage::setDeadLine(double deadLine_var)
{
    this->deadLine_var = deadLine_var;
}

Chunk& VideoMessage::getChunk()
{
    return chunk_var;
}

void VideoMessage::setChunk(const Chunk& chunk_var)
{
    this->chunk_var = chunk_var;
}

VideoFrame& VideoMessage::getVFrame()
{
    return VFrame_var;
}

void VideoMessage::setVFrame(const VideoFrame& VFrame_var)
{
    this->VFrame_var = VFrame_var;
}

class VideoMessageDescriptor : public cClassDescriptor
{
  public:
    VideoMessageDescriptor();
    virtual ~VideoMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(VideoMessageDescriptor);

VideoMessageDescriptor::VideoMessageDescriptor() : cClassDescriptor("VideoMessage", "cPacket")
{
}

VideoMessageDescriptor::~VideoMessageDescriptor()
{
}

bool VideoMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<VideoMessage *>(obj)!=NULL;
}

const char *VideoMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int VideoMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int VideoMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *VideoMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "command",
        "dstNode",
        "srcNode",
        "deadLine",
        "chunk",
        "VFrame",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int VideoMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstNode")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNode")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "deadLine")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunk")==0) return base+4;
    if (fieldName[0]=='V' && strcmp(fieldName, "VFrame")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *VideoMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "TransportAddress",
        "TransportAddress",
        "double",
        "Chunk",
        "VideoFrame",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *VideoMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "VideoCommand";
            return NULL;
        default: return NULL;
    }
}

int VideoMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string VideoMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCommand());
        case 1: {std::stringstream out; out << pp->getDstNode(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSrcNode(); return out.str();}
        case 3: return double2string(pp->getDeadLine());
        case 4: {std::stringstream out; out << pp->getChunk(); return out.str();}
        case 5: {std::stringstream out; out << pp->getVFrame(); return out.str();}
        default: return "";
    }
}

bool VideoMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand(string2long(value)); return true;
        case 3: pp->setDeadLine(string2double(value)); return true;
        default: return false;
    }
}

const char *VideoMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "TransportAddress",
        "TransportAddress",
        NULL,
        "Chunk",
        "VideoFrame",
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *VideoMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    VideoMessage *pp = (VideoMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getDstNode()); break;
        case 2: return (void *)(&pp->getSrcNode()); break;
        case 4: return (void *)(&pp->getChunk()); break;
        case 5: return (void *)(&pp->getVFrame()); break;
        default: return NULL;
    }
}

Register_Class(BufferMapMessage);

BufferMapMessage::BufferMapMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->totalBandwidth_var = 0;
    this->myHopCount_var = 0;
}

BufferMapMessage::BufferMapMessage(const BufferMapMessage& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

BufferMapMessage::~BufferMapMessage()
{
}

BufferMapMessage& BufferMapMessage::operator=(const BufferMapMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->srcNode_var = other.srcNode_var;
    this->totalBandwidth_var = other.totalBandwidth_var;
    this->myHopCount_var = other.myHopCount_var;
    this->buffermap_var = other.buffermap_var;
    return *this;
}

void BufferMapMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcNode_var);
    doPacking(b,this->totalBandwidth_var);
    doPacking(b,this->myHopCount_var);
    doPacking(b,this->buffermap_var);
}

void BufferMapMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcNode_var);
    doUnpacking(b,this->totalBandwidth_var);
    doUnpacking(b,this->myHopCount_var);
    doUnpacking(b,this->buffermap_var);
}

TransportAddress& BufferMapMessage::getSrcNode()
{
    return srcNode_var;
}

void BufferMapMessage::setSrcNode(const TransportAddress& srcNode_var)
{
    this->srcNode_var = srcNode_var;
}

double BufferMapMessage::getTotalBandwidth() const
{
    return totalBandwidth_var;
}

void BufferMapMessage::setTotalBandwidth(double totalBandwidth_var)
{
    this->totalBandwidth_var = totalBandwidth_var;
}

double BufferMapMessage::getMyHopCount() const
{
    return myHopCount_var;
}

void BufferMapMessage::setMyHopCount(double myHopCount_var)
{
    this->myHopCount_var = myHopCount_var;
}

BufferMap& BufferMapMessage::getBuffermap()
{
    return buffermap_var;
}

void BufferMapMessage::setBuffermap(const BufferMap& buffermap_var)
{
    this->buffermap_var = buffermap_var;
}

class BufferMapMessageDescriptor : public cClassDescriptor
{
  public:
    BufferMapMessageDescriptor();
    virtual ~BufferMapMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BufferMapMessageDescriptor);

BufferMapMessageDescriptor::BufferMapMessageDescriptor() : cClassDescriptor("BufferMapMessage", "cPacket")
{
}

BufferMapMessageDescriptor::~BufferMapMessageDescriptor()
{
}

bool BufferMapMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BufferMapMessage *>(obj)!=NULL;
}

const char *BufferMapMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BufferMapMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int BufferMapMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *BufferMapMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNode",
        "totalBandwidth",
        "myHopCount",
        "buffermap",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int BufferMapMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNode")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalBandwidth")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "myHopCount")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "buffermap")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BufferMapMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "TransportAddress",
        "double",
        "double",
        "BufferMap",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *BufferMapMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BufferMapMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BufferMapMessage *pp = (BufferMapMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BufferMapMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BufferMapMessage *pp = (BufferMapMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcNode(); return out.str();}
        case 1: return double2string(pp->getTotalBandwidth());
        case 2: return double2string(pp->getMyHopCount());
        case 3: {std::stringstream out; out << pp->getBuffermap(); return out.str();}
        default: return "";
    }
}

bool BufferMapMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BufferMapMessage *pp = (BufferMapMessage *)object; (void)pp;
    switch (field) {
        case 1: pp->setTotalBandwidth(string2double(value)); return true;
        case 2: pp->setMyHopCount(string2double(value)); return true;
        default: return false;
    }
}

const char *BufferMapMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "TransportAddress",
        NULL,
        NULL,
        "BufferMap",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *BufferMapMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BufferMapMessage *pp = (BufferMapMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcNode()); break;
        case 3: return (void *)(&pp->getBuffermap()); break;
        default: return NULL;
    }
}


