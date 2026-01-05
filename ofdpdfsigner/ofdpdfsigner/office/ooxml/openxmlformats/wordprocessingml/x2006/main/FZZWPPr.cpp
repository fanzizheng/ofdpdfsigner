//
//  Created by zizheng fan on 2023/10/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr::FZZWPPr() : FZZXMLElementObject(),m_FZZWRPr(NULL),m_FZZWInd(NULL),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWSectPr(NULL),m_FZZWPStyle(NULL),m_FZZWPBdr(NULL),m_FZZWWidowControl(NULL),m_FZZWTabs(NULL),m_FZZWFramePr(NULL),m_FZZWNumPr(NULL)
{
    //DLOG("FZZWPPr()");
    FZZConst::addClassCount("FZZWPPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr::FZZWPPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRPr(NULL),m_FZZWInd(NULL),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWSectPr(NULL),m_FZZWPStyle(NULL),m_FZZWPBdr(NULL),m_FZZWWidowControl(NULL),m_FZZWTabs(NULL),m_FZZWFramePr(NULL),m_FZZWNumPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr::FZZWPPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPr(NULL),m_FZZWInd(NULL),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWSectPr(NULL),m_FZZWPStyle(NULL),m_FZZWPBdr(NULL),m_FZZWWidowControl(NULL),m_FZZWTabs(NULL),m_FZZWFramePr(NULL),m_FZZWNumPr(NULL)
{
    FZZConst::addClassCount("FZZWPPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr::FZZWPPr(const FZZWPPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
    m_FZZWInd = obj.m_FZZWInd != NULL ? new FZZWInd(*obj.m_FZZWInd) : NULL;
    m_FZZWSpacing = obj.m_FZZWSpacing != NULL ? new FZZWSpacing(*obj.m_FZZWSpacing) : NULL;
    m_FZZWJc = obj.m_FZZWJc != NULL ? new FZZWJc(*obj.m_FZZWJc) : NULL;
    m_FZZWSectPr = obj.m_FZZWSectPr != NULL ? new FZZWSectPr(*obj.m_FZZWSectPr) : NULL;
    m_FZZWPStyle = obj.m_FZZWPStyle != NULL ? new FZZWPStyle(*obj.m_FZZWPStyle) : NULL;
    m_FZZWPBdr = obj.m_FZZWPBdr != NULL ? new FZZWPBdr(*obj.m_FZZWPBdr) : NULL;
    m_FZZWWidowControl = obj.m_FZZWWidowControl != NULL ? new FZZWWidowControl(*obj.m_FZZWWidowControl) : NULL;
    m_FZZWTabs = obj.m_FZZWTabs != NULL ? new FZZWTabs(*obj.m_FZZWTabs) : NULL;
    m_FZZWFramePr = obj.m_FZZWFramePr != NULL ? new FZZWFramePr(*obj.m_FZZWFramePr) : NULL;
    m_FZZWNumPr = obj.m_FZZWNumPr != NULL ? new FZZWNumPr(*obj.m_FZZWNumPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr::~FZZWPPr()
{
    //DLOG("~FZZWPPr()");
    FZZConst::delClassCount("FZZWPPr");
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
    if ( m_FZZWInd != NULL ) {
        delete m_FZZWInd;
        m_FZZWInd = NULL;
    }
    if ( m_FZZWSpacing != NULL ) {
        delete m_FZZWSpacing;
        m_FZZWSpacing = NULL;
    }
    if ( m_FZZWJc != NULL ) {
        delete m_FZZWJc;
        m_FZZWJc = NULL;
    }
    if ( m_FZZWSectPr != NULL ) {
        delete m_FZZWSectPr;
        m_FZZWSectPr = NULL;
    }
    if ( m_FZZWPStyle != NULL ) {
        delete m_FZZWPStyle;
        m_FZZWPStyle = NULL;
    }
    if ( m_FZZWPBdr != NULL ) {
        delete m_FZZWPBdr;
        m_FZZWPBdr = NULL;
    }
    if ( m_FZZWWidowControl != NULL ) {
        delete m_FZZWWidowControl;
        m_FZZWWidowControl = NULL;
    }
    if ( m_FZZWTabs != NULL ) {
        delete m_FZZWTabs;
        m_FZZWTabs = NULL;
    }
    if ( m_FZZWFramePr != NULL ) {
        delete m_FZZWFramePr;
        m_FZZWFramePr = NULL;
    }
    if ( m_FZZWNumPr != NULL ) {
        delete m_FZZWNumPr;
        m_FZZWNumPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWPPr::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWPPr::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd * FZZWPPr::setInd()
{
    return m_FZZWInd = setElementObject(m_FZZWInd,FZZWIND_Find_Key,FZZWIND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInd * FZZWPPr::getInd()
{
    return m_FZZWInd = getElementObject(m_FZZWInd,FZZWIND_Find_Key,FZZWIND_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing * FZZWPPr::setSpacing()
{
    return m_FZZWSpacing = setElementObject(m_FZZWSpacing,FZZWSPACING_Find_Key,FZZWSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing * FZZWPPr::getSpacing()
{
    return m_FZZWSpacing = getElementObject(m_FZZWSpacing,FZZWSPACING_Find_Key,FZZWSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWPPr::setJc()
{
    return m_FZZWJc = setElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWPPr::getJc()
{
    return m_FZZWJc = getElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr * FZZWPPr::setSectPr()
{
    return m_FZZWSectPr = setElementObject(m_FZZWSectPr,FZZWSECTPT_Find_Key,FZZWSECTPT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr * FZZWPPr::getSectPr()
{
    return m_FZZWSectPr = getElementObject(m_FZZWSectPr,FZZWSECTPT_Find_Key,FZZWSECTPT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle * FZZWPPr::setPStyle()
{
    return m_FZZWPStyle = setElementObject(m_FZZWPStyle,FZZWPSTYLE_Find_Key,FZZWPSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPStyle * FZZWPPr::getPStyle()
{
    return m_FZZWPStyle = getElementObject(m_FZZWPStyle,FZZWPSTYLE_Find_Key,FZZWPSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr * FZZWPPr::setPBdr()
{
    return m_FZZWPBdr = setElementObject(m_FZZWPBdr,FZZWPBDR_Find_Key,FZZWPBDR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr * FZZWPPr::getPBdr()
{
    return m_FZZWPBdr = getElementObject(m_FZZWPBdr,FZZWPBDR_Find_Key,FZZWPBDR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl * FZZWPPr::setWidowControl()
{
    return m_FZZWWidowControl = setElementObject(m_FZZWWidowControl,FZZWWIDOWCONTROL_Find_Key,FZZWWIDOWCONTROL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWWidowControl * FZZWPPr::getWidowControl()
{
    return m_FZZWWidowControl = getElementObject(m_FZZWWidowControl,FZZWWIDOWCONTROL_Find_Key,FZZWWIDOWCONTROL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs * FZZWPPr::setTabs()
{
    return m_FZZWTabs = setElementObject(m_FZZWTabs,FZZWTABS_Find_Key,FZZWTABS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs * FZZWPPr::getTabs()
{
    return m_FZZWTabs = getElementObject(m_FZZWTabs,FZZWTABS_Find_Key,FZZWTABS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr * FZZWPPr::setFramePr()
{
    return m_FZZWFramePr = setElementObject(m_FZZWFramePr,FZZWFRAMEPR_Find_Key,FZZWFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFramePr * FZZWPPr::getFramePr()
{
    return m_FZZWFramePr = getElementObject(m_FZZWFramePr,FZZWFRAMEPR_Find_Key,FZZWFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr * FZZWPPr::setNumPr()
{
    return m_FZZWNumPr = setElementObject(m_FZZWNumPr,FZZWNUMPR_Find_Key,FZZWNUMPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr * FZZWPPr::getNumPr()
{
    return m_FZZWNumPr = getElementObject(m_FZZWNumPr,FZZWNUMPR_Find_Key,FZZWNUMPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
