//
//  Created by zizheng fan on 2023/11/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTl2br.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTl2br**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br::FZZWTl2br() : FZZXMLElementObject()
{
    //DLOG("FZZWTl2br()");
    FZZConst::addClassCount("FZZWTl2br");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br::FZZWTl2br(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTl2br");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br::FZZWTl2br(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTl2br");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br::FZZWTl2br(const FZZWTl2br& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTl2br");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br::~FZZWTl2br()
{
    //DLOG("~FZZWTl2br()");
    FZZConst::delClassCount("FZZWTl2br");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setSz(string value)
{
    setAttribute_String("w:sz",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getSz()
{
    return getAttribute_String("w:sz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTl2br::setColor(string value)
{
    setAttribute_String("w:color",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTl2br::getColor()
{
    return getAttribute_String("w:color");
}
//-----------------------------------------------------------------------------------------------------------------
