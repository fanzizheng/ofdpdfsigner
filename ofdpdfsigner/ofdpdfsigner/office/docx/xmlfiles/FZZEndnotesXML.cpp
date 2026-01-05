//
//  Created by zizheng fan on 2023/04/10.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZEndnotesXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZEndnotesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZEndnotesXML::FZZEndnotesXML() : FZZOfficeObject()
{
    //DLOG("FZZEndnotesXML()");
    FZZConst::addClassCount("FZZEndnotesXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:endnotes");
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
    
    m_FileName = ENDNOTESXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZEndnotesXML::FZZEndnotesXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZEndnotesXML");
    m_FileName = ENDNOTESXML_FILENAME;
    

}
//-----------------------------------------------------------------------------------------------------------------
FZZEndnotesXML::FZZEndnotesXML(const FZZEndnotesXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZEndnotesXML");
    if ( this == &obj ) {
        return;
    }
   
    vector<FZZWEndnote*>::const_iterator itr;
    for( itr = obj.m_FZZWEndnoteList.begin(); itr != obj.m_FZZWEndnoteList.end(); itr++ ) {
        FZZWEndnote * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWEndnoteList.push_back(new FZZWEndnote(*temp));
        }
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZEndnotesXML::~FZZEndnotesXML()
{
    //DLOG("~FZZEndnotesXML()");
    FZZConst::delClassCount("FZZEndnotesXML");
   
    vector<FZZWEndnote *>::const_iterator defitr;
    for( defitr = m_FZZWEndnoteList.begin(); defitr != m_FZZWEndnoteList.end(); defitr++ ) {
        FZZWEndnote * temp = *defitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWEndnoteList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWEndnote *> * FZZEndnotesXML::getEndnoteList()
{
    getElementObjectList(&m_FZZWEndnoteList,FZZWENDNOTE_Find_Key,FZZWENDNOTE_Name);
    return &m_FZZWEndnoteList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWEndnote * FZZEndnotesXML::addEndnote()
{
    return addElementObject(&m_FZZWEndnoteList,FZZWENDNOTE_Find_Key,FZZWENDNOTE_Name);
}
//-----------------------------------------------------------------------------------------------------------------



