//
//  Created by zizheng fan on 2023/11/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTc.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTc::FZZWTc() : FZZXMLElementObject(),m_FZZWTcPr(NULL),m_DocXDir(NULL)
{
    //DLOG("FZZWTc()");
    FZZConst::addClassCount("FZZWTc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc::FZZWTc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWTcPr(NULL),m_DocXDir(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc::FZZWTc(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTcPr(NULL),m_DocXDir(NULL)
{
    FZZConst::addClassCount("FZZWTc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc::FZZWTc(const FZZWTc& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTc");
    if ( this == &obj ) {
        return;
    }
    m_DocXDir = obj.m_DocXDir;
    m_FZZWTcPr = obj.m_FZZWTcPr != NULL ? new FZZWTcPr(*obj.m_FZZWTcPr) : NULL;
    vector<FZZWP*>::const_iterator itr;
    for( itr = obj.m_FZZWPs.begin(); itr != obj.m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWPs.push_back(new FZZWP(*temp));
        }
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc::~FZZWTc()
{
    //DLOG("~FZZWTc()");
    FZZConst::delClassCount("FZZWTc");
    
    
    if ( m_FZZWTcPr != NULL ) {
        delete m_FZZWTcPr;
        m_FZZWTcPr = NULL;
    }
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
FZZWTcPr * FZZWTc::setTcPr()
{
    return m_FZZWTcPr = setElementObject(m_FZZWTcPr,FZZWTCPR_Find_Key,FZZWTCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr * FZZWTc::getTcPr()
{
    return m_FZZWTcPr = getElementObject(m_FZZWTcPr,FZZWTCPR_Find_Key,FZZWTCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWTc::addParagraph()
{
    FZZWP* retP = addElementObject(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
    if ( retP != NULL ) {
        retP->setDocXDir(m_DocXDir);
    }
    return retP;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWP*> * FZZWTc::getParagraphList()
{
    getElementObjectList(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
    
    vector<FZZWP*>::const_iterator itr;
    for( itr = m_FZZWPs.begin(); itr != m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            temp->setDocXDir(m_DocXDir);
        }
    }
    
    return &m_FZZWPs;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTc::setDocXDir(FZZDocXDir * docXDir)
{
    m_DocXDir = docXDir;
}
//-----------------------------------------------------------------------------------------------------------------

