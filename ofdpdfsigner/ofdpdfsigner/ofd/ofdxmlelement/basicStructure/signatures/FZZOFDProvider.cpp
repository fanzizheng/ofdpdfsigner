//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDProvider.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDProvider**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider::FZZOFDProvider() : FZZOFDXMLElementObject(),m_FZZOFDExtendData(NULL)
{
    //DLOG("FZZOFDProvider()");
    FZZConst::addClassCount("FZZOFDProvider");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider::FZZOFDProvider(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDExtendData(NULL)
{
    
    FZZConst::addClassCount("FZZOFDProvider");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider::FZZOFDProvider(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDExtendData(NULL)
{
    FZZConst::addClassCount("FZZOFDProvider");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider::FZZOFDProvider(const FZZOFDProvider& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDProvider");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDExtendData = obj.m_FZZOFDExtendData != NULL ? new FZZOFDExtendData(*obj.m_FZZOFDExtendData) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProvider::~FZZOFDProvider()
{
    //DLOG("~FZZOFDProvider()");
    FZZConst::delClassCount("FZZOFDProvider");
    if ( m_FZZOFDExtendData != NULL ) {
        delete m_FZZOFDExtendData;
        m_FZZOFDExtendData = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProvider::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProvider::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProvider::setProviderName(string value)
{
    setAttribute_String("ProviderName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProvider::getProviderName()
{
    return getAttribute_String("ProviderName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProvider::setVersion(string value)
{
    setAttribute_String("Version",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProvider::getVersion()
{
    return getAttribute_String("Version");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProvider::setCompany(string value)
{
    setAttribute_String("Company",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProvider::getCompany()
{
    return getAttribute_String("Company");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProvider::setProtocolVer(string value)
{
    setAttribute_String("ProtocolVer",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDProvider::getProtocolVer()
{
    return getAttribute_String("ProtocolVer");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData * FZZOFDProvider::setExtendData()
{
    return m_FZZOFDExtendData = setElementObject(m_FZZOFDExtendData,FZZOFDEXTENDDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData * FZZOFDProvider::getExtendData()
{
    return m_FZZOFDExtendData = getElementObject(m_FZZOFDExtendData,FZZOFDEXTENDDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
