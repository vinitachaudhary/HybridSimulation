//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/denacastoverlay/DenaCastTrackerMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DenaCastTrackerMessage_m.h"

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
    cEnum *e = cEnum::find("TRACKERCommand");
    if (!e) enums.getInstance()->add(e = new cEnum("TRACKERCommand"));
    e->insert(NEIGHBOR_REQUEST, "NEIGHBOR_REQUEST");
    e->insert(NEIGHBOR_RESPONSE, "NEIGHBOR_RESPONSE");
    e->insert(SELF_REGISTER, "SELF_REGISTER");
    e->insert(SELF_UNREGISTER, "SELF_UNREGISTER");
    e->insert(REMAIN_NEIGHBOR, "REMAIN_NEIGHBOR");
);

Register_Class(DenaCastTrackerMessage);

DenaCastTrackerMessage::DenaCastTrackerMessage(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
    this->command_var = 0;
    neighbors_arraysize = 0;
    this->neighbors_var = 0;
    this->neighborSize_var = 0;
    this->isServer_var = 0;
    this->remainNeighbor_var = 0;
}

DenaCastTrackerMessage::DenaCastTrackerMessage(const DenaCastTrackerMessage& other) : BaseOverlayMessage()
{
    setName(other.getName());
    neighbors_arraysize = 0;
    this->neighbors_var = 0;
    operator=(other);
}

DenaCastTrackerMessage::~DenaCastTrackerMessage()
{
    delete [] neighbors_var;
}

DenaCastTrackerMessage& DenaCastTrackerMessage::operator=(const DenaCastTrackerMessage& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    this->command_var = other.command_var;
    this->srcNode_var = other.srcNode_var;
    delete [] this->neighbors_var;
    this->neighbors_var = (other.neighbors_arraysize==0) ? NULL : new ::TransportAddress[other.neighbors_arraysize];
    neighbors_arraysize = other.neighbors_arraysize;
    for (unsigned int i=0; i<neighbors_arraysize; i++)
        this->neighbors_var[i] = other.neighbors_var[i];
    this->neighborSize_var = other.neighborSize_var;
    this->isServer_var = other.isServer_var;
    this->remainNeighbor_var = other.remainNeighbor_var;
    return *this;
}

void DenaCastTrackerMessage::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
    doPacking(b,this->command_var);
    doPacking(b,this->srcNode_var);
    b->pack(neighbors_arraysize);
    doPacking(b,this->neighbors_var,neighbors_arraysize);
    doPacking(b,this->neighborSize_var);
    doPacking(b,this->isServer_var);
    doPacking(b,this->remainNeighbor_var);
}

void DenaCastTrackerMessage::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
    doUnpacking(b,this->command_var);
    doUnpacking(b,this->srcNode_var);
    delete [] this->neighbors_var;
    b->unpack(neighbors_arraysize);
    if (neighbors_arraysize==0) {
        this->neighbors_var = 0;
    } else {
        this->neighbors_var = new ::TransportAddress[neighbors_arraysize];
        doUnpacking(b,this->neighbors_var,neighbors_arraysize);
    }
    doUnpacking(b,this->neighborSize_var);
    doUnpacking(b,this->isServer_var);
    doUnpacking(b,this->remainNeighbor_var);
}

int DenaCastTrackerMessage::getCommand() const
{
    return command_var;
}

void DenaCastTrackerMessage::setCommand(int command_var)
{
    this->command_var = command_var;
}

TransportAddress& DenaCastTrackerMessage::getSrcNode()
{
    return srcNode_var;
}

void DenaCastTrackerMessage::setSrcNode(const TransportAddress& srcNode_var)
{
    this->srcNode_var = srcNode_var;
}

void DenaCastTrackerMessage::setNeighborsArraySize(unsigned int size)
{
    ::TransportAddress *neighbors_var2 = (size==0) ? NULL : new ::TransportAddress[size];
    unsigned int sz = neighbors_arraysize < size ? neighbors_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighbors_var2[i] = this->neighbors_var[i];
    neighbors_arraysize = size;
    delete [] this->neighbors_var;
    this->neighbors_var = neighbors_var2;
}

unsigned int DenaCastTrackerMessage::getNeighborsArraySize() const
{
    return neighbors_arraysize;
}

TransportAddress& DenaCastTrackerMessage::getNeighbors(unsigned int k)
{
    if (k>=neighbors_arraysize) throw cRuntimeError("Array of size %d indexed by %d", neighbors_arraysize, k);
    return neighbors_var[k];
}

void DenaCastTrackerMessage::setNeighbors(unsigned int k, const TransportAddress& neighbors_var)
{
    if (k>=neighbors_arraysize) throw cRuntimeError("Array of size %d indexed by %d", neighbors_arraysize, k);
    this->neighbors_var[k]=neighbors_var;
}

int DenaCastTrackerMessage::getNeighborSize() const
{
    return neighborSize_var;
}

void DenaCastTrackerMessage::setNeighborSize(int neighborSize_var)
{
    this->neighborSize_var = neighborSize_var;
}

bool DenaCastTrackerMessage::getIsServer() const
{
    return isServer_var;
}

void DenaCastTrackerMessage::setIsServer(bool isServer_var)
{
    this->isServer_var = isServer_var;
}

int DenaCastTrackerMessage::getRemainNeighbor() const
{
    return remainNeighbor_var;
}

void DenaCastTrackerMessage::setRemainNeighbor(int remainNeighbor_var)
{
    this->remainNeighbor_var = remainNeighbor_var;
}

class DenaCastTrackerMessageDescriptor : public cClassDescriptor
{
  public:
    DenaCastTrackerMessageDescriptor();
    virtual ~DenaCastTrackerMessageDescriptor();

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

Register_ClassDescriptor(DenaCastTrackerMessageDescriptor);

DenaCastTrackerMessageDescriptor::DenaCastTrackerMessageDescriptor() : cClassDescriptor("DenaCastTrackerMessage", "BaseOverlayMessage")
{
}

DenaCastTrackerMessageDescriptor::~DenaCastTrackerMessageDescriptor()
{
}

bool DenaCastTrackerMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DenaCastTrackerMessage *>(obj)!=NULL;
}

const char *DenaCastTrackerMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DenaCastTrackerMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int DenaCastTrackerMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *DenaCastTrackerMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "command",
        "srcNode",
        "neighbors",
        "neighborSize",
        "isServer",
        "remainNeighbor",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int DenaCastTrackerMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNode")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbors")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborSize")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isServer")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "remainNeighbor")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DenaCastTrackerMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "bool",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *DenaCastTrackerMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "TRACKERCommand";
            return NULL;
        default: return NULL;
    }
}

int DenaCastTrackerMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DenaCastTrackerMessage *pp = (DenaCastTrackerMessage *)object; (void)pp;
    switch (field) {
        case 2: return pp->getNeighborsArraySize();
        default: return 0;
    }
}

std::string DenaCastTrackerMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DenaCastTrackerMessage *pp = (DenaCastTrackerMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCommand());
        case 1: {std::stringstream out; out << pp->getSrcNode(); return out.str();}
        case 2: {std::stringstream out; out << pp->getNeighbors(i); return out.str();}
        case 3: return long2string(pp->getNeighborSize());
        case 4: return bool2string(pp->getIsServer());
        case 5: return long2string(pp->getRemainNeighbor());
        default: return "";
    }
}

bool DenaCastTrackerMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DenaCastTrackerMessage *pp = (DenaCastTrackerMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand(string2long(value)); return true;
        case 3: pp->setNeighborSize(string2long(value)); return true;
        case 4: pp->setIsServer(string2bool(value)); return true;
        case 5: pp->setRemainNeighbor(string2long(value)); return true;
        default: return false;
    }
}

const char *DenaCastTrackerMessageDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *DenaCastTrackerMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DenaCastTrackerMessage *pp = (DenaCastTrackerMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSrcNode()); break;
        case 2: return (void *)(&pp->getNeighbors(i)); break;
        default: return NULL;
    }
}


