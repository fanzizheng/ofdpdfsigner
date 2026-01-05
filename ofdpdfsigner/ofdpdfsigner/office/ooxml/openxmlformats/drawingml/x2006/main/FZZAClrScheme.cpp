//
//  Created by zizheng fan on 2023/08/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAClrScheme**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme::FZZAClrScheme() : FZZXMLElementObject(),m_hlink(NULL),m_folHlink(NULL)
    ,m_dkCount(0),m_ltCount(0),m_accentCount(0)
{
    //DLOG("FZZAClrScheme()");
    FZZConst::addClassCount("FZZAClrScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme::FZZAClrScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_hlink(NULL),m_folHlink(NULL)
    ,m_dkCount(0),m_ltCount(0),m_accentCount(0)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAClrScheme");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme::FZZAClrScheme(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_hlink(NULL),m_folHlink(NULL)
    ,m_dkCount(0),m_ltCount(0),m_accentCount(0)
{
    FZZConst::addClassCount("FZZAClrScheme");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme::FZZAClrScheme(const FZZAClrScheme& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAClrScheme");
    if ( this == &obj ) {
        return;
    }

    m_hlink = obj.m_hlink != NULL ? new FZZAClrScheme_Item(*obj.m_hlink) : NULL;
    m_folHlink = obj.m_folHlink != NULL ? new FZZAClrScheme_Item(*obj.m_folHlink) : NULL;
    m_dkCount = obj.m_dkCount;
    m_ltCount = obj.m_ltCount;
    m_accentCount = obj.m_accentCount;
    
    vector<FZZAClrScheme_Item*>::const_iterator itr;
    for( itr = obj.m_dkList.begin(); itr != obj.m_dkList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            m_dkList.push_back(new FZZAClrScheme_Item(*temp));
        }
    }
    
    
    for( itr = obj.m_ltList.begin(); itr != obj.m_ltList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            m_ltList.push_back(new FZZAClrScheme_Item(*temp));
        }
    }
    
    
    for( itr = obj.m_accentList.begin(); itr != obj.m_accentList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            m_accentList.push_back(new FZZAClrScheme_Item(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme::~FZZAClrScheme()
{
   
    FZZConst::delClassCount("FZZAClrScheme");
    
    if ( m_hlink != NULL ) {
        delete m_hlink;
        m_hlink = NULL;
    }
    if ( m_folHlink != NULL ) {
        delete m_folHlink;
        m_folHlink = NULL;
    }
    
    vector<FZZAClrScheme_Item *>::const_iterator itr;
    for( itr = m_dkList.begin(); itr != m_dkList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_dkList.clear();
    for( itr = m_ltList.begin(); itr != m_ltList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_ltList.clear();
    for( itr = m_accentList.begin(); itr != m_accentList.end(); itr++ ) {
        FZZAClrScheme_Item * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_accentList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAClrScheme::setName(string value)
{
    setAttribute_String("name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAClrScheme::getName()
{
    return getAttribute_String("name");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::setHlink()
{
    return m_hlink = setElementObject(m_hlink,CTCLRSCHEME_ITEM_Find_Key,"hlink");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::getHlink()
{
    return m_hlink = getElementObject(m_hlink,CTCLRSCHEME_ITEM_Find_Key,"hlink");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::setFolHlink()
{
    return m_folHlink = setElementObject(m_folHlink,CTCLRSCHEME_ITEM_Find_Key,"folHlink");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::getFolHlink()
{
    return m_folHlink = getElementObject(m_folHlink,CTCLRSCHEME_ITEM_Find_Key,"folHlink");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::addDk()
{
    string key = "dk"+FZZConst::fmt(++m_dkCount);
    return addElementObject(&m_dkList,CTCLRSCHEME_ITEM_Find_Key,key.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::addLt()
{
    string key = "lt"+FZZConst::fmt(++m_ltCount);
    return addElementObject(&m_ltList,CTCLRSCHEME_ITEM_Find_Key,key.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item * FZZAClrScheme::addAccent()
{
    string key = "accent"+FZZConst::fmt(++m_accentCount);
    return addElementObject(&m_accentList,CTCLRSCHEME_ITEM_Find_Key,key.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
