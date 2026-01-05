//
//  Created by zizheng fan on 2023/04/12.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZHeaderXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZHeaderXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML::FZZHeaderXML() : FZZOfficeObject(),m_FZZWP(NULL),m_FZZWSdt(NULL)
{
    //DLOG("FZZDocumentXMLRels()");
    FZZConst::addClassCount("FZZHeaderXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:hdr");
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
    
    //m_FileName = DOCUMENTXMLRELS_FILENAME;
    
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML::FZZHeaderXML(XMLDocument * doc) : FZZOfficeObject(doc),m_FZZWP(NULL),m_FZZWSdt(NULL)
{
    FZZConst::addClassCount("FZZHeaderXML");
    //m_FileName = DOCUMENTXMLRELS_FILENAME;
    

}
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML::FZZHeaderXML(const FZZHeaderXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZHeaderXML");
    if ( this == &obj ) {
        return;
    }
   
    m_FZZWP = obj.m_FZZWP != NULL ? new FZZWP(*obj.m_FZZWP) : NULL;
    m_FZZWSdt = obj.m_FZZWSdt != NULL ? new FZZWSdt(*obj.m_FZZWSdt) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZHeaderXML::~FZZHeaderXML()
{
    //DLOG("~FZZHeaderXML()");
    FZZConst::delClassCount("FZZHeaderXML");
   
    if ( m_FZZWP != NULL ) {
        delete m_FZZWP;
        m_FZZWP = NULL;
    }
    if ( m_FZZWSdt != NULL ) {
        delete m_FZZWSdt;
        m_FZZWSdt = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZHeaderXML::setP()
{
    return m_FZZWP = setElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZHeaderXML::getP()
{
    return m_FZZWP = getElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt * FZZHeaderXML::setSdt()
{
    return m_FZZWSdt = setElementObject(m_FZZWSdt,FZZWSDT_Find_Key,FZZWSDT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt * FZZHeaderXML::getSdt()
{
    return m_FZZWSdt = getElementObject(m_FZZWSdt,FZZWSDT_Find_Key,FZZWSDT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
