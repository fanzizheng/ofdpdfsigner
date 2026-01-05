//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrHeight.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTrHeight**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight::FZZWTrHeight() : FZZXMLElementObject()
{
    //DLOG("FZZWTrHeight()");
    FZZConst::addClassCount("FZZWTrHeight");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight::FZZWTrHeight(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTrHeight");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight::FZZWTrHeight(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTrHeight");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight::FZZWTrHeight(const FZZWTrHeight& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTrHeight");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrHeight::~FZZWTrHeight()
{
    //DLOG("~FZZWTrHeight()");
    FZZConst::delClassCount("FZZWTrHeight");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTrHeight::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTrHeight::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTrHeight::setHRule(string value)
{
    setAttribute_String("w:hRule",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTrHeight::getHRule()
{
    return getAttribute_String("w:hRule");
    
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
