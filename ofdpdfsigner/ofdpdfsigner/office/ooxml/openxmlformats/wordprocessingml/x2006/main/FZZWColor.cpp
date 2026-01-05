//
//  Created by zizheng fan on 2023/10/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWColor.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWColor**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWColor::FZZWColor() : FZZXMLElementObject()
{
    //DLOG("FZZWColor()");
    FZZConst::addClassCount("FZZWColor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor::FZZWColor(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWColor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor::FZZWColor(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWColor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor::FZZWColor(const FZZWColor& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWColor");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor::~FZZWColor()
{
    //DLOG("~FZZWColor()");
    FZZConst::delClassCount("FZZWColor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWColor::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWColor::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

