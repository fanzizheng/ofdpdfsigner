//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDActions**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions::FZZOFDActions() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDActions()");
    FZZConst::addClassCount("FZZOFDActions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions::FZZOFDActions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDActions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions::FZZOFDActions(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDActions");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions::FZZOFDActions(const FZZOFDActions& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDActions");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZOFDAction*>::const_iterator itr;
    for( itr = obj.m_FZZOFDActions.begin(); itr != obj.m_FZZOFDActions.end(); itr++ ) {
        FZZOFDAction * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDActions.push_back(new FZZOFDAction(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions::~FZZOFDActions()
{
    //DLOG("~FZZOFDActions()");
    FZZConst::delClassCount("FZZOFDActions");
    vector<FZZOFDAction*>::const_iterator itr;
    for( itr = m_FZZOFDActions.begin(); itr != m_FZZOFDActions.end(); itr++ ) {
        FZZOFDAction * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDActions.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAction * FZZOFDActions::addAction()
{
    return addElementObject(&m_FZZOFDActions,FZZOFDACTION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDAction*> * FZZOFDActions::getActionList()
{
    getElementObjectList(&m_FZZOFDActions,FZZOFDACTION_Name);
    return &m_FZZOFDActions;
}
//-----------------------------------------------------------------------------------------------------------------
