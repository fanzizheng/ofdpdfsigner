//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPathObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPathObject::FZZOFDPathObject() : FZZOFDPath()
{
    //DLOG("FZZOFDPathObject()");
    FZZConst::addClassCount("FZZOFDPathObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPathObject::FZZOFDPathObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDPath(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDPathObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPathObject::FZZOFDPathObject(FZZOFDXMLFileObject * parent) : FZZOFDPath(parent)
{
    FZZConst::addClassCount("FZZOFDPathObject");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPathObject::FZZOFDPathObject(const FZZOFDPathObject& obj) : FZZOFDPath(obj)
{
    
    FZZConst::addClassCount("FZZOFDPathObject");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPathObject::~FZZOFDPathObject()
{
    //DLOG("~FZZOFDPathObject()");
    FZZConst::delClassCount("FZZOFDPathObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPathObject::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPathObject::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPathObject::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDPathObject::getID_long()
{
    return getAttribute_long("ID");
    
}
//-----------------------------------------------------------------------------------------------------------------
