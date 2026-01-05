//
//  Created by zizheng fan on 2023/11/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridSpan.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWGridSpan**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan::FZZWGridSpan() : FZZXMLElementObject()
{
    //DLOG("FZZWGridSpan()");
    FZZConst::addClassCount("FZZWGridSpan");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan::FZZWGridSpan(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWGridSpan");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan::FZZWGridSpan(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWGridSpan");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan::FZZWGridSpan(const FZZWGridSpan& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWGridSpan");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan::~FZZWGridSpan()
{
    //DLOG("~FZZWGridSpan()");
    FZZConst::delClassCount("FZZWGridSpan");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWGridSpan::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWGridSpan::getVal()
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
