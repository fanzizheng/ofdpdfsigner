//
//  Created by zizheng fan on 2023/11/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStart.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWStart**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWStart::FZZWStart() : FZZXMLElementObject()
{
    //DLOG("FZZWStart()");
    FZZConst::addClassCount("FZZWStart");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart::FZZWStart(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWStart");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart::FZZWStart(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWStart");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart::FZZWStart(const FZZWStart& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWStart");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart::~FZZWStart()
{
    //DLOG("~FZZWStart()");
    FZZConst::delClassCount("FZZWStart");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWStart::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWStart::getVal()
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
