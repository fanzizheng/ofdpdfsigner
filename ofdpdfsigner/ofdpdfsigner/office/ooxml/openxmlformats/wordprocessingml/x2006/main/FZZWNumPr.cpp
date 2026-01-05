//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumPr.h"
#include "office/FZZOfficeObject.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNumPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr::FZZWNumPr() : FZZXMLElementObject(),m_FZZWIlvl(NULL),m_FZZWNumId(NULL)
{
    //DLOG("FZZWNumPr()");
    FZZConst::addClassCount("FZZWNumPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr::FZZWNumPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWIlvl(NULL),m_FZZWNumId(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNumPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr::FZZWNumPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWIlvl(NULL),m_FZZWNumId(NULL)
{
    FZZConst::addClassCount("FZZWNumPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr::FZZWNumPr(const FZZWNumPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNumPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWIlvl = obj.m_FZZWIlvl != NULL ? new FZZWIlvl(*obj.m_FZZWIlvl) : NULL;
    m_FZZWNumId = obj.m_FZZWNumId != NULL ? new FZZWNumId(*obj.m_FZZWNumId) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumPr::~FZZWNumPr()
{
    //DLOG("~FZZWNumPr()");
    FZZConst::delClassCount("FZZWNumPr");
    if ( m_FZZWIlvl != NULL ) {
        delete m_FZZWIlvl;
        m_FZZWIlvl = NULL;
    }
    if ( m_FZZWNumId != NULL ) {
        delete m_FZZWNumId;
        m_FZZWNumId = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl * FZZWNumPr::setIlvl()
{
    return m_FZZWIlvl = setElementObject(m_FZZWIlvl,FZZWILVL_Find_Key,FZZWILVL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWIlvl * FZZWNumPr::getIlvl()
{
    return m_FZZWIlvl = getElementObject(m_FZZWIlvl,FZZWILVL_Find_Key,FZZWILVL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId * FZZWNumPr::setNumId()
{
    return m_FZZWNumId = setElementObject(m_FZZWNumId,FZZWNUMID_Find_Key,FZZWNUMID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumId * FZZWNumPr::getNumId()
{
    return m_FZZWNumId = getElementObject(m_FZZWNumId,FZZWNUMID_Find_Key,FZZWNUMID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
