//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDCompositeGraphicUnits.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCompositeGraphicUnits**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits::FZZOFDCompositeGraphicUnits() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCompositeGraphicUnits()");
    FZZConst::addClassCount("FZZOFDCompositeGraphicUnits");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits::FZZOFDCompositeGraphicUnits(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDCompositeGraphicUnits");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits::FZZOFDCompositeGraphicUnits(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCompositeGraphicUnits");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits::FZZOFDCompositeGraphicUnits(const FZZOFDCompositeGraphicUnits& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCompositeGraphicUnits");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDVectorG*>::const_iterator itr;
    for( itr = obj.m_FZZOFDVectorGs.begin(); itr != obj.m_FZZOFDVectorGs.end(); itr++ ) {
        FZZOFDVectorG * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDVectorGs.push_back(new FZZOFDVectorG(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCompositeGraphicUnits::~FZZOFDCompositeGraphicUnits()
{
    //DLOG("~FZZOFDCompositeGraphicUnits()");
    FZZConst::delClassCount("FZZOFDCompositeGraphicUnits");
        
    vector<FZZOFDVectorG*>::const_iterator itr;
    for( itr = m_FZZOFDVectorGs.begin(); itr != m_FZZOFDVectorGs.end(); itr++ ) {
        FZZOFDVectorG * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDVectorGs.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG * FZZOFDCompositeGraphicUnits::addVectorG()
{
    return addElementObject(&m_FZZOFDVectorGs,FZZOFDCOMPOSITEGRAPHICUNIT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDVectorG*> * FZZOFDCompositeGraphicUnits::getVectorGList()
{
    getElementObjectList(&m_FZZOFDVectorGs,FZZOFDCOMPOSITEGRAPHICUNIT_Name);
    return &m_FZZOFDVectorGs;
}
//-----------------------------------------------------------------------------------------------------------------

