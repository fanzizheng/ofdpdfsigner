//
//  Created by zizheng fan on 2023/10/19
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr::FZZWTblPr() : FZZXMLElementObject(),m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL),m_FZZWTblStyle(NULL),m_FZZWTblW(NULL),m_FZZWTblLook(NULL),m_FZZWTblBorders(NULL),m_FZZWJc(NULL),m_FZZWTblpPr(NULL),m_FZZWTblOverlap(NULL),m_FZZWTblLayout(NULL),m_FZZWTblCellSpacing(NULL)
{
    //DLOG("FZZWTblPr()");
    FZZConst::addClassCount("FZZWTblPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr::FZZWTblPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL),m_FZZWTblStyle(NULL),m_FZZWTblW(NULL),m_FZZWTblLook(NULL),m_FZZWTblBorders(NULL),m_FZZWJc(NULL),m_FZZWTblpPr(NULL),m_FZZWTblOverlap(NULL),m_FZZWTblLayout(NULL),m_FZZWTblCellSpacing(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr::FZZWTblPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTblInd(NULL),m_FZZWTblCellMar(NULL),m_FZZWTblStyle(NULL),m_FZZWTblW(NULL),m_FZZWTblLook(NULL),m_FZZWTblBorders(NULL),m_FZZWJc(NULL),m_FZZWTblpPr(NULL),m_FZZWTblOverlap(NULL),m_FZZWTblLayout(NULL),m_FZZWTblCellSpacing(NULL)
{
    FZZConst::addClassCount("FZZWTblPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr::FZZWTblPr(const FZZWTblPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTblInd = obj.m_FZZWTblInd != NULL ? new FZZWTblInd(*obj.m_FZZWTblInd) : NULL;
    m_FZZWTblCellMar = obj.m_FZZWTblCellMar != NULL ? new FZZWTblCellMar(*obj.m_FZZWTblCellMar) : NULL;
    m_FZZWTblStyle = obj.m_FZZWTblStyle != NULL ? new FZZWTblStyle(*obj.m_FZZWTblStyle) : NULL;
    m_FZZWTblW = obj.m_FZZWTblW != NULL ? new FZZWTblW(*obj.m_FZZWTblW) : NULL;
    m_FZZWTblLook = obj.m_FZZWTblLook != NULL ? new FZZWTblLook(*obj.m_FZZWTblLook) : NULL;
    m_FZZWTblBorders = obj.m_FZZWTblBorders != NULL ? new FZZWTblBorders(*obj.m_FZZWTblBorders) : NULL;
    m_FZZWJc = obj.m_FZZWJc != NULL ? new FZZWJc(*obj.m_FZZWJc) : NULL;
    m_FZZWTblpPr = obj.m_FZZWTblpPr != NULL ? new FZZWTblpPr(*obj.m_FZZWTblpPr) : NULL;
    m_FZZWTblOverlap = obj.m_FZZWTblOverlap != NULL ? new FZZWTblOverlap(*obj.m_FZZWTblOverlap) : NULL;
    m_FZZWTblLayout = obj.m_FZZWTblLayout != NULL ? new FZZWTblLayout(*obj.m_FZZWTblLayout) : NULL;
    m_FZZWTblCellSpacing = obj.m_FZZWTblCellSpacing != NULL ? new FZZWTblCellSpacing(*obj.m_FZZWTblCellSpacing) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr::~FZZWTblPr()
{
    //DLOG("~FZZWTblPr()");
    FZZConst::delClassCount("FZZWTblPr");
    
    
    if ( m_FZZWTblInd != NULL ) {
        delete m_FZZWTblInd;
        m_FZZWTblInd = NULL;
    }
    if ( m_FZZWTblCellMar != NULL ) {
        delete m_FZZWTblCellMar;
        m_FZZWTblCellMar = NULL;
    }
    if ( m_FZZWTblStyle != NULL ) {
        delete m_FZZWTblStyle;
        m_FZZWTblStyle = NULL;
    }
    if ( m_FZZWTblW != NULL ) {
        delete m_FZZWTblW;
        m_FZZWTblW = NULL;
    }
    if ( m_FZZWTblLook != NULL ) {
        delete m_FZZWTblLook;
        m_FZZWTblLook = NULL;
    }
    if ( m_FZZWTblBorders != NULL ) {
        delete m_FZZWTblBorders;
        m_FZZWTblBorders = NULL;
    }
    if ( m_FZZWJc != NULL ) {
        delete m_FZZWJc;
        m_FZZWJc = NULL;
    }
    if ( m_FZZWTblpPr != NULL ) {
        delete m_FZZWTblpPr;
        m_FZZWTblpPr = NULL;
    }
    if ( m_FZZWTblOverlap != NULL ) {
        delete m_FZZWTblOverlap;
        m_FZZWTblOverlap = NULL;
    }
    if ( m_FZZWTblLayout != NULL ) {
        delete m_FZZWTblLayout;
        m_FZZWTblLayout = NULL;
    }
    if ( m_FZZWTblCellSpacing != NULL ) {
        delete m_FZZWTblCellSpacing;
        m_FZZWTblCellSpacing = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd * FZZWTblPr::setTblInd()
{
    return m_FZZWTblInd = setElementObject(m_FZZWTblInd,FZZWTBLIND_Find_Key,FZZWTBLIND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd * FZZWTblPr::getTblInd()
{
    return m_FZZWTblInd = getElementObject(m_FZZWTblInd,FZZWTBLIND_Find_Key,FZZWTBLIND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar * FZZWTblPr::setTblCellMar()
{
    return m_FZZWTblCellMar = setElementObject(m_FZZWTblCellMar,FZZWTBLCELLMAR_Find_Key,FZZWTBLCELLMAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar * FZZWTblPr::getTblCellMar()
{
    return m_FZZWTblCellMar = getElementObject(m_FZZWTblCellMar,FZZWTBLCELLMAR_Find_Key,FZZWTBLCELLMAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle * FZZWTblPr::setTblStyle()
{
    return m_FZZWTblStyle = setElementObject(m_FZZWTblStyle,FZZWTBLSTYLE_Find_Key,FZZWTBLSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStyle * FZZWTblPr::getTblStyle()
{
    return m_FZZWTblStyle = getElementObject(m_FZZWTblStyle,FZZWTBLSTYLE_Find_Key,FZZWTBLSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW * FZZWTblPr::setTblW()
{
    return m_FZZWTblW = setElementObject(m_FZZWTblW,FZZWTBLW_Find_Key,FZZWTBLW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblW * FZZWTblPr::getTblW()
{
    return m_FZZWTblW = getElementObject(m_FZZWTblW,FZZWTBLW_Find_Key,FZZWTBLW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook * FZZWTblPr::setTblLook()
{
    return m_FZZWTblLook = setElementObject(m_FZZWTblLook,FZZWTBLLOOK_Find_Key,FZZWTBLLOOK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook * FZZWTblPr::getTblLook()
{
    return m_FZZWTblLook = getElementObject(m_FZZWTblLook,FZZWTBLLOOK_Find_Key,FZZWTBLLOOK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders * FZZWTblPr::setTblBorders()
{
    return m_FZZWTblBorders = setElementObject(m_FZZWTblBorders,FZZWTBLBORDERS_Find_Key,FZZWTBLBORDERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders * FZZWTblPr::getTblBorders()
{
    return m_FZZWTblBorders = getElementObject(m_FZZWTblBorders,FZZWTBLBORDERS_Find_Key,FZZWTBLBORDERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWTblPr::setJc()
{
    return m_FZZWJc = setElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWTblPr::getJc()
{
    return m_FZZWJc = getElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr * FZZWTblPr::setTblpPr()
{
    return m_FZZWTblpPr = setElementObject(m_FZZWTblpPr,FZZWTBLPPR_Find_Key,FZZWTBLPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblpPr * FZZWTblPr::getTblpPr()
{
    return m_FZZWTblpPr = getElementObject(m_FZZWTblpPr,FZZWTBLPPR_Find_Key,FZZWTBLPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap * FZZWTblPr::setTblOverlap()
{
    return m_FZZWTblOverlap = setElementObject(m_FZZWTblOverlap,FZZWTBLOVERLAP_Find_Key,FZZWTBLOVERLAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblOverlap * FZZWTblPr::getTblOverlap()
{
    return m_FZZWTblOverlap = getElementObject(m_FZZWTblOverlap,FZZWTBLOVERLAP_Find_Key,FZZWTBLOVERLAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout * FZZWTblPr::setTblLayout()
{
    return m_FZZWTblLayout = setElementObject(m_FZZWTblLayout,FZZWTBLLAYOUT_Find_Key,FZZWTBLLAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLayout * FZZWTblPr::getTblLayout()
{
    return m_FZZWTblLayout = getElementObject(m_FZZWTblLayout,FZZWTBLLAYOUT_Find_Key,FZZWTBLLAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing * FZZWTblPr::setTblCellSpacing()
{
    return m_FZZWTblCellSpacing = setElementObject(m_FZZWTblCellSpacing,FZZWTBLCELLSPACING_Find_Key,FZZWTBLCELLSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing * FZZWTblPr::getTblCellSpacing()
{
    return m_FZZWTblCellSpacing = getElementObject(m_FZZWTblCellSpacing,FZZWTBLCELLSPACING_Find_Key,FZZWTBLCELLSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
