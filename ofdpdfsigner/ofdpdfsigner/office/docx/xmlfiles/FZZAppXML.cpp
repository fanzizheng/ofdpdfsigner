//
//  Created by zizheng fan on 2023/04/13.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZAppXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAppXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAppXML::FZZAppXML() : FZZOfficeObject()
{
    //DLOG("FZZAppXML()");
    FZZConst::addClassCount("FZZAppXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("Properties");
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_EXTENDED_PROPERTIES_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_EXTENDED_PROPERTIES_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_DOCPROPSVTYPES_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_DOCPROPSVTYPES_VALUE);
    
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = APPXML_FILENAME;
    
    setApplication(WORD_COMPANY);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAppXML::FZZAppXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZAppXML");
    m_FileName = APPXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAppXML::FZZAppXML(const FZZAppXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZAppXML");
    if ( this == &obj ) {
        return;
    }
   
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAppXML::~FZZAppXML()
{
    //DLOG("~FZZAppXML()");
    FZZConst::delClassCount("FZZAppXML");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAppXML::setTemplate(string value)
{
    setXMLElement_Value("Template",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAppXML::getTemplate()
{
    return getXMLElement_Value("Template");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAppXML::setApplication(string value)
{
    setXMLElement_Value("Application",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAppXML::getApplication()
{
    return getXMLElement_Value("Application");
}
//-----------------------------------------------------------------------------------------------------------------
