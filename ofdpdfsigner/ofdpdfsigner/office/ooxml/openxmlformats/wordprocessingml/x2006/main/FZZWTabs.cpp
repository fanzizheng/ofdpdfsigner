//
//  Created by zizheng fan on 2023/11/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTabs.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTabs**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs::FZZWTabs() : FZZXMLElementObject()
{
    //DLOG("FZZWTabs()");
    FZZConst::addClassCount("FZZWTabs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs::FZZWTabs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTabs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs::FZZWTabs(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTabs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs::FZZWTabs(const FZZWTabs& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTabs");
    if ( this == &obj ) {
        return;
    }

    vector<FZZWTab*>::const_iterator itr;
    for( itr = obj.m_FZZWTabs.begin(); itr != obj.m_FZZWTabs.end(); itr++ ) {
        FZZWTab * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWTabs.push_back(new FZZWTab(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTabs::~FZZWTabs()
{
    //DLOG("~FZZWTabs()");
    FZZConst::delClassCount("FZZWTabs");
    vector<FZZWTab*>::const_iterator itr;
    for( itr = m_FZZWTabs.begin(); itr != m_FZZWTabs.end(); itr++ ) {
        FZZWTab * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWTabs.clear();
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWTabs::setVal(string value)
//{
//    setAttribute_String("w:val",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWTabs::getVal()
//{
//    string retstr = getAttribute_String("w:val");
//    return retstr;
//}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWTabs::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWTabs::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab * FZZWTabs::addTab()
{
    return addElementObject(&m_FZZWTabs,FZZWTAB_Find_Key,FZZWTAB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWTab*> * FZZWTabs::getTabs()
{
    getElementObjectList(&m_FZZWTabs,FZZWTAB_Find_Key,FZZWTAB_Name);
    return &m_FZZWTabs;
}
//-----------------------------------------------------------------------------------------------------------------
