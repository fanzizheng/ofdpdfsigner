//
//  Created by zizheng fan on 2023/10/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLang.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLang**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLang::FZZWLang() : FZZXMLElementObject()
{
    //DLOG("FZZWLang()");
    FZZConst::addClassCount("FZZWLang");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang::FZZWLang(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLang");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang::FZZWLang(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWLang");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang::FZZWLang(const FZZWLang& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLang");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang::~FZZWLang()
{
    //DLOG("~FZZWLang()");
    FZZConst::delClassCount("FZZWLang");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLang::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLang::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLang::setEastAsia(string value)
{
    setAttribute_String("w:eastAsia",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLang::getEastAsia()
{
    return getAttribute_String("w:eastAsia");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLang::setBidi(string value)
{
    setAttribute_String("w:bidi",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLang::getBidi()
{
    return getAttribute_String("w:bidi");
}
//-----------------------------------------------------------------------------------------------------------------
