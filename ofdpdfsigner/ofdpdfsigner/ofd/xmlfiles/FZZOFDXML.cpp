//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML::FZZOFDXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDXML()");
    FZZConst::addClassCount("FZZOFDXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:OFD");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    ofd_Document->SetAttribute("DocType", "OFD");
    ofd_Document->SetAttribute("Version", OFD_VERSION);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML::FZZOFDXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDXML");
    m_FileName = FZZOFDXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML::FZZOFDXML(const FZZOFDXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDDocBody*>::const_iterator itr;
    for( itr = obj.m_FZZOFDDocBodys.begin(); itr != obj.m_FZZOFDDocBodys.end(); itr++ ) {
        FZZOFDDocBody * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDDocBodys.push_back(new FZZOFDDocBody(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML::~FZZOFDXML()
{
    //DLOG("~FZZOFDXML()");
    FZZConst::delClassCount("FZZOFDXML");
    
    vector<FZZOFDDocBody *>::const_iterator itr;
    for( itr = m_FZZOFDDocBodys.begin(); itr != m_FZZOFDDocBodys.end(); itr++ ) {
        FZZOFDDocBody * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDDocBodys.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDDocBody*>* FZZOFDXML::getDocBodys()
{
    getElementObjectList(&m_FZZOFDDocBodys,FZZOFDDOCBODY_Name);
    return &m_FZZOFDDocBodys;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody* FZZOFDXML::addDocBody()
{
    return addElementObject(&m_FZZOFDDocBodys,FZZOFDDOCBODY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXML::setDocType(string value)
{
    setAttribute_String("DocType",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXML::getDocType()
{
    return getAttribute_String("DocType");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDXML::setVersion(string value)
{
    setAttribute_String("Version",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDXML::getVersion()
{
    return getAttribute_String("Version");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody* FZZOFDXML::getDocBody_default()
{
    getDocBodys();
    if ( m_FZZOFDDocBodys.size() > 0 ) {
        return *(m_FZZOFDDocBodys.begin());
    } else {
        return NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
