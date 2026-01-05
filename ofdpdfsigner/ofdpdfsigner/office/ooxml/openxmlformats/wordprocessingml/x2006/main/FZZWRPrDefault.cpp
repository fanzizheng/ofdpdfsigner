//
//  Created by zizheng fan on 2023/10/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPrDefault.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRPrDefault**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault::FZZWRPrDefault() : FZZXMLElementObject(),m_FZZWRPr(NULL)
{
    //DLOG("FZZWRPrDefault()");
    FZZConst::addClassCount("FZZWRPrDefault");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault::FZZWRPrDefault(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRPrDefault");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault::FZZWRPrDefault(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPr(NULL)
{
    FZZConst::addClassCount("FZZWRPrDefault");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault::FZZWRPrDefault(const FZZWRPrDefault& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRPrDefault");
    if ( this == &obj ) {
        return;
    }
    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault::~FZZWRPrDefault()
{
    //DLOG("~FZZWRPrDefault()");
    FZZConst::delClassCount("FZZWRPrDefault");
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWRPrDefault::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWRPrDefault::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------

