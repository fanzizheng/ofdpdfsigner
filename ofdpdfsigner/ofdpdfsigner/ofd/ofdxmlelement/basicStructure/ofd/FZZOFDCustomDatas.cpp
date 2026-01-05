//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomDatas.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCustomDatas**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas::FZZOFDCustomDatas() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCustomDatas()");
    FZZConst::addClassCount("FZZOFDCustomDatas");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas::FZZOFDCustomDatas(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDCustomDatas");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas::FZZOFDCustomDatas(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCustomDatas");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas::FZZOFDCustomDatas(const FZZOFDCustomDatas& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDCustomDatas");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDCustomData*>::const_iterator itr;
    for( itr = obj.m_FZZOFDCustomDatas.begin(); itr != obj.m_FZZOFDCustomDatas.end(); itr++ ) {
        FZZOFDCustomData * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDCustomDatas.push_back(new FZZOFDCustomData(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomDatas::~FZZOFDCustomDatas()
{
    //DLOG("~FZZOFDCustomDatas()");
    FZZConst::delClassCount("FZZOFDCustomDatas");
        
    vector<FZZOFDCustomData*>::const_iterator itr;
    for( itr = m_FZZOFDCustomDatas.begin(); itr != m_FZZOFDCustomDatas.end(); itr++ ) {
        FZZOFDCustomData * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDCustomDatas.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomData * FZZOFDCustomDatas::addCustomData()
{
    return addElementObject(&m_FZZOFDCustomDatas,FZZOFDCUSTOMDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDCustomData*> * FZZOFDCustomDatas::getCustomDataList()
{
    getElementObjectList(&m_FZZOFDCustomDatas,FZZOFDCUSTOMDATA_Name);
    return &m_FZZOFDCustomDatas;
}
//-----------------------------------------------------------------------------------------------------------------

