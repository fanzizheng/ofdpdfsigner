//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlines.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDOutlines**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines::FZZOFDOutlines() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDOutlines()");
    FZZConst::addClassCount("FZZOFDOutlines");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines::FZZOFDOutlines(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDOutlines");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines::FZZOFDOutlines(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDOutlines");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines::FZZOFDOutlines(const FZZOFDOutlines& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDOutlines");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDOutlineElem*>::const_iterator itr;
    for( itr = obj.m_FZZOFDOutlineElems.begin(); itr != obj.m_FZZOFDOutlineElems.end(); itr++ ) {
        FZZOFDOutlineElem * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDOutlineElems.push_back(new FZZOFDOutlineElem(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlines::~FZZOFDOutlines()
{
    //DLOG("~FZZOFDOutlines()");
    FZZConst::delClassCount("FZZOFDOutlines");
    
    vector<FZZOFDOutlineElem*>::const_iterator itr;
    for( itr = m_FZZOFDOutlineElems.begin(); itr != m_FZZOFDOutlineElems.end(); itr++ ) {
        FZZOFDOutlineElem * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDOutlineElems.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDOutlineElem * FZZOFDOutlines::addOutlineElem()
{
    return addElementObject(&m_FZZOFDOutlineElems,FZZOFDOUTLINEELEM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDOutlineElem*> * FZZOFDOutlines::getOutlineElemList()
{
    getElementObjectList(&m_FZZOFDOutlineElems,FZZOFDOUTLINEELEM_Name);
    return &m_FZZOFDOutlineElems;
}
//-----------------------------------------------------------------------------------------------------------------
