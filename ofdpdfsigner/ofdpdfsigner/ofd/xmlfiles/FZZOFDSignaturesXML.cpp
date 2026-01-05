//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDSignaturesXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignaturesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML::FZZOFDSignaturesXML() : FZZOFDXMLFileObject(),m_FZZOFDMaxSignId(NULL)
{
    //DLOG("FZZOFDSignaturesXML()");
    FZZConst::addClassCount("FZZOFDSignaturesXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Signatures");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDSIGNATURESXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML::FZZOFDSignaturesXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDMaxSignId(NULL)
{
    FZZConst::addClassCount("FZZOFDSignaturesXML");
    m_FileName = FZZOFDSIGNATURESXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML::FZZOFDSignaturesXML(const FZZOFDSignaturesXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDSignaturesXML");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDMaxSignId = obj.m_FZZOFDMaxSignId != NULL ? new FZZOFDMaxSignId(*obj.m_FZZOFDMaxSignId) : NULL;
    
    vector<FZZOFDSignature*>::const_iterator itr;
    for( itr = obj.m_FZZOFDSignatures.begin(); itr != obj.m_FZZOFDSignatures.end(); itr++ ) {
        FZZOFDSignature * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDSignatures.push_back(new FZZOFDSignature(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignaturesXML::~FZZOFDSignaturesXML()
{
    //DLOG("~FZZOFDSignaturesXML()");
    FZZConst::delClassCount("FZZOFDSignaturesXML");
    
    if ( m_FZZOFDMaxSignId != NULL ) {
        delete m_FZZOFDMaxSignId;
        m_FZZOFDMaxSignId = NULL;
    }

    vector<FZZOFDSignature *>::const_iterator itr;
    for( itr = m_FZZOFDSignatures.begin(); itr != m_FZZOFDSignatures.end(); itr++ ) {
        FZZOFDSignature * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDSignatures.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDSignature*>* FZZOFDSignaturesXML::getSignatureList()
{
    getElementObjectList(&m_FZZOFDSignatures,FZZOFDSIGNATURE_Name);
    return &m_FZZOFDSignatures;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignature* FZZOFDSignaturesXML::addSignature()
{
    return addElementObject(&m_FZZOFDSignatures,FZZOFDSIGNATURE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId * FZZOFDSignaturesXML::setMaxSignId()
{
    return m_FZZOFDMaxSignId = setElementObject(m_FZZOFDMaxSignId,FZZOFDMAXSIGNID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMaxSignId * FZZOFDSignaturesXML::getMaxSignId()
{
    return m_FZZOFDMaxSignId = getElementObject(m_FZZOFDMaxSignId,FZZOFDMAXSIGNID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
