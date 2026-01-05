//
//  Created by zizheng fan on 2023/11/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle::FZZWPStyle() : FZZXMLElementObject()
{
    //DLOG("FZZWPStyle()");
    FZZConst::addClassCount("FZZWPStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle::FZZWPStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle::FZZWPStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle::FZZWPStyle(const FZZWPStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPStyle");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle::~FZZWPStyle()
{
    //DLOG("~FZZWPStyle()");
    FZZConst::delClassCount("FZZWPStyle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPStyle::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPStyle::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
