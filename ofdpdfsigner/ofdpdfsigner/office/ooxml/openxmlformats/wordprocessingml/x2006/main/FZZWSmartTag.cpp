//
//  Created by zizheng fan on 2023/11/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTag.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSmartTag**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag::FZZWSmartTag() : FZZXMLElementObject(),m_FZZWSmartTagPr(NULL)
{
    //DLOG("FZZWSmartTag()");
    FZZConst::addClassCount("FZZWSmartTag");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag::FZZWSmartTag(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWSmartTagPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSmartTag");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag::FZZWSmartTag(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWSmartTagPr(NULL)
{
    FZZConst::addClassCount("FZZWSmartTag");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag::FZZWSmartTag(const FZZWSmartTag& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSmartTag");
    if ( this == &obj ) {
        return;
    }
    m_FZZWSmartTagPr = obj.m_FZZWSmartTagPr != NULL ? new FZZWSmartTagPr(*obj.m_FZZWSmartTagPr) : NULL;
    
    vector<FZZWR*>::const_iterator itr_r;
    for( itr_r = obj.m_FZZWRs.begin(); itr_r != obj.m_FZZWRs.end(); itr_r++ ) {
        FZZWR * temp = *itr_r;
        if ( temp != NULL ) {
            m_FZZWRs.push_back(new FZZWR(*temp));
        }
    }
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTag::~FZZWSmartTag()
{
    //DLOG("~FZZWSmartTag()");
    FZZConst::delClassCount("FZZWSmartTag");
    if ( m_FZZWSmartTagPr != NULL ) {
        delete m_FZZWSmartTagPr;
        m_FZZWSmartTagPr = NULL;
    }
    
    vector<FZZWR*>::const_iterator itr_r;
    for( itr_r = m_FZZWRs.begin(); itr_r != m_FZZWRs.end(); itr_r++ ) {
        FZZWR * temp = *itr_r;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWRs.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr * FZZWSmartTag::setSmartTagPr()
{
    return m_FZZWSmartTagPr = setElementObject(m_FZZWSmartTagPr,FZZWSMARTTAGPR_Find_Key,FZZWSMARTTAGPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSmartTagPr * FZZWSmartTag::getSmartTagPr()
{
    return m_FZZWSmartTagPr = getElementObject(m_FZZWSmartTagPr,FZZWSMARTTAGPR_Find_Key,FZZWSMARTTAGPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR * FZZWSmartTag::addR()
{
    return addElementObject(&m_FZZWRs,FZZWR_Find_Key,FZZWR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWR*> * FZZWSmartTag::getRList()
{
    getElementObjectList(&m_FZZWRs,FZZWR_Find_Key,FZZWR_Name);
    return &m_FZZWRs;
}
//-----------------------------------------------------------------------------------------------------------------
