//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWIlvl.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWIlvl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl::FZZWIlvl() : FZZXMLElementObject()
{
    //DLOG("FZZWIlvl()");
    FZZConst::addClassCount("FZZWIlvl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl::FZZWIlvl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWIlvl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl::FZZWIlvl(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWIlvl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl::FZZWIlvl(const FZZWIlvl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWIlvl");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl::~FZZWIlvl()
{
    //DLOG("~FZZWIlvl()");
    FZZConst::delClassCount("FZZWIlvl");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWIlvl::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWIlvl::getVal()
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
