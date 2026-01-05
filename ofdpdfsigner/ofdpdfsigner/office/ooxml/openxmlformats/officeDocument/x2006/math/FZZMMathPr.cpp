//
//  Created by zizheng fan on 2023/05/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathPr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMMathPr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr::FZZMMathPr() : FZZXMLElementObject(),m_FZZMBrkBin(NULL),m_FZZMBrkBinSub(NULL),m_FZZMDefJc(NULL),m_FZZMDispDef(NULL),m_FZZMIntLim(NULL),m_FZZMLMargin(NULL),m_FZZMMathFont(NULL),m_FZZMNaryLim(NULL),m_FZZMRMargin(NULL),m_FZZMSmallFrac(NULL),m_FZZMWrapIndent(NULL)
{
    //DLOG("FZZMMathPr()");
    FZZConst::addClassCount("FZZMMathPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr::FZZMMathPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZMBrkBin(NULL),m_FZZMBrkBinSub(NULL),m_FZZMDefJc(NULL),m_FZZMDispDef(NULL),m_FZZMIntLim(NULL),m_FZZMLMargin(NULL),m_FZZMMathFont(NULL),m_FZZMNaryLim(NULL),m_FZZMRMargin(NULL),m_FZZMSmallFrac(NULL),m_FZZMWrapIndent(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMMathPr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr::FZZMMathPr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZMBrkBin(NULL),m_FZZMBrkBinSub(NULL),m_FZZMDefJc(NULL),m_FZZMDispDef(NULL),m_FZZMIntLim(NULL),m_FZZMLMargin(NULL),m_FZZMMathFont(NULL),m_FZZMNaryLim(NULL),m_FZZMRMargin(NULL),m_FZZMSmallFrac(NULL),m_FZZMWrapIndent(NULL)
{
    FZZConst::addClassCount("FZZMMathPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr::FZZMMathPr(const FZZMMathPr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMMathPr");
    if ( this == &obj ) {
        return;
    }
    m_FZZMBrkBin = obj.m_FZZMBrkBin != NULL ? new FZZMBrkBin(*obj.m_FZZMBrkBin) : NULL;
    m_FZZMBrkBinSub = obj.m_FZZMBrkBinSub != NULL ? new FZZMBrkBinSub(*obj.m_FZZMBrkBinSub) : NULL;
    m_FZZMDefJc = obj.m_FZZMDefJc != NULL ? new FZZMDefJc(*obj.m_FZZMDefJc) : NULL;
    m_FZZMDispDef = obj.m_FZZMDispDef != NULL ? new FZZMDispDef(*obj.m_FZZMDispDef) : NULL;
    m_FZZMIntLim = obj.m_FZZMIntLim != NULL ? new FZZMIntLim(*obj.m_FZZMIntLim) : NULL;
    m_FZZMLMargin = obj.m_FZZMLMargin != NULL ? new FZZMLMargin(*obj.m_FZZMLMargin) : NULL;
    m_FZZMMathFont = obj.m_FZZMMathFont != NULL ? new FZZMMathFont(*obj.m_FZZMMathFont) : NULL;
    m_FZZMNaryLim = obj.m_FZZMNaryLim != NULL ? new FZZMNaryLim(*obj.m_FZZMNaryLim) : NULL;
    m_FZZMRMargin = obj.m_FZZMRMargin != NULL ? new FZZMRMargin(*obj.m_FZZMRMargin) : NULL;
    m_FZZMSmallFrac = obj.m_FZZMSmallFrac != NULL ? new FZZMSmallFrac(*obj.m_FZZMSmallFrac) : NULL;
    m_FZZMWrapIndent = obj.m_FZZMWrapIndent != NULL ? new FZZMWrapIndent(*obj.m_FZZMWrapIndent) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathPr::~FZZMMathPr()
{
    //DLOG("~FZZMMathPr()");
    FZZConst::delClassCount("FZZMMathPr");
    if ( m_FZZMBrkBin != NULL ) {
        delete m_FZZMBrkBin;
        m_FZZMBrkBin = NULL;
    }
    if ( m_FZZMBrkBinSub != NULL ) {
        delete m_FZZMBrkBinSub;
        m_FZZMBrkBinSub = NULL;
    }
    if ( m_FZZMDefJc != NULL ) {
        delete m_FZZMDefJc;
        m_FZZMDefJc = NULL;
    }
    if ( m_FZZMDispDef != NULL ) {
        delete m_FZZMDispDef;
        m_FZZMDispDef = NULL;
    }
    if ( m_FZZMIntLim != NULL ) {
        delete m_FZZMIntLim;
        m_FZZMIntLim = NULL;
    }
    if ( m_FZZMLMargin != NULL ) {
        delete m_FZZMLMargin;
        m_FZZMLMargin = NULL;
    }
    if ( m_FZZMMathFont != NULL ) {
        delete m_FZZMMathFont;
        m_FZZMMathFont = NULL;
    }
    if ( m_FZZMNaryLim != NULL ) {
        delete m_FZZMNaryLim;
        m_FZZMNaryLim = NULL;
    }
    if ( m_FZZMRMargin != NULL ) {
        delete m_FZZMRMargin;
        m_FZZMRMargin = NULL;
    }
    if ( m_FZZMSmallFrac != NULL ) {
        delete m_FZZMSmallFrac;
        m_FZZMSmallFrac = NULL;
    }
    if ( m_FZZMWrapIndent != NULL ) {
        delete m_FZZMWrapIndent;
        m_FZZMWrapIndent = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin * FZZMMathPr::setBrkBin()
{
    return m_FZZMBrkBin = setElementObject(m_FZZMBrkBin,FZZMBRKBIN_Find_Key,FZZMBRKBIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin * FZZMMathPr::getBrkBin()
{
    return m_FZZMBrkBin = getElementObject(m_FZZMBrkBin,FZZMBRKBIN_Find_Key,FZZMBRKBIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub * FZZMMathPr::setBrkBinSub()
{
    return m_FZZMBrkBinSub = setElementObject(m_FZZMBrkBinSub,FZZMBRKBINSUB_Find_Key,FZZMBRKBINSUB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub * FZZMMathPr::getBrkBinSub()
{
    return m_FZZMBrkBinSub = getElementObject(m_FZZMBrkBinSub,FZZMBRKBINSUB_Find_Key,FZZMBRKBINSUB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc * FZZMMathPr::setDefJc()
{
    return m_FZZMDefJc = setElementObject(m_FZZMDefJc,FZZMDEFJC_Find_Key,FZZMDEFJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc * FZZMMathPr::getDefJc()
{
    return m_FZZMDefJc = getElementObject(m_FZZMDefJc,FZZMDEFJC_Find_Key,FZZMDEFJC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef * FZZMMathPr::setDispDef()
{
    return m_FZZMDispDef = setElementObject(m_FZZMDispDef,FZZMDISPDEF_Find_Key,FZZMDISPDEF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDispDef * FZZMMathPr::getDispDef()
{
    return m_FZZMDispDef = getElementObject(m_FZZMDispDef,FZZMDISPDEF_Find_Key,FZZMDISPDEF_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim * FZZMMathPr::setIntLim()
{
    return m_FZZMIntLim = setElementObject(m_FZZMIntLim,FZZMINTLIM_Find_Key,FZZMINTLIM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim * FZZMMathPr::getIntLim()
{
    return m_FZZMIntLim = getElementObject(m_FZZMIntLim,FZZMINTLIM_Find_Key,FZZMINTLIM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin * FZZMMathPr::setLMargin()
{
    return m_FZZMLMargin = setElementObject(m_FZZMLMargin,FZZMLMARGIN_Find_Key,FZZMLMARGIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin * FZZMMathPr::getLMargin()
{
    return m_FZZMLMargin = getElementObject(m_FZZMLMargin,FZZMLMARGIN_Find_Key,FZZMLMARGIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont * FZZMMathPr::setMathFont()
{
    return m_FZZMMathFont = setElementObject(m_FZZMMathFont,FZZMMATHFONT_Find_Key,FZZMMATHFONT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont * FZZMMathPr::getMathFont()
{
    return m_FZZMMathFont = getElementObject(m_FZZMMathFont,FZZMMATHFONT_Find_Key,FZZMMATHFONT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim * FZZMMathPr::setNaryLim()
{
    return m_FZZMNaryLim = setElementObject(m_FZZMNaryLim,FZZMNARYLIM_Find_Key,FZZMNARYLIM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim * FZZMMathPr::getNaryLim()
{
    return m_FZZMNaryLim = getElementObject(m_FZZMNaryLim,FZZMNARYLIM_Find_Key,FZZMNARYLIM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin * FZZMMathPr::setRMargin()
{
    return m_FZZMRMargin = setElementObject(m_FZZMRMargin,FZZMRMARGIN_Find_Key,FZZMRMARGIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin * FZZMMathPr::getRMargin()
{
    return m_FZZMRMargin = getElementObject(m_FZZMRMargin,FZZMRMARGIN_Find_Key,FZZMRMARGIN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac * FZZMMathPr::setSmallFrac()
{
    return m_FZZMSmallFrac = setElementObject(m_FZZMSmallFrac,FZZMSMALLFRAC_Find_Key,FZZMSMALLFRAC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac * FZZMMathPr::getSmallFrac()
{
    return m_FZZMSmallFrac = getElementObject(m_FZZMSmallFrac,FZZMSMALLFRAC_Find_Key,FZZMSMALLFRAC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent * FZZMMathPr::setWrapIndent()
{
    return m_FZZMWrapIndent = setElementObject(m_FZZMWrapIndent,FZZMWRAPINDENT_Find_Key,FZZMWRAPINDENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMWrapIndent * FZZMMathPr::getWrapIndent()
{
    return m_FZZMWrapIndent = getElementObject(m_FZZMWrapIndent,FZZMWRAPINDENT_Find_Key,FZZMWRAPINDENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
