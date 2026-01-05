//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFont.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFont**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::FZZOFDFont() : FZZOFDXMLElementObject(),m_FZZOFDFontFile(NULL)
{
    //DLOG("FZZOFDFont()");
    FZZConst::addClassCount("FZZOFDFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::FZZOFDFont(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDFontFile(NULL)
{
    FZZConst::addClassCount("FZZOFDFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::FZZOFDFont(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDFontFile(NULL)
{
    FZZConst::addClassCount("FZZOFDFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::FZZOFDFont(const FZZOFDFont& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFont");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDFontFile = obj.m_FZZOFDFontFile != NULL ? new FZZOFDFontFile(*obj.m_FZZOFDFontFile) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::~FZZOFDFont()
{
    //DLOG("~FZZOFDFont()");
    FZZConst::delClassCount("FZZOFDFont");
        
    if ( m_FZZOFDFontFile != NULL ) {
        delete m_FZZOFDFontFile;
        m_FZZOFDFontFile = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setCharset(FZZOFDFont::TYPE value)
{
    string strvalu = "unicode";
    switch (value) {
        case FZZOFDFont::TYPE::unicode:
            strvalu = "unicode";
            break;
        case FZZOFDFont::TYPE::symbol:
            strvalu = "symbol";
            break;
        case FZZOFDFont::TYPE::prc:
            strvalu = "prc";
            break;
        case FZZOFDFont::TYPE::big5:
            strvalu = "big5";
            break;
        case FZZOFDFont::TYPE::shift_jis:
            strvalu = "shift-jis";
            break;
        case FZZOFDFont::TYPE::wansung:
            strvalu = "wansung";
            break;
        case FZZOFDFont::TYPE::johab:
            strvalu = "johab";
            break;
        
        default:
            strvalu = "unicode";
            break;

    }
    setAttribute_String("Charset",strvalu);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont::TYPE FZZOFDFont::getCharset()
{
    string strValue = getAttribute_String("Charset");
    FZZOFDFont::TYPE type = FZZOFDFont::TYPE::unicode;
    if (strValue == "unicode") {
        type = FZZOFDFont::TYPE::unicode;
    }
    else if (strValue == "symbol") {
        type = FZZOFDFont::TYPE::symbol;
    }
    else if (strValue == "prc") {
        type = FZZOFDFont::TYPE::prc;
    }
    else if (strValue == "big5") {
        type = FZZOFDFont::TYPE::big5;
    }
    else if (strValue == "shift-jis") {
        type = FZZOFDFont::TYPE::shift_jis;
    }
    else if (strValue == "wansung") {
        type = FZZOFDFont::TYPE::wansung;
    }
    else if (strValue == "johab") {
        type = FZZOFDFont::TYPE::johab;
    }
    return type;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFont::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDFont::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setFontName(string value)
{
    setAttribute_String("FontName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFont::getFontName()
{
    return getAttribute_String("FontName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setFamilyName(string value)
{
    setAttribute_String("FamilyName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFont::getFamilyName()
{
    return getAttribute_String("FamilyName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setItalic(bool value)
{
    setAttribute_Bool("Italic",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDFont::getItalic()
{
    return getAttribute_Bool("Italic",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setBold(bool value)
{
    setAttribute_Bool("Bold",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDFont::getBold()
{
    return getAttribute_Bool("Bold",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setSerif(bool value)
{
    setAttribute_Bool("Serif",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDFont::getSerif()
{
    return getAttribute_Bool("Serif",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFont::setFixedWidth(bool value)
{
    setAttribute_Bool("FixedWidth",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDFont::getFixedWidth()
{
    return getAttribute_Bool("FixedWidth",false);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile * FZZOFDFont::setFontFile()
{
    return m_FZZOFDFontFile = setElementObject(m_FZZOFDFontFile,FZZOFDFONTFILE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile * FZZOFDFont::getFontFile()
{
    return m_FZZOFDFontFile = getElementObject(m_FZZOFDFontFile,FZZOFDFONTFILE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
