//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDContent.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDContent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent::FZZOFDContent() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDContent()");
    FZZConst::addClassCount("FZZOFDContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent::FZZOFDContent(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent::FZZOFDContent(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDContent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent::FZZOFDContent(const FZZOFDContent& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDContent");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDLayer*>::const_iterator r_itr;
    for( r_itr = obj.m_FZZOFDLayers.begin(); r_itr != obj.m_FZZOFDLayers.end(); r_itr++ ) {
        FZZOFDLayer * temp = *r_itr;
        if ( temp != NULL ) {
            m_FZZOFDLayers.push_back(new FZZOFDLayer(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDContent::~FZZOFDContent()
{
    //DLOG("~FZZOFDContent()");
    FZZConst::delClassCount("FZZOFDContent");
    
    vector<FZZOFDLayer *>::const_iterator r_itr;
    for( r_itr = m_FZZOFDLayers.begin(); r_itr != m_FZZOFDLayers.end(); r_itr++ ) {
        FZZOFDLayer * temp = *r_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDLayers.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDLayer*>* FZZOFDContent::getLayerList()
{
    getElementObjectList(&m_FZZOFDLayers,FZZOFDLAYER_Name);
    return &m_FZZOFDLayers;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer* FZZOFDContent::addLayer()
{
    return addElementObject(&m_FZZOFDLayers,FZZOFDLAYER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
