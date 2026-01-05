//
//  Created by zizheng fan on 2023/04/14.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZContentTypesXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZContentTypesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZContentTypesXML::FZZContentTypesXML() : FZZOfficeObject()
{
    //DLOG("FZZContentTypesXML()");
    FZZConst::addClassCount("FZZContentTypesXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("Types");
    ofd_Document->SetAttribute(OPENXMLFORMATS_PACKAGE_2006_CONTENT_TYPES_NAME, OPENXMLFORMATS_PACKAGE_2006_CONTENT_TYPES_VALUE);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
    InitXmlnsList();
    m_FileName = CONTENTTYPESXML_FILENAME;
    
    CTContentTypes_Default * tempDefautl = addDefault();
    if ( tempDefautl != NULL ) {
        tempDefautl->setExtension("rels");
        tempDefautl->setContentType("application/vnd.openxmlformats-package.relationships+xml");
    }
    tempDefautl = addDefault();
    if ( tempDefautl != NULL ) {
        tempDefautl->setExtension("xml");
        tempDefautl->setContentType("application/xml");
    }
    
    CTContentTypes_Override * tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/docProps/core.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-package.core-properties+xml");
    }
    
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/docProps/app.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.extended-properties+xml");
    }
    
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/document.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml");
    }
    
    
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/styles.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml");
    }
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/settings.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml");
    }
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/webSettings.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.wordprocessingml.webSettings+xml");
    }
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/fontTable.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.wordprocessingml.fontTable+xml");
    }
    tempOverride = addOverride();
    if ( tempOverride != NULL ) {
        tempOverride->setPartName("/word/theme/theme1.xml");
        tempOverride->setContentType("application/vnd.openxmlformats-officedocument.theme+xml");
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentTypesXML::FZZContentTypesXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZContentTypesXML");
    m_FileName = CONTENTTYPESXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentTypesXML::FZZContentTypesXML(const FZZContentTypesXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZContentTypesXML");
    if ( this == &obj ) {
        return;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZContentTypesXML::~FZZContentTypesXML()
{
    //DLOG("~FZZContentTypesXML()");
    FZZConst::delClassCount("FZZContentTypesXML");
    
    vector<CTContentTypes_Default *>::const_iterator defitr;
    for( defitr = m_DefaultList.begin(); defitr != m_DefaultList.end(); defitr++ ) {
        CTContentTypes_Default * temp = *defitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_DefaultList.clear();
    
    vector<CTContentTypes_Override *>::const_iterator overitr;
    for( overitr = m_OverrideList.begin(); overitr != m_OverrideList.end(); overitr++ ) {
        CTContentTypes_Override * temp = *overitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_OverrideList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<CTContentTypes_Default *> * FZZContentTypesXML::getDefaults()
{
    if ( m_DefaultList.size() == 0 ) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,CTContentTypes_Default_Find_Key,CTContentTypes_Default_Name,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                CTContentTypes_Default * temp = CTContentTypes_Default::getInstance(this,m_doc, ele,(CTContentTypes_Default*)NULL);
                if ( temp != NULL ) {
                    m_DefaultList.push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
    
    return &m_DefaultList;
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Default * FZZContentTypesXML::addDefault()
{
    if (m_doc == NULL) {
        return NULL;
    }
    if (m_ofd_Node == NULL) {
        return NULL;
    }
    
    if ( m_DefaultList.size() == 0 ) {
        getDefaults();
    }

    CTContentTypes_Default * cttemp;
    string key;
    getElement(&m_XmlnsList,m_ofd_Node,CTContentTypes_Default_Find_Key,CTContentTypes_Default_Name,key);
    //if (ele == NULL) {
        cttemp = new CTContentTypes_Default(this,m_doc, m_ofd_Node,key);
    //}
    //else {
    //    cttemp = CTContentTypes_Default::getInstance(m_doc, ele);
    //}
        
    m_DefaultList.push_back(cttemp);
    return cttemp;
}
//-----------------------------------------------------------------------------------------------------------------
vector<CTContentTypes_Override *> * FZZContentTypesXML::getOverrides()
{
  
    
    if ( m_OverrideList.size() == 0 ) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,CTContentTypes_Override_Find_Key,CTContentTypes_Override_Name,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                CTContentTypes_Override * temp = CTContentTypes_Override::getInstance(this,m_doc, ele,(CTContentTypes_Override*)NULL);
                if ( temp != NULL ) {
                    m_OverrideList.push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
    
    return &m_OverrideList;
}
//-----------------------------------------------------------------------------------------------------------------
CTContentTypes_Override * FZZContentTypesXML::addOverride()
{
    if (m_doc == NULL) {
        return NULL;
    }
    if (m_ofd_Node == NULL) {
        return NULL;
    }
    
    if ( m_OverrideList.size() == 0 ) {
        getOverrides();
    }

    CTContentTypes_Override * cttemp;
    string key;
    getElement(&m_XmlnsList,m_ofd_Node,CTContentTypes_Override_Find_Key,CTContentTypes_Override_Name,key);
    //if (ele == NULL) {
        cttemp = new CTContentTypes_Override(this,m_doc, m_ofd_Node,key);
    //}
    //else {
    //    cttemp = CTContentTypes_Override::getInstance(m_doc, ele);
    //}
        
    m_OverrideList.push_back(cttemp);
    return cttemp;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZContentTypesXML::isHave_Default_ContentType(string type)
{
    vector<CTContentTypes_Default *> * tempTypes = getDefaults();
    vector<CTContentTypes_Default *>::const_iterator defitr;
    for( defitr = m_DefaultList.begin(); defitr != m_DefaultList.end(); defitr++ ) {
        CTContentTypes_Default * temp = *defitr;
        if ( temp != NULL ) {
            if ( temp->getContentType() == type ) {
                return true;
            }
        }
    }
    return false;
}
//-----------------------------------------------------------------------------------------------------------------
