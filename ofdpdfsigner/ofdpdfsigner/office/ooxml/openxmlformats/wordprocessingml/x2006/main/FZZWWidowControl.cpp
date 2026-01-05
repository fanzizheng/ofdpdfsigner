//
//  Created by zizheng fan on 2023/11/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWWidowControl.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWWidowControl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl::FZZWWidowControl() : FZZXMLElementObject()
{
    //DLOG("FZZWWidowControl()");
    FZZConst::addClassCount("FZZWWidowControl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl::FZZWWidowControl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWWidowControl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl::FZZWWidowControl(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWWidowControl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl::FZZWWidowControl(const FZZWWidowControl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWWidowControl");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl::~FZZWWidowControl()
{
    //DLOG("~FZZWWidowControl()");
    FZZConst::delClassCount("FZZWWidowControl");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWWidowControl::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWWidowControl::getVal()
{
    string retstr = getAttribute_String("w:val");
    if ( retstr.empty() ) {
        retstr = "0";
    }
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
