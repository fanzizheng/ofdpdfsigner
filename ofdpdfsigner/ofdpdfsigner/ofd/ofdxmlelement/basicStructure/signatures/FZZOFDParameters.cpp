//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameters.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDParameters**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters::FZZOFDParameters() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDParameters()");
    FZZConst::addClassCount("FZZOFDParameters");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters::FZZOFDParameters(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDParameters");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters::FZZOFDParameters(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDParameters");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters::FZZOFDParameters(const FZZOFDParameters& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDParameters");
    if ( this == &obj ) {
        return;
    }
  
    vector<FZZOFDParameter*>::const_iterator itr;
    for( itr = obj.m_FZZOFDParameters.begin(); itr != obj.m_FZZOFDParameters.end(); itr++ ) {
        FZZOFDParameter * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDParameters.push_back(new FZZOFDParameter(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters::~FZZOFDParameters()
{
    //DLOG("~FZZOFDParameters()");
    FZZConst::delClassCount("FZZOFDParameters");
   
    vector<FZZOFDParameter*>::const_iterator itr;
    for( itr = m_FZZOFDParameters.begin(); itr != m_FZZOFDParameters.end(); itr++ ) {
        FZZOFDParameter * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDParameters.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter * FZZOFDParameters::addParameter_SignType()
{
    return addElementObject(&m_FZZOFDParameters,FZZOFDPARAMETER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDParameter*> * FZZOFDParameters::getParameterList_SignType()
{
    getElementObjectList(&m_FZZOFDParameters,FZZOFDPARAMETER_Name);
    return &m_FZZOFDParameters;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameter * FZZOFDParameters::addParameter_AnnotType()
{
    return addElementObject(&m_FZZOFDParameters,CPARAMETER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDParameter*> * FZZOFDParameters::getParameterList_AnnotType()
{
    getElementObjectList(&m_FZZOFDParameters,CPARAMETER_Name);
    return &m_FZZOFDParameters;
}
//-----------------------------------------------------------------------------------------------------------------
