//
//  Created by zizheng fan on 2023/11/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWMultiLevelType.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWMultiLevelType**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType::FZZWMultiLevelType() : FZZXMLElementObject()
{
    //DLOG("FZZWMultiLevelType()");
    FZZConst::addClassCount("FZZWMultiLevelType");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType::FZZWMultiLevelType(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWMultiLevelType");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType::FZZWMultiLevelType(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWMultiLevelType");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType::FZZWMultiLevelType(const FZZWMultiLevelType& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWMultiLevelType");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType::~FZZWMultiLevelType()
{
    //DLOG("~FZZWMultiLevelType()");
    FZZConst::delClassCount("FZZWMultiLevelType");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWMultiLevelType::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWMultiLevelType::getVal()
{
    string retstr = getAttribute_String("w:val");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWW::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWW::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
