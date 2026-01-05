//
//  Created by zizheng fan on 2024/10/16.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDExtendParams.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDExtendParams**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams::FZZOFDExtendParams() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDExtendParams()");
    FZZConst::addClassCount("FZZOFDExtendParams");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams::FZZOFDExtendParams(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDExtendParams");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams::FZZOFDExtendParams(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDExtendParams");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams::FZZOFDExtendParams(const FZZOFDExtendParams& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDExtendParams");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDEncParameter*>::const_iterator p_itr;
    for( p_itr = obj.m_FZZOFDEncParameters.begin(); p_itr != obj.m_FZZOFDEncParameters.end(); p_itr++ ) {
        FZZOFDEncParameter * temp = *p_itr;
        if ( temp != NULL ) {
            m_FZZOFDEncParameters.push_back(new FZZOFDEncParameter(*temp));
        }
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams::~FZZOFDExtendParams()
{
    //DLOG("~FZZOFDExtendParams()");
    FZZConst::delClassCount("FZZOFDExtendParams");
    
    vector<FZZOFDEncParameter*>::const_iterator p_itr;
    for( p_itr = m_FZZOFDEncParameters.begin(); p_itr != m_FZZOFDEncParameters.end(); p_itr++ ) {
        FZZOFDEncParameter * temp = *p_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDEncParameters.clear();
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncParameter * FZZOFDExtendParams::addParameter()
{
    return addElementObject(&m_FZZOFDEncParameters,FZZOFDENCPARAMETER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDEncParameter*> * FZZOFDExtendParams::getParameterList()
{
    getElementObjectList(&m_FZZOFDEncParameters,FZZOFDENCPARAMETER_Name);
    return &m_FZZOFDEncParameters;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZOFDExtendParams::clearFile()
//{
//    vector<FZZOFDFile*>::const_iterator p_itr;
//    for( p_itr = m_FZZOFDFiles.begin(); p_itr != m_FZZOFDFiles.end(); p_itr++ ) {
//        FZZOFDFile * temp = *p_itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZOFDFiles.clear();
//
//    clearElementObjectList(FZZOFDFILE_Name);
//}
////-----------------------------------------------------------------------------------------------------------------

