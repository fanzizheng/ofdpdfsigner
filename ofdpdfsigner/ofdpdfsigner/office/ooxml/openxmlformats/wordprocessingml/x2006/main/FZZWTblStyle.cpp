//
//  Created by zizheng fan on 2023/11/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle::FZZWTblStyle() : FZZXMLElementObject()
{
    //DLOG("FZZWTblStyle()");
    FZZConst::addClassCount("FZZWTblStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle::FZZWTblStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle::FZZWTblStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle::FZZWTblStyle(const FZZWTblStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblStyle");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle::~FZZWTblStyle()
{
    //DLOG("~FZZWTblStyle()");
    FZZConst::delClassCount("FZZWTblStyle");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblStyle::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblStyle::getVal()
{
    return getAttribute_String("w:val");
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
