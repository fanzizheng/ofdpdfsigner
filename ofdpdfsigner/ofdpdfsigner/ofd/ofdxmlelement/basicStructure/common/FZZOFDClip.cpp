//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClip.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDClip**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip::FZZOFDClip() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDClip()");
    FZZConst::addClassCount("FZZOFDClip");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip::FZZOFDClip(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDClip");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip::FZZOFDClip(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDClip");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip::FZZOFDClip(const FZZOFDClip& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDClip");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDClipArea*>::const_iterator itr;
    for( itr = obj.m_FZZOFDClipAreas.begin(); itr != obj.m_FZZOFDClipAreas.end(); itr++ ) {
        FZZOFDClipArea * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDClipAreas.push_back(new FZZOFDClipArea(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip::~FZZOFDClip()
{
    //DLOG("~FZZOFDClip()");
    FZZConst::delClassCount("FZZOFDClip");
    
    vector<FZZOFDClipArea*>::const_iterator itr;
    for( itr = m_FZZOFDClipAreas.begin(); itr != m_FZZOFDClipAreas.end(); itr++ ) {
        FZZOFDClipArea * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDClipAreas.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea * FZZOFDClip::addArea()
{
    return addElementObject(&m_FZZOFDClipAreas,FZZOFDCLIPAREA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDClipArea*> * FZZOFDClip::getAreaList()
{
    getElementObjectList(&m_FZZOFDClipAreas,FZZOFDCLIPAREA_Name);
    return &m_FZZOFDClipAreas;
}
//-----------------------------------------------------------------------------------------------------------------
