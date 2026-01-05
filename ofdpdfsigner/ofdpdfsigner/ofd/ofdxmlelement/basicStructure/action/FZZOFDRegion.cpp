//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDRegion.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDRegion**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion::FZZOFDRegion() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDRegion()");
    FZZConst::addClassCount("FZZOFDRegion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion::FZZOFDRegion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDRegion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion::FZZOFDRegion(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDRegion");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion::FZZOFDRegion(const FZZOFDRegion& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDRegion");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDArea*>::const_iterator itr;
    for( itr = obj.m_FZZOFDAreas.begin(); itr != obj.m_FZZOFDAreas.end(); itr++ ) {
        FZZOFDArea * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDAreas.push_back(new FZZOFDArea(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRegion::~FZZOFDRegion()
{
    //DLOG("~FZZOFDRegion()");
    FZZConst::delClassCount("FZZOFDRegion");
    
    vector<FZZOFDArea*>::const_iterator itr;
    for( itr = m_FZZOFDAreas.begin(); itr != m_FZZOFDAreas.end(); itr++ ) {
        FZZOFDArea * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDAreas.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea * FZZOFDRegion::addArea()
{
    return addElementObject(&m_FZZOFDAreas,FZZOFDAREA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDArea*> * FZZOFDRegion::getAreaList()
{
    getElementObjectList(&m_FZZOFDAreas,FZZOFDAREA_Name);
    return &m_FZZOFDAreas;
}
//-----------------------------------------------------------------------------------------------------------------
