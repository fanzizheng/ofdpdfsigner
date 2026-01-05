//
//  Created by zizheng fan on 2023/11/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVAlign.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWVAlign**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign::FZZWVAlign() : FZZXMLElementObject()
{
    //DLOG("FZZWVAlign()");
    FZZConst::addClassCount("FZZWVAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign::FZZWVAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWVAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign::FZZWVAlign(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWVAlign");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign::FZZWVAlign(const FZZWVAlign& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWVAlign");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign::~FZZWVAlign()
{
    //DLOG("~FZZWVAlign()");
    FZZConst::delClassCount("FZZWVAlign");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWVAlign::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWVAlign::getVal()
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
