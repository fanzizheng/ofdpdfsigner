//
//  Created by zizheng fan on 2023/11/14
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCr::FZZWCr() : FZZXMLElementObject()
{
    //DLOG("FZZWCr()");
    FZZConst::addClassCount("FZZWCr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr::FZZWCr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr::FZZWCr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWCr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr::FZZWCr(const FZZWCr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCr");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr::~FZZWCr()
{
    //DLOG("~FZZWCr()");
    FZZConst::delClassCount("FZZWCr");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWCr::setVal(string value)
//{
//    setAttribute_String("w:val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWCr::getVal()
//{
//    string retstr = getAttribute_String("w:val");
//    if ( retstr.empty() ) {
//        retstr = "0";
//    }
//    return retstr;
//}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWCr::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWCr::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
