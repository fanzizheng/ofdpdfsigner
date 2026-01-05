//
//  Created by zizheng fan on 2023/11/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWW.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWW**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWW::FZZWW() : FZZXMLElementObject()
{
    //DLOG("FZZWW()");
    FZZConst::addClassCount("FZZWW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW::FZZWW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWW");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW::FZZWW(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWW");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW::FZZWW(const FZZWW& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWW");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW::~FZZWW()
{
    //DLOG("~FZZWW()");
    FZZConst::delClassCount("FZZWW");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWW::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWW::getVal()
{
    string retstr = getAttribute_String("w:val");
    if ( retstr.empty() ) {
        retstr = "100";
    }
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
