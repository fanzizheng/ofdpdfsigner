//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDAnnotationsXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAnnotationsXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotationsXML::FZZOFDAnnotationsXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDAnnotationsXML()");
    FZZConst::addClassCount("FZZOFDAnnotationsXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:Annotations");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDANNOTATIONSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotationsXML::FZZOFDAnnotationsXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDAnnotationsXML");
    m_FileName = FZZOFDANNOTATIONSXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotationsXML::FZZOFDAnnotationsXML(const FZZOFDAnnotationsXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDAnnotationsXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDAnnPage*>::const_iterator itr;
    for( itr = obj.m_FZZOFDAnnPages.begin(); itr != obj.m_FZZOFDAnnPages.end(); itr++ ) {
        FZZOFDAnnPage * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDAnnPages.push_back(new FZZOFDAnnPage(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotationsXML::~FZZOFDAnnotationsXML()
{
    //DLOG("~FZZOFDAnnotationsXML()");
    FZZConst::delClassCount("FZZOFDAnnotationsXML");

    vector<FZZOFDAnnPage *>::const_iterator itr;
    for( itr = m_FZZOFDAnnPages.begin(); itr != m_FZZOFDAnnPages.end(); itr++ ) {
        FZZOFDAnnPage * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDAnnPages.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDAnnPage*>* FZZOFDAnnotationsXML::getPageList()
{
    getElementObjectList(&m_FZZOFDAnnPages,FZZOFDANNPAGE_Name);
    return &m_FZZOFDAnnPages;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnPage* FZZOFDAnnotationsXML::addPage()
{
    return addElementObject(&m_FZZOFDAnnPages,FZZOFDANNPAGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
