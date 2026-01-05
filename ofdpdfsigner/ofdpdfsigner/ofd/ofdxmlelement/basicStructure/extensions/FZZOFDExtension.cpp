//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/extensions/FZZOFDExtension.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDExtension**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension::FZZOFDExtension() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDExtension()");
    FZZConst::addClassCount("FZZOFDExtension");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension::FZZOFDExtension(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDExtension");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension::FZZOFDExtension(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDExtension");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension::FZZOFDExtension(const FZZOFDExtension& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDExtension");
    if ( this == &obj ) {
        return;
    }
    vector<FZZOFDProperty*>::const_iterator p_itr;
    for( p_itr = obj.m_FZZOFDPropertys.begin(); p_itr != obj.m_FZZOFDPropertys.end(); p_itr++ ) {
        FZZOFDProperty * temp = *p_itr;
        if ( temp != NULL ) {
            m_FZZOFDPropertys.push_back(new FZZOFDProperty(*temp));
        }
    }
    
    vector<FZZOFDExtendData*>::const_iterator e_itr;
    for( e_itr = obj.m_FZZOFDExtendDatas.begin(); e_itr != obj.m_FZZOFDExtendDatas.end(); e_itr++ ) {
        FZZOFDExtendData * temp = *e_itr;
        if ( temp != NULL ) {
            m_FZZOFDExtendDatas.push_back(new FZZOFDExtendData(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtension::~FZZOFDExtension()
{
    //DLOG("~FZZOFDExtension()");
    FZZConst::delClassCount("FZZOFDExtension");
    
    vector<FZZOFDProperty*>::const_iterator p_itr;
    for( p_itr = m_FZZOFDPropertys.begin(); p_itr != m_FZZOFDPropertys.end(); p_itr++ ) {
        FZZOFDProperty * temp = *p_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDPropertys.clear();
    
    vector<FZZOFDExtendData*>::const_iterator e_itr;
    for( e_itr = m_FZZOFDExtendDatas.begin(); e_itr != m_FZZOFDExtendDatas.end(); e_itr++ ) {
        FZZOFDExtendData * temp = *e_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDExtendDatas.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setAppName(string value)
{
    setAttribute_String("AppName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtension::getAppName()
{
    return getAttribute_String("AppName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setCompany(string value)
{
    setAttribute_String("Company",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtension::getCompany()
{
    return getAttribute_String("Company");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setAppVersion(string value)
{
    setAttribute_String("AppVersion",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtension::getAppVersion()
{
    return getAttribute_String("AppVersion");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setDate(string value)
{
    setAttribute_String("Date",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtension::getDate()
{
    return getAttribute_String("Date");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setRefId(string value)
{
    setAttribute_String("RefId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDExtension::getRefId()
{
    return getAttribute_String("RefId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDExtension::setRefId(long value)
{
    setAttribute_long("RefId",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDExtension::getRefId_long()
{
    return getAttribute_long("RefId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProperty * FZZOFDExtension::addProperty()
{
    return addElementObject(&m_FZZOFDPropertys,FZZOFDPROPERTY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDProperty*> * FZZOFDExtension::getPropertyList()
{
    getElementObjectList(&m_FZZOFDPropertys,FZZOFDPROPERTY_Name);
    return &m_FZZOFDPropertys;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDExtendData * FZZOFDExtension::addExtendData()
{
    return addElementObject(&m_FZZOFDExtendDatas,FZZOFDEXTENDDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDExtendData*> * FZZOFDExtension::getExtendDataList()
{
    getElementObjectList(&m_FZZOFDExtendDatas,FZZOFDEXTENDDATA_Name);
    return &m_FZZOFDExtendDatas;
}
//-----------------------------------------------------------------------------------------------------------------
