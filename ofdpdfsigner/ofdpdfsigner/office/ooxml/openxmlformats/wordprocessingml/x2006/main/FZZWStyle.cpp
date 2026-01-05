//
//  Created by zizheng fan on 2023/10/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStyle.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWStyle**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle::FZZWStyle() : FZZXMLElementObject(),m_FZZWName(NULL),m_FZZWUnhideWhenUsed(NULL),m_FZZWSemiHidden(NULL),m_FZZWUiPriority(NULL),m_FZZWQFormat(NULL),m_FZZWRsid(NULL),m_FZZWPPr(NULL),m_FZZWBasedOn(NULL),m_FZZWTblPr(NULL),m_FZZWRPr(NULL),m_FZZWTblStylePr(NULL)
{
    //DLOG("FZZWStyle()");
    FZZConst::addClassCount("FZZWStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle::FZZWStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWName(NULL),m_FZZWUnhideWhenUsed(NULL),m_FZZWSemiHidden(NULL),m_FZZWUiPriority(NULL),m_FZZWQFormat(NULL),m_FZZWRsid(NULL),m_FZZWPPr(NULL),m_FZZWBasedOn(NULL),m_FZZWTblPr(NULL),m_FZZWRPr(NULL),m_FZZWTblStylePr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWStyle");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle::FZZWStyle(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWName(NULL),m_FZZWUnhideWhenUsed(NULL),m_FZZWSemiHidden(NULL),m_FZZWUiPriority(NULL),m_FZZWQFormat(NULL),m_FZZWRsid(NULL),m_FZZWPPr(NULL),m_FZZWBasedOn(NULL),m_FZZWTblPr(NULL),m_FZZWRPr(NULL),m_FZZWTblStylePr(NULL)
{
    FZZConst::addClassCount("FZZWStyle");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle::FZZWStyle(const FZZWStyle& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWStyle");
    if ( this == &obj ) {
        return;
    }
//    vector<FZZWTblPr*>::const_iterator itr;
//    for( itr = obj.m_FZZWTblPrs.begin(); itr != obj.m_FZZWTblPrs.end(); itr++ ) {
//        FZZWTblPr * temp = *itr;
//        if ( temp != NULL ) {
//            m_FZZWTblPrs.push_back(new FZZWTblPr(*temp));
//        }
//    }
    
    m_FZZWName = obj.m_FZZWName != NULL ? new FZZWName(*obj.m_FZZWName) : NULL;
    m_FZZWUnhideWhenUsed = obj.m_FZZWUnhideWhenUsed != NULL ? new FZZWUnhideWhenUsed(*obj.m_FZZWUnhideWhenUsed) : NULL;
    m_FZZWSemiHidden = obj.m_FZZWSemiHidden != NULL ? new FZZWSemiHidden(*obj.m_FZZWSemiHidden) : NULL;
    m_FZZWUiPriority = obj.m_FZZWUiPriority != NULL ? new FZZWUiPriority(*obj.m_FZZWUiPriority) : NULL;
    m_FZZWQFormat = obj.m_FZZWQFormat != NULL ? new FZZWQFormat(*obj.m_FZZWQFormat) : NULL;
    m_FZZWRsid = obj.m_FZZWRsid != NULL ? new FZZWRsid(*obj.m_FZZWRsid) : NULL;
    m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    m_FZZWBasedOn = obj.m_FZZWBasedOn != NULL ? new FZZWBasedOn(*obj.m_FZZWBasedOn) : NULL;
    m_FZZWTblPr = obj.m_FZZWTblPr != NULL ? new FZZWTblPr(*obj.m_FZZWTblPr) : NULL;
    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
    m_FZZWTblStylePr = obj.m_FZZWTblStylePr != NULL ? new FZZWTblStylePr(*obj.m_FZZWTblStylePr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStyle::~FZZWStyle()
{
    //DLOG("~FZZWStyle()");
    FZZConst::delClassCount("FZZWStyle");
    
    
//    vector<FZZWTblPr*>::const_iterator itr;
//    for( itr = m_FZZWTblPrs.begin(); itr != m_FZZWTblPrs.end(); itr++ ) {
//        FZZWTblPr * temp = *itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_FZZWTblPrs.clear();
    if ( m_FZZWTblPr != NULL ) {
        delete m_FZZWTblPr;
        m_FZZWTblPr = NULL;
    }
    
    if ( m_FZZWName != NULL ) {
        delete m_FZZWName;
        m_FZZWName = NULL;
    }
    if ( m_FZZWUnhideWhenUsed != NULL ) {
        delete m_FZZWUnhideWhenUsed;
        m_FZZWUnhideWhenUsed = NULL;
    }
    if ( m_FZZWSemiHidden != NULL ) {
        delete m_FZZWSemiHidden;
        m_FZZWSemiHidden = NULL;
    }
    if ( m_FZZWUiPriority != NULL ) {
        delete m_FZZWUiPriority;
        m_FZZWUiPriority = NULL;
    }
    if ( m_FZZWQFormat != NULL ) {
        delete m_FZZWQFormat;
        m_FZZWQFormat = NULL;
    }
    if ( m_FZZWRsid != NULL ) {
        delete m_FZZWRsid;
        m_FZZWRsid = NULL;
    }
    if ( m_FZZWPPr != NULL ) {
        delete m_FZZWPPr;
        m_FZZWPPr = NULL;
    }
    if ( m_FZZWBasedOn != NULL ) {
        delete m_FZZWBasedOn;
        m_FZZWBasedOn = NULL;
    }
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
    if ( m_FZZWTblStylePr != NULL ) {
        delete m_FZZWTblStylePr;
        m_FZZWTblStylePr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//FZZWTblPr * FZZWStyle::addTblPr()
//{
//    return addElementObject(&m_FZZWTblPrs,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//vector<FZZWTblPr*> * FZZWStyle::getTblPrs()
//{
//    getElementObjectList(&m_FZZWTblPrs,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
//    return &m_FZZWTblPrs;
//}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWStyle::setTblPr()
{
    return m_FZZWTblPr = setElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblPr * FZZWStyle::getTblPr()
{
    return m_FZZWTblPr = getElementObject(m_FZZWTblPr,FZZWTBLPR_Find_Key,FZZWTBLPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWStyle::setDefault(string value)
{
    setAttribute_String("w:default",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWStyle::getDefault()
{
    return getAttribute_String("w:default");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWStyle::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWStyle::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWStyle::setStyleId(string value)
{
    setAttribute_String("w:styleId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWStyle::getStyleId()
{
    return getAttribute_String("w:styleId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName * FZZWStyle::setName()
{
    return m_FZZWName = setElementObject(m_FZZWName,FZZWNAME_Find_Key,FZZWNAME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWName * FZZWStyle::getName()
{
    return m_FZZWName = getElementObject(m_FZZWName,FZZWNAME_Find_Key,FZZWNAME_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed * FZZWStyle::setUnhideWhenUsed()
{
    return m_FZZWUnhideWhenUsed = setElementObject(m_FZZWUnhideWhenUsed,FZZWUNHIDEWHENUSED_Find_Key,FZZWUNHIDEWHENUSED_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUnhideWhenUsed * FZZWStyle::getUnhideWhenUsed()
{
    return m_FZZWUnhideWhenUsed = getElementObject(m_FZZWUnhideWhenUsed,FZZWUNHIDEWHENUSED_Find_Key,FZZWUNHIDEWHENUSED_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden * FZZWStyle::setSemiHidden()
{
    return m_FZZWSemiHidden = setElementObject(m_FZZWSemiHidden,FZZWSEMIHIDDEN_Find_Key,FZZWSEMIHIDDEN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden * FZZWStyle::getSemiHidden()
{
    return m_FZZWSemiHidden = getElementObject(m_FZZWSemiHidden,FZZWSEMIHIDDEN_Find_Key,FZZWSEMIHIDDEN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority * FZZWStyle::setUiPriority()
{
    return m_FZZWUiPriority = setElementObject(m_FZZWUiPriority,FZZWUIPRIORITY_Find_Key,FZZWUIPRIORITY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUiPriority * FZZWStyle::getUiPriority()
{
    return m_FZZWUiPriority = getElementObject(m_FZZWUiPriority,FZZWUIPRIORITY_Find_Key,FZZWUIPRIORITY_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat * FZZWStyle::setQFormat()
{
    return m_FZZWQFormat = setElementObject(m_FZZWQFormat,FZZWQFORMAT_Find_Key,FZZWQFORMAT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWQFormat * FZZWStyle::getQFormat()
{
    return m_FZZWQFormat = getElementObject(m_FZZWQFormat,FZZWQFORMAT_Find_Key,FZZWQFORMAT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid * FZZWStyle::setRsid()
{
    return m_FZZWRsid = setElementObject(m_FZZWRsid,FZZWRSID_Find_Key,FZZWRSID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid * FZZWStyle::getRsid()
{
    return m_FZZWRsid = getElementObject(m_FZZWRsid,FZZWRSID_Find_Key,FZZWRSID_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWStyle::setPpr()
{
    return m_FZZWPPr = setElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWStyle::getPpr()
{
    return m_FZZWPPr = getElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn * FZZWStyle::setBasedOn()
{
    return m_FZZWBasedOn = setElementObject(m_FZZWBasedOn,FZZWBASEDON_Find_Key,FZZWBASEDON_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBasedOn * FZZWStyle::getBasedOn()
{
    return m_FZZWBasedOn = getElementObject(m_FZZWBasedOn,FZZWBASEDON_Find_Key,FZZWBASEDON_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWStyle::setRpr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWStyle::getRpr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr * FZZWStyle::setTblStylePr()
{
    return m_FZZWTblStylePr = setElementObject(m_FZZWTblStylePr,FZZWTBLSTYLEPR_Find_Key,FZZWTBLSTYLEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblStylePr * FZZWStyle::getTblStylePr()
{
    return m_FZZWTblStylePr = getElementObject(m_FZZWTblStylePr,FZZWTBLSTYLEPR_Find_Key,FZZWTBLSTYLEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
