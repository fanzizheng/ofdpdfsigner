//
//  Created by zizheng fan on 2023/04/28.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSCNvCnPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSCNvCnPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr::FZZWPSCNvCnPr() : FZZXMLElementObject()
{
    //DLOG("FZZWPSCNvCnPr()");
    FZZConst::addClassCount("FZZWPSCNvCnPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr::FZZWPSCNvCnPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSCNvCnPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr::FZZWPSCNvCnPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPSCNvCnPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr::FZZWPSCNvCnPr(const FZZWPSCNvCnPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSCNvCnPr");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSCNvCnPr::~FZZWPSCNvCnPr()
{
    //DLOG("~FZZWPSCNvCnPr()");
    FZZConst::delClassCount("FZZWPSCNvCnPr");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------


