//
//  Created by zizheng fan on 2023/11/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtContent.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSdtContent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent::FZZWSdtContent() : FZZXMLElementObject(),m_FZZWP(NULL)
{
    //DLOG("FZZWSdtContent()");
    FZZConst::addClassCount("FZZWSdtContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent::FZZWSdtContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWP(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSdtContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent::FZZWSdtContent(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWP(NULL)
{
    FZZConst::addClassCount("FZZWSdtContent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent::FZZWSdtContent(const FZZWSdtContent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSdtContent");
    if ( this == &obj ) {
        return;
    }

    m_FZZWP = obj.m_FZZWP != NULL ? new FZZWP(*obj.m_FZZWP) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSdtContent::~FZZWSdtContent()
{
    //DLOG("~FZZWSdtContent()");
    FZZConst::delClassCount("FZZWSdtContent");
    
    if ( m_FZZWP != NULL ) {
        delete m_FZZWP;
        m_FZZWP = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWSdtContent::setP()
{
    return m_FZZWP = setElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWSdtContent::getP()
{
    return m_FZZWP = getElementObject(m_FZZWP,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
