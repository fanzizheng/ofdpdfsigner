//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDPalette.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPalette**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette::FZZOFDPalette() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPalette()");
    FZZConst::addClassCount("FZZOFDPalette");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette::FZZOFDPalette(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDPalette");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette::FZZOFDPalette(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPalette");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette::FZZOFDPalette(const FZZOFDPalette& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPalette");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDCV*>::const_iterator itr;
    for( itr = obj.m_FZZOFDCVs.begin(); itr != obj.m_FZZOFDCVs.end(); itr++ ) {
        FZZOFDCV * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDCVs.push_back(new FZZOFDCV(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette::~FZZOFDPalette()
{
    //DLOG("~FZZOFDPalette()");
    FZZConst::delClassCount("FZZOFDPalette");
        
    vector<FZZOFDCV*>::const_iterator itr;
    for( itr = m_FZZOFDCVs.begin(); itr != m_FZZOFDCVs.end(); itr++ ) {
        FZZOFDCV * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDCVs.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV * FZZOFDPalette::addCV()
{
    return addElementObject(&m_FZZOFDCVs,FZZOFDCV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDCV*> * FZZOFDPalette::getCVList()
{
    getElementObjectList(&m_FZZOFDCVs,FZZOFDCV_Name);
    return &m_FZZOFDCVs;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPalette::getColorByIndex(string index,vector<string> & array)
{
    getCVList();
    long num = strtol(index.c_str(),NULL,10);
    if ( m_FZZOFDCVs.size() > num ) {
        FZZOFDCV * ofdCV = *(m_FZZOFDCVs.begin()+num);
        if ( ofdCV != NULL ) {
            ofdCV->getColor(array);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
