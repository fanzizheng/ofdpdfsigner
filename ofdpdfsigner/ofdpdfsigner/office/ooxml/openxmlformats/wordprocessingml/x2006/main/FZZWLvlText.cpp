//
//  Created by zizheng fan on 2023/11/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlText.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLvlText**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText::FZZWLvlText() : FZZXMLElementObject()
{
    //DLOG("FZZWLvlText()");
    FZZConst::addClassCount("FZZWLvlText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText::FZZWLvlText(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLvlText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText::FZZWLvlText(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLvlText");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText::FZZWLvlText(const FZZWLvlText& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLvlText");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText::~FZZWLvlText()
{
    //DLOG("~FZZWLvlText()");
    FZZConst::delClassCount("FZZWLvlText");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLvlText::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLvlText::getVal()
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
