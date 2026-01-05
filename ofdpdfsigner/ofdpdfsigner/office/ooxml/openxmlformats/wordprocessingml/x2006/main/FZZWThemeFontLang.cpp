//
//  Created by zizheng fan on 2023/09/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWThemeFontLang.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWThemeFontLang**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang::FZZWThemeFontLang() : FZZXMLElementObject()
{
    //DLOG("FZZWThemeFontLang()");
    FZZConst::addClassCount("FZZWThemeFontLang");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang::FZZWThemeFontLang(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWThemeFontLang");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang::FZZWThemeFontLang(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWThemeFontLang");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang::FZZWThemeFontLang(const FZZWThemeFontLang& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWThemeFontLang");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWThemeFontLang::~FZZWThemeFontLang()
{
    //DLOG("~FZZWThemeFontLang()");
    FZZConst::delClassCount("FZZWThemeFontLang");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWThemeFontLang::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWThemeFontLang::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWThemeFontLang::setEastAsia(string value)
{
    setAttribute_String("w:eastAsia",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWThemeFontLang::getEastAsia()
{
    return getAttribute_String("w:eastAsia");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
