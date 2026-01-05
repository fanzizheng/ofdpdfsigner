//
//  Created by zizheng fan on 2023/10/25
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSectPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSectPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr::FZZWSectPr() : FZZXMLElementObject(),m_FZZWDocGrid(NULL),m_FZZWCols(NULL),m_FZZWPgMar(NULL),m_FZZWPgSz(NULL),m_FZZWTitlePg(NULL)
{
    //DLOG("FZZWSectPr()");
    FZZConst::addClassCount("FZZWSectPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr::FZZWSectPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWDocGrid(NULL),m_FZZWCols(NULL),m_FZZWPgMar(NULL),m_FZZWPgSz(NULL),m_FZZWTitlePg(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSectPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr::FZZWSectPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWDocGrid(NULL),m_FZZWCols(NULL),m_FZZWPgMar(NULL),m_FZZWPgSz(NULL),m_FZZWTitlePg(NULL)
{
    FZZConst::addClassCount("FZZWSectPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr::FZZWSectPr(const FZZWSectPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSectPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWDocGrid = obj.m_FZZWDocGrid != NULL ? new FZZWDocGrid(*obj.m_FZZWDocGrid) : NULL;
    m_FZZWCols = obj.m_FZZWCols != NULL ? new FZZWCols(*obj.m_FZZWCols) : NULL;
    m_FZZWPgMar = obj.m_FZZWPgMar != NULL ? new FZZWPgMar(*obj.m_FZZWPgMar) : NULL;
    m_FZZWPgSz = obj.m_FZZWPgSz != NULL ? new FZZWPgSz(*obj.m_FZZWPgSz) : NULL;
    m_FZZWTitlePg = obj.m_FZZWTitlePg != NULL ? new FZZWTitlePg(*obj.m_FZZWTitlePg) : NULL;
    
    vector<FZZWFooterReference*>::const_iterator footer_itr;
    for( footer_itr = obj.m_FZZWFooterReferences.begin(); footer_itr != obj.m_FZZWFooterReferences.end(); footer_itr++ ) {
        FZZWFooterReference * temp = *footer_itr;
        if ( temp != NULL ) {
            m_FZZWFooterReferences.push_back(new FZZWFooterReference(*temp));
        }
    }
    
    vector<FZZWHeaderReference*>::const_iterator header_itr;
    for( header_itr = obj.m_FZZWHeaderReferences.begin(); header_itr != obj.m_FZZWHeaderReferences.end(); header_itr++ ) {
        FZZWHeaderReference * temp = *header_itr;
        if ( temp != NULL ) {
            m_FZZWHeaderReferences.push_back(new FZZWHeaderReference(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr::~FZZWSectPr()
{
    //DLOG("~FZZWSectPr()");
    FZZConst::delClassCount("FZZWSectPr");
    if ( m_FZZWDocGrid != NULL ) {
        delete m_FZZWDocGrid;
        m_FZZWDocGrid = NULL;
    }
    if ( m_FZZWCols != NULL ) {
        delete m_FZZWCols;
        m_FZZWCols = NULL;
    }
    if ( m_FZZWPgMar != NULL ) {
        delete m_FZZWPgMar;
        m_FZZWPgMar = NULL;
    }
    if ( m_FZZWPgSz != NULL ) {
        delete m_FZZWPgSz;
        m_FZZWPgSz = NULL;
    }
    if ( m_FZZWTitlePg != NULL ) {
        delete m_FZZWTitlePg;
        m_FZZWTitlePg = NULL;
    }
    
    vector<FZZWFooterReference*>::const_iterator footer_itr;
    for( footer_itr = m_FZZWFooterReferences.begin(); footer_itr != m_FZZWFooterReferences.end(); footer_itr++ ) {
        FZZWFooterReference * temp = *footer_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWFooterReferences.clear();
    
    vector<FZZWHeaderReference*>::const_iterator header_itr;
    for( header_itr = m_FZZWHeaderReferences.begin(); header_itr != m_FZZWHeaderReferences.end(); header_itr++ ) {
        FZZWHeaderReference * temp = *header_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWHeaderReferences.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSectPr::setRsidR(string value)
{
    setAttribute_String("w:rsidR",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSectPr::getRsidR()
{
    return getAttribute_String("w:rsidR");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid * FZZWSectPr::setDocGrid()
{
    return m_FZZWDocGrid = setElementObject(m_FZZWDocGrid,FZZWDOCGRID_Find_Key,FZZWDOCGRID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid * FZZWSectPr::getDocGrid()
{
    return m_FZZWDocGrid = getElementObject(m_FZZWDocGrid,FZZWDOCGRID_Find_Key,FZZWDOCGRID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols * FZZWSectPr::setCols()
{
    return m_FZZWCols = setElementObject(m_FZZWCols,FZZWCOLS_Find_Key,FZZWCOLS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols * FZZWSectPr::getCols()
{
    return m_FZZWCols = getElementObject(m_FZZWCols,FZZWCOLS_Find_Key,FZZWCOLS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar * FZZWSectPr::setPgMar()
{
    return m_FZZWPgMar = setElementObject(m_FZZWPgMar,FZZWPGMAR_Find_Key,FZZWPGMAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgMar * FZZWSectPr::getPgMar()
{
    return m_FZZWPgMar = getElementObject(m_FZZWPgMar,FZZWPGMAR_Find_Key,FZZWPGMAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz * FZZWSectPr::setPgSz()
{
    return m_FZZWPgSz = setElementObject(m_FZZWPgSz,FZZWPGSZ_Find_Key,FZZWPGSZ_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPgSz * FZZWSectPr::getPgSz()
{
    return m_FZZWPgSz = getElementObject(m_FZZWPgSz,FZZWPGSZ_Find_Key,FZZWPGSZ_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFooterReference * FZZWSectPr::addFooterReference()
{
    return addElementObject(&m_FZZWFooterReferences,FZZWFOOTERREFERENCE_Find_Key,FZZWFOOTERREFERENCE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWFooterReference*> * FZZWSectPr::getFooterReferences()
{
    getElementObjectList(&m_FZZWFooterReferences,FZZWFOOTERREFERENCE_Find_Key,FZZWFOOTERREFERENCE_Name);
    return &m_FZZWFooterReferences;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHeaderReference * FZZWSectPr::addHeaderReference()
{
    return addElementObject(&m_FZZWHeaderReferences,FZZWHEADERREFERENCE_Find_Key,FZZWHEADERREFERENCE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWHeaderReference*> * FZZWSectPr::getHeaderReferences()
{
    getElementObjectList(&m_FZZWHeaderReferences,FZZWHEADERREFERENCE_Find_Key,FZZWHEADERREFERENCE_Name);
    return &m_FZZWHeaderReferences;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg * FZZWSectPr::setTitlePg()
{
    return m_FZZWTitlePg = setElementObject(m_FZZWTitlePg,FZZWTITLEPG_Find_Key,FZZWTITLEPG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTitlePg * FZZWSectPr::getTitlePg()
{
    return m_FZZWTitlePg = getElementObject(m_FZZWTitlePg,FZZWTITLEPG_Find_Key,FZZWTITLEPG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
