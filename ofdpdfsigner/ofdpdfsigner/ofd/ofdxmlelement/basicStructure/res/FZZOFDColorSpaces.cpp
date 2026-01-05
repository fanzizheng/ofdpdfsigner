//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpaces.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDColorSpaces**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces::FZZOFDColorSpaces() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDColorSpaces()");
    FZZConst::addClassCount("FZZOFDColorSpaces");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces::FZZOFDColorSpaces(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDColorSpaces");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces::FZZOFDColorSpaces(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDColorSpaces");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces::FZZOFDColorSpaces(const FZZOFDColorSpaces& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDColorSpaces");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDColorSpace*>::const_iterator itr;
    for( itr = obj.m_FZZOFDColorSpaces.begin(); itr != obj.m_FZZOFDColorSpaces.end(); itr++ ) {
        FZZOFDColorSpace * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDColorSpaces.push_back(new FZZOFDColorSpace(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpaces::~FZZOFDColorSpaces()
{
    //DLOG("~FZZOFDColorSpaces()");
    FZZConst::delClassCount("FZZOFDColorSpaces");
        
    vector<FZZOFDColorSpace*>::const_iterator itr;
    for( itr = m_FZZOFDColorSpaces.begin(); itr != m_FZZOFDColorSpaces.end(); itr++ ) {
        FZZOFDColorSpace * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDColorSpaces.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace * FZZOFDColorSpaces::addColorSpace()
{
    return addElementObject(&m_FZZOFDColorSpaces,FZZOFDCOLORSPACE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDColorSpace*> * FZZOFDColorSpaces::getColorSpaceList()
{
    getElementObjectList(&m_FZZOFDColorSpaces,FZZOFDCOLORSPACE_Name);
    return &m_FZZOFDColorSpaces;
}
//-----------------------------------------------------------------------------------------------------------------

