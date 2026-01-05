//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersions.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDVersions**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions::FZZOFDVersions() : FZZOFDXMLElementObject()
{
    FZZConst::addClassCount("FZZOFDVersions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions::FZZOFDVersions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDVersions");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions::FZZOFDVersions(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDVersions");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions::FZZOFDVersions(const FZZOFDVersions& obj) : FZZOFDXMLElementObject(obj)
{
    FZZConst::addClassCount("FZZOFDVersions");
    if ( this == &obj ) {
        return;
    }
   
    
    vector<FZZOFDVersion*>::const_iterator itr;
    for( itr = obj.m_FZZOFDVersions.begin(); itr != obj.m_FZZOFDVersions.end(); itr++ ) {
        FZZOFDVersion * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDVersions.push_back(new FZZOFDVersion(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions::~FZZOFDVersions()
{
    FZZConst::delClassCount("FZZOFDVersions");
    
    
    vector<FZZOFDVersion*>::const_iterator itr;
    for( itr = m_FZZOFDVersions.begin(); itr != m_FZZOFDVersions.end(); itr++ ) {
        FZZOFDVersion * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDVersions.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion * FZZOFDVersions::addVersion()
{
    return addElementObject(&m_FZZOFDVersions,FZZOFDVERSION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDVersion*> * FZZOFDVersions::getVersions()
{
    getElementObjectList(&m_FZZOFDVersions,FZZOFDVERSION_Name);
    return &m_FZZOFDVersions;
}
//-----------------------------------------------------------------------------------------------------------------

