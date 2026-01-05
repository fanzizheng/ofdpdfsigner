//
//  Created by zizheng fan on 2023/06/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICSpPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZPICSpPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr::FZZPICSpPr() : FZZXMLElementObject(),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL)
{
    //DLOG("FZZPICSpPr()");
    FZZConst::addClassCount("FZZPICSpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr::FZZPICSpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZPICSpPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr::FZZPICSpPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAXfrm(NULL),m_FZZAPrstGeom(NULL)
{
    FZZConst::addClassCount("FZZPICSpPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr::FZZPICSpPr(const FZZPICSpPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZPICSpPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZAXfrm = obj.m_FZZAXfrm != NULL ? new FZZAXfrm(*obj.m_FZZAXfrm) : NULL;
    m_FZZAPrstGeom = obj.m_FZZAPrstGeom != NULL ? new FZZAPrstGeom(*obj.m_FZZAPrstGeom) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZPICSpPr::~FZZPICSpPr()
{
    //DLOG("~FZZPICSpPr()");
    FZZConst::delClassCount("FZZPICSpPr");
    if ( m_FZZAXfrm != NULL ) {
        delete m_FZZAXfrm;
        m_FZZAXfrm = NULL;
    }
    if ( m_FZZAPrstGeom != NULL ) {
        delete m_FZZAPrstGeom;
        m_FZZAPrstGeom = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZPICSpPr::setXmlnsPic(string value)
//{
//    setAttribute_String("xmlns:pic",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZPICSpPr::getXmlnsPic()
//{
//    return getAttribute_String("xmlns:pic");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm * FZZPICSpPr::setXfrm()
{
    return m_FZZAXfrm = setElementObject(m_FZZAXfrm,FZZAXFRM_Find_Key,FZZAXFRM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAXfrm * FZZPICSpPr::getXfrm()
{
    return m_FZZAXfrm = getElementObject(m_FZZAXfrm,FZZAXFRM_Find_Key,FZZAXFRM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom * FZZPICSpPr::setPrstGeom()
{
    return m_FZZAPrstGeom = setElementObject(m_FZZAPrstGeom,FZZAPRSTGEOM_Find_Key,FZZAPRSTGEOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAPrstGeom * FZZPICSpPr::getPrstGeom()
{
    return m_FZZAPrstGeom = getElementObject(m_FZZAPrstGeom,FZZAPRSTGEOM_Find_Key,FZZAPRSTGEOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
