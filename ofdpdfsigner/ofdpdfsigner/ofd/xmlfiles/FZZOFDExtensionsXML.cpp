//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDExtensionsXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDExtensionsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML::FZZOFDExtensionsXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDExtensionsXML()");
    FZZConst::addClassCount("FZZOFDExtensionsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Extensions");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDEXTENSIONSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML::FZZOFDExtensionsXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDExtensionsXML");
    m_FileName = FZZOFDEXTENSIONSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML::FZZOFDExtensionsXML(const FZZOFDExtensionsXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDExtensionsXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDExtension*>::const_iterator itr;
    for( itr = obj.m_FZZOFDExtensions.begin(); itr != obj.m_FZZOFDExtensions.end(); itr++ ) {
        FZZOFDExtension * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDExtensions.push_back(new FZZOFDExtension(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtensionsXML::~FZZOFDExtensionsXML()
{
    //DLOG("~FZZOFDExtensionsXML()");
    FZZConst::delClassCount("FZZOFDExtensionsXML");

    vector<FZZOFDExtension *>::const_iterator itr;
    for( itr = m_FZZOFDExtensions.begin(); itr != m_FZZOFDExtensions.end(); itr++ ) {
        FZZOFDExtension * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDExtensions.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDExtension*>* FZZOFDExtensionsXML::getExtensionList()
{
    getElementObjectList(&m_FZZOFDExtensions,FZZOFDEXTENSION_Name);
    return &m_FZZOFDExtensions;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension* FZZOFDExtensionsXML::addExtension()
{
    return addElementObject(&m_FZZOFDExtensions,FZZOFDEXTENSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
