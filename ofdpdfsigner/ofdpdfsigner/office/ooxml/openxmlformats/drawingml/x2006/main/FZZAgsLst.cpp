//
//  Created by zizheng fan on 2023/08/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgsLst.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAgsLst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst::FZZAgsLst() : FZZXMLElementObject()
{
    //DLOG("FZZAgsLst()");
    FZZConst::addClassCount("FZZAgsLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst::FZZAgsLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAgsLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst::FZZAgsLst(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAgsLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst::FZZAgsLst(const FZZAgsLst& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAgsLst");
    if ( this == &obj ) {
        return;
    }

    vector<FZZAgs *>::const_iterator itr_CTgs;
    for( itr_CTgs = obj.m_CTgss.begin(); itr_CTgs != obj.m_CTgss.end(); itr_CTgs++ ) {
        FZZAgs * temp = *itr_CTgs;
        if ( temp != NULL ) {
            m_CTgss.push_back(new FZZAgs(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgsLst::~FZZAgsLst()
{
    //DLOG("~FZZAgsLst()");
    FZZConst::delClassCount("FZZAgsLst");
    
    vector<FZZAgs *>::const_iterator itr_CTgs;
    for( itr_CTgs = m_CTgss.begin(); itr_CTgs != m_CTgss.end(); itr_CTgs++ ) {
        FZZAgs * temp = *itr_CTgs;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_CTgss.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZAgs * FZZAgsLst::addgs()
{
    return addElementObject(&m_CTgss,FZZAGS_Find_Key,FZZAGS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAgs *>* FZZAgsLst::getgss()
{
    getElementObjectList(&m_CTgss,FZZAGS_Find_Key,FZZAGS_Name);
    return &m_CTgss;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
