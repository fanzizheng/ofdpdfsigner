//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptEntry.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncryptEntry**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry::FZZOFDEncryptEntry() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDEncryptEntry()");
    FZZConst::addClassCount("FZZOFDEncryptEntry");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry::FZZOFDEncryptEntry(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDEncryptEntry");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry::FZZOFDEncryptEntry(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDEncryptEntry");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry::FZZOFDEncryptEntry(const FZZOFDEncryptEntry& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEncryptEntry");
    if ( this == &obj ) {
        return;
    }

    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry::~FZZOFDEncryptEntry()
{
    //DLOG("~FZZOFDEncryptEntry()");
    FZZConst::delClassCount("FZZOFDEncryptEntry");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptEntry::setPath(string value)
{
    setAttribute_String("Path",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptEntry::getPath()
{
    return getAttribute_String("Path");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptEntry::setEPath(string value)
{
    setAttribute_String("EPath",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptEntry::getEPath()
{
    return getAttribute_String("EPath");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptEntry::setDecryptSeedLoc(string value)
{
    setAttribute_String("DecryptSeedLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptEntry::getDecryptSeedLoc()
{
    return getAttribute_String("DecryptSeedLoc");
}
//-----------------------------------------------------------------------------------------------------------------
