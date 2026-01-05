//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParams.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDrawParams**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams::FZZOFDDrawParams() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDrawParams()");
    FZZConst::addClassCount("FZZOFDDrawParams");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams::FZZOFDDrawParams(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDDrawParams");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams::FZZOFDDrawParams(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDrawParams");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams::FZZOFDDrawParams(const FZZOFDDrawParams& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDDrawParams");
    if ( this == &obj ) {
        return;
    }
    
    
    vector<FZZOFDDrawParam*>::const_iterator itr;
    for( itr = obj.m_FZZOFDDrawParams.begin(); itr != obj.m_FZZOFDDrawParams.end(); itr++ ) {
        FZZOFDDrawParam * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDDrawParams.push_back(new FZZOFDDrawParam(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParams::~FZZOFDDrawParams()
{
    //DLOG("~FZZOFDDrawParams()");
    FZZConst::delClassCount("FZZOFDDrawParams");
        
    vector<FZZOFDDrawParam*>::const_iterator itr;
    for( itr = m_FZZOFDDrawParams.begin(); itr != m_FZZOFDDrawParams.end(); itr++ ) {
        FZZOFDDrawParam * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDDrawParams.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam * FZZOFDDrawParams::addDrawParam()
{
    return addElementObject(&m_FZZOFDDrawParams,FZZOFDDRAWPARAM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDDrawParam*> * FZZOFDDrawParams::getDrawParamList()
{
    getElementObjectList(&m_FZZOFDDrawParams,FZZOFDDRAWPARAM_Name);
    return &m_FZZOFDDrawParams;
}
//-----------------------------------------------------------------------------------------------------------------

