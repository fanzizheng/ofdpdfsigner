//
//  Created by zizheng fan on 2023/07/19
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectLst.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAeffectLst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst::FZZAeffectLst() : FZZXMLElementObject()
{
    //DLOG("FZZAeffectLst()");
    FZZConst::addClassCount("FZZAeffectLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst::FZZAeffectLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAeffectLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst::FZZAeffectLst(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAeffectLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst::FZZAeffectLst(const FZZAeffectLst& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAeffectLst");
    if ( this == &obj ) {
        return;
    }

    vector<FZZAouterShdw*>::const_iterator itr;
    for( itr = obj.m_outerShdws.begin(); itr != obj.m_outerShdws.end(); itr++ ) {
        FZZAouterShdw * temp = *itr;
        if ( temp != NULL ) {
            m_outerShdws.push_back(new FZZAouterShdw(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAeffectLst::~FZZAeffectLst()
{
    //DLOG("~FZZAeffectLst()");
    FZZConst::delClassCount("FZZAeffectLst");
    vector<FZZAouterShdw*>::const_iterator itr;
    for( itr = m_outerShdws.begin(); itr != m_outerShdws.end(); itr++ ) {
        FZZAouterShdw * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_outerShdws.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZAouterShdw* FZZAeffectLst::addOuterShdw()
{
    return addElementObject(&m_outerShdws,FZZAOUTERSHDW_Find_Key,FZZAOUTERSHDW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAouterShdw*> * FZZAeffectLst::getOuterShdws()
{
    getElementObjectList(&m_outerShdws,FZZAOUTERSHDW_Find_Key,FZZAOUTERSHDW_Name);
    return &m_outerShdws;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
