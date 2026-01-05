//
//  Created by zizheng fan on 2023/04/15.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZDocumentXMLRels.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocumentXMLRels**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels::FZZDocumentXMLRels() : FZZOfficeObject(),m_id(0)
{
    //DLOG("FZZDocumentXMLRels()");
    FZZConst::addClassCount("FZZDocumentXMLRels");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("Relationships");
    ofd_Document->SetAttribute(OPENXMLFORMATS_PACKAGE_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_PACKAGE_2006_RELATIONSHIPS_VALUE);
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = DOCUMENTXMLRELS_FILENAME;
    
    FZZRelationship * temp = NULL;
//    temp = addRelationship();
//    if ( temp != NULL ) {
//        temp->setId("rId1");
//        temp->setType(DOCUMENTXMLRELS_TYPE_SETTINGS);
//        temp->setTarget("settings.xml");
//    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId(getNexId());
        temp->setType(DOCUMENTXMLRELS_TYPE_STYLES);
        temp->setTarget("styles.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId(getNexId());
        temp->setType(DOCUMENTXMLRELS_TYPE_SETTINGS);
        temp->setTarget("settings.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId(getNexId());
        temp->setType(DOCUMENTXMLRELS_TYPE_WEBSETTINGS);
        temp->setTarget("webSettings.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId(getNexId());
        temp->setType(DOCUMENTXMLRELS_TYPE_FONTTABLE);
        temp->setTarget("fontTable.xml");
    }
    
    temp = addRelationship();
    if ( temp != NULL ) {
        temp->setId(getNexId());
        temp->setType(DOCUMENTXMLRELS_TYPE_THEME);
        temp->setTarget("theme/theme1.xml");
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels::FZZDocumentXMLRels(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZDocumentXMLRels");
    m_FileName = DOCUMENTXMLRELS_FILENAME;
    
    getRelationships();
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels::FZZDocumentXMLRels(const FZZDocumentXMLRels& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZDocumentXMLRels");
    if ( this == &obj ) {
        return;
    }
   
    m_id = obj.m_id;
    
    vector<FZZRelationship*>::const_iterator itr;
    for( itr = obj.m_RelationshipList.begin(); itr != obj.m_RelationshipList.end(); itr++ ) {
        FZZRelationship * temp = *itr;
        if ( temp != NULL ) {
            m_RelationshipList.push_back(new FZZRelationship(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZDocumentXMLRels::~FZZDocumentXMLRels()
{
    //DLOG("~FZZDocumentXMLRels()");
    FZZConst::delClassCount("FZZDocumentXMLRels");
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
vector<FZZRelationship *> * FZZDocumentXMLRels::getRelationships()
{
    int tempmaxid = 0;
    if ( m_RelationshipList.size() == 0 ) {
        string key;
        XMLElement* ele = getElement(&m_XmlnsList,m_ofd_Node,FZZRELATIONSHIP_Find_Key,FZZRELATIONSHIP_Name,key);
        
        while (ele != NULL) {
            const char* elename = ele->Name();
            if (strcmp(elename, key.c_str()) == 0) {
                FZZRelationship * temp = FZZRelationship::getInstance(this,m_doc, ele,(FZZRelationship*)NULL);
                if ( temp != NULL ) {
                    string strid = temp->getId();
                    size_t pos = strid.find("rId");
                    if ( pos != string::npos ) {
                        strid = strid.substr(pos+1);
                        int num = atoi(strid.c_str());
                        if ( tempmaxid < num ) {
                            tempmaxid = num;
                        }
                    }
                    m_RelationshipList.push_back(temp);
                }
            }

            ele = ele->NextSiblingElement();
        }
    }
    m_id = tempmaxid;
    return &m_RelationshipList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRelationship * FZZDocumentXMLRels::addRelationship()
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
string FZZDocumentXMLRels::getNexId()
{
    m_id++;
    return "rId"+FZZConst::fmt(m_id);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZDocumentXMLRels::getTarget(string Id)
{
    getRelationships();
    string retStr = "";
    vector<FZZRelationship *>::const_iterator defitr;
    for( defitr = m_RelationshipList.begin(); defitr != m_RelationshipList.end(); defitr++ ) {
        FZZRelationship * temp = *defitr;
        if ( temp != NULL ) {
            if ( temp->getId() == Id ) {
                retStr = temp->getTarget();
                break;
            }
        }
    }
    return retStr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZDocumentXMLRels::getTarget(string Type,vector<string> & idlist,vector<string> & targetlist)
{
    getRelationships();

    vector<FZZRelationship *>::const_iterator defitr;
    for( defitr = m_RelationshipList.begin(); defitr != m_RelationshipList.end(); defitr++ ) {
        FZZRelationship * temp = *defitr;
        if ( temp != NULL ) {
            if ( temp->getType() == Type ) {
                targetlist.push_back(temp->getTarget());
                idlist.push_back(temp->getId());
            }
        }
    }

}
//-----------------------------------------------------------------------------------------------------------------
