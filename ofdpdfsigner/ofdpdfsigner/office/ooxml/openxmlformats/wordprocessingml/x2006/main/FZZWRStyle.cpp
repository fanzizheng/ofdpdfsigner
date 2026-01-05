//
//  Created by zizheng fan on 2023/11/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle::FZZWRStyle() : FZZXMLElementObject()
{
    //DLOG("FZZWRStyle()");
    FZZConst::addClassCount("FZZWRStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle::FZZWRStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle::FZZWRStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWRStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle::FZZWRStyle(const FZZWRStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRStyle");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle::~FZZWRStyle()
{
    //DLOG("~FZZWRStyle()");
    FZZConst::delClassCount("FZZWRStyle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRStyle::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRStyle::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
