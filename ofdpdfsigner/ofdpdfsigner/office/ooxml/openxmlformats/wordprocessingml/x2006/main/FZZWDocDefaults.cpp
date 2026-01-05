//
//  Created by zizheng fan on 2023/10/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocDefaults.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDocDefaults**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults::FZZWDocDefaults() : FZZXMLElementObject(),m_FZZWRPrDefault(NULL),m_FZZWPPrDefault(NULL)
{
    //DLOG("FZZWDocDefaults()");
    FZZConst::addClassCount("FZZWDocDefaults");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults::FZZWDocDefaults(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRPrDefault(NULL),m_FZZWPPrDefault(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDocDefaults");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults::FZZWDocDefaults(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPrDefault(NULL),m_FZZWPPrDefault(NULL)
{
    FZZConst::addClassCount("FZZWDocDefaults");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults::FZZWDocDefaults(const FZZWDocDefaults& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDocDefaults");
    if ( this == &obj ) {
        return;
    }
    
    
//    vector<FZZWRPrDefault*>::const_iterator itr;
//    for( itr = obj.m_FZZWRPrDefaults.begin(); itr != obj.m_FZZWRPrDefaults.end(); itr++ ) {
//        FZZWRPrDefault * temp = *itr;
//        if ( temp != NULL ) {
//            m_FZZWRPrDefaults.push_back(new FZZWRPrDefault(*temp));
//        }
//    }
    m_FZZWRPrDefault = obj.m_FZZWRPrDefault != NULL ? new FZZWRPrDefault(*obj.m_FZZWRPrDefault) : NULL;
    
//    vector<FZZWPPrDefault*>::const_iterator itr_ppr;
//    for( itr_ppr = obj.m_FZZWPPrDefaults.begin(); itr_ppr != obj.m_FZZWPPrDefaults.end(); itr_ppr++ ) {
//        FZZWPPrDefault * temp = *itr_ppr;
//        if ( temp != NULL ) {
//            m_FZZWPPrDefaults.push_back(new FZZWPPrDefault(*temp));
//        }
//    }
    m_FZZWPPrDefault = obj.m_FZZWPPrDefault != NULL ? new FZZWPPrDefault(*obj.m_FZZWPPrDefault) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocDefaults::~FZZWDocDefaults()
{
    //DLOG("~FZZWDocDefaults()");
    FZZConst::delClassCount("FZZWDocDefaults");
    
    if ( m_FZZWRPrDefault != NULL ) {
        delete m_FZZWRPrDefault;
        m_FZZWRPrDefault = NULL;
    }
    
    if ( m_FZZWPPrDefault != NULL ) {
        delete m_FZZWPPrDefault;
        m_FZZWPPrDefault = NULL;
    }
    
//    vector<FZZWRPrDefault*>::const_iterator itr;
//    for( itr = m_FZZWRPrDefaults.begin(); itr != m_FZZWRPrDefaults.end(); itr++ ) {
//        FZZWRPrDefault * temp = *itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZWRPrDefaults.clear();
    
//    vector<FZZWPPrDefault*>::const_iterator itr_ppr;
//    for( itr_ppr = m_FZZWPPrDefaults.begin(); itr_ppr != m_FZZWPPrDefaults.end(); itr_ppr++ ) {
//        FZZWPPrDefault * temp = *itr_ppr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZWPPrDefaults.clear();
}
//-----------------------------------------------------------------------------------------------------------------
//FZZWRPrDefault * FZZWDocDefaults::addRPrDefault()
//{
//    return addElementObject(&m_FZZWRPrDefaults,FZZWRPRDEFAULT_Find_Key,FZZWRPRDEFAULT_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//vector<FZZWRPrDefault*> * FZZWDocDefaults::getRPrDefaults()
//{
//    getElementObjectList(&m_FZZWRPrDefaults,FZZWRPRDEFAULT_Find_Key,FZZWRPRDEFAULT_Name);
//    return &m_FZZWRPrDefaults;
//}
FZZWRPrDefault * FZZWDocDefaults::setRPrDefault()
{
    return m_FZZWRPrDefault = setElementObject(m_FZZWRPrDefault,FZZWRPRDEFAULT_Find_Key,FZZWRPRDEFAULT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPrDefault * FZZWDocDefaults::getRPrDefault()
{
    return m_FZZWRPrDefault = getElementObject(m_FZZWRPrDefault,FZZWRPRDEFAULT_Find_Key,FZZWRPRDEFAULT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//FZZWPPrDefault * FZZWDocDefaults::addPPrDefault()
//{
//    return addElementObject(&m_FZZWPPrDefaults,FZZWPPRDEFAULT_Find_Key,FZZWPPRDEFAULT_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//vector<FZZWPPrDefault*> * FZZWDocDefaults::getPPrDefaults()
//{
//    getElementObjectList(&m_FZZWPPrDefaults,FZZWPPRDEFAULT_Find_Key,FZZWPPRDEFAULT_Name);
//    return &m_FZZWPPrDefaults;
//}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault * FZZWDocDefaults::setPPrDefault()
{
    return m_FZZWPPrDefault = setElementObject(m_FZZWPPrDefault,FZZWPPRDEFAULT_Find_Key,FZZWPPRDEFAULT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPrDefault * FZZWDocDefaults::getPPrDefault()
{
    return m_FZZWPPrDefault = getElementObject(m_FZZWPPrDefault,FZZWPPRDEFAULT_Find_Key,FZZWPPRDEFAULT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
