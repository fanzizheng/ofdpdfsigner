//
//  Created by zizheng fan on 2024/10/16.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDEntriesMapXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEntriesMapXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapXML::FZZOFDEntriesMapXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDEntriesMapXML()");
    FZZConst::addClassCount("FZZOFDEntriesMapXML");
    m_doc = new XMLDocument();
    if ( m_doc == NULL ) {
        return;
    }
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:EncryptedEntries");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
 
    //m_FileName = FZZOFDENTRIESMAPXML_FILENAME;
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapXML::FZZOFDEntriesMapXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDEntriesMapXML");
    //m_FileName = FZZOFDENTRIESMAPXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapXML::FZZOFDEntriesMapXML(const FZZOFDEntriesMapXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDEntriesMapXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDEncryptEntry*>::const_iterator itr;
    for( itr = obj.m_FZZOFDEncryptEntrys.begin(); itr != obj.m_FZZOFDEncryptEntrys.end(); itr++ ) {
        FZZOFDEncryptEntry * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDEncryptEntrys.push_back(new FZZOFDEncryptEntry(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapXML::~FZZOFDEntriesMapXML()
{
    //DLOG("~FZZOFDEntriesMapXML()");
    FZZConst::delClassCount("FZZOFDEntriesMapXML");

    vector<FZZOFDEncryptEntry *>::const_iterator itr;
    for( itr = m_FZZOFDEncryptEntrys.begin(); itr != m_FZZOFDEncryptEntrys.end(); itr++ ) {
        FZZOFDEncryptEntry * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDEncryptEntrys.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesMapXML::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesMapXML::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDEncryptEntry*>* FZZOFDEntriesMapXML::getEncryptEntryList()
{
    getElementObjectList(&m_FZZOFDEncryptEntrys,FZZOFDENCRYPTENTRY_Name);
    return &m_FZZOFDEncryptEntrys;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptEntry* FZZOFDEntriesMapXML::addEncryptEntry()
{
    return addElementObject(&m_FZZOFDEncryptEntrys,FZZOFDENCRYPTENTRY_Name);
}
//-----------------------------------------------------------------------------------------------------------------

