//
//  Created by zizheng fan on 2023/10/11
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr::FZZWRPr() : FZZXMLElementObject(),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWLang(NULL),m_FZZWSzCS(NULL),m_FZZWSz(NULL),m_FZZWKern(NULL),m_FZZWRFonts(NULL),m_FZZWColor(NULL),m_FZZWBCs(NULL),m_FZZWB(NULL),m_FZZW14TextFill(NULL),m_FZZWVertAlign(NULL),m_FZZWNoProof(NULL),m_FZZWRStyle(NULL),m_FZZWW(NULL),m_FZZWU(NULL),m_FZZWVanish(NULL),m_FZZWPosition(NULL)
{
    //DLOG("FZZWRPr()");
    FZZConst::addClassCount("FZZWRPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr::FZZWRPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWLang(NULL),m_FZZWSzCS(NULL),m_FZZWSz(NULL),m_FZZWKern(NULL),m_FZZWRFonts(NULL),m_FZZWColor(NULL),m_FZZWBCs(NULL),m_FZZWB(NULL),m_FZZW14TextFill(NULL),m_FZZWVertAlign(NULL),m_FZZWNoProof(NULL),m_FZZWRStyle(NULL),m_FZZWW(NULL),m_FZZWU(NULL),m_FZZWVanish(NULL),m_FZZWPosition(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr::FZZWRPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWSpacing(NULL),m_FZZWJc(NULL),m_FZZWLang(NULL),m_FZZWSzCS(NULL),m_FZZWSz(NULL),m_FZZWKern(NULL),m_FZZWRFonts(NULL),m_FZZWColor(NULL),m_FZZWBCs(NULL),m_FZZWB(NULL),m_FZZW14TextFill(NULL),m_FZZWVertAlign(NULL),m_FZZWNoProof(NULL),m_FZZWRStyle(NULL),m_FZZWW(NULL),m_FZZWU(NULL),m_FZZWVanish(NULL),m_FZZWPosition(NULL)
{
    FZZConst::addClassCount("FZZWRPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr::FZZWRPr(const FZZWRPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRPr");
    if ( this == &obj ) {
        return;
    }

    m_FZZWSpacing = obj.m_FZZWSpacing != NULL ? new FZZWSpacing(*obj.m_FZZWSpacing) : NULL;
    m_FZZWJc = obj.m_FZZWJc != NULL ? new FZZWJc(*obj.m_FZZWJc) : NULL;
    m_FZZWLang = obj.m_FZZWLang != NULL ? new FZZWLang(*obj.m_FZZWLang) : NULL;
    m_FZZWSzCS = obj.m_FZZWSzCS != NULL ? new FZZWSzCS(*obj.m_FZZWSzCS) : NULL;
    m_FZZWSz = obj.m_FZZWSz != NULL ? new FZZWSz(*obj.m_FZZWSz) : NULL;
    m_FZZWKern = obj.m_FZZWKern != NULL ? new FZZWKern(*obj.m_FZZWKern) : NULL;
    m_FZZWRFonts = obj.m_FZZWRFonts != NULL ? new FZZWRFonts(*obj.m_FZZWRFonts) : NULL;
    m_FZZWColor = obj.m_FZZWColor != NULL ? new FZZWColor(*obj.m_FZZWColor) : NULL;
    m_FZZWBCs = obj.m_FZZWBCs != NULL ? new FZZWBCs(*obj.m_FZZWBCs) : NULL;
    m_FZZWB = obj.m_FZZWB != NULL ? new FZZWB(*obj.m_FZZWB) : NULL;
    m_FZZW14TextFill = obj.m_FZZW14TextFill != NULL ? new FZZW14TextFill(*obj.m_FZZW14TextFill) : NULL;
    m_FZZWVertAlign = obj.m_FZZWVertAlign != NULL ? new FZZWVertAlign(*obj.m_FZZWVertAlign) : NULL;
    m_FZZWNoProof = obj.m_FZZWNoProof != NULL ? new FZZWNoProof(*obj.m_FZZWNoProof) : NULL;
    m_FZZWRStyle = obj.m_FZZWRStyle != NULL ? new FZZWRStyle(*obj.m_FZZWRStyle) : NULL;
    m_FZZWW = obj.m_FZZWW != NULL ? new FZZWW(*obj.m_FZZWW) : NULL;
    m_FZZWU = obj.m_FZZWU != NULL ? new FZZWU(*obj.m_FZZWU) : NULL;
    m_FZZWVanish = obj.m_FZZWVanish != NULL ? new FZZWVanish(*obj.m_FZZWVanish) : NULL;
    m_FZZWPosition = obj.m_FZZWPosition != NULL ? new FZZWPosition(*obj.m_FZZWPosition) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr::~FZZWRPr()
{
    //DLOG("~FZZWRPr()");
    FZZConst::delClassCount("FZZWRPr");
    if ( m_FZZWSpacing != NULL ) {
        delete m_FZZWSpacing;
        m_FZZWSpacing = NULL;
    }
    if ( m_FZZWJc != NULL ) {
        delete m_FZZWJc;
        m_FZZWJc = NULL;
    }
    if ( m_FZZWLang != NULL ) {
        delete m_FZZWLang;
        m_FZZWLang = NULL;
    }
    if ( m_FZZWSzCS != NULL ) {
        delete m_FZZWSzCS;
        m_FZZWSzCS = NULL;
    }
    if ( m_FZZWSz != NULL ) {
        delete m_FZZWSz;
        m_FZZWSz = NULL;
    }
    if ( m_FZZWKern != NULL ) {
        delete m_FZZWKern;
        m_FZZWKern = NULL;
    }
    if ( m_FZZWRFonts != NULL ) {
        delete m_FZZWRFonts;
        m_FZZWRFonts = NULL;
    }
    if ( m_FZZWColor != NULL ) {
        delete m_FZZWColor;
        m_FZZWColor = NULL;
    }
    if ( m_FZZWBCs != NULL ) {
        delete m_FZZWBCs;
        m_FZZWBCs = NULL;
    }
    if ( m_FZZWB != NULL ) {
        delete m_FZZWB;
        m_FZZWB = NULL;
    }
    if ( m_FZZW14TextFill != NULL ) {
        delete m_FZZW14TextFill;
        m_FZZW14TextFill = NULL;
    }
    if ( m_FZZWVertAlign != NULL ) {
        delete m_FZZWVertAlign;
        m_FZZWVertAlign = NULL;
    }
    if ( m_FZZWNoProof != NULL ) {
        delete m_FZZWNoProof;
        m_FZZWNoProof = NULL;
    }
    if ( m_FZZWRStyle != NULL ) {
        delete m_FZZWRStyle;
        m_FZZWRStyle = NULL;
    }
    if ( m_FZZWW != NULL ) {
        delete m_FZZWW;
        m_FZZWW = NULL;
    }
    if ( m_FZZWU != NULL ) {
        delete m_FZZWU;
        m_FZZWU = NULL;
    }
    if ( m_FZZWVanish != NULL ) {
        delete m_FZZWVanish;
        m_FZZWVanish = NULL;
    }
    if ( m_FZZWPosition != NULL ) {
        delete m_FZZWPosition;
        m_FZZWPosition = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing * FZZWRPr::setSpacing()
{
    return m_FZZWSpacing = setElementObject(m_FZZWSpacing,FZZWSPACING_Find_Key,FZZWSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpacing * FZZWRPr::getSpacing()
{
    return m_FZZWSpacing = getElementObject(m_FZZWSpacing,FZZWSPACING_Find_Key,FZZWSPACING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWRPr::setJc()
{
    return m_FZZWJc = setElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWJc * FZZWRPr::getJc()
{
    return m_FZZWJc = getElementObject(m_FZZWJc,FZZWJC_Find_Key,FZZWJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang * FZZWRPr::setLang()
{
    return m_FZZWLang = setElementObject(m_FZZWLang,FZZWLANG_Find_Key,FZZWLANG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLang * FZZWRPr::getLang()
{
    return m_FZZWLang = getElementObject(m_FZZWLang,FZZWLANG_Find_Key,FZZWLANG_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS * FZZWRPr::setSzCS()
{
    return m_FZZWSzCS = setElementObject(m_FZZWSzCS,FZZWSZCS_Find_Key,FZZWSZCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS * FZZWRPr::getSzCS()
{
    return m_FZZWSzCS = getElementObject(m_FZZWSzCS,FZZWSZCS_Find_Key,FZZWSZCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz * FZZWRPr::setSz()
{
    return m_FZZWSz = setElementObject(m_FZZWSz,FZZWSZ_Find_Key,FZZWSZ_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz * FZZWRPr::getSz()
{
    return m_FZZWSz = getElementObject(m_FZZWSz,FZZWSZ_Find_Key,FZZWSZ_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern * FZZWRPr::setKern()
{
    return m_FZZWKern = setElementObject(m_FZZWKern,FZZWKERN_Find_Key,FZZWKERN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWKern * FZZWRPr::getKern()
{
    return m_FZZWKern = getElementObject(m_FZZWKern,FZZWKERN_Find_Key,FZZWKERN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts * FZZWRPr::setRFonts()
{
    return m_FZZWRFonts = setElementObject(m_FZZWRFonts,FZZWRFONTS_Find_Key,FZZWRFONTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRFonts * FZZWRPr::getRFonts()
{
    return m_FZZWRFonts = getElementObject(m_FZZWRFonts,FZZWRFONTS_Find_Key,FZZWRFONTS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor * FZZWRPr::setColor()
{
    return m_FZZWColor = setElementObject(m_FZZWColor,FZZWCOLOR_Find_Key,FZZWCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWColor * FZZWRPr::getColor()
{
    return m_FZZWColor = getElementObject(m_FZZWColor,FZZWCOLOR_Find_Key,FZZWCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs * FZZWRPr::setBCs()
{
    return m_FZZWBCs = setElementObject(m_FZZWBCs,FZZWBCS_Find_Key,FZZWBCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBCs * FZZWRPr::getBCs()
{
    return m_FZZWBCs = getElementObject(m_FZZWBCs,FZZWBCS_Find_Key,FZZWBCS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB * FZZWRPr::setB()
{
    return m_FZZWB = setElementObject(m_FZZWB,FZZWB_Find_Key,FZZWB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWB * FZZWRPr::getB()
{
    return m_FZZWB = getElementObject(m_FZZWB,FZZWB_Find_Key,FZZWB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill * FZZWRPr::setTextFill()
{
    return m_FZZW14TextFill = setElementObject(m_FZZW14TextFill,FZZW14TEXTFILL_Find_Key,FZZW14TEXTFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill * FZZWRPr::getTextFill()
{
    return m_FZZW14TextFill = getElementObject(m_FZZW14TextFill,FZZW14TEXTFILL_Find_Key,FZZW14TEXTFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign * FZZWRPr::setVertAlign()
{
    return m_FZZWVertAlign = setElementObject(m_FZZWVertAlign,FZZWVERTALIGN_Find_Key,FZZWVERTALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign * FZZWRPr::getVertAlign()
{
    return m_FZZWVertAlign = getElementObject(m_FZZWVertAlign,FZZWVERTALIGN_Find_Key,FZZWVERTALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof * FZZWRPr::setNoProof()
{
    return m_FZZWNoProof = setElementObject(m_FZZWNoProof,FZZWNOPROOF_Find_Key,FZZWNOPROOF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof * FZZWRPr::getNoProof()
{
    return m_FZZWNoProof = getElementObject(m_FZZWNoProof,FZZWNOPROOF_Find_Key,FZZWNOPROOF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle * FZZWRPr::setRStyle()
{
    return m_FZZWRStyle = setElementObject(m_FZZWRStyle,FZZWRSTYLE_Find_Key,FZZWRSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRStyle * FZZWRPr::getRStyle()
{
    return m_FZZWRStyle = getElementObject(m_FZZWRStyle,FZZWRSTYLE_Find_Key,FZZWRSTYLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW * FZZWRPr::setW()
{
    return m_FZZWW = setElementObject(m_FZZWW,FZZWW_Find_Key,FZZWW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWW * FZZWRPr::getW()
{
    return m_FZZWW = getElementObject(m_FZZWW,FZZWW_Find_Key,FZZWW_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU * FZZWRPr::setU()
{
    return m_FZZWU = setElementObject(m_FZZWU,FZZWU_Find_Key,FZZWU_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWU * FZZWRPr::getU()
{
    return m_FZZWU = getElementObject(m_FZZWU,FZZWU_Find_Key,FZZWU_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish * FZZWRPr::setVanish()
{
    return m_FZZWVanish = setElementObject(m_FZZWVanish,FZZWVANISH_Find_Key,FZZWVANISH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish * FZZWRPr::getVanish()
{
    return m_FZZWVanish = getElementObject(m_FZZWVanish,FZZWVANISH_Find_Key,FZZWVANISH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition * FZZWRPr::setPosition()
{
    return m_FZZWPosition = setElementObject(m_FZZWPosition,FZZWPOSITION_Find_Key,FZZWPOSITION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPosition * FZZWRPr::getPosition()
{
    return m_FZZWPosition = getElementObject(m_FZZWPosition,FZZWPOSITION_Find_Key,FZZWPOSITION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
