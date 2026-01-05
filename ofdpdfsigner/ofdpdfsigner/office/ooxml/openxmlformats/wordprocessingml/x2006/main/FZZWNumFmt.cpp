//
//  Created by zizheng fan on 2023/11/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumFmt.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNumFmt**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt::FZZWNumFmt() : FZZXMLElementObject()
{
    //DLOG("FZZWNumFmt()");
    FZZConst::addClassCount("FZZWNumFmt");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt::FZZWNumFmt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNumFmt");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt::FZZWNumFmt(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWNumFmt");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt::FZZWNumFmt(const FZZWNumFmt& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNumFmt");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt::~FZZWNumFmt()
{
    //DLOG("~FZZWNumFmt()");
    FZZConst::delClassCount("FZZWNumFmt");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWNumFmt::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWNumFmt::getVal()
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
