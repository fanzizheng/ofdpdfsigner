//
//  Created by zizheng fan on 2023/11/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStylePr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblStylePr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr::FZZWTblStylePr() : FZZXMLElementObject(),m_FZZWTrPr(NULL),m_FZZWTblPr(NULL),m_FZZWTcPr(NULL)
{
    //DLOG("FZZWTblStylePr()");
    FZZConst::addClassCount("FZZWTblStylePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr::FZZWTblStylePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWTrPr(NULL),m_FZZWTblPr(NULL),m_FZZWTcPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblStylePr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr::FZZWTblStylePr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTrPr(NULL),m_FZZWTblPr(NULL),m_FZZWTcPr(NULL)
{
    FZZConst::addClassCount("FZZWTblStylePr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr::FZZWTblStylePr(const FZZWTblStylePr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblStylePr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTrPr = obj.m_FZZWTrPr != NULL ? new FZZWTrPr(*obj.m_FZZWTrPr) : NULL;
    m_FZZWTblPr = obj.m_FZZWTblPr != NULL ? new FZZWTblPr(*obj.m_FZZWTblPr) : NULL;
    m_FZZWTcPr = obj.m_FZZWTcPr != NULL ? new FZZWTcPr(*obj.m_FZZWTcPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr::~FZZWTblStylePr()
{
    //DLOG("~FZZWTblStylePr()");
    FZZConst::delClassCount("FZZWTblStylePr");
    if ( m_FZZWTrPr != NULL ) {
        delete m_FZZWTrPr;
        m_FZZWTrPr = NULL;
    }
    if ( m_FZZWTblPr != NULL ) {
        delete m_FZZWTblPr;
        m_FZZWTblPr = NULL;
    }
    if ( m_FZZWTcPr != NULL ) {
        delete m_FZZWTcPr;
        m_FZZWTcPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblStylePr::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblStylePr::getType()
{
    string retstr = getAttribute_String("w:type");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZWB::setValue(string value)
//{
//    setValue_String(value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZWB::getValue()
//{
//    return getValue_String();
//}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr * FZZWTblStylePr::setTrPr()
{
    return m_FZZWTrPr = setElementObject(m_FZZWTrPr,FZZWTRPR_Find_Key,FZZWTRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTrPr * FZZWTblStylePr::getTrPr()
{
    return m_FZZWTrPr = getElementObject(m_FZZWTrPr,FZZWTRPR_Find_Key,FZZWTRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWTblStylePr::setTblPr()
{
    return m_FZZWTblPr = setElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWTblStylePr::getTblPr()
{
    return m_FZZWTblPr = getElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr * FZZWTblStylePr::setTcPr()
{
    return m_FZZWTcPr = setElementObject(m_FZZWTcPr,FZZWTCPR_Find_Key,FZZWTCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcPr * FZZWTblStylePr::getTcPr()
{
    return m_FZZWTcPr = getElementObject(m_FZZWTcPr,FZZWTCPR_Find_Key,FZZWTCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
