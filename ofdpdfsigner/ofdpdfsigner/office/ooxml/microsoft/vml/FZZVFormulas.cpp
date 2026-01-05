//
//  Created by zizheng fan on 2023/04/17.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVFormulas.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVFormulas**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas::FZZVFormulas() : FZZXMLElementObject()
{
    //DLOG("FZZVFormulas()");
    FZZConst::addClassCount("FZZVFormulas");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas::FZZVFormulas(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVFormulas");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas::FZZVFormulas(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVFormulas");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas::FZZVFormulas(const FZZVFormulas& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVFormulas");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    vector<FZZVF*>::const_iterator FZZVF_itr;
    for( FZZVF_itr = obj.m_FZZVFList.begin(); FZZVF_itr != obj.m_FZZVFList.end(); FZZVF_itr++ ) {
        FZZVF * temp = *FZZVF_itr;
        if ( temp != NULL ) {
            m_FZZVFList.push_back(new FZZVF(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas::~FZZVFormulas()
{
    //DLOG("~FZZVFormulas()");
    FZZConst::delClassCount("FZZVFormulas");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    vector<FZZVF*>::const_iterator FZZVF_itr;
    for( FZZVF_itr = m_FZZVFList.begin(); FZZVF_itr != m_FZZVFList.end(); FZZVF_itr++ ) {
        FZZVF * temp = *FZZVF_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVFList.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVF * FZZVFormulas::addF()
{
    return addElementObject(&m_FZZVFList,FZZVF_Find_Key,FZZVF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVF*> * FZZVFormulas::getFList()
{
    getElementObjectList(&m_FZZVFList,FZZVF_Find_Key,FZZVF_Name);
    return &m_FZZVFList;
}
//-----------------------------------------------------------------------------------------------------------------
