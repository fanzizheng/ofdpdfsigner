//
//  Created by zizheng fan on 2023/11/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWB.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWB**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWB::FZZWB() : FZZXMLElementObject()
{
    //DLOG("FZZWB()");
    FZZConst::addClassCount("FZZWB");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB::FZZWB(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWB");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB::FZZWB(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWB");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB::FZZWB(const FZZWB& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWB");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB::~FZZWB()
{
    //DLOG("~FZZWB()");
    FZZConst::delClassCount("FZZWB");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setVal(string value)
//{
//    setAttribute_String("w:val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getVal()
//{
//    return getAttribute_String("w:val");
//}
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
