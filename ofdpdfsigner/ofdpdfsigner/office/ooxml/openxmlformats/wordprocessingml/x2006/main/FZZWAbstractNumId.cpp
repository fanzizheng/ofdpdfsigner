//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNumId.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAbstractNumId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId::FZZWAbstractNumId() : FZZXMLElementObject()
{
    //DLOG("FZZWAbstractNumId()");
    FZZConst::addClassCount("FZZWAbstractNumId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId::FZZWAbstractNumId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAbstractNumId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId::FZZWAbstractNumId(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWAbstractNumId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId::FZZWAbstractNumId(const FZZWAbstractNumId& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAbstractNumId");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId::~FZZWAbstractNumId()
{
    //DLOG("~FZZWAbstractNumId()");
    FZZConst::delClassCount("FZZWAbstractNumId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWAbstractNumId::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAbstractNumId::getVal()
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
