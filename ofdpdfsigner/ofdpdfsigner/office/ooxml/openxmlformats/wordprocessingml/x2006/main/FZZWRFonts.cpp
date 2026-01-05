//
//  Created by zizheng fan on 2023/10/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRFonts.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRFonts**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts::FZZWRFonts() : FZZXMLElementObject()
{
    //DLOG("FZZWRFonts()");
    FZZConst::addClassCount("FZZWRFonts");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts::FZZWRFonts(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRFonts");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts::FZZWRFonts(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWRFonts");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts::FZZWRFonts(const FZZWRFonts& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRFonts");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts::~FZZWRFonts()
{
    //DLOG("~FZZWRFonts()");
    FZZConst::delClassCount("FZZWRFonts");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setAsciiTheme(string value)
{
    setAttribute_String("w:asciiTheme",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getAsciiTheme()
{
    return getAttribute_String("w:asciiTheme");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setEastAsiaTheme(string value)
{
    setAttribute_String("w:eastAsiaTheme",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getEastAsiaTheme()
{
    return getAttribute_String("w:eastAsiaTheme");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setHAnsiTheme(string value)
{
    setAttribute_String("w:hAnsiTheme",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getHAnsiTheme()
{
    return getAttribute_String("w:hAnsiTheme");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setCstheme(string value)
{
    setAttribute_String("w:cstheme",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getCstheme()
{
    return getAttribute_String("w:cstheme");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setHint(string value)
{
    setAttribute_String("w:hint",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getHint()
{
    return getAttribute_String("w:hint");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setAscii(string value)
{
    setAttribute_String("w:ascii",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getAscii()
{
    return getAttribute_String("w:ascii");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setEastAsia(string value)
{
    setAttribute_String("w:eastAsia",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getEastAsia()
{
    return getAttribute_String("w:eastAsia");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setHAnsi(string value)
{
    setAttribute_String("w:hAnsi",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getHAnsi()
{
    return getAttribute_String("w:hAnsi");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRFonts::setCS(string value)
{
    setAttribute_String("w:cs",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRFonts::getCS()
{
    return getAttribute_String("w:cs");
}
//-----------------------------------------------------------------------------------------------------------------
