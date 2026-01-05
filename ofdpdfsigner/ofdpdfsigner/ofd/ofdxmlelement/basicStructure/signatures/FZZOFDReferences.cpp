//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReferences.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDReferences**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences::FZZOFDReferences() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDReferences()");
    FZZConst::addClassCount("FZZOFDReferences");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences::FZZOFDReferences(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDReferences");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences::FZZOFDReferences(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDReferences");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences::FZZOFDReferences(const FZZOFDReferences& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDReferences");
    if ( this == &obj ) {
        return;
    }
  
    vector<FZZOFDReference*>::const_iterator itr;
    for( itr = obj.m_FZZOFDReferences.begin(); itr != obj.m_FZZOFDReferences.end(); itr++ ) {
        FZZOFDReference * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDReferences.push_back(new FZZOFDReference(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences::~FZZOFDReferences()
{
    //DLOG("~FZZOFDReferences()");
    FZZConst::delClassCount("FZZOFDReferences");
   
    vector<FZZOFDReference*>::const_iterator itr;
    for( itr = m_FZZOFDReferences.begin(); itr != m_FZZOFDReferences.end(); itr++ ) {
        FZZOFDReference * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDReferences.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDReferences::setCheckMethod(FZZOFDCheckMethod::TYPE type)
{
    setAttribute_String("CheckMethod",FZZOFDCheckMethod::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckMethod::TYPE FZZOFDReferences::getCheckMethod()
{
    return FZZOFDCheckMethod::toType(getAttribute_String("CheckMethod").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDReferences::getCheckMethod_String()
{
    return getAttribute_String("CheckMethod");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference * FZZOFDReferences::addReference()
{
    return addElementObject(&m_FZZOFDReferences,FZZOFDREFERENCE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDReference*> * FZZOFDReferences::getReferenceList()
{
    getElementObjectList(&m_FZZOFDReferences,FZZOFDREFERENCE_Name);
    return &m_FZZOFDReferences;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDReferences::hasFile(string & absLoc)
{
    string strAbsLoc = absLoc;
    transform(strAbsLoc.begin(), strAbsLoc.end(), strAbsLoc.begin(), ::tolower);
    if ( strAbsLoc[0] == '/' ) {
        strAbsLoc = strAbsLoc.substr(1);
    }
    if ( m_FZZOFDReferences.size() <= 0 ) {
        getReferenceList();
    }
    vector<FZZOFDReference*>::const_iterator iter;
    for (iter = m_FZZOFDReferences.begin(); iter != m_FZZOFDReferences.end(); iter++) {
        string temploc = (*iter)->getFileRef();
        if ( temploc.empty() ) {
            continue;
        }
        transform(temploc.begin(), temploc.end(), temploc.begin(), ::tolower);
        
        if ( temploc[0] == '/' ) {
            temploc = temploc.substr(1);
        }
        
        if ( strAbsLoc == temploc ) {
            return true;
        }
    }
    return false;
}
//-----------------------------------------------------------------------------------------------------------------
