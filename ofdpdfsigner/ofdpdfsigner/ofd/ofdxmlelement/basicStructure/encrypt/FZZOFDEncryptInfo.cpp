//
//  Created by zizheng fan on 2024/10/19.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptInfo.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEncryptInfo**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo::FZZOFDEncryptInfo() : FZZOFDXMLElementObject(),m_FZZOFDProvider(NULL),m_FZZOFDEncryptScope(NULL),m_FZZOFDExtendParams(NULL),m_FZZOFDEntriesMapLoc(NULL),m_FZZOFDDecryptSeedLoc(NULL),m_FZZOFDEncryptDate(NULL)
{
    //DLOG("FZZOFDEncryptInfo()");
    FZZConst::addClassCount("FZZOFDEncryptInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo::FZZOFDEncryptInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false),m_FZZOFDProvider(NULL),m_FZZOFDEncryptScope(NULL),m_FZZOFDExtendParams(NULL),m_FZZOFDEntriesMapLoc(NULL),m_FZZOFDDecryptSeedLoc(NULL),m_FZZOFDEncryptDate(NULL)
{
    
    FZZConst::addClassCount("FZZOFDEncryptInfo");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo::FZZOFDEncryptInfo(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDProvider(NULL),m_FZZOFDEncryptScope(NULL),m_FZZOFDExtendParams(NULL),m_FZZOFDEntriesMapLoc(NULL),m_FZZOFDDecryptSeedLoc(NULL),m_FZZOFDEncryptDate(NULL)
{
    FZZConst::addClassCount("FZZOFDEncryptInfo");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo::FZZOFDEncryptInfo(const FZZOFDEncryptInfo& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDEncryptInfo");
    if ( this == &obj ) {
        return;
    }

    m_FZZOFDProvider = obj.m_FZZOFDProvider != NULL ? new FZZOFDProvider(*obj.m_FZZOFDProvider) : NULL;
    m_FZZOFDEncryptScope = obj.m_FZZOFDEncryptScope != NULL ? new FZZOFDEncryptScope(*obj.m_FZZOFDEncryptScope) : NULL;
    m_FZZOFDExtendParams = obj.m_FZZOFDExtendParams != NULL ? new FZZOFDExtendParams(*obj.m_FZZOFDExtendParams) : NULL;
    
    m_FZZOFDEntriesMapLoc = obj.m_FZZOFDEntriesMapLoc != NULL ? new FZZOFDEntriesMapLoc(*obj.m_FZZOFDEntriesMapLoc) : NULL;
    m_FZZOFDDecryptSeedLoc = obj.m_FZZOFDDecryptSeedLoc != NULL ? new FZZOFDDecryptSeedLoc(*obj.m_FZZOFDDecryptSeedLoc) : NULL;
    m_FZZOFDEncryptDate = obj.m_FZZOFDEncryptDate != NULL ? new FZZOFDEncryptDate(*obj.m_FZZOFDEncryptDate) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptInfo::~FZZOFDEncryptInfo()
{
    //DLOG("~FZZOFDEncryptInfo()");
    FZZConst::delClassCount("FZZOFDEncryptInfo");
   
    if ( m_FZZOFDProvider != NULL ) {
        delete m_FZZOFDProvider;
        m_FZZOFDProvider = NULL;
    }
    
    if ( m_FZZOFDEncryptScope != NULL ) {
        delete m_FZZOFDEncryptScope;
        m_FZZOFDEncryptScope = NULL;
    }
    
    if ( m_FZZOFDExtendParams != NULL ) {
        delete m_FZZOFDExtendParams;
        m_FZZOFDExtendParams = NULL;
    }
    
    if ( m_FZZOFDEntriesMapLoc != NULL ) {
        delete m_FZZOFDEntriesMapLoc;
        m_FZZOFDEntriesMapLoc = NULL;
    }
    
    if ( m_FZZOFDDecryptSeedLoc != NULL ) {
        delete m_FZZOFDDecryptSeedLoc;
        m_FZZOFDDecryptSeedLoc = NULL;
    }
    
    if ( m_FZZOFDEncryptDate != NULL ) {
        delete m_FZZOFDEncryptDate;
        m_FZZOFDEncryptDate = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptInfo::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptInfo::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncryptInfo::setRelative(string value)
{
    setAttribute_String("Relative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEncryptInfo::getRelative()
{
    return getAttribute_String("Relative");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider * FZZOFDEncryptInfo::setProvider()
{
    return m_FZZOFDProvider = setElementObject(m_FZZOFDProvider,FZZOFDPROVIDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider * FZZOFDEncryptInfo::getProvider()
{
    return m_FZZOFDProvider = getElementObject(m_FZZOFDProvider,FZZOFDPROVIDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope * FZZOFDEncryptInfo::setEncryptScope()
{
    return m_FZZOFDEncryptScope = setElementObject(m_FZZOFDEncryptScope,FZZOFDENCRYPTSCOPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptScope * FZZOFDEncryptInfo::getEncryptScope()
{
    return m_FZZOFDEncryptScope = getElementObject(m_FZZOFDEncryptScope,FZZOFDENCRYPTSCOPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams * FZZOFDEncryptInfo::setParameters()
{
    return m_FZZOFDExtendParams = setElementObject(m_FZZOFDExtendParams,FZZOFDENCINFOPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendParams * FZZOFDEncryptInfo::getParameters()
{
    return m_FZZOFDExtendParams = getElementObject(m_FZZOFDExtendParams,FZZOFDENCINFOPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc * FZZOFDEncryptInfo::setEntriesMapLoc()
{
    return m_FZZOFDEntriesMapLoc = setElementObject(m_FZZOFDEntriesMapLoc,FZZOFDENRIESMAPLOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesMapLoc * FZZOFDEncryptInfo::getEntriesMapLoc()
{
    return m_FZZOFDEntriesMapLoc = getElementObject(m_FZZOFDEntriesMapLoc,FZZOFDENRIESMAPLOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc * FZZOFDEncryptInfo::setDecryptSeedLoc()
{
    return m_FZZOFDDecryptSeedLoc = setElementObject(m_FZZOFDDecryptSeedLoc,FZZOFDDECRYPTSEEDLOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDecryptSeedLoc * FZZOFDEncryptInfo::getDecryptSeedLoc()
{
    return m_FZZOFDDecryptSeedLoc = getElementObject(m_FZZOFDDecryptSeedLoc,FZZOFDDECRYPTSEEDLOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate * FZZOFDEncryptInfo::setEncryptDate()
{
    return m_FZZOFDEncryptDate = setElementObject(m_FZZOFDEncryptDate,FZZOFDENCRYPTDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncryptDate * FZZOFDEncryptInfo::getEncryptDate()
{
    return m_FZZOFDEncryptDate = getElementObject(m_FZZOFDEncryptDate,FZZOFDENCRYPTDATE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
