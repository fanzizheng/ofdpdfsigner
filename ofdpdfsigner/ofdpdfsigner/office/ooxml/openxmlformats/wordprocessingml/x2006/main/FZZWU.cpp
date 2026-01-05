//
//  Created by zizheng fan on 2023/11/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWU.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWU**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWU::FZZWU() : FZZXMLElementObject()
{
    //DLOG("FZZWU()");
    FZZConst::addClassCount("FZZWU");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU::FZZWU(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWU");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU::FZZWU(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWU");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU::FZZWU(const FZZWU& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWU");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU::~FZZWU()
{
    //DLOG("~FZZWU()");
    FZZConst::delClassCount("FZZWU");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWU::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWU::getVal()
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
