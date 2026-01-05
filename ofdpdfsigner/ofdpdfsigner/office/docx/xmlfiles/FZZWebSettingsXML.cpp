//
//  Created by zizheng fan on 2023/04/08.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZWebSettingsXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWebSettingsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWebSettingsXML::FZZWebSettingsXML() : FZZOfficeObject(),m_FZZWOptimizeForBrowser(NULL),m_FZZWAllowPNG(NULL)
{
    //DLOG("FZZWebSettingsXML()");
    FZZConst::addClassCount("FZZWebSettingsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:webSettings");
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
    
    m_FileName = WEBSETTINGSXML_FILENAME;
    
    defaultInit();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWebSettingsXML::FZZWebSettingsXML(XMLDocument * doc) : FZZOfficeObject(doc),m_FZZWOptimizeForBrowser(NULL),m_FZZWAllowPNG(NULL)
{
    FZZConst::addClassCount("FZZWebSettingsXML");
    m_FileName = WEBSETTINGSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWebSettingsXML::FZZWebSettingsXML(const FZZWebSettingsXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZWebSettingsXML");
    if ( this == &obj ) {
        return;
    }

    m_FZZWOptimizeForBrowser = obj.m_FZZWOptimizeForBrowser != NULL ? new FZZWOptimizeForBrowser(*obj.m_FZZWOptimizeForBrowser) : NULL;
    m_FZZWAllowPNG = obj.m_FZZWAllowPNG != NULL ? new FZZWAllowPNG(*obj.m_FZZWAllowPNG) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWebSettingsXML::~FZZWebSettingsXML()
{
    //DLOG("~FZZWebSettingsXML()");
    FZZConst::delClassCount("FZZWebSettingsXML");
    if ( m_FZZWOptimizeForBrowser != NULL ) {
        delete m_FZZWOptimizeForBrowser;
        m_FZZWOptimizeForBrowser = NULL;
    }
    
    if ( m_FZZWAllowPNG != NULL ) {
        delete m_FZZWAllowPNG;
        m_FZZWAllowPNG = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWebSettingsXML::defaultInit()
{
    setOptimizeForBrowser();
    setAllowPNG();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser * FZZWebSettingsXML::setOptimizeForBrowser()
{

    return m_FZZWOptimizeForBrowser = setElementObject(m_FZZWOptimizeForBrowser,FZZWOPTIMIZEFORBROWSER_Find_Key,FZZWOPTIMIZEFORBROWSER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser * FZZWebSettingsXML::getOptimizeForBrowser()
{
    return m_FZZWOptimizeForBrowser = getElementObject(m_FZZWOptimizeForBrowser,FZZWOPTIMIZEFORBROWSER_Find_Key,FZZWOPTIMIZEFORBROWSER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG * FZZWebSettingsXML::setAllowPNG()
{

    return m_FZZWAllowPNG = setElementObject(m_FZZWAllowPNG,FZZWALLOWPNG_Find_Key,FZZWALLOWPNG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG * FZZWebSettingsXML::getAllowPNG()
{
    return m_FZZWAllowPNG = getElementObject(m_FZZWAllowPNG,FZZWALLOWPNG_Find_Key,FZZWALLOWPNG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
