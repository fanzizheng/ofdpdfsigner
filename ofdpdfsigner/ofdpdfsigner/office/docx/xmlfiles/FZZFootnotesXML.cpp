//
//  Created by zizheng fan on 2023/04/11.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZFootnotesXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZFootnotesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZFootnotesXML::FZZFootnotesXML() : FZZOfficeObject()
{
    //DLOG("FZZFootnotesXML()");
    FZZConst::addClassCount("FZZFootnotesXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:footnotes");
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGCANVAS_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGCANVAS_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2014_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2014_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2015_9_8_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2015_9_8_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2015_10_21_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2015_10_21_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_9_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_9_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_10_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_10_CHARTEX_VALUE);
    
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_11_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_11_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_12_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_12_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_13_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_13_CHARTEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_5_14_CHARTEX_NAME, MICROSOFT_OFFICE_DRAWING_2016_5_14_CHARTEX_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME, OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_DRAWING_2016_INK_NAME, MICROSOFT_OFFICE_DRAWING_2016_INK_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_NAME, MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_OFFICE_NAME, MICROSOFT_OFFICE_OFFICE_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_2019_EXTLST_NAME, MICROSOFT_OFFICE_2019_EXTLST_VALUE);
    ofd_Document->SetAttribute( OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute( OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_URN_VML_NAME, MICROSOFT_URN_VML_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_URN_OFFICE_WORD_NAME, MICROSOFT_URN_OFFICE_WORD_VALUE);
    ofd_Document->SetAttribute( OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2023_WORDML_WORD16DU_NAME, MICROSOFT_OFFICE_WORD_2023_WORDML_WORD16DU_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2006_WORDML_NAME, MICROSOFT_OFFICE_WORD_2006_WORDML_VALUE);
    ofd_Document->SetAttribute( MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_VALUE);
    ofd_Document->SetAttribute( MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE);
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = FOOTNOTESXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZFootnotesXML::FZZFootnotesXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZFootnotesXML");
    m_FileName = FOOTNOTESXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZFootnotesXML::FZZFootnotesXML(const FZZFootnotesXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZFootnotesXML");
    if ( this == &obj ) {
        return;
    }
   
    vector<FZZWFootnote*>::const_iterator itr;
    for( itr = obj.m_FZZWFootnoteList.begin(); itr != obj.m_FZZWFootnoteList.end(); itr++ ) {
        FZZWFootnote * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWFootnoteList.push_back(new FZZWFootnote(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZFootnotesXML::~FZZFootnotesXML()
{
    //DLOG("~FZZFootnotesXML()");
    FZZConst::delClassCount("FZZFootnotesXML");
    
    vector<FZZWFootnote *>::const_iterator defitr;
    for( defitr = m_FZZWFootnoteList.begin(); defitr != m_FZZWFootnoteList.end(); defitr++ ) {
        FZZWFootnote * temp = *defitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWFootnoteList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWFootnote *> * FZZFootnotesXML::getFootnoteList()
{
    getElementObjectList(&m_FZZWFootnoteList,FZZWFOOTNOTE_Find_Key,FZZWFOOTNOTE_Name);
    return &m_FZZWFootnoteList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFootnote * FZZFootnotesXML::addFootnote()
{
    return addElementObject(&m_FZZWFootnoteList,FZZWFOOTNOTE_Find_Key,FZZWFOOTNOTE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
