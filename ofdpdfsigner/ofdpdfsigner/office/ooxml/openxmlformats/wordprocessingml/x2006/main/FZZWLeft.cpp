//
//  Created by zizheng fan on 2023/10/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLeft**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft::FZZWLeft() : FZZXMLElementObject()
{
    //DLOG("FZZWLeft()");
    FZZConst::addClassCount("FZZWLeft");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft::FZZWLeft(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLeft");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft::FZZWLeft(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLeft");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft::FZZWLeft(const FZZWLeft& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLeft");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft::~FZZWLeft()
{
    //DLOG("~FZZWLeft()");
    FZZConst::delClassCount("FZZWLeft");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setSz(string value)
{
    setAttribute_String("w:sz",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getSz()
{
    return getAttribute_String("w:sz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLeft::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLeft::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
