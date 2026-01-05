//
//  Created by zizheng fan on 2023/09/25
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsids.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRsids**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids::FZZWRsids() : FZZXMLElementObject(),m_FZZWRsidRoot(NULL)
{
    //DLOG("FZZWRsids()");
    FZZConst::addClassCount("FZZWRsids");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids::FZZWRsids(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWRsidRoot(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRsids");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids::FZZWRsids(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRsidRoot(NULL)
{
    FZZConst::addClassCount("FZZWRsids");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids::FZZWRsids(const FZZWRsids& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRsids");
    if ( this == &obj ) {
        return;
    }
    m_FZZWRsidRoot = obj.m_FZZWRsidRoot != NULL ? new FZZWRsidRoot(*obj.m_FZZWRsidRoot) : NULL;
    
    vector<FZZWRsid*>::const_iterator itr;
    for( itr = obj.m_FZZWRsids.begin(); itr != obj.m_FZZWRsids.end(); itr++ ) {
        FZZWRsid * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWRsids.push_back(new FZZWRsid(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsids::~FZZWRsids()
{
    //DLOG("~FZZWRsids()");
    FZZConst::delClassCount("FZZWRsids");
    if ( m_FZZWRsidRoot != NULL ) {
        delete m_FZZWRsidRoot;
        m_FZZWRsidRoot = NULL;
    }
    
    
    vector<FZZWRsid*>::const_iterator itr;
    for( itr = m_FZZWRsids.begin(); itr != m_FZZWRsids.end(); itr++ ) {
        FZZWRsid * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWRsids.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid * FZZWRsids::addRsid()
{
    return addElementObject(&m_FZZWRsids,FZZWRSID_Find_Key,FZZWRSID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWRsid*> * FZZWRsids::getRsids()
{
    getElementObjectList(&m_FZZWRsids,FZZWRSID_Find_Key,FZZWRSID_Name);
    return &m_FZZWRsids;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot * FZZWRsids::setRsidRoot()
{
    return m_FZZWRsidRoot = setElementObject(m_FZZWRsidRoot,FZZWRSIDROOT_Find_Key,FZZWRSIDROOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot * FZZWRsids::getRsidRoot()
{
    return m_FZZWRsidRoot = getElementObject(m_FZZWRsidRoot,FZZWRSIDROOT_Find_Key,FZZWRSIDROOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------

