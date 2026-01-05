//
//  Created by zizheng fan on 2023/11/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdt.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSdt**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt::FZZWSdt() : FZZXMLElementObject(),m_FZZWSdtPr(NULL),m_FZZWSdtEndPr(NULL),m_FZZWSdtContent(NULL)
{
    //DLOG("FZZWSdt()");
    FZZConst::addClassCount("FZZWSdt");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt::FZZWSdt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWSdtPr(NULL),m_FZZWSdtEndPr(NULL),m_FZZWSdtContent(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSdt");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt::FZZWSdt(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWSdtPr(NULL),m_FZZWSdtEndPr(NULL),m_FZZWSdtContent(NULL)
{
    FZZConst::addClassCount("FZZWSdt");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt::FZZWSdt(const FZZWSdt& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSdt");
    if ( this == &obj ) {
        return;
    }

    m_FZZWSdtPr = obj.m_FZZWSdtPr != NULL ? new FZZWSdtPr(*obj.m_FZZWSdtPr) : NULL;
    m_FZZWSdtEndPr = obj.m_FZZWSdtEndPr != NULL ? new FZZWSdtEndPr(*obj.m_FZZWSdtEndPr) : NULL;
    m_FZZWSdtContent = obj.m_FZZWSdtContent != NULL ? new FZZWSdtContent(*obj.m_FZZWSdtContent) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdt::~FZZWSdt()
{
    //DLOG("~FZZWSdt()");
    FZZConst::delClassCount("FZZWSdt");
    
    if ( m_FZZWSdtPr != NULL ) {
        delete m_FZZWSdtPr;
        m_FZZWSdtPr = NULL;
    }
    if ( m_FZZWSdtEndPr != NULL ) {
        delete m_FZZWSdtEndPr;
        m_FZZWSdtEndPr = NULL;
    }
    if ( m_FZZWSdtContent != NULL ) {
        delete m_FZZWSdtContent;
        m_FZZWSdtContent = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr * FZZWSdt::setSdtPr()
{
    return m_FZZWSdtPr = setElementObject(m_FZZWSdtPr,FZZWSDTPR_Find_Key,FZZWSDTPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtPr * FZZWSdt::getSdtPr()
{
    return m_FZZWSdtPr = getElementObject(m_FZZWSdtPr,FZZWSDTPR_Find_Key,FZZWSDTPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr * FZZWSdt::setSdtEndPr()
{
    return m_FZZWSdtEndPr = setElementObject(m_FZZWSdtEndPr,FZZWSDTENDPR_Find_Key,FZZWSDTENDPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtEndPr * FZZWSdt::getSdtEndPr()
{
    return m_FZZWSdtEndPr = getElementObject(m_FZZWSdtEndPr,FZZWSDTENDPR_Find_Key,FZZWSDTENDPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent * FZZWSdt::setSdtContent()
{
    return m_FZZWSdtContent = setElementObject(m_FZZWSdtContent,FZZWSDTCONTENT_Find_Key,FZZWSDTCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent * FZZWSdt::getSdtContent()
{
    return m_FZZWSdtContent = getElementObject(m_FZZWSdtContent,FZZWSDTCONTENT_Find_Key,FZZWSDTCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
