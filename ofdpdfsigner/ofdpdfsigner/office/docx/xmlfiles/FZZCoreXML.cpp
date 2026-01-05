//
//  Created by zizheng fan on 2023/04/14.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZCoreXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZCoreXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZCoreXML::FZZCoreXML() : FZZOfficeObject()
{
    //DLOG("FZZCoreXML()");
    FZZConst::addClassCount("FZZCoreXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("cp:coreProperties");
    ofd_Document->SetAttribute(OPENXMLFORMATS_PACKAGE_2006_METADATA_CORE_PROPERTIES_NAME, OPENXMLFORMATS_PACKAGE_2006_METADATA_CORE_PROPERTIES_VALUE);
    ofd_Document->SetAttribute(PURL_DC_ELEMENTS_1_1_NAME, PURL_DC_ELEMENTS_1_1_VALUE);
    ofd_Document->SetAttribute(PURL_DC_TERMS_NAME, PURL_DC_TERMS_VALUE);
    ofd_Document->SetAttribute(PURL_DC_DCMITYPE_NAME, PURL_DC_DCMITYPE_VALUE);
    ofd_Document->SetAttribute(W3_2001_XMLSCHEMA_INSTANCE_NAME, W3_2001_XMLSCHEMA_INSTANCE_VALUE);
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = COREXML_FILENAME;
    
    setDcCreator(WORD_COMPANY);
    setCpLastModifiedBy(WORD_COMPANY);
    time_t createDate;
    time(&createDate);
    string timerstr = FZZConst::format_time_YYYY_MM_DD_T_hh_mm_ss_Z(createDate);
    setDctermsCreated(timerstr);
    setDctermsModified(timerstr);
}
//-----------------------------------------------------------------------------------------------------------------
FZZCoreXML::FZZCoreXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZCoreXML");
    m_FileName = COREXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZCoreXML::FZZCoreXML(const FZZCoreXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZCoreXML");
    if ( this == &obj ) {
        return;
    }
   
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZCoreXML::~FZZCoreXML()
{
    //DLOG("~FZZCoreXML()");
    FZZConst::delClassCount("FZZCoreXML");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZCoreXML::setDcTitle(string value)
{
    setXMLElement_Value("dc:title",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDcTitle()
{
    return getXMLElement_Value("dc:title");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZCoreXML::setDcSubject(string value)
{
    setXMLElement_Value("dc:subject",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDcSubject()
{
    return getXMLElement_Value("dc:subject");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setDcCreator(string value)
{
    setXMLElement_Value("dc:creator",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDcCreator()
{
    return getXMLElement_Value("dc:creator");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setCpKeywords(string value)
{
    setXMLElement_Value("cp:keywords",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getCpKeywords()
{
    return getXMLElement_Value("cp:keywords");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setDcDescription(string value)
{
    setXMLElement_Value("dc:description",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDcDescription()
{
    return getXMLElement_Value("dc:description");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setCpLastModifiedBy(string value)
{
    setXMLElement_Value("cp:lastModifiedBy",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getCpLastModifiedBy()
{
    return getXMLElement_Value("cp:lastModifiedBy");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setCpRevision(string value)
{
    setXMLElement_Value("cp:revision",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getCpRevision()
{
    return getXMLElement_Value("cp:revision");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setDctermsCreated(string value)
{
    setXMLElement_Value("dcterms:created",value);
    setAttribute_String("dcterms:created","xsi:type","dcterms:W3CDTF");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDctermsCreated()
{
    return getXMLElement_Value("dcterms:created");
}
//-----------------------------------------------------------------------------------------------------------------

void FZZCoreXML::setDctermsModified(string value)
{
    setXMLElement_Value("dcterms:modified",value);
    setAttribute_String("dcterms:modified","xsi:type","dcterms:W3CDTF");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCoreXML::getDctermsModified()
{
    return getXMLElement_Value("dcterms:modified");
}
//-----------------------------------------------------------------------------------------------------------------


