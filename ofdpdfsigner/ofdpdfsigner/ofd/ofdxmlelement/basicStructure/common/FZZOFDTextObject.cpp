//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTextObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextObject::FZZOFDTextObject() : FZZOFDText()
{
    //DLOG("FZZOFDTextObject()");
    FZZConst::addClassCount("FZZOFDTextObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextObject::FZZOFDTextObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDText(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDTextObject");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextObject::FZZOFDTextObject(FZZOFDXMLFileObject * parent) : FZZOFDText(parent)
{
    FZZConst::addClassCount("FZZOFDTextObject");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextObject::FZZOFDTextObject(const FZZOFDTextObject& obj) : FZZOFDText(obj)
{
    
    FZZConst::addClassCount("FZZOFDTextObject");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextObject::~FZZOFDTextObject()
{
    //DLOG("~FZZOFDTextObject()");
    FZZConst::delClassCount("FZZOFDTextObject");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextObject::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTextObject::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextObject::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDTextObject::getID_long()
{
    return  getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
