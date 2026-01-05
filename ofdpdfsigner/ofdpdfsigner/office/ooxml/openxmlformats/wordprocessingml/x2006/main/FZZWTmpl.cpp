//
//  Created by zizheng fan on 2023/11/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTmpl.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTmpl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl::FZZWTmpl() : FZZXMLElementObject()
{
    //DLOG("FZZWTmpl()");
    FZZConst::addClassCount("FZZWTmpl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl::FZZWTmpl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTmpl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl::FZZWTmpl(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTmpl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl::FZZWTmpl(const FZZWTmpl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTmpl");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl::~FZZWTmpl()
{
    //DLOG("~FZZWTmpl()");
    FZZConst::delClassCount("FZZWTmpl");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTmpl::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTmpl::getVal()
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
