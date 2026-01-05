//
//  Created by zizheng fan on 2023/11/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInstrText.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWInstrText**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText::FZZWInstrText() : FZZXMLElementObject()
{
    //DLOG("FZZWInstrText()");
    FZZConst::addClassCount("FZZWInstrText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText::FZZWInstrText(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWInstrText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText::FZZWInstrText(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWInstrText");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText::FZZWInstrText(const FZZWInstrText& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWInstrText");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText::~FZZWInstrText()
{
    //DLOG("~FZZWInstrText()");
    FZZConst::delClassCount("FZZWInstrText");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInstrText::setSpace(string value)
{
    setAttribute_String("xml:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInstrText::getSpace()
{
    return getAttribute_String("xml:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWInstrText::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWInstrText::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
