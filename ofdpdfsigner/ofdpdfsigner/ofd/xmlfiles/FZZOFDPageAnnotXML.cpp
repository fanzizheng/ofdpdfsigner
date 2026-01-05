//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDPageAnnotXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageAnnotXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML::FZZOFDPageAnnotXML() : FZZOFDXMLFileObject()
{
    //DLOG("FZZOFDPageAnnotXML()");
    FZZConst::addClassCount("FZZOFDPageAnnotXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:PageAnnot");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
 
    m_FileName = FZZOFDPAGEANNOTXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML::FZZOFDPageAnnotXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc)
{
    FZZConst::addClassCount("FZZOFDPageAnnotXML");
    m_FileName = FZZOFDPAGEANNOTXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML::FZZOFDPageAnnotXML(const FZZOFDPageAnnotXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDPageAnnotXML");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDAnnot_Annotation*>::const_iterator itr;
    for( itr = obj.m_FZZOFDAnnots.begin(); itr != obj.m_FZZOFDAnnots.end(); itr++ ) {
        FZZOFDAnnot_Annotation * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDAnnots.push_back(new FZZOFDAnnot_Annotation(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML::~FZZOFDPageAnnotXML()
{
    //DLOG("~FZZOFDPageAnnotXML()");
    FZZConst::delClassCount("FZZOFDPageAnnotXML");

    vector<FZZOFDAnnot_Annotation *>::const_iterator itr;
    for( itr = m_FZZOFDAnnots.begin(); itr != m_FZZOFDAnnots.end(); itr++ ) {
        FZZOFDAnnot_Annotation * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDAnnots.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDAnnot_Annotation*>* FZZOFDPageAnnotXML::getAnnotList()
{
    getElementObjectList(&m_FZZOFDAnnots,FZZOFDANNOT_ANNOTATION_Name);
    return &m_FZZOFDAnnots;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation* FZZOFDPageAnnotXML::addAnnot()
{
    return addElementObject(&m_FZZOFDAnnots,FZZOFDANNOT_ANNOTATION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
