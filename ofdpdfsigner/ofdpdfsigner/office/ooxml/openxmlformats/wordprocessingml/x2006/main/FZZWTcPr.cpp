//
//  Created by zizheng fan on 2023/11/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTcPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr::FZZWTcPr() : FZZXMLElementObject(),m_FZZWTcW(NULL),m_FZZWShd(NULL),m_FZZWVAlign(NULL),m_FZZWTcBorders(NULL),m_FZZWVMerge(NULL),m_FZZWGridSpan(NULL)
{
    //DLOG("FZZWTcPr()");
    FZZConst::addClassCount("FZZWTcPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr::FZZWTcPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWTcW(NULL),m_FZZWShd(NULL),m_FZZWVAlign(NULL),m_FZZWTcBorders(NULL),m_FZZWVMerge(NULL),m_FZZWGridSpan(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTcPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr::FZZWTcPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTcW(NULL),m_FZZWShd(NULL),m_FZZWVAlign(NULL),m_FZZWTcBorders(NULL),m_FZZWVMerge(NULL),m_FZZWGridSpan(NULL)
{
    FZZConst::addClassCount("FZZWTcPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr::FZZWTcPr(const FZZWTcPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTcPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTcW = obj.m_FZZWTcW != NULL ? new FZZWTcW(*obj.m_FZZWTcW) : NULL;
    m_FZZWShd = obj.m_FZZWShd != NULL ? new FZZWShd(*obj.m_FZZWShd) : NULL;
    m_FZZWVAlign = obj.m_FZZWVAlign != NULL ? new FZZWVAlign(*obj.m_FZZWVAlign) : NULL;
    m_FZZWTcBorders = obj.m_FZZWTcBorders != NULL ? new FZZWTcBorders(*obj.m_FZZWTcBorders) : NULL;
    m_FZZWVMerge = obj.m_FZZWVMerge != NULL ? new FZZWVMerge(*obj.m_FZZWVMerge) : NULL;
    m_FZZWGridSpan = obj.m_FZZWGridSpan != NULL ? new FZZWGridSpan(*obj.m_FZZWGridSpan) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr::~FZZWTcPr()
{
    //DLOG("~FZZWTcPr()");
    FZZConst::delClassCount("FZZWTcPr");
    
    
    if ( m_FZZWTcW != NULL ) {
        delete m_FZZWTcW;
        m_FZZWTcW = NULL;
    }
    if ( m_FZZWShd != NULL ) {
        delete m_FZZWShd;
        m_FZZWShd = NULL;
    }
    if ( m_FZZWVAlign != NULL ) {
        delete m_FZZWVAlign;
        m_FZZWVAlign = NULL;
    }
    if ( m_FZZWTcBorders != NULL ) {
        delete m_FZZWTcBorders;
        m_FZZWTcBorders = NULL;
    }
    if ( m_FZZWVMerge != NULL ) {
        delete m_FZZWVMerge;
        m_FZZWVMerge = NULL;
    }
    if ( m_FZZWGridSpan != NULL ) {
        delete m_FZZWGridSpan;
        m_FZZWGridSpan = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW * FZZWTcPr::setTcW()
{
    return m_FZZWTcW = setElementObject(m_FZZWTcW,FZZWTCW_Find_Key,FZZWTCW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcW * FZZWTcPr::getTcW()
{
    return m_FZZWTcW = getElementObject(m_FZZWTcW,FZZWTCW_Find_Key,FZZWTCW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd * FZZWTcPr::setShd()
{
    return m_FZZWShd = setElementObject(m_FZZWShd,FZZWSHD_Find_Key,FZZWSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWShd * FZZWTcPr::getShd()
{
    return m_FZZWShd = getElementObject(m_FZZWShd,FZZWSHD_Find_Key,FZZWSHD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign * FZZWTcPr::setVAlign()
{
    return m_FZZWVAlign = setElementObject(m_FZZWVAlign,FZZWVALIGN_Find_Key,FZZWVALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVAlign * FZZWTcPr::getVAlign()
{
    return m_FZZWVAlign = getElementObject(m_FZZWVAlign,FZZWVALIGN_Find_Key,FZZWVALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders * FZZWTcPr::setTcBorders()
{
    return m_FZZWTcBorders = setElementObject(m_FZZWTcBorders,FZZWTCBORDERS_Find_Key,FZZWTCBORDERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders * FZZWTcPr::getTcBorders()
{
    return m_FZZWTcBorders = getElementObject(m_FZZWTcBorders,FZZWTCBORDERS_Find_Key,FZZWTCBORDERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge * FZZWTcPr::setVMerge()
{
    return m_FZZWVMerge = setElementObject(m_FZZWVMerge,FZZWVMERGE_Find_Key,FZZWVMERGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVMerge * FZZWTcPr::getVMerge()
{
    return m_FZZWVMerge = getElementObject(m_FZZWVMerge,FZZWVMERGE_Find_Key,FZZWVMERGE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan * FZZWTcPr::setGridSpan()
{
    return m_FZZWGridSpan = setElementObject(m_FZZWGridSpan,FZZWGRIDSPAN_Find_Key,FZZWGRIDSPAN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWGridSpan * FZZWTcPr::getGridSpan()
{
    return m_FZZWGridSpan = getElementObject(m_FZZWGridSpan,FZZWGRIDSPAN_Find_Key,FZZWGRIDSPAN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
