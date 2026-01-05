//
//  Created by zizheng fan on 2023/11/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideH.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWInsideH**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH::FZZWInsideH() : FZZXMLElementObject()
{
    //DLOG("FZZWInsideH()");
    FZZConst::addClassCount("FZZWInsideH");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH::FZZWInsideH(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWInsideH");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH::FZZWInsideH(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWInsideH");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH::FZZWInsideH(const FZZWInsideH& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWInsideH");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH::~FZZWInsideH()
{
    //DLOG("~FZZWInsideH()");
    FZZConst::delClassCount("FZZWInsideH");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setSz(string value)
{
    setAttribute_String("w:sz",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getSz()
{
    return getAttribute_String("w:sz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideH::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideH::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
