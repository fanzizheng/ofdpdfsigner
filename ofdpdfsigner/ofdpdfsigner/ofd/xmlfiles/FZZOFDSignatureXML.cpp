//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDSignatureXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignatureXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML::FZZOFDSignatureXML() : FZZOFDXMLFileObject(),m_FZZOFDSignedValue(NULL),m_FZZOFDSignedInfo(NULL)
{
    //DLOG("FZZOFDSignatureXML()");
    FZZConst::addClassCount("FZZOFDSignatureXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Signature");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDSIGNATUREXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML::FZZOFDSignatureXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDSignedValue(NULL),m_FZZOFDSignedInfo(NULL)
{
    FZZConst::addClassCount("FZZOFDSignatureXML");
    m_FileName = FZZOFDSIGNATUREXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML::FZZOFDSignatureXML(const FZZOFDSignatureXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDSignatureXML");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDSignedValue = obj.m_FZZOFDSignedValue != NULL ? new FZZOFDSignedValue(*obj.m_FZZOFDSignedValue) : NULL;
    m_FZZOFDSignedInfo = obj.m_FZZOFDSignedInfo != NULL ? new FZZOFDSignedInfo(*obj.m_FZZOFDSignedInfo) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureXML::~FZZOFDSignatureXML()
{
    //DLOG("~FZZOFDSignatureXML()");
    FZZConst::delClassCount("FZZOFDSignatureXML");
    
    if ( m_FZZOFDSignedValue != NULL ) {
        delete m_FZZOFDSignedValue;
        m_FZZOFDSignedValue = NULL;
    }
    
    if ( m_FZZOFDSignedInfo != NULL ) {
        delete m_FZZOFDSignedInfo;
        m_FZZOFDSignedInfo = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue * FZZOFDSignatureXML::setSignedValue()
{
    return m_FZZOFDSignedValue = setElementObject(m_FZZOFDSignedValue,FZZOFDSIGNEDVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValue * FZZOFDSignatureXML::getSignedValue()
{
    return m_FZZOFDSignedValue = getElementObject(m_FZZOFDSignedValue,FZZOFDSIGNEDVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo * FZZOFDSignatureXML::setSignedInfo()
{
    return m_FZZOFDSignedInfo = setElementObject(m_FZZOFDSignedInfo,FZZOFDSIGNEDINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo * FZZOFDSignatureXML::getSignedInfo()
{
    return m_FZZOFDSignedInfo = getElementObject(m_FZZOFDSignedInfo,FZZOFDSIGNEDINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
