//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/denacastoverlay/DenaCastOverlayMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DenaCastOverlayMessage_m.h"

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




Register_Class(EncapVideoMessage);

EncapVideoMessage::EncapVideoMessage(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
    this->seqNo_var = 0;
    this->length_var = 0;
    this->redundant_var = 0;
}

EncapVideoMessage::EncapVideoMessage(const EncapVideoMessage& other) : BaseOverlayMessage()
{
    setName(other.getName());
    operator=(other);
}

EncapVideoMessage::~EncapVideoMessage()
{
}

EncapVideoMessage& EncapVideoMessage::operator=(const EncapVideoMessage& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    this->seqNo_var = other.seqNo_var;
    this->length_var = other.length_var;
    this->redundant_var = other.redundant_var;
    return *this;
}

void EncapVideoMessage::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
    doPacking(b,this->seqNo_var);
    doPacking(b,this->length_var);
    doPacking(b,this->redundant_var);
}

void EncapVideoMessage::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
    doUnpacking(b,this->seqNo_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->redundant_var);
}

int EncapVideoMessage::getSeqNo() const
{
    return seqNo_var;
}

void EncapVideoMessage::setSeqNo(int seqNo_var)
{
    this->seqNo_var = seqNo_var;
}

int EncapVideoMessage::getLength() const
{
    return length_var;
}

void EncapVideoMessage::setLength(int length_var)
{
    this->length_var = length_var;
}

int EncapVideoMessage::getRedundant() const
{
    return redundant_var;
}

void EncapVideoMessage::setRedundant(int redundant_var)
{
    this->redundant_var = redundant_var;
}

class EncapVideoMessageDescriptor : public cClassDescriptor
{
  public:
    EncapVideoMessageDescriptor();
    virtual ~EncapVideoMessageDescriptor();

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

Register_ClassDescriptor(EncapVideoMessageDescriptor);

EncapVideoMessageDescriptor::EncapVideoMessageDescriptor() : cClassDescriptor("EncapVideoMessage", "BaseOverlayMessage")
{
}

EncapVideoMessageDescriptor::~EncapVideoMessageDescriptor()
{
}

bool EncapVideoMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EncapVideoMessage *>(obj)!=NULL;
}

const char *EncapVideoMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EncapVideoMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int EncapVideoMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *EncapVideoMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "seqNo",
        "length",
        "redundant",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int EncapVideoMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNo")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "redundant")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EncapVideoMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *EncapVideoMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EncapVideoMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EncapVideoMessage *pp = (EncapVideoMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EncapVideoMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EncapVideoMessage *pp = (EncapVideoMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSeqNo());
        case 1: return long2string(pp->getLength());
        case 2: return long2string(pp->getRedundant());
        default: return "";
    }
}

bool EncapVideoMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EncapVideoMessage *pp = (EncapVideoMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSeqNo(string2long(value)); return true;
        case 1: pp->setLength(string2long(value)); return true;
        case 2: pp->setRedundant(string2long(value)); return true;
        default: return false;
    }
}

const char *EncapVideoMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *EncapVideoMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EncapVideoMessage *pp = (EncapVideoMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ErrorRecoveryMessage);

ErrorRecoveryMessage::ErrorRecoveryMessage(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
    this->seqNo_var = 0;
    this->chunkNo_var = 0;
    this->length_var = 0;
    this->packetLength_var = 0;
}

ErrorRecoveryMessage::ErrorRecoveryMessage(const ErrorRecoveryMessage& other) : BaseOverlayMessage()
{
    setName(other.getName());
    operator=(other);
}

ErrorRecoveryMessage::~ErrorRecoveryMessage()
{
}

ErrorRecoveryMessage& ErrorRecoveryMessage::operator=(const ErrorRecoveryMessage& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    this->seqNo_var = other.seqNo_var;
    this->chunkNo_var = other.chunkNo_var;
    this->length_var = other.length_var;
    this->packetLength_var = other.packetLength_var;
    this->srcNode_var = other.srcNode_var;
    return *this;
}

void ErrorRecoveryMessage::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
    doPacking(b,this->seqNo_var);
    doPacking(b,this->chunkNo_var);
    doPacking(b,this->length_var);
    doPacking(b,this->packetLength_var);
    doPacking(b,this->srcNode_var);
}

void ErrorRecoveryMessage::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
    doUnpacking(b,this->seqNo_var);
    doUnpacking(b,this->chunkNo_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->packetLength_var);
    doUnpacking(b,this->srcNode_var);
}

int ErrorRecoveryMessage::getSeqNo() const
{
    return seqNo_var;
}

void ErrorRecoveryMessage::setSeqNo(int seqNo_var)
{
    this->seqNo_var = seqNo_var;
}

int ErrorRecoveryMessage::getChunkNo() const
{
    return chunkNo_var;
}

void ErrorRecoveryMessage::setChunkNo(int chunkNo_var)
{
    this->chunkNo_var = chunkNo_var;
}

int ErrorRecoveryMessage::getLength() const
{
    return length_var;
}

void ErrorRecoveryMessage::setLength(int length_var)
{
    this->length_var = length_var;
}

int ErrorRecoveryMessage::getPacketLength() const
{
    return packetLength_var;
}

void ErrorRecoveryMessage::setPacketLength(int packetLength_var)
{
    this->packetLength_var = packetLength_var;
}

TransportAddress& ErrorRecoveryMessage::getSrcNode()
{
    return srcNode_var;
}

void ErrorRecoveryMessage::setSrcNode(const TransportAddress& srcNode_var)
{
    this->srcNode_var = srcNode_var;
}

class ErrorRecoveryMessageDescriptor : public cClassDescriptor
{
  public:
    ErrorRecoveryMessageDescriptor();
    virtual ~ErrorRecoveryMessageDescriptor();

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

Register_ClassDescriptor(ErrorRecoveryMessageDescriptor);

ErrorRecoveryMessageDescriptor::ErrorRecoveryMessageDescriptor() : cClassDescriptor("ErrorRecoveryMessage", "BaseOverlayMessage")
{
}

ErrorRecoveryMessageDescriptor::~ErrorRecoveryMessageDescriptor()
{
}

bool ErrorRecoveryMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ErrorRecoveryMessage *>(obj)!=NULL;
}

const char *ErrorRecoveryMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ErrorRecoveryMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int ErrorRecoveryMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ErrorRecoveryMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "seqNo",
        "chunkNo",
        "length",
        "packetLength",
        "srcNode",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int ErrorRecoveryMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNo")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkNo")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetLength")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNode")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ErrorRecoveryMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "TransportAddress",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *ErrorRecoveryMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ErrorRecoveryMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ErrorRecoveryMessage *pp = (ErrorRecoveryMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ErrorRecoveryMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ErrorRecoveryMessage *pp = (ErrorRecoveryMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSeqNo());
        case 1: return long2string(pp->getChunkNo());
        case 2: return long2string(pp->getLength());
        case 3: return long2string(pp->getPacketLength());
        case 4: {std::stringstream out; out << pp->getSrcNode(); return out.str();}
        default: return "";
    }
}

bool ErrorRecoveryMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ErrorRecoveryMessage *pp = (ErrorRecoveryMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSeqNo(string2long(value)); return true;
        case 1: pp->setChunkNo(string2long(value)); return true;
        case 2: pp->setLength(string2long(value)); return true;
        case 3: pp->setPacketLength(string2long(value)); return true;
        default: return false;
    }
}

const char *ErrorRecoveryMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        "TransportAddress",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *ErrorRecoveryMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ErrorRecoveryMessage *pp = (ErrorRecoveryMessage *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getSrcNode()); break;
        default: return NULL;
    }
}

Register_Class(EncapBufferMap);

EncapBufferMap::EncapBufferMap(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
}

EncapBufferMap::EncapBufferMap(const EncapBufferMap& other) : BaseOverlayMessage()
{
    setName(other.getName());
    operator=(other);
}

EncapBufferMap::~EncapBufferMap()
{
}

EncapBufferMap& EncapBufferMap::operator=(const EncapBufferMap& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    return *this;
}

void EncapBufferMap::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
}

void EncapBufferMap::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
}

class EncapBufferMapDescriptor : public cClassDescriptor
{
  public:
    EncapBufferMapDescriptor();
    virtual ~EncapBufferMapDescriptor();

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

Register_ClassDescriptor(EncapBufferMapDescriptor);

EncapBufferMapDescriptor::EncapBufferMapDescriptor() : cClassDescriptor("EncapBufferMap", "BaseOverlayMessage")
{
}

EncapBufferMapDescriptor::~EncapBufferMapDescriptor()
{
}

bool EncapBufferMapDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EncapBufferMap *>(obj)!=NULL;
}

const char *EncapBufferMapDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EncapBufferMapDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int EncapBufferMapDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *EncapBufferMapDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int EncapBufferMapDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EncapBufferMapDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *EncapBufferMapDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EncapBufferMapDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EncapBufferMap *pp = (EncapBufferMap *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EncapBufferMapDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EncapBufferMap *pp = (EncapBufferMap *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool EncapBufferMapDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EncapBufferMap *pp = (EncapBufferMap *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *EncapBufferMapDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *EncapBufferMapDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EncapBufferMap *pp = (EncapBufferMap *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


