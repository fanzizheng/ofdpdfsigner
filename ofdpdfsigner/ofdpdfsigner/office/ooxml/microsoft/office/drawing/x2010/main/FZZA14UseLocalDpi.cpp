//
//  Created by zizheng fan on 2023/04/24.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/drawing/x2010/main/FZZA14UseLocalDpi.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZA14UseLocalDpi**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi::FZZA14UseLocalDpi() : FZZXMLElementObject()
{
    //DLOG("FZZA14UseLocalDpi()");
    FZZConst::addClassCount("FZZA14UseLocalDpi");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi::FZZA14UseLocalDpi(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZA14UseLocalDpi");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi::FZZA14UseLocalDpi(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZA14UseLocalDpi");
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi::FZZA14UseLocalDpi(const FZZA14UseLocalDpi& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZA14UseLocalDpi");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZA14UseLocalDpi::~FZZA14UseLocalDpi()
{
    //DLOG("~FZZA14UseLocalDpi()");
    FZZConst::delClassCount("FZZA14UseLocalDpi");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZA14UseLocalDpi::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZA14UseLocalDpi::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZA14UseLocalDpi::setXmlnsA14(string value)
{
    setAttribute_String("xmlns:a14",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZA14UseLocalDpi::getXmlnsA14()
{
    return getAttribute_String("xmlns:a14");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZA14UseLocalDpi::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZA14UseLocalDpi::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
