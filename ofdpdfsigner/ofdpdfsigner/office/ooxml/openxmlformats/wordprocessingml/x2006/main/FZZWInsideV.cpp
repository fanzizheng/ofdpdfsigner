//
//  Created by zizheng fan on 2023/11/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideV.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWInsideV**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV::FZZWInsideV() : FZZXMLElementObject()
{
    //DLOG("FZZWInsideV()");
    FZZConst::addClassCount("FZZWInsideV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV::FZZWInsideV(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWInsideV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV::FZZWInsideV(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWInsideV");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV::FZZWInsideV(const FZZWInsideV& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWInsideV");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV::~FZZWInsideV()
{
    //DLOG("~FZZWInsideV()");
    FZZConst::delClassCount("FZZWInsideV");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setSz(string value)
{
    setAttribute_String("w:sz",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getSz()
{
    return getAttribute_String("w:sz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInsideV::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInsideV::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
