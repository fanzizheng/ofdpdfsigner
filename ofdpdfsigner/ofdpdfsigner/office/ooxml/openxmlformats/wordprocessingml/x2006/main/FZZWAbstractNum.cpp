//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNum.h"
#include "office/FZZOfficeObject.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAbstractNum**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum::FZZWAbstractNum() : FZZXMLElementObject(),m_FZZWNsid(NULL),m_FZZWMultiLevelType(NULL),m_FZZWTmpl(NULL)
{
    //DLOG("FZZWNumPr()");
    FZZConst::addClassCount("FZZWNumPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum::FZZWAbstractNum(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWNsid(NULL),m_FZZWMultiLevelType(NULL),m_FZZWTmpl(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAbstractNum");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum::FZZWAbstractNum(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWNsid(NULL),m_FZZWMultiLevelType(NULL),m_FZZWTmpl(NULL)
{
    FZZConst::addClassCount("FZZWAbstractNum");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum::FZZWAbstractNum(const FZZWAbstractNum& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAbstractNum");
    if ( this == &obj ) {
        return;
    }
    m_FZZWNsid = obj.m_FZZWNsid != NULL ? new FZZWNsid(*obj.m_FZZWNsid) : NULL;
    m_FZZWMultiLevelType = obj.m_FZZWMultiLevelType != NULL ? new FZZWMultiLevelType(*obj.m_FZZWMultiLevelType) : NULL;
    m_FZZWTmpl = obj.m_FZZWTmpl != NULL ? new FZZWTmpl(*obj.m_FZZWTmpl) : NULL;
    
    
    vector<FZZWLvl*>::const_iterator itr;
    for( itr = obj.m_FZZWLvlList.begin(); itr != obj.m_FZZWLvlList.end(); itr++ ) {
        FZZWLvl * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWLvlList.push_back(new FZZWLvl(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNum::~FZZWAbstractNum()
{
    //DLOG("~FZZWAbstractNum()");
    FZZConst::delClassCount("FZZWAbstractNum");
    if ( m_FZZWNsid != NULL ) {
        delete m_FZZWNsid;
        m_FZZWNsid = NULL;
    }
    if ( m_FZZWMultiLevelType != NULL ) {
        delete m_FZZWMultiLevelType;
        m_FZZWMultiLevelType = NULL;
    }
    if ( m_FZZWTmpl != NULL ) {
        delete m_FZZWTmpl;
        m_FZZWTmpl = NULL;
    }
    
    
    vector<FZZWLvl*>::const_iterator itr;
    for( itr = m_FZZWLvlList.begin(); itr != m_FZZWLvlList.end(); itr++ ) {
        FZZWLvl * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWLvlList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid * FZZWAbstractNum::setNsid()
{
    return m_FZZWNsid = setElementObject(m_FZZWNsid,FZZWNSID_Find_Key,FZZWNSID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNsid * FZZWAbstractNum::getNsid()
{
    return m_FZZWNsid = getElementObject(m_FZZWNsid,FZZWNSID_Find_Key,FZZWNSID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType * FZZWAbstractNum::setMultiLevelType()
{
    return m_FZZWMultiLevelType = setElementObject(m_FZZWMultiLevelType,FZZWMULTILEVELTYPE_Find_Key,FZZWMULTILEVELTYPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWMultiLevelType * FZZWAbstractNum::getMultiLevelType()
{
    return m_FZZWMultiLevelType = getElementObject(m_FZZWMultiLevelType,FZZWMULTILEVELTYPE_Find_Key,FZZWMULTILEVELTYPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl * FZZWAbstractNum::setTmpl()
{
    return m_FZZWTmpl = setElementObject(m_FZZWTmpl,FZZWTMPL_Find_Key,FZZWTMPL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTmpl * FZZWAbstractNum::getTmpl()
{
    return m_FZZWTmpl = getElementObject(m_FZZWTmpl,FZZWTMPL_Find_Key,FZZWTMPL_Name);
}
//-----------------------------------------------------------------------------------------------------------------

void FZZWAbstractNum::setRestartNumberingAfterBreak(string value)
{
    setAttribute_String("w:restartNumberingAfterBreak",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAbstractNum::getRestartNumberingAfterBreak()
{
    string retstr = getAttribute_String("w:restartNumberingAfterBreak");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWAbstractNum::setAbstractNumId(string value)
{
    setAttribute_String("w:abstractNumId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWAbstractNum::getAbstractNumId()
{
    string retstr = getAttribute_String("w:abstractNumId");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl * FZZWAbstractNum::addLvl()
{
    return addElementObject(&m_FZZWLvlList,FZZWLVL_Find_Key,FZZWLVL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWLvl*> * FZZWAbstractNum::getLvlList()
{
    getElementObjectList(&m_FZZWLvlList,FZZWLVL_Find_Key,FZZWLVL_Name);
    return &m_FZZWLvlList;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl * FZZWAbstractNum::getLvl(string lvlid)
{
    FZZWLvl * retFZZWLvl = NULL;
    getLvlList();
    
    if ( m_FZZWLvlList.size() <= 0 ) {
        return retFZZWLvl;
    }
    
    vector<FZZWLvl*>::const_iterator itr;
    for( itr = m_FZZWLvlList.begin(); itr != m_FZZWLvlList.end(); itr++) {
        FZZWLvl * temp = *itr;
        if ( temp != NULL ) {
            string tempivlid = temp->getIlvl();
            if ( tempivlid == lvlid ) {
                retFZZWLvl = temp;
                break;
            }
        }
    }//for
    return retFZZWLvl;
}
//-----------------------------------------------------------------------------------------------------------------
