//
//  Created by zizheng fan on 2023/11/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvl.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWLvl**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl::FZZWLvl() : FZZXMLElementObject(),m_FZZWStart(NULL),m_FZZWNumFmt(NULL),m_FZZWSuff(NULL),m_FZZWLvlText(NULL),m_FZZWLvlJc(NULL),m_FZZWPPr(NULL),m_FZZWRPr(NULL)
{
    //DLOG("FZZWLvl()");
    FZZConst::addClassCount("FZZWLvl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl::FZZWLvl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWStart(NULL),m_FZZWNumFmt(NULL),m_FZZWSuff(NULL),m_FZZWLvlText(NULL),m_FZZWLvlJc(NULL),m_FZZWPPr(NULL),m_FZZWRPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWLvl");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl::FZZWLvl(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWStart(NULL),m_FZZWNumFmt(NULL),m_FZZWSuff(NULL),m_FZZWLvlText(NULL),m_FZZWLvlJc(NULL),m_FZZWPPr(NULL),m_FZZWRPr(NULL)
{
    FZZConst::addClassCount("FZZWLvl");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl::FZZWLvl(const FZZWLvl& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWLvl");
    if ( this == &obj ) {
        return;
    }

    m_FZZWStart = obj.m_FZZWStart != NULL ? new FZZWStart(*obj.m_FZZWStart) : NULL;
    m_FZZWNumFmt = obj.m_FZZWNumFmt != NULL ? new FZZWNumFmt(*obj.m_FZZWNumFmt) : NULL;
    m_FZZWSuff = obj.m_FZZWSuff != NULL ? new FZZWSuff(*obj.m_FZZWSuff) : NULL;
    m_FZZWLvlText = obj.m_FZZWLvlText != NULL ? new FZZWLvlText(*obj.m_FZZWLvlText) : NULL;
    m_FZZWLvlJc = obj.m_FZZWLvlJc != NULL ? new FZZWLvlJc(*obj.m_FZZWLvlJc) : NULL;
    m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvl::~FZZWLvl()
{
    //DLOG("~FZZWLvl()");
    FZZConst::delClassCount("FZZWLvl");
    if ( m_FZZWStart != NULL ) {
        delete m_FZZWStart;
        m_FZZWStart = NULL;
    }
    if ( m_FZZWNumFmt != NULL ) {
        delete m_FZZWNumFmt;
        m_FZZWNumFmt = NULL;
    }
    if ( m_FZZWSuff != NULL ) {
        delete m_FZZWSuff;
        m_FZZWSuff = NULL;
    }
    if ( m_FZZWLvlText != NULL ) {
        delete m_FZZWLvlText;
        m_FZZWLvlText = NULL;
    }
    if ( m_FZZWLvlJc != NULL ) {
        delete m_FZZWLvlJc;
        m_FZZWLvlJc = NULL;
    }
    if ( m_FZZWPPr != NULL ) {
        delete m_FZZWPPr;
        m_FZZWPPr = NULL;
    }
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWLvl::setIlvl(string value)
{
    setAttribute_String("w:ilvl",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWLvl::getIlvl()
{
    string retstr = getAttribute_String("w:ilvl");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart * FZZWLvl::setStart()
{
    return m_FZZWStart = setElementObject(m_FZZWStart,FZZWSTART_Find_Key,FZZWSTART_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWStart * FZZWLvl::getStart()
{
    return m_FZZWStart = getElementObject(m_FZZWStart,FZZWSTART_Find_Key,FZZWSTART_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt * FZZWLvl::setNumFmt()
{
    return m_FZZWNumFmt = setElementObject(m_FZZWNumFmt,FZZWNUMFMT_Find_Key,FZZWNUMFMT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNumFmt * FZZWLvl::getNumFmt()
{
    return m_FZZWNumFmt = getElementObject(m_FZZWNumFmt,FZZWNUMFMT_Find_Key,FZZWNUMFMT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff * FZZWLvl::setSuff()
{
    return m_FZZWSuff = setElementObject(m_FZZWSuff,FZZWSUFF_Find_Key,FZZWSUFF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSuff * FZZWLvl::getSuff()
{
    return m_FZZWSuff = getElementObject(m_FZZWSuff,FZZWSUFF_Find_Key,FZZWSUFF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText * FZZWLvl::setLvlText()
{
    return m_FZZWLvlText = setElementObject(m_FZZWLvlText,FZZWLVLTEXT_Find_Key,FZZWLVLTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlText * FZZWLvl::getLvlText()
{
    return m_FZZWLvlText = getElementObject(m_FZZWLvlText,FZZWLVLTEXT_Find_Key,FZZWLVLTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc * FZZWLvl::setLvlJc()
{
    return m_FZZWLvlJc = setElementObject(m_FZZWLvlJc,FZZWLVLJC_Find_Key,FZZWLVLJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLvlJc * FZZWLvl::getLvlJc()
{
    return m_FZZWLvlJc = getElementObject(m_FZZWLvlJc,FZZWLVLJC_Find_Key,FZZWLVLJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWLvl::setPPr()
{
    return m_FZZWPPr = setElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPr * FZZWLvl::getPPr()
{
    return m_FZZWPPr = getElementObject(m_FZZWPPr,FZZWPPR_Find_Key,FZZWPPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWLvl::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWLvl::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
