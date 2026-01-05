//
//  Created by zizheng fan on 2023/11/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSdtPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr::FZZWSdtPr() : FZZXMLElementObject(),m_FZZWRPr(NULL),m_FZZWId(NULL)
{
    //DLOG("FZZWSdtPr()");
    FZZConst::addClassCount("FZZWSdtPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr::FZZWSdtPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRPr(NULL),m_FZZWId(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSdtPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr::FZZWSdtPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPr(NULL),m_FZZWId(NULL)
{
    FZZConst::addClassCount("FZZWSdtPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr::FZZWSdtPr(const FZZWSdtPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSdtPr");
    if ( this == &obj ) {
        return;
    }

    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
    m_FZZWId = obj.m_FZZWId != NULL ? new FZZWId(*obj.m_FZZWId) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr::~FZZWSdtPr()
{
    //DLOG("~FZZWSdtPr()");
    FZZConst::delClassCount("FZZWSdtPr");
    
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
    if ( m_FZZWId != NULL ) {
        delete m_FZZWId;
        m_FZZWId = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWSdtPr::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWSdtPr::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId * FZZWSdtPr::setId()
{
    return m_FZZWId = setElementObject(m_FZZWId,FZZWID_Find_Key,FZZWID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWId * FZZWSdtPr::getId()
{
    return m_FZZWId = getElementObject(m_FZZWId,FZZWID_Find_Key,FZZWID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
