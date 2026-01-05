//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCompositeObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeObject::FZZOFDCompositeObject() : FZZOFDPath()
{
    //DLOG("FZZOFDCompositeObject()");
    FZZConst::addClassCount("FZZOFDCompositeObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeObject::FZZOFDCompositeObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDPath(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDCompositeObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeObject::FZZOFDCompositeObject(FZZOFDXMLFileObject * parent) : FZZOFDPath(parent)
{
    FZZConst::addClassCount("FZZOFDCompositeObject");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeObject::FZZOFDCompositeObject(const FZZOFDCompositeObject& obj) : FZZOFDPath(obj)
{
    
    FZZConst::addClassCount("FZZOFDCompositeObject");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeObject::~FZZOFDCompositeObject()
{
    //DLOG("~FZZOFDCompositeObject()");
    FZZConst::delClassCount("FZZOFDCompositeObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCompositeObject::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCompositeObject::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCompositeObject::setResourceID(string value)
{
    setAttribute_String("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCompositeObject::getResourceID()
{
    return getAttribute_String("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCompositeObject::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDCompositeObject::getID_long()
{
    return getAttribute_long("ID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCompositeObject::setResourceID(long value)
{
    
    setAttribute_long("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDCompositeObject::getResourceID_long()
{
    return getAttribute_long("ResourceID");
    
}
//-----------------------------------------------------------------------------------------------------------------
