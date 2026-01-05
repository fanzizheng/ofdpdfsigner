//
//  Created by zizheng fan on 2023/08/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAExtLst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst::FZZAExtLst() : FZZXMLElementObject()
{
    //DLOG("FZZAExtLst()");
    FZZConst::addClassCount("FZZAExtLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst::FZZAExtLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAExtLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst::FZZAExtLst(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAExtLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst::FZZAExtLst(const FZZAExtLst& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAExtLst");
    if ( this == &obj ) {
        return;
    }

    vector<FZZAExt*>::const_iterator itr;
    for( itr = obj.m_ExtList.begin(); itr != obj.m_ExtList.end(); itr++ ) {
        FZZAExt * temp = *itr;
        if ( temp != NULL ) {
            m_ExtList.push_back(new FZZAExt(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtLst::~FZZAExtLst()
{
    //DLOG("~FZZAExtLst()");
    FZZConst::delClassCount("FZZAExtLst");
    vector<FZZAExt*>::const_iterator itr;
    for( itr = m_ExtList.begin(); itr != m_ExtList.end(); itr++ ) {
        FZZAExt * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_ExtList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExt* FZZAExtLst::addExt()
{
    return addElementObject(&m_ExtList,FZZAEXT_Find_Key,FZZAEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZAExt*> * FZZAExtLst::getExtList()
{
    getElementObjectList(&m_ExtList,FZZAEXT_Find_Key,FZZAEXT_Name);
    return &m_ExtList;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
