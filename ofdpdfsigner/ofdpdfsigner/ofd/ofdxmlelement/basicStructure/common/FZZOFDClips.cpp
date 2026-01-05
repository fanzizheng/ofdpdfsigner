//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClips.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDClips**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips::FZZOFDClips() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDClips()");
    FZZConst::addClassCount("FZZOFDClips");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips::FZZOFDClips(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDClips");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips::FZZOFDClips(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDClips");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips::FZZOFDClips(const FZZOFDClips& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDClips");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDClip*>::const_iterator itr;
    for( itr = obj.m_FZZOFDClips.begin(); itr != obj.m_FZZOFDClips.end(); itr++ ) {
        FZZOFDClip * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDClips.push_back(new FZZOFDClip(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips::~FZZOFDClips()
{
    //DLOG("~FZZOFDClips()");
    FZZConst::delClassCount("FZZOFDClips");
    
    vector<FZZOFDClip*>::const_iterator itr;
    for( itr = m_FZZOFDClips.begin(); itr != m_FZZOFDClips.end(); itr++ ) {
        FZZOFDClip * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDClips.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClips::setTransFlag(bool value)
{
    setAttribute_Bool("TransFlag",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDClips::getTransFlag()
{
    return getAttribute_Bool("TransFlag",false);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClip * FZZOFDClips::addClip()
{
    return addElementObject(&m_FZZOFDClips,FZZOFDCLIP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDClip*> * FZZOFDClips::getClipList()
{
    getElementObjectList(&m_FZZOFDClips,FZZOFDCLIP_Name);
    return &m_FZZOFDClips;
}
//-----------------------------------------------------------------------------------------------------------------
