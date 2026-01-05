//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocBody**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody::FZZOFDDocBody() : FZZOFDXMLElementObject(),m_FZZOFDDocInfo(NULL),m_FZZOFDDocRoot(NULL),m_FZZOFDDocBody_Signatures(NULL),m_FZZOFDVersions(NULL)
{
    FZZConst::addClassCount("FZZOFDDocBody");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody::FZZOFDDocBody(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true),m_FZZOFDDocInfo(NULL),m_FZZOFDDocRoot(NULL),m_FZZOFDDocBody_Signatures(NULL),m_FZZOFDVersions(NULL)
{
    FZZConst::addClassCount("FZZOFDDocBody");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody::FZZOFDDocBody(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDDocInfo(NULL),m_FZZOFDDocRoot(NULL),m_FZZOFDDocBody_Signatures(NULL),m_FZZOFDVersions(NULL)
{
    FZZConst::addClassCount("FZZOFDDocBody");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody::FZZOFDDocBody(const FZZOFDDocBody& obj) : FZZOFDXMLElementObject(obj)
{
 
    FZZConst::addClassCount("FZZOFDDocBody");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDDocInfo = obj.m_FZZOFDDocInfo != NULL ? new FZZOFDDocInfo(*obj.m_FZZOFDDocInfo) : NULL;
    m_FZZOFDDocRoot = obj.m_FZZOFDDocRoot != NULL ? new FZZOFDDocRoot(*obj.m_FZZOFDDocRoot) : NULL;
    m_FZZOFDDocBody_Signatures = obj.m_FZZOFDDocBody_Signatures != NULL ? new FZZOFDDocBody_Signatures(*obj.m_FZZOFDDocBody_Signatures) : NULL;
    m_FZZOFDVersions = obj.m_FZZOFDVersions != NULL ? new FZZOFDVersions(*obj.m_FZZOFDVersions) : NULL;

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody::~FZZOFDDocBody()
{
    //DLOG("~FZZOFDDocBody()");
    FZZConst::delClassCount("FZZOFDDocBody");
    if ( m_FZZOFDDocInfo != NULL ) {
        delete m_FZZOFDDocInfo;
        m_FZZOFDDocInfo = NULL;
    }
    if ( m_FZZOFDDocRoot != NULL ) {
        delete m_FZZOFDDocRoot;
        m_FZZOFDDocRoot = NULL;
    }
    if ( m_FZZOFDDocBody_Signatures != NULL ) {
        delete m_FZZOFDDocBody_Signatures;
        m_FZZOFDDocBody_Signatures = NULL;
    }
    if ( m_FZZOFDVersions != NULL ) {
        delete m_FZZOFDVersions;
        m_FZZOFDVersions = NULL;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo * FZZOFDDocBody::setDocInfo()
{
    return m_FZZOFDDocInfo = setElementObject(m_FZZOFDDocInfo,FZZOFDDOCINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo * FZZOFDDocBody::getDocInfo()
{
    return m_FZZOFDDocInfo = getElementObject(m_FZZOFDDocInfo,FZZOFDDOCINFO_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot * FZZOFDDocBody::setDocRoot()
{
    return m_FZZOFDDocRoot = setElementObject(m_FZZOFDDocRoot,FZZOFDDOCROOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocRoot * FZZOFDDocBody::getDocRoot()
{
    return m_FZZOFDDocRoot = getElementObject(m_FZZOFDDocRoot,FZZOFDDOCROOT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures * FZZOFDDocBody::setSignatures()
{
    return m_FZZOFDDocBody_Signatures = setElementObject(m_FZZOFDDocBody_Signatures,FZZOFDDOCBODY_SIGNATURES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocBody_Signatures * FZZOFDDocBody::getSignatures()
{
    return m_FZZOFDDocBody_Signatures = getElementObject(m_FZZOFDDocBody_Signatures,FZZOFDDOCBODY_SIGNATURES_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions * FZZOFDDocBody::setVersions()
{
    return m_FZZOFDVersions = setElementObject(m_FZZOFDVersions,FZZOFDVERSIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersions * FZZOFDDocBody::getVersions()
{
    return m_FZZOFDVersions = getElementObject(m_FZZOFDVersions,FZZOFDVERSIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
