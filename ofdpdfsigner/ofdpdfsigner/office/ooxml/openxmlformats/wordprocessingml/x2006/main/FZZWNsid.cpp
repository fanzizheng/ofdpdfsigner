//
//  Created by zizheng fan on 2023/11/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNsid.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNsid**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid::FZZWNsid() : FZZXMLElementObject()
{
    //DLOG("FZZWNsid()");
    FZZConst::addClassCount("FZZWNsid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid::FZZWNsid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNsid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid::FZZWNsid(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWNsid");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid::FZZWNsid(const FZZWNsid& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNsid");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid::~FZZWNsid()
{
    //DLOG("~FZZWNsid()");
    FZZConst::delClassCount("FZZWNsid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWNsid::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWNsid::getVal()
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
