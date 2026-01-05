//
//  Created by zizheng fan on 2023/04/28.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSBodyPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSBodyPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr::FZZWPSBodyPr() : FZZXMLElementObject(),m_FZZAPrstTxWarp(NULL)
{
    //DLOG("FZZWPSBodyPr()");
    FZZConst::addClassCount("FZZWPSBodyPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr::FZZWPSBodyPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAPrstTxWarp(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSBodyPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr::FZZWPSBodyPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAPrstTxWarp(NULL)
{
    FZZConst::addClassCount("FZZWPSBodyPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr::FZZWPSBodyPr(const FZZWPSBodyPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSBodyPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZAPrstTxWarp = obj.m_FZZAPrstTxWarp != NULL ? new FZZAPrstTxWarp(*obj.m_FZZAPrstTxWarp) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSBodyPr::~FZZWPSBodyPr()
{
    //DLOG("~FZZWPSBodyPr()");
    FZZConst::delClassCount("FZZWPSBodyPr");
    if ( m_FZZAPrstTxWarp != NULL ) {
        delete m_FZZAPrstTxWarp;
        m_FZZAPrstTxWarp = NULL;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp * FZZWPSBodyPr::setPrstTxWarp()
{
    return m_FZZAPrstTxWarp = setElementObject(m_FZZAPrstTxWarp,FZZAPRSTTXWARP_Find_Key,FZZAPRSTTXWARP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstTxWarp * FZZWPSBodyPr::getPrstTxWarp()
{
    return m_FZZAPrstTxWarp = getElementObject(m_FZZAPrstTxWarp,FZZAPRSTTXWARP_Find_Key,FZZAPRSTTXWARP_Name);
}
//-----------------------------------------------------------------------------------------------------------------

