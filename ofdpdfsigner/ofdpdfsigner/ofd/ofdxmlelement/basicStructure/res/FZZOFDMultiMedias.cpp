//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedias.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMultiMedias**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias::FZZOFDMultiMedias() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDMultiMedias()");
    FZZConst::addClassCount("FZZOFDMultiMedias");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias::FZZOFDMultiMedias(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDMultiMedias");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias::FZZOFDMultiMedias(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDMultiMedias");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias::FZZOFDMultiMedias(const FZZOFDMultiMedias& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMultiMedias");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDMultiMedia*>::const_iterator itr;
    for( itr = obj.m_FZZOFDMultiMedias.begin(); itr != obj.m_FZZOFDMultiMedias.end(); itr++ ) {
        FZZOFDMultiMedia * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDMultiMedias.push_back(new FZZOFDMultiMedia(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedias::~FZZOFDMultiMedias()
{
    //DLOG("~FZZOFDMultiMedias()");
    FZZConst::delClassCount("FZZOFDMultiMedias");
        
    vector<FZZOFDMultiMedia*>::const_iterator itr;
    for( itr = m_FZZOFDMultiMedias.begin(); itr != m_FZZOFDMultiMedias.end(); itr++ ) {
        FZZOFDMultiMedia * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDMultiMedias.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia * FZZOFDMultiMedias::addMultiMedia()
{
    return addElementObject(&m_FZZOFDMultiMedias,FZZOFDMULTIMEDIA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDMultiMedia*> * FZZOFDMultiMedias::getMultiMediaList()
{
    getElementObjectList(&m_FZZOFDMultiMedias,FZZOFDMULTIMEDIA_Name);
    return &m_FZZOFDMultiMedias;
}
//-----------------------------------------------------------------------------------------------------------------

