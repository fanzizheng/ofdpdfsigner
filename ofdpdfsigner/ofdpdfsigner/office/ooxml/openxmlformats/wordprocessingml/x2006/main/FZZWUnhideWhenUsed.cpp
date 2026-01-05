//
//  Created by zizheng fan on 2023/10/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUnhideWhenUsed.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWUnhideWhenUsed**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed::FZZWUnhideWhenUsed() : FZZXMLElementObject()
{
    //DLOG("FZZWUnhideWhenUsed()");
    FZZConst::addClassCount("FZZWUnhideWhenUsed");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed::FZZWUnhideWhenUsed(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWUnhideWhenUsed");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed::FZZWUnhideWhenUsed(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWUnhideWhenUsed");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed::FZZWUnhideWhenUsed(const FZZWUnhideWhenUsed& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWUnhideWhenUsed");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed::~FZZWUnhideWhenUsed()
{
    //DLOG("~FZZWUnhideWhenUsed()");
    FZZConst::delClassCount("FZZWUnhideWhenUsed");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWUnhideWhenUsed::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWUnhideWhenUsed::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
