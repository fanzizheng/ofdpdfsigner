//
//  Created by zizheng fan on 2023/11/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBr::FZZWBr() : FZZXMLElementObject()
{
    //DLOG("FZZWBr()");
    FZZConst::addClassCount("FZZWBr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr::FZZWBr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr::FZZWBr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr::FZZWBr(const FZZWBr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr::~FZZWBr()
{
    //DLOG("~FZZWBr()");
    FZZConst::delClassCount("FZZWBr");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWBr::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWBr::getType()
{
    string retstr = getAttribute_String("w:type");
    
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
