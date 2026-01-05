//
//  Created by zizheng fan on 2023/11/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPrDefault.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPrDefault**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault::FZZWPPrDefault() : FZZXMLElementObject(),m_FZZWPPr(NULL)
{
    //DLOG("FZZWPPrDefault()");
    FZZConst::addClassCount("FZZWPPrDefault");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault::FZZWPPrDefault(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWPPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPPrDefault");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault::FZZWPPrDefault(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPPr(NULL)
{
    FZZConst::addClassCount("FZZWPPrDefault");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault::FZZWPPrDefault(const FZZWPPrDefault& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPPrDefault");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault::~FZZWPPrDefault()
{
    //DLOG("~FZZWPPrDefault()");
    FZZConst::delClassCount("FZZWPPrDefault");
    if ( m_FZZWPPr != NULL ) {
        delete m_FZZWPPr;
        m_FZZWPPr = NULL;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWPPrDefault::setPPr()
{
    return m_FZZWPPr = setElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWPPrDefault::getPPr()
{
    return m_FZZWPPr = getElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------

