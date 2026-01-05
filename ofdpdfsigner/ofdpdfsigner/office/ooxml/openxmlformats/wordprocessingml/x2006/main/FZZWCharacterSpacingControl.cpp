//
//  Created by zizheng fan on 2023/09/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharacterSpacingControl.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCharacterSpacingControl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl::FZZWCharacterSpacingControl() : FZZXMLElementObject()
{
    //DLOG("FZZWCharacterSpacingControl()");
    FZZConst::addClassCount("FZZWCharacterSpacingControl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl::FZZWCharacterSpacingControl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCharacterSpacingControl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl::FZZWCharacterSpacingControl(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWCharacterSpacingControl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl::FZZWCharacterSpacingControl(const FZZWCharacterSpacingControl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCharacterSpacingControl");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCharacterSpacingControl::~FZZWCharacterSpacingControl()
{
    //DLOG("~FZZWCharacterSpacingControl()");
    FZZConst::delClassCount("FZZWCharacterSpacingControl");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCharacterSpacingControl::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCharacterSpacingControl::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
