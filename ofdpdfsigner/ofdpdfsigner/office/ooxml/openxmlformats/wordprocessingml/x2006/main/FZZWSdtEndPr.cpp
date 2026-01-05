//
//  Created by zizheng fan on 2023/11/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtEndPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSdtEndPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr::FZZWSdtEndPr() : FZZXMLElementObject(),m_FZZWRPr(NULL)
{
    //DLOG("FZZWSdtEndPr()");
    FZZConst::addClassCount("FZZWSdtEndPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr::FZZWSdtEndPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSdtEndPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr::FZZWSdtEndPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPr(NULL)
{
    FZZConst::addClassCount("FZZWSdtEndPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr::FZZWSdtEndPr(const FZZWSdtEndPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSdtEndPr");
    if ( this == &obj ) {
        return;
    }

    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr::~FZZWSdtEndPr()
{
    //DLOG("~FZZWSdtEndPr()");
    FZZConst::delClassCount("FZZWSdtEndPr");
    
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWSdtEndPr::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWSdtEndPr::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
