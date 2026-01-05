//
//  Created by zizheng fan on 2023/05/15.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCFallback.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMCFallback**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback::FZZMCFallback() : FZZXMLElementObject()
{
    //DLOG("FZZMCFallback()");
    FZZConst::addClassCount("FZZMCFallback");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback::FZZMCFallback(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMCFallback");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback::FZZMCFallback(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMCFallback");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback::FZZMCFallback(const FZZMCFallback& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMCFallback");
    if ( this == &obj ) {
        return;
    }
    

    
    vector<FZZWPict*>::const_iterator itr;
    for( itr = obj.m_FZZWPicts.begin(); itr != obj.m_FZZWPicts.end(); itr++ ) {
        FZZWPict * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWPicts.push_back(new FZZWPict(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback::~FZZMCFallback()
{
    //DLOG("~FZZMCFallback()");
    FZZConst::delClassCount("FZZMCFallback");
    
    vector<FZZWPict*>::const_iterator itr;
    for( itr = m_FZZWPicts.begin(); itr != m_FZZWPicts.end(); itr++ ) {
        FZZWPict * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWPicts.clear();

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict * FZZMCFallback::addPict()
{
    return addElementObject(&m_FZZWPicts,FZZWPICT_Find_Key,FZZWPICT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWPict*> * FZZMCFallback::getPictList()
{
    getElementObjectList(&m_FZZWPicts,FZZWPICT_Find_Key,FZZWPICT_Name);
    return &m_FZZWPicts;
}
//-----------------------------------------------------------------------------------------------------------------


