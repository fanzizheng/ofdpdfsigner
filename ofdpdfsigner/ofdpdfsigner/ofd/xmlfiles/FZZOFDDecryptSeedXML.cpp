//
//  Created by zizheng fan on 2024/10/16.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDDecryptSeedXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDecryptSeedXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedXML::FZZOFDDecryptSeedXML() : FZZOFDXMLFileObject(),m_FZZOFDExtendParams(NULL)
{
    //DLOG("FZZOFDDecryptSeedXML()");
    FZZConst::addClassCount("FZZOFDDecryptSeedXML");
    m_doc = new XMLDocument();
    if ( m_doc == NULL ) {
        return;
    }
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:DecyptSeed");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
 
    //m_FileName = FZZOFDDECRYPTSEEDXML_FILENAME;
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedXML::FZZOFDDecryptSeedXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDExtendParams(NULL)
{
    FZZConst::addClassCount("FZZOFDDecryptSeedXML");
    //m_FileName = FZZOFDDECRYPTSEEDXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedXML::FZZOFDDecryptSeedXML(const FZZOFDDecryptSeedXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDDecryptSeedXML");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDExtendParams = obj.m_FZZOFDExtendParams != NULL ? new FZZOFDExtendParams(*obj.m_FZZOFDExtendParams) : NULL;
   
    
    vector<FZZOFDUserInfo*>::const_iterator itr;
    for( itr = obj.m_FZZOFDUserInfos.begin(); itr != obj.m_FZZOFDUserInfos.end(); itr++ ) {
        FZZOFDUserInfo * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDUserInfos.push_back(new FZZOFDUserInfo(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedXML::~FZZOFDDecryptSeedXML()
{
    //DLOG("~FZZOFDDecryptSeedXML()");
    FZZConst::delClassCount("FZZOFDDecryptSeedXML");

    if ( m_FZZOFDExtendParams != NULL ) {
        delete m_FZZOFDExtendParams;
        m_FZZOFDExtendParams = NULL;
    }
    vector<FZZOFDUserInfo *>::const_iterator itr;
    for( itr = m_FZZOFDUserInfos.begin(); itr != m_FZZOFDUserInfos.end(); itr++ ) {
        FZZOFDUserInfo * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDUserInfos.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDecryptSeedXML::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDecryptSeedXML::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDecryptSeedXML::setEncryptCaseId(string value)
{
    setAttribute_String("EncryptCaseId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDecryptSeedXML::getEncryptCaseId()
{
    return getAttribute_String("EncryptCaseId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams * FZZOFDDecryptSeedXML::setExtendParams()
{
    return m_FZZOFDExtendParams = setElementObject(m_FZZOFDExtendParams,FZZOFDEXTENDPARAMS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams * FZZOFDDecryptSeedXML::getExtendParams()
{
    return m_FZZOFDExtendParams = getElementObject(m_FZZOFDExtendParams,FZZOFDEXTENDPARAMS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDUserInfo*>* FZZOFDDecryptSeedXML::getUserInfoList()
{
    getElementObjectList(&m_FZZOFDUserInfos,FZZOFDUSERINFO_Name);
    return &m_FZZOFDUserInfos;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserInfo* FZZOFDDecryptSeedXML::addUserInfo()
{
    return addElementObject(&m_FZZOFDUserInfos,FZZOFDUSERINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
