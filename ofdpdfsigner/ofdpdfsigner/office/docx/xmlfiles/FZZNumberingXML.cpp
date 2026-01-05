//
//  Created by zizheng fan on 2023/04/09.
//
#include "basic/FZZConst.h"
#include "office/docx/xmlfiles/FZZNumberingXML.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZNumberingXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML::FZZNumberingXML() : FZZOfficeObject()
{
    //DLOG("FZZNumberingXML()");
    FZZConst::addClassCount("FZZNumberingXML");
    m_doc = new XMLDocument();
    m_doc->InsertEndChild(m_doc->NewDeclaration(XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("w:numbering");
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
    ofd_Document->SetAttribute(OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_NAME,OPENXMLFORMATS_MARKUP_COMPATIBILITY_2006_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2016_INK_NAME, MICROSOFT_OFFICE_DRAWING_2016_INK_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_NAME, MICROSOFT_OFFICE_DRAWING_2017_MODEL3D_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_OFFICE_NAME, MICROSOFT_OFFICE_OFFICE_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_RELATIONSHIPS_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_NAME, OPENXMLFORMATS_OFFICEDOCUMENT_2006_MATH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_VML_NAME, MICROSOFT_URN_VML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_NAME, MICROSOFT_OFFICE_WORD_2006_WORDPROCESSINGDRAWING_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_URN_OFFICE_WORD_NAME, MICROSOFT_URN_OFFICE_WORD_VALUE);
    ofd_Document->SetAttribute(OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_NAME, OPENXMLFORMATS_WORDPROCESSINGML_2006_MAIN_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDML_NAME, MICROSOFT_OFFICE_WORD_2010_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2012_WORDML_NAME, MICROSOFT_OFFICE_WORD_2012_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_CEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2016_WORDML_CID_NAME, MICROSOFT_OFFICE_WORD_2016_WORDML_CID_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2018_WORDML_NAME, MICROSOFT_OFFICE_WORD_2018_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_NAME, MICROSOFT_OFFICE_WORD_2020_WORDML_SDTDATAHASH_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_NAME, MICROSOFT_OFFICE_WORD_2015_WORDML_SYMEX_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGGROUP_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGINK_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2006_WORDML_NAME, MICROSOFT_OFFICE_WORD_2006_WORDML_VALUE);
    ofd_Document->SetAttribute(MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_NAME, MICROSOFT_OFFICE_WORD_2010_WORDPROCESSINGSHAPE_VALUE);
    ofd_Document->SetAttribute( MC_IGNORABLE_NAME, MC_IGNORABLE_VALUE);
    
    
    
    
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    InitXmlnsList();
    
    m_FileName = NUMBERINGXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML::FZZNumberingXML(XMLDocument * doc) : FZZOfficeObject(doc)
{
    FZZConst::addClassCount("FZZNumberingXML");
    m_FileName = NUMBERINGXML_FILENAME;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML::FZZNumberingXML(const FZZNumberingXML& obj) : FZZOfficeObject(obj)
{
    FZZConst::addClassCount("FZZNumberingXML");
    if ( this == &obj ) {
        return;
    }
   
    vector<FZZWNum*>::const_iterator itr;
    for( itr = obj.m_FZZWNumList.begin(); itr != obj.m_FZZWNumList.end(); itr++ ) {
        FZZWNum * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWNumList.push_back(new FZZWNum(*temp));
        }
    }
    
    vector<FZZWAbstractNum*>::const_iterator amitr;
    for( amitr = obj.m_FZZWAbstractNumList.begin(); amitr != obj.m_FZZWAbstractNumList.end(); amitr++ ) {
        FZZWAbstractNum * temp = *amitr;
        if ( temp != NULL ) {
            m_FZZWAbstractNumList.push_back(new FZZWAbstractNum(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberingXML::~FZZNumberingXML()
{
    //DLOG("~FZZNumberingXML()");
    FZZConst::delClassCount("FZZNumberingXML");
    
    vector<FZZWNum *>::const_iterator defitr;
    for( defitr = m_FZZWNumList.begin(); defitr != m_FZZWNumList.end(); defitr++ ) {
        FZZWNum * temp = *defitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWNumList.clear();
    
    vector<FZZWAbstractNum *>::const_iterator amlitr;
    for( amlitr = m_FZZWAbstractNumList.begin(); amlitr != m_FZZWAbstractNumList.end(); amlitr++ ) {
        FZZWAbstractNum * temp = *amlitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWAbstractNumList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWNum *> * FZZNumberingXML::getNumList()
{
    getElementObjectList(&m_FZZWNumList,FZZWNUM_Find_Key,FZZWNUM_Name);
    return &m_FZZWNumList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNum * FZZNumberingXML::addNum()
{
    return addElementObject(&m_FZZWNumList,FZZWNUM_Find_Key,FZZWNUM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWAbstractNum *> * FZZNumberingXML::getAbstractNumList()
{
    getElementObjectList(&m_FZZWAbstractNumList,FZZWABSTRACTNUM_Find_Key,FZZWABSTRACTNUM_Name);
    return &m_FZZWAbstractNumList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum * FZZNumberingXML::addAbstractNum()
{
    return addElementObject(&m_FZZWAbstractNumList,FZZWABSTRACTNUM_Find_Key,FZZWABSTRACTNUM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum * FZZNumberingXML::getAbstractNum(string numid)
{
    FZZWAbstractNum * retAbstractNum = NULL;
    getNumList();
    getAbstractNumList();
    if ( m_FZZWNumList.size() <= 0 || m_FZZWAbstractNumList.size() <= 0) {
        return retAbstractNum;
    }
    
    string abstractNumId = "";
    vector<FZZWNum *>::const_iterator numItr;
    for( numItr = m_FZZWNumList.begin(); numItr != m_FZZWNumList.end(); numItr++ ) {
        FZZWNum * tempNum = *numItr;
        if ( tempNum != NULL ) {
            string tempNumId = tempNum->getNumId();
            if ( tempNumId == numid ) {
                FZZWAbstractNumId * ctwAbstractNumId = tempNum->getAbstractNumId();
                if ( ctwAbstractNumId != NULL ) {
                    abstractNumId = ctwAbstractNumId->getVal();
                }
                break;
            }
        }//if( tempNum != NULL )
    }//for
    
    if ( abstractNumId.empty() ) {
        return retAbstractNum;
    }
    
    vector<FZZWAbstractNum *>::const_iterator abstractNumItr;
    for( abstractNumItr = m_FZZWAbstractNumList.begin(); abstractNumItr != m_FZZWAbstractNumList.end(); abstractNumItr++ ) {
        FZZWAbstractNum * tempAbstractNum = *abstractNumItr;
        if ( tempAbstractNum != NULL ) {
            string tempAbstractNumId = tempAbstractNum->getAbstractNumId();
            if ( tempAbstractNumId == abstractNumId ) {
                retAbstractNum = tempAbstractNum;
                break;
            }
        }//if ( tempAbstractNum != NULL )
    }//for
    
    return retAbstractNum;
}
//-----------------------------------------------------------------------------------------------------------------
