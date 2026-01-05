//
//  Created by zizheng fan on 2023/10/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUiPriority.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWUiPriority**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority::FZZWUiPriority() : FZZXMLElementObject()
{
    //DLOG("FZZWUiPriority()");
    FZZConst::addClassCount("FZZWUiPriority");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority::FZZWUiPriority(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWUiPriority");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority::FZZWUiPriority(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWUiPriority");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority::FZZWUiPriority(const FZZWUiPriority& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWUiPriority");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority::~FZZWUiPriority()
{
    //DLOG("~FZZWUiPriority()");
    FZZConst::delClassCount("FZZWUiPriority");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWUiPriority::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWUiPriority::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
