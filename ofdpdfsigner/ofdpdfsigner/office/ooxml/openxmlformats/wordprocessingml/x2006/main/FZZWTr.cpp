//
//  Created by zizheng fan on 2023/11/02
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTr::FZZWTr() : FZZXMLElementObject(),m_DocXDir(NULL),m_FZZWTrPr(NULL)
{
    //DLOG("FZZWTr()");
    FZZConst::addClassCount("FZZWTr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr::FZZWTr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_DocXDir(NULL),m_FZZWTrPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr::FZZWTr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_DocXDir(NULL),m_FZZWTrPr(NULL)
{
    FZZConst::addClassCount("FZZWTr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr::FZZWTr(const FZZWTr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTr");
    if ( this == &obj ) {
        return;
    }
    
    m_DocXDir = obj.m_DocXDir;
    
    m_FZZWTrPr = obj.m_FZZWTrPr != NULL ? new FZZWTrPr(*obj.m_FZZWTrPr) : NULL;
    
    vector<FZZWTc*>::const_iterator itr;
    for( itr = obj.m_FZZWTcs.begin(); itr != obj.m_FZZWTcs.end(); itr++ ) {
        FZZWTc * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWTcs.push_back(new FZZWTc(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr::~FZZWTr()
{
    //DLOG("~FZZWTr()");
    FZZConst::delClassCount("FZZWTr");
    
    vector<FZZWTc*>::const_iterator itr;
    for( itr = m_FZZWTcs.begin(); itr != m_FZZWTcs.end(); itr++ ) {
        FZZWTc * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWTcs.clear();

    if ( m_FZZWTrPr != NULL ) {
        delete m_FZZWTrPr;
        m_FZZWTrPr = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc * FZZWTr::addTc()
{
    return addElementObject(&m_FZZWTcs,FZZWTC_Find_Key,FZZWTC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWTc*> * FZZWTr::getTcList()
{
    getElementObjectList(&m_FZZWTcs,FZZWTC_Find_Key,FZZWTC_Name);
    return &m_FZZWTcs;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTr::setDocXDir(FZZDocXDir * docXDir)
{
    m_DocXDir = docXDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc * FZZWTr::addColumn()
{
    FZZWTc * retTc = addTc();
    if ( retTc != NULL ) {
        retTc->setDocXDir(m_DocXDir);
    }
    return retTc;
}
//-----------------------------------------------------------------------------------------------------------------
size_t FZZWTr::getColumnCount()
{
    vector<FZZWTc*> * TcList = getTcList();
    if ( TcList == NULL ) {
        return 0;
    }
    return TcList->size();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTc * FZZWTr::getColumn(int index)
{
    vector<FZZWTc*> * TcList = getTcList();
    if ( TcList == NULL || TcList->size() == 0 ) {
        return NULL;
    }
    
    if ( index > TcList->size() -1 ) {
        return NULL;
    }
    
    FZZWTc * tempTc = *(TcList->begin()+index);
    if ( tempTc != NULL ) {
        tempTc->setDocXDir(m_DocXDir);
    }
    return tempTc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr * FZZWTr::setTrPr()
{
    return m_FZZWTrPr = setElementObject(m_FZZWTrPr,FZZWTRPR_Find_Key,FZZWTRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr * FZZWTr::getTrPr()
{
    return m_FZZWTrPr = getElementObject(m_FZZWTrPr,FZZWTRPR_Find_Key,FZZWTRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
