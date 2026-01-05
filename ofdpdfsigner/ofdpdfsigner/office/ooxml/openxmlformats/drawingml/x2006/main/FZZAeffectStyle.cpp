//
//  Created by zizheng fan on 2023/07/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAeffectStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle::FZZAeffectStyle() : FZZXMLElementObject(),m_CTeffectLst(NULL)
{
    //DLOG("FZZAeffectStyle()");
    FZZConst::addClassCount("FZZAeffectStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle::FZZAeffectStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_CTeffectLst(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAeffectStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle::FZZAeffectStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTeffectLst(NULL)
{
    FZZConst::addClassCount("FZZAeffectStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle::FZZAeffectStyle(const FZZAeffectStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAeffectStyle");
    if ( this == &obj ) {
        return;
    }
    m_CTeffectLst = obj.m_CTeffectLst != NULL ? new FZZAeffectLst(*obj.m_CTeffectLst) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectStyle::~FZZAeffectStyle()
{
    //DLOG("~FZZAeffectStyle()");
    FZZConst::delClassCount("FZZAeffectStyle");
    if ( m_CTeffectLst != NULL ) {
        delete m_CTeffectLst;
        m_CTeffectLst = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst * FZZAeffectStyle::setEffectLst()
{
    return m_CTeffectLst = setElementObject(m_CTeffectLst,FZZAEFFECTLST_Find_Key,FZZAEFFECTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst * FZZAeffectStyle::getEffectLst()
{
    return m_CTeffectLst = getElementObject(m_CTeffectLst,FZZAEFFECTLST_Find_Key,FZZAEFFECTLST_Name);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
