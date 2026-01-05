//
//  Created by zizheng fan on 2023/10/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTop**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTop::FZZWTop() : FZZXMLElementObject()
{
    //DLOG("FZZWTop()");
    FZZConst::addClassCount("FZZWTop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop::FZZWTop(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop::FZZWTop(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTop");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop::FZZWTop(const FZZWTop& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTop");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop::~FZZWTop()
{
    //DLOG("~FZZWTop()");
    FZZConst::delClassCount("FZZWTop");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setSz(string value)
{
    setAttribute_String("w:sz",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getSz()
{
    return getAttribute_String("w:sz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTop::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTop::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
