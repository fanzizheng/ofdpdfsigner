//
//  Created by zizheng fan on 2023/11/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTxbxContent.h"
#include "office/FZZOfficeObject.h"

#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTxbxContent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent::FZZWTxbxContent() : FZZXMLElementObject()
{
    //DLOG("FZZWTxbxContent()");
    FZZConst::addClassCount("FZZWTxbxContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent::FZZWTxbxContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTxbxContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent::FZZWTxbxContent(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTxbxContent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent::FZZWTxbxContent(const FZZWTxbxContent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTxbxContent");
    if ( this == &obj ) {
        return;
    }
  
    vector<FZZWP*>::const_iterator itr;
    for( itr = obj.m_FZZWPs.begin(); itr != obj.m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWPs.push_back(new FZZWP(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTxbxContent::~FZZWTxbxContent()
{
    //DLOG("~FZZWTxbxContent()");
    FZZConst::delClassCount("FZZWTxbxContent");
    vector<FZZWP*>::const_iterator itr;
    for( itr = m_FZZWPs.begin(); itr != m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWPs.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWTxbxContent::addP()
{
    return addElementObject(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWP*> * FZZWTxbxContent::getPList()
{
    getElementObjectList(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
    return &m_FZZWPs;
}
//-----------------------------------------------------------------------------------------------------------------

