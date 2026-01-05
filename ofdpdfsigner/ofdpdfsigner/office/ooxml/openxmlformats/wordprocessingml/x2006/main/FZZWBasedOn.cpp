//
//  Created by zizheng fan on 2023/11/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBasedOn.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBasedOn**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn::FZZWBasedOn() : FZZXMLElementObject()
{
    //DLOG("FZZWBasedOn()");
    FZZConst::addClassCount("FZZWBasedOn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn::FZZWBasedOn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBasedOn");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn::FZZWBasedOn(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBasedOn");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn::FZZWBasedOn(const FZZWBasedOn& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBasedOn");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn::~FZZWBasedOn()
{
    //DLOG("~FZZWBasedOn()");
    FZZConst::delClassCount("FZZWBasedOn");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWBasedOn::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWBasedOn::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
