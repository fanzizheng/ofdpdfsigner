//
//  Created by zizheng fan on 2023/05/06.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSSpPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSSpPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr::FZZWPSSpPr() : FZZXMLElementObject(),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL),m_CTln(NULL)
{
    //DLOG("FZZWPSSpPr()");
    FZZConst::addClassCount("FZZWPSSpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr::FZZWPSSpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL),m_CTln(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSSpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr::FZZWPSSpPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL),m_CTln(NULL)
{
    FZZConst::addClassCount("FZZWPSSpPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr::FZZWPSSpPr(const FZZWPSSpPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSSpPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZAXfrm = obj.m_FZZAXfrm != NULL ? new FZZAXfrm(*obj.m_FZZAXfrm) : NULL;
    m_FZZAPrstGeom = obj.m_FZZAPrstGeom != NULL ? new FZZAPrstGeom(*obj.m_FZZAPrstGeom) : NULL;
    m_CTln = obj.m_CTln != NULL ? new FZZALn(*obj.m_CTln) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSSpPr::~FZZWPSSpPr()
{
    //DLOG("~FZZWPSSpPr()");
    FZZConst::delClassCount("FZZWPSSpPr");
    if ( m_FZZAXfrm != NULL ) {
        delete m_FZZAXfrm;
        m_FZZAXfrm = NULL;
    }
    if ( m_FZZAPrstGeom != NULL ) {
        delete m_FZZAPrstGeom;
        m_FZZAPrstGeom = NULL;
    }
    if ( m_CTln != NULL ) {
        delete m_CTln;
        m_CTln = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm * FZZWPSSpPr::setXfrm()
{
    return m_FZZAXfrm = setElementObject(m_FZZAXfrm,FZZAXFRM_Find_Key,FZZAXFRM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm * FZZWPSSpPr::getXfrm()
{
    return m_FZZAXfrm = getElementObject(m_FZZAXfrm,FZZAXFRM_Find_Key,FZZAXFRM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom * FZZWPSSpPr::setPrstGeom()
{
    return m_FZZAPrstGeom = setElementObject(m_FZZAPrstGeom,FZZAPRSTGEOM_Find_Key,FZZAPRSTGEOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom * FZZWPSSpPr::getPrstGeom()
{
    return m_FZZAPrstGeom = getElementObject(m_FZZAPrstGeom,FZZAPRSTGEOM_Find_Key,FZZAPRSTGEOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn * FZZWPSSpPr::setLn()
{
    return m_CTln = setElementObject(m_CTln,FZZALN_Find_Key,FZZALN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZALn * FZZWPSSpPr::getLn()
{
    return m_CTln = getElementObject(m_CTln,FZZALN_Find_Key,FZZALN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
