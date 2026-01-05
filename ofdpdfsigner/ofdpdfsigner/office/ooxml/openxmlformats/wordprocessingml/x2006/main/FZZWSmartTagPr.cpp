//
//  Created by zizheng fan on 2023/11/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTagPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSmartTagPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr::FZZWSmartTagPr() : FZZXMLElementObject()
{
    //DLOG("FZZWSmartTagPr()");
    FZZConst::addClassCount("FZZWSmartTagPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr::FZZWSmartTagPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSmartTagPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr::FZZWSmartTagPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSmartTagPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr::FZZWSmartTagPr(const FZZWSmartTagPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSmartTagPr");
    if ( this == &obj ) {
        return;
    }

    vector<FZZWAttr*>::const_iterator FZZWAttr_itr;
    for( FZZWAttr_itr = obj.m_FZZWAttrList.begin(); FZZWAttr_itr != obj.m_FZZWAttrList.end(); FZZWAttr_itr++ ) {
        FZZWAttr * temp = *FZZWAttr_itr;
        if ( temp != NULL ) {
            m_FZZWAttrList.push_back(new FZZWAttr(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr::~FZZWSmartTagPr()
{
    //DLOG("~FZZWSmartTagPr()");
    FZZConst::delClassCount("FZZWSmartTagPr");
    
    vector<FZZWAttr*>::const_iterator FZZWAttr_itr;
    for( FZZWAttr_itr = m_FZZWAttrList.begin(); FZZWAttr_itr != m_FZZWAttrList.end(); FZZWAttr_itr++ ) {
        FZZWAttr * temp = *FZZWAttr_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWAttrList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAttr * FZZWSmartTagPr::addAttr()
{
    return addElementObject(&m_FZZWAttrList,FZZWATTR_Find_Key,FZZWATTR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWAttr*> * FZZWSmartTagPr::getAttrList()
{
    getElementObjectList(&m_FZZWAttrList,FZZWATTR_Find_Key,FZZWATTR_Name);
    return &m_FZZWAttrList;
}
//-----------------------------------------------------------------------------------------------------------------
