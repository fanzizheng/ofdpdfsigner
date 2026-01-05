//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDCustomTagsXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCustomTagsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML::FZZOFDCustomTagsXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDCustomTagsXML()");
    FZZConst::addClassCount("FZZOFDCustomTagsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:CustomTags");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDCUSTOMTAGSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML::FZZOFDCustomTagsXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDCustomTagsXML");
    m_FileName = FZZOFDCUSTOMTAGSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML::FZZOFDCustomTagsXML(const FZZOFDCustomTagsXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDCustomTagsXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDCustomTag*>::const_iterator itr;
    for( itr = obj.m_FZZOFDCustomTags.begin(); itr != obj.m_FZZOFDCustomTags.end(); itr++ ) {
        FZZOFDCustomTag * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDCustomTags.push_back(new FZZOFDCustomTag(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTagsXML::~FZZOFDCustomTagsXML()
{
    //DLOG("~FZZOFDCustomTagsXML()");
    FZZConst::delClassCount("FZZOFDCustomTagsXML");

    vector<FZZOFDCustomTag *>::const_iterator itr;
    for( itr = m_FZZOFDCustomTags.begin(); itr != m_FZZOFDCustomTags.end(); itr++ ) {
        FZZOFDCustomTag * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDCustomTags.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag * FZZOFDCustomTagsXML::addCustomTag()
{
    return addElementObject(&m_FZZOFDCustomTags,FZZOFDCUSTOMTAG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDCustomTag*> * FZZOFDCustomTagsXML::getCustomTagList()
{
    getElementObjectList(&m_FZZOFDCustomTags,FZZOFDCUSTOMTAG_Name);
    return &m_FZZOFDCustomTags;
}
//-----------------------------------------------------------------------------------------------------------------
