//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDDocumentXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocumentXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML::FZZOFDDocumentXML() : FZZOFDXMLFileObject(),m_FZZOFDDocument_Extensions(NULL),m_FZZOFDDocument_Attachments(NULL)
,m_FZZOFDDocument_CustomTags(NULL),m_FZZOFDDocument_Annotations(NULL),m_FZZOFDBookmarks(NULL),m_FZZOFDVPreferences(NULL)
,m_FZZOFDActions(NULL),m_FZZOFDPermission(NULL),m_FZZOFDOutlines(NULL),m_FZZOFDPages(NULL),m_FZZOFDCommonData(NULL)
{
    //DLOG("FZZOFDDocumentXML()");
    FZZConst::addClassCount("FZZOFDDocumentXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Document");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDDOCUMENTXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML::FZZOFDDocumentXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDDocument_Extensions(NULL),m_FZZOFDDocument_Attachments(NULL)
,m_FZZOFDDocument_CustomTags(NULL),m_FZZOFDDocument_Annotations(NULL),m_FZZOFDBookmarks(NULL),m_FZZOFDVPreferences(NULL),m_FZZOFDActions(NULL)
,m_FZZOFDPermission(NULL),m_FZZOFDOutlines(NULL),m_FZZOFDPages(NULL),m_FZZOFDCommonData(NULL)
{
    FZZConst::addClassCount("FZZOFDDocumentXML");
    m_FileName = FZZOFDDOCUMENTXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML::FZZOFDDocumentXML(const FZZOFDDocumentXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDDocumentXML");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDDocument_Extensions = obj.m_FZZOFDDocument_Extensions != NULL ? new FZZOFDDocument_Extensions(*obj.m_FZZOFDDocument_Extensions) : NULL;
    m_FZZOFDDocument_Attachments = obj.m_FZZOFDDocument_Attachments != NULL ? new FZZOFDDocument_Attachments(*obj.m_FZZOFDDocument_Attachments) : NULL;
    m_FZZOFDDocument_CustomTags = obj.m_FZZOFDDocument_CustomTags != NULL ? new FZZOFDDocument_CustomTags(*obj.m_FZZOFDDocument_CustomTags) : NULL;
    m_FZZOFDDocument_Annotations = obj.m_FZZOFDDocument_Annotations != NULL ? new FZZOFDDocument_Annotations(*obj.m_FZZOFDDocument_Annotations) : NULL;
    m_FZZOFDBookmarks = obj.m_FZZOFDBookmarks != NULL ? new FZZOFDBookmarks(*obj.m_FZZOFDBookmarks) : NULL;
    m_FZZOFDVPreferences = obj.m_FZZOFDVPreferences != NULL ? new FZZOFDVPreferences(*obj.m_FZZOFDVPreferences) : NULL;
    m_FZZOFDActions = obj.m_FZZOFDActions != NULL ? new FZZOFDActions(*obj.m_FZZOFDActions) : NULL;
    m_FZZOFDPermission = obj.m_FZZOFDPermission != NULL ? new FZZOFDPermission(*obj.m_FZZOFDPermission) : NULL;
    m_FZZOFDOutlines = obj.m_FZZOFDOutlines != NULL ? new FZZOFDOutlines(*obj.m_FZZOFDOutlines) : NULL;
    m_FZZOFDPages = obj.m_FZZOFDPages != NULL ? new FZZOFDPages(*obj.m_FZZOFDPages) : NULL;
    m_FZZOFDCommonData = obj.m_FZZOFDCommonData != NULL ? new FZZOFDCommonData(*obj.m_FZZOFDCommonData) : NULL;
//    vector<FZZOFDDocBody*>::const_iterator itr;
//    for( itr = obj.m_FZZOFDDocBodys.begin(); itr != obj.m_FZZOFDDocBodys.end(); itr++ ) {
//        FZZOFDDocBody * temp = *itr;
//        if ( temp != NULL ) {
//            m_FZZOFDDocBodys.push_back(new FZZOFDDocBody(*temp));
//        }
//    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML::~FZZOFDDocumentXML()
{
    //DLOG("~FZZOFDDocumentXML()");
    FZZConst::delClassCount("FZZOFDDocumentXML");
    if ( m_FZZOFDDocument_Extensions != NULL ) {
        delete m_FZZOFDDocument_Extensions;
        m_FZZOFDDocument_Extensions = NULL;
    }
    if ( m_FZZOFDDocument_Attachments != NULL ) {
        delete m_FZZOFDDocument_Attachments;
        m_FZZOFDDocument_Attachments = NULL;
    }
    if ( m_FZZOFDDocument_CustomTags != NULL ) {
        delete m_FZZOFDDocument_CustomTags;
        m_FZZOFDDocument_CustomTags = NULL;
    }
    if ( m_FZZOFDDocument_Annotations != NULL ) {
        delete m_FZZOFDDocument_Annotations;
        m_FZZOFDDocument_Annotations = NULL;
    }
    if ( m_FZZOFDBookmarks != NULL ) {
        delete m_FZZOFDBookmarks;
        m_FZZOFDBookmarks = NULL;
    }
    if ( m_FZZOFDVPreferences != NULL ) {
        delete m_FZZOFDVPreferences;
        m_FZZOFDVPreferences = NULL;
    }
    if ( m_FZZOFDActions != NULL ) {
        delete m_FZZOFDActions;
        m_FZZOFDActions = NULL;
    }
    if ( m_FZZOFDPermission != NULL ) {
        delete m_FZZOFDPermission;
        m_FZZOFDPermission = NULL;
    }
    if ( m_FZZOFDOutlines != NULL ) {
        delete m_FZZOFDOutlines;
        m_FZZOFDOutlines = NULL;
    }
    if ( m_FZZOFDPages != NULL ) {
        delete m_FZZOFDPages;
        m_FZZOFDPages = NULL;
    }
    if ( m_FZZOFDCommonData != NULL ) {
        delete m_FZZOFDCommonData;
        m_FZZOFDCommonData = NULL;
    }
//    vector<FZZOFDDocBody *>::const_iterator itr;
//    for( itr = m_FZZOFDDocBodys.begin(); itr != m_FZZOFDDocBodys.end(); itr++ ) {
//        FZZOFDDocBody * temp = *itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZOFDDocBodys.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions * FZZOFDDocumentXML::setExtensions()
{
    return m_FZZOFDDocument_Extensions = setElementObject(m_FZZOFDDocument_Extensions,FZZOFDDOCUMENT_EXTENSIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Extensions * FZZOFDDocumentXML::getExtensions()
{
    return m_FZZOFDDocument_Extensions = getElementObject(m_FZZOFDDocument_Extensions,FZZOFDDOCUMENT_EXTENSIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments * FZZOFDDocumentXML::setAttachments()
{
    return m_FZZOFDDocument_Attachments = setElementObject(m_FZZOFDDocument_Attachments,FZZOFDDOCUMENT_ATTACHMENTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Attachments * FZZOFDDocumentXML::getAttachments()
{
    return m_FZZOFDDocument_Attachments = getElementObject(m_FZZOFDDocument_Attachments,FZZOFDDOCUMENT_ATTACHMENTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags * FZZOFDDocumentXML::setCustomTags()
{
    return m_FZZOFDDocument_CustomTags = setElementObject(m_FZZOFDDocument_CustomTags,FZZOFDDOCUMENT_CUSTOMTAGS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_CustomTags * FZZOFDDocumentXML::getCustomTags()
{
    return m_FZZOFDDocument_CustomTags = getElementObject(m_FZZOFDDocument_CustomTags,FZZOFDDOCUMENT_CUSTOMTAGS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations * FZZOFDDocumentXML::setAnnotations()
{
    return m_FZZOFDDocument_Annotations = setElementObject(m_FZZOFDDocument_Annotations,FZZOFDDOCUMENT_ANNOTATIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocument_Annotations * FZZOFDDocumentXML::getAnnotations()
{
    return m_FZZOFDDocument_Annotations = getElementObject(m_FZZOFDDocument_Annotations,FZZOFDDOCUMENT_ANNOTATIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks * FZZOFDDocumentXML::setBookmarks()
{
    return m_FZZOFDBookmarks = setElementObject(m_FZZOFDBookmarks,FZZOFDBOOKMARKS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBookmarks * FZZOFDDocumentXML::getBookmarks()
{
    return m_FZZOFDBookmarks = getElementObject(m_FZZOFDBookmarks,FZZOFDBOOKMARKS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences * FZZOFDDocumentXML::setVPreferences()
{
    return m_FZZOFDVPreferences = setElementObject(m_FZZOFDVPreferences,FZZOFDVPREFERENCES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVPreferences * FZZOFDDocumentXML::getVPreferences()
{
    return m_FZZOFDVPreferences = getElementObject(m_FZZOFDVPreferences,FZZOFDVPREFERENCES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDDocumentXML::setActions()
{
    return m_FZZOFDActions = setElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDDocumentXML::getActions()
{
    return m_FZZOFDActions = getElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission * FZZOFDDocumentXML::setPermission()
{
    return m_FZZOFDPermission = setElementObject(m_FZZOFDPermission,FZZOFDPERMISSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPermission * FZZOFDDocumentXML::getPermission()
{
    return m_FZZOFDPermission = getElementObject(m_FZZOFDPermission,FZZOFDPERMISSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines * FZZOFDDocumentXML::setOutlines()
{
    return m_FZZOFDOutlines = setElementObject(m_FZZOFDOutlines,FZZOFDOUTLINES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines * FZZOFDDocumentXML::getOutlines()
{
    return m_FZZOFDOutlines = getElementObject(m_FZZOFDOutlines,FZZOFDOUTLINES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages * FZZOFDDocumentXML::setPages()
{
    return m_FZZOFDPages = setElementObject(m_FZZOFDPages,FZZOFDPAGES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPages * FZZOFDDocumentXML::getPages()
{
    return m_FZZOFDPages = getElementObject(m_FZZOFDPages,FZZOFDPAGES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData * FZZOFDDocumentXML::setCommonData()
{
    return m_FZZOFDCommonData = setElementObject(m_FZZOFDCommonData,FZZOFDCOMMONDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCommonData * FZZOFDDocumentXML::getCommonData()
{
    return m_FZZOFDCommonData = getElementObject(m_FZZOFDCommonData,FZZOFDCOMMONDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
