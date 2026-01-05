//
//  Created by zizheng fan on 2023/11/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLastRenderedPageBreak.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLastRenderedPageBreak**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak::FZZWLastRenderedPageBreak() : FZZXMLElementObject()
{
    //DLOG("FZZWLastRenderedPageBreak()");
    FZZConst::addClassCount("FZZWLastRenderedPageBreak");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak::FZZWLastRenderedPageBreak(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLastRenderedPageBreak");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak::FZZWLastRenderedPageBreak(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLastRenderedPageBreak");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak::FZZWLastRenderedPageBreak(const FZZWLastRenderedPageBreak& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLastRenderedPageBreak");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak::~FZZWLastRenderedPageBreak()
{
    //DLOG("~FZZWLastRenderedPageBreak()");
    FZZConst::delClassCount("FZZWLastRenderedPageBreak");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWLastRenderedPageBreak::setVal(string value)
//{
//    setAttribute_String("w:val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWLastRenderedPageBreak::getVal()
//{
//    string retstr = getAttribute_String("w:val");
//    return retstr;
//}
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
