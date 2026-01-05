//
//  Created by zizheng fan on 2023/04/16.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZFontTableXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZFontTableXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML::FZZFontTableXML() : FZZOfficeObject()
{
    //DLOG("FZZFontTableXML()");
    FZZConst::addClassCount("FZZFontTableXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:fonts");
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME, OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute(MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE1);
    
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = FONTTABLEXML_FILENAME;
    
    defaultInit();
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML::FZZFontTableXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZFontTableXML");
    m_FileName = FONTTABLEXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML::FZZFontTableXML(const FZZFontTableXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZFontTableXML");
    if ( this == &obj ) {
        return;
    }
    vector<FZZWFont*>::const_iterator itr;
    for( itr = obj.m_FontList.begin(); itr != obj.m_FontList.end(); itr++ ) {
        FZZWFont * temp = *itr;
        if ( temp != NULL ) {
            m_FontList.push_back(new FZZWFont(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontTableXML::~FZZFontTableXML()
{
    //DLOG("~FZZFontTableXML()");
    FZZConst::delClassCount("FZZFontTableXML");
    
    vector<FZZWFont*>::const_iterator itr;
    for( itr = m_FontList.begin(); itr != m_FontList.end(); itr++ ) {
        FZZWFont * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FontList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZFontTableXML::defaultInit()
{
    FZZWFont* font = NULL;
    FZZWAltName * altName = NULL;
    FZZWSig * Sig = NULL;
    FZZWPitch * Pitch = NULL;
    FZZWPanose1 * Panose1 = NULL;
    FZZWFamily * Family = NULL;
    FZZWCharset * Charset = NULL;
    font = addFont();
    if ( font != NULL ) {
        font->setName("DengXian");
        altName = font->setAltName();
        if ( altName != NULL ) altName->setVal("等线");
        Panose1 = font->setPanose1();
        if ( Panose1 != NULL ) Panose1->setVal("02010600030101010101");
        Charset = font->setCharset();
        if ( Charset != NULL ) Charset->setVal("86");
        Family = font->setFamily();
        if ( Family != NULL ) Family->setVal("auto");
        Pitch = font->setPitch();
        if ( Pitch != NULL ) Pitch->setVal("variable");
        Sig = font->setSig();
        if ( Sig != NULL ) {
            Sig->setUsb0("A00002BF");
            Sig->setUsb1("38CF7CFA");
            Sig->setUsb2("00000016");
            Sig->setUsb3("00000000");
            Sig->setCsb0("0004000F");
            Sig->setCsb1("00000000");
        }
    }
    font = addFont();
    if ( font != NULL ) {
        font->setName("Times New Roman");
        Panose1 = font->setPanose1();
        if ( Panose1 != NULL ) Panose1->setVal("02020603050405020304");
        Charset = font->setCharset();
        if ( Charset != NULL ) Charset->setVal("00");
        Family = font->setFamily();
        if ( Family != NULL ) Family->setVal("roman");
        Pitch = font->setPitch();
        if ( Pitch != NULL ) Pitch->setVal("variable");
        Sig = font->setSig();
        if ( Sig != NULL ) {
            Sig->setUsb0("E0002EFF");
            Sig->setUsb1("C000785B");
            Sig->setUsb2("00000009");
            Sig->setUsb3("00000000");
            Sig->setCsb0("000001FF");
            Sig->setCsb1("00000000");
        }
    }
    
    font = addFont();
    if ( font != NULL ) {
        font->setName("等线 Light");
        Panose1 = font->setPanose1();
        if ( Panose1 != NULL ) Panose1->setVal("02010600030101010101");
        Charset = font->setCharset();
        if ( Charset != NULL ) Charset->setVal("86");
        Family = font->setFamily();
        if ( Family != NULL ) Family->setVal("auto");
        Pitch = font->setPitch();
        if ( Pitch != NULL ) Pitch->setVal("variable");
        Sig = font->setSig();
        if ( Sig != NULL ) {
            Sig->setUsb0("A00002BF");
            Sig->setUsb1("38CF7CFA");
            Sig->setUsb2("00000016");
            Sig->setUsb3("00000000");
            Sig->setCsb0("0004000F");
            Sig->setCsb1("00000000");
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFont* FZZFontTableXML::addFont()
{
    return addElementObject(&m_FontList,FZZWFONT_Find_Key,FZZWFONT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWFont*> * FZZFontTableXML::getFontList()
{
    getElementObjectList(&m_FontList,FZZWFONT_Find_Key,FZZWFONT_Name);
    return &m_FontList;
}
//-----------------------------------------------------------------------------------------------------------------
