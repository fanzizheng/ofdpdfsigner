//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDImageObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImageObject::FZZOFDImageObject() : FZZOFDImage()
{
    //DLOG("FZZOFDImageObject()");
    FZZConst::addClassCount("FZZOFDImageObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImageObject::FZZOFDImageObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDImage(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDImageObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImageObject::FZZOFDImageObject(FZZOFDXMLFileObject * parent) : FZZOFDImage(parent)
{
    FZZConst::addClassCount("FZZOFDImageObject");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImageObject::FZZOFDImageObject(const FZZOFDImageObject& obj) : FZZOFDImage(obj)
{
    
    FZZConst::addClassCount("FZZOFDImageObject");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImageObject::~FZZOFDImageObject()
{
    //DLOG("~FZZOFDImageObject()");
    FZZConst::delClassCount("FZZOFDImageObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImageObject::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDImageObject::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImageObject::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDImageObject::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
