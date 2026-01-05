//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumId.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNumId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId::FZZWNumId() : FZZXMLElementObject()
{
    //DLOG("FZZWNumId()");
    FZZConst::addClassCount("FZZWNumId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId::FZZWNumId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNumId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId::FZZWNumId(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWNumId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId::FZZWNumId(const FZZWNumId& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNumId");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId::~FZZWNumId()
{
    //DLOG("~FZZWNumId()");
    FZZConst::delClassCount("FZZWNumId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWNumId::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWNumId::getVal()
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
