//
//  Created by zizheng fan on 2024/10/16.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDEncryptionsXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncryptionsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML::FZZOFDEncryptionsXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDEncryptionsXML()");
    FZZConst::addClassCount("FZZOFDEncryptionsXML");
    m_doc = new XMLDocument();
    if ( m_doc == NULL ) {
        return;
    }
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Encryptions");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
 
    m_FileName = FZZOFDENCRYPTIONSXML_FILENAME;
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML::FZZOFDEncryptionsXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDEncryptionsXML");
    m_FileName = FZZOFDENCRYPTIONSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML::FZZOFDEncryptionsXML(const FZZOFDEncryptionsXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDEncryptionsXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDEncryptInfo*>::const_iterator itr;
    for( itr = obj.m_FZZOFDEncryptInfos.begin(); itr != obj.m_FZZOFDEncryptInfos.end(); itr++ ) {
        FZZOFDEncryptInfo * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDEncryptInfos.push_back(new FZZOFDEncryptInfo(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptionsXML::~FZZOFDEncryptionsXML()
{
    //DLOG("~FZZOFDEncryptionsXML()");
    FZZConst::delClassCount("FZZOFDEncryptionsXML");

    vector<FZZOFDEncryptInfo *>::const_iterator itr;
    for( itr = m_FZZOFDEncryptInfos.begin(); itr != m_FZZOFDEncryptInfos.end(); itr++ ) {
        FZZOFDEncryptInfo * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDEncryptInfos.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDEncryptInfo*>* FZZOFDEncryptionsXML::getEncryptInfoList()
{
    getElementObjectList(&m_FZZOFDEncryptInfos,FZZOFDENCRYPTINFO_Name);
    return &m_FZZOFDEncryptInfos;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo* FZZOFDEncryptionsXML::addEncryptInfo()
{
    return addElementObject(&m_FZZOFDEncryptInfos,FZZOFDENCRYPTINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------

