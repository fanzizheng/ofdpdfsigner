//
//  Created by zizheng fan on 2023/11/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNum.h"
#include "office/FZZOfficeObject.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNum**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNum::FZZWNum() : FZZXMLElementObject(),m_FZZWAbstractNumId(NULL)
{
    //DLOG("FZZWNum()");
    FZZConst::addClassCount("FZZWNum");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNum::FZZWNum(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWAbstractNumId(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNum");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNum::FZZWNum(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWAbstractNumId(NULL)
{
    FZZConst::addClassCount("FZZWNum");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNum::FZZWNum(const FZZWNum& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNum");
    if ( this == &obj ) {
        return;
    }
    m_FZZWAbstractNumId = obj.m_FZZWAbstractNumId != NULL ? new FZZWAbstractNumId(*obj.m_FZZWAbstractNumId) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNum::~FZZWNum()
{
    //DLOG("~FZZWNum()");
    FZZConst::delClassCount("FZZWNum");
    if ( m_FZZWAbstractNumId != NULL ) {
        delete m_FZZWAbstractNumId;
        m_FZZWAbstractNumId = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId * FZZWNum::setAbstractNumId()
{
    return m_FZZWAbstractNumId = setElementObject(m_FZZWAbstractNumId,FZZWABSTRACTNUMID_Find_Key,FZZWABSTRACTNUMID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAbstractNumId * FZZWNum::getAbstractNumId()
{
    return m_FZZWAbstractNumId = getElementObject(m_FZZWAbstractNumId,FZZWABSTRACTNUMID_Find_Key,FZZWABSTRACTNUMID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWNum::setNumId(string value)
{
    setAttribute_String("w:numId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWNum::getNumId()
{
    string retstr = getAttribute_String("w:numId");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
