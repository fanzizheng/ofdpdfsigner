//
//  Created by zizheng fan on 2023/04/16.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZRelsXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZRelsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZRelsXML::FZZRelsXML() : FZZOfficeObject()
{
    //DLOG("FZZRelsXML()");
    FZZConst::addClassCount("FZZRelsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("Relationships");
    ofd_Document->SetAttribute(OPENXMLFORMATS_PACKAGE_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_PACKAGE_2006_RELATIONSHIPS_VALUE);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = RELSXML_FILENAME;
    
    FZZRelationship * temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId("rId1");
        temp->setType(RELSXML_TYPE_Extended_OfficeDocument);
        temp->setTarget("word/document.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId("rId2");
        temp->setType(RELSXML_TYPE_Core_properties);
        temp->setTarget("docProps/core.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId("rId3");
        temp->setType(RELSXML_TYPE_Extended_properties);
        temp->setTarget("docProps/app.xml");
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsXML::FZZRelsXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZRelsXML");
    m_FileName = RELSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsXML::FZZRelsXML(const FZZRelsXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZRelsXML");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelsXML::~FZZRelsXML()
{
    //DLOG("~FZZContentTypesXML()");
    FZZConst::delClassCount("FZZRelsXML");
    vector<FZZRelationship *>::const_iterator defitr;
    for( defitr = m_RelationshipList.begin(); defitr != m_RelationshipList.end(); defitr++ ) {
        FZZRelationship * temp = *defitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_RelationshipList.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZRelationship *> * FZZRelsXML::getRelationships()
{
    if ( m_RelationshipList.size() == 0 ) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,FZZRELATIONSHIP_Find_Key,FZZRELATIONSHIP_Name,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                FZZRelationship * temp = FZZRelationship::getInstance(this,m_doc, ele,(FZZRelationship*)NULL);
                if ( temp != NULL ) {
                    m_RelationshipList.push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
    
    return &m_RelationshipList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship * FZZRelsXML::addRelationship()
{
    if (m_doc == NULL) {
        return NULL;
    }
    if (m_ofd_Node == NULL) {
        return NULL;
    }
    
    if ( m_RelationshipList.size() == 0 ) {
        getRelationships();
    }

    FZZRelationship * cttemp;
    string key;
    getElement(&m_XmlnsList,m_ofd_Node,FZZRELATIONSHIP_Find_Key,FZZRELATIONSHIP_Name,key);
   
    cttemp = new FZZRelationship(this,m_doc, m_ofd_Node,key);
   
        
    m_RelationshipList.push_back(cttemp);
    return cttemp;
}
//-----------------------------------------------------------------------------------------------------------------
