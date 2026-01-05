//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDAttachmentsXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAttachmentsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML::FZZOFDAttachmentsXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDAttachmentsXML()");
    FZZConst::addClassCount("FZZOFDAttachmentsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Attachments");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDATTACHMENTSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML::FZZOFDAttachmentsXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDAttachmentsXML");
    m_FileName = FZZOFDATTACHMENTSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML::FZZOFDAttachmentsXML(const FZZOFDAttachmentsXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDAttachmentsXML");
    if ( this == &obj ) {
        return;
    }
    //m_FZZOFDDocument_Extensions = obj.m_FZZOFDDocument_Extensions != NULL ? new FZZOFDDocument_Extensions(*obj.m_FZZOFDDocument_Extensions) : NULL;
    vector<FZZOFDAttachment*>::const_iterator itr;
    for( itr = obj.m_FZZOFDAttachments.begin(); itr != obj.m_FZZOFDAttachments.end(); itr++ ) {
        FZZOFDAttachment * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDAttachments.push_back(new FZZOFDAttachment(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachmentsXML::~FZZOFDAttachmentsXML()
{
    //DLOG("~FZZOFDAttachmentsXML()");
    FZZConst::delClassCount("FZZOFDAttachmentsXML");
//    if ( m_FZZOFDDocument_Extensions != NULL ) {
//        delete m_FZZOFDDocument_Extensions;
//        m_FZZOFDDocument_Extensions = NULL;
//    }
    vector<FZZOFDAttachment *>::const_iterator itr;
    for( itr = m_FZZOFDAttachments.begin(); itr != m_FZZOFDAttachments.end(); itr++ ) {
        FZZOFDAttachment * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDAttachments.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDAttachment*>* FZZOFDAttachmentsXML::getAttachmentList()
{
    getElementObjectList(&m_FZZOFDAttachments,FZZOFDATTACHMENT_Name);
    return &m_FZZOFDAttachments;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment* FZZOFDAttachmentsXML::addAttachment()
{
    return addElementObject(&m_FZZOFDAttachments,FZZOFDATTACHMENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
