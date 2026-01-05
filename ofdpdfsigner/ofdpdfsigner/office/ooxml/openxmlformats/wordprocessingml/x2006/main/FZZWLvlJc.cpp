//
//  Created by zizheng fan on 2023/11/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlJc.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLvlJc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc::FZZWLvlJc() : FZZXMLElementObject()
{
    //DLOG("FZZWLvlJc()");
    FZZConst::addClassCount("FZZWLvlJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc::FZZWLvlJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLvlJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc::FZZWLvlJc(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLvlJc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc::FZZWLvlJc(const FZZWLvlJc& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLvlJc");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc::~FZZWLvlJc()
{
    //DLOG("~FZZWLvlJc()");
    FZZConst::delClassCount("FZZWLvlJc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLvlJc::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLvlJc::getVal()
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
