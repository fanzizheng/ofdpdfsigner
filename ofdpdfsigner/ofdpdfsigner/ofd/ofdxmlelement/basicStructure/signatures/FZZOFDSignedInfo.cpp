//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedInfo.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSignedInfo**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo::FZZOFDSignedInfo() : FZZOFDXMLElementObject(),m_FZZOFDSignatureMethod(NULL),m_FZZOFDSignatureDateTime(NULL)
,m_FZZOFDProvider(NULL),m_FZZOFDReferences(NULL),m_FZZOFDSeal(NULL),m_FZZOFDParameters(NULL)
{
    //DLOG("FZZOFDSignedInfo()");
    FZZConst::addClassCount("FZZOFDSignedInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo::FZZOFDSignedInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDSignatureMethod(NULL),m_FZZOFDSignatureDateTime(NULL),m_FZZOFDProvider(NULL),m_FZZOFDReferences(NULL),m_FZZOFDSeal(NULL),m_FZZOFDParameters(NULL)
{
    
    FZZConst::addClassCount("FZZOFDSignedInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo::FZZOFDSignedInfo(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDSignatureMethod(NULL)
,m_FZZOFDSignatureDateTime(NULL),m_FZZOFDProvider(NULL),m_FZZOFDReferences(NULL),m_FZZOFDSeal(NULL),m_FZZOFDParameters(NULL)
{
    FZZConst::addClassCount("FZZOFDSignedInfo");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo::FZZOFDSignedInfo(const FZZOFDSignedInfo& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSignedInfo");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDSignatureMethod = obj.m_FZZOFDSignatureMethod != NULL ? new FZZOFDSignatureMethod(*obj.m_FZZOFDSignatureMethod) : NULL;
    m_FZZOFDSignatureDateTime = obj.m_FZZOFDSignatureDateTime != NULL ? new FZZOFDSignatureDateTime(*obj.m_FZZOFDSignatureDateTime) : NULL;
    m_FZZOFDProvider = obj.m_FZZOFDProvider != NULL ? new FZZOFDProvider(*obj.m_FZZOFDProvider) : NULL;
    m_FZZOFDReferences = obj.m_FZZOFDReferences != NULL ? new FZZOFDReferences(*obj.m_FZZOFDReferences) : NULL;
    m_FZZOFDSeal = obj.m_FZZOFDSeal != NULL ? new FZZOFDSeal(*obj.m_FZZOFDSeal) : NULL;
    m_FZZOFDParameters = obj.m_FZZOFDParameters != NULL ? new FZZOFDParameters(*obj.m_FZZOFDParameters) : NULL;
    
    vector<FZZOFDStampAnnot*>::const_iterator itr;
    for( itr = obj.m_FZZOFDStampAnnots.begin(); itr != obj.m_FZZOFDStampAnnots.end(); itr++ ) {
        FZZOFDStampAnnot * temp = *itr;
        if ( temp != NULL ) {
            m_FZZOFDStampAnnots.push_back(new FZZOFDStampAnnot(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedInfo::~FZZOFDSignedInfo()
{
    //DLOG("~FZZOFDSignedInfo()");
    FZZConst::delClassCount("FZZOFDSignedInfo");
    if ( m_FZZOFDSignatureMethod != NULL ) {
        delete m_FZZOFDSignatureMethod;
        m_FZZOFDSignatureMethod = NULL;
    }
    if ( m_FZZOFDSignatureDateTime != NULL ) {
        delete m_FZZOFDSignatureDateTime;
        m_FZZOFDSignatureDateTime = NULL;
    }
    if ( m_FZZOFDProvider != NULL ) {
        delete m_FZZOFDProvider;
        m_FZZOFDProvider = NULL;
    }
    if ( m_FZZOFDReferences != NULL ) {
        delete m_FZZOFDReferences;
        m_FZZOFDReferences = NULL;
    }
    if ( m_FZZOFDSeal != NULL ) {
        delete m_FZZOFDSeal;
        m_FZZOFDSeal = NULL;
    }
    if ( m_FZZOFDParameters != NULL ) {
        delete m_FZZOFDParameters;
        m_FZZOFDParameters = NULL;
    }
    
    vector<FZZOFDStampAnnot*>::const_iterator itr;
    for( itr = m_FZZOFDStampAnnots.begin(); itr != m_FZZOFDStampAnnots.end(); itr++ ) {
        FZZOFDStampAnnot * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDStampAnnots.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod * FZZOFDSignedInfo::setSignatureMethod()
{
    return m_FZZOFDSignatureMethod = setElementObject(m_FZZOFDSignatureMethod,FZZOFDSIGNATUREMETHOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureMethod * FZZOFDSignedInfo::getSignatureMethod()
{
    return m_FZZOFDSignatureMethod = getElementObject(m_FZZOFDSignatureMethod,FZZOFDSIGNATUREMETHOD_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime * FZZOFDSignedInfo::setSignatureDateTime()
{
    return m_FZZOFDSignatureDateTime = setElementObject(m_FZZOFDSignatureDateTime,FZZOFDSIGNATUREDATETIME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignatureDateTime * FZZOFDSignedInfo::getSignatureDateTime()
{
    return m_FZZOFDSignatureDateTime = getElementObject(m_FZZOFDSignatureDateTime,FZZOFDSIGNATUREDATETIME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider * FZZOFDSignedInfo::setProvider()
{
    return m_FZZOFDProvider = setElementObject(m_FZZOFDProvider,FZZOFDPROVIDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider * FZZOFDSignedInfo::getProvider()
{
    return m_FZZOFDProvider = getElementObject(m_FZZOFDProvider,FZZOFDPROVIDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences * FZZOFDSignedInfo::setReferences()
{
    return m_FZZOFDReferences = setElementObject(m_FZZOFDReferences,FZZOFDREFERENCES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReferences * FZZOFDSignedInfo::getReferences()
{
    return m_FZZOFDReferences = getElementObject(m_FZZOFDReferences,FZZOFDREFERENCES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal * FZZOFDSignedInfo::setSeal()
{
    return m_FZZOFDSeal = setElementObject(m_FZZOFDSeal,FZZOFDSEAL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSeal * FZZOFDSignedInfo::getSeal()
{
    return m_FZZOFDSeal = getElementObject(m_FZZOFDSeal,FZZOFDSEAL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters * FZZOFDSignedInfo::setParameters()
{
    return m_FZZOFDParameters = setElementObject(m_FZZOFDParameters,FZZOFDPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters * FZZOFDSignedInfo::getParameters()
{
    return m_FZZOFDParameters = getElementObject(m_FZZOFDParameters,FZZOFDPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot * FZZOFDSignedInfo::addStampAnnot()
{
    return addElementObject(&m_FZZOFDStampAnnots,FZZOFDSTAMPANNOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDStampAnnot*> * FZZOFDSignedInfo::getStampAnnotList()
{
    getElementObjectList(&m_FZZOFDStampAnnots,FZZOFDSTAMPANNOT_Name);
    return &m_FZZOFDStampAnnots;
}
//-----------------------------------------------------------------------------------------------------------------
