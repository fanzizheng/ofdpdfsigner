//
//  Created by zizheng fan on 2023/10/31
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWR.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWR**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWR::FZZWR() : FZZXMLElementObject(),m_FZZWRPr(NULL),m_FZZWT(NULL),m_FZZWTab(NULL),m_FZZWDrawing(NULL),m_FZZMCAlternateContent(NULL),m_FZZWSeparator(NULL),m_FZZWContinuationSeparator(NULL),m_FZZWFldChar(NULL),m_FZZWInstrText(NULL),m_FZZWCr(NULL),m_FZZWBr(NULL),m_FZZWLastRenderedPageBreak(NULL),m_FZZWPict(NULL)
{
    //DLOG("FZZWR()");
    FZZConst::addClassCount("FZZWR");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR::FZZWR(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWRPr(NULL),m_FZZWT(NULL),m_FZZWTab(NULL),m_FZZWDrawing(NULL),m_FZZMCAlternateContent(NULL),m_FZZWSeparator(NULL),m_FZZWContinuationSeparator(NULL),m_FZZWFldChar(NULL),m_FZZWInstrText(NULL),m_FZZWCr(NULL),m_FZZWBr(NULL),m_FZZWLastRenderedPageBreak(NULL),m_FZZWPict(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWR");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR::FZZWR(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWRPr(NULL),m_FZZWT(NULL),m_FZZWTab(NULL),m_FZZWDrawing(NULL),m_FZZMCAlternateContent(NULL),m_FZZWSeparator(NULL),m_FZZWContinuationSeparator(NULL),m_FZZWFldChar(NULL),m_FZZWInstrText(NULL),m_FZZWCr(NULL),m_FZZWBr(NULL),m_FZZWLastRenderedPageBreak(NULL),m_FZZWPict(NULL)
{
    FZZConst::addClassCount("FZZWR");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR::FZZWR(const FZZWR& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWR");
    if ( this == &obj ) {
        return;
    }
    m_FZZWRPr = obj.m_FZZWRPr != NULL ? new FZZWRPr(*obj.m_FZZWRPr) : NULL;
    m_FZZWT = obj.m_FZZWT != NULL ? new FZZWT(*obj.m_FZZWT) : NULL;
    m_FZZWTab = obj.m_FZZWTab != NULL ? new FZZWTab(*obj.m_FZZWTab) : NULL;
    m_FZZWDrawing = obj.m_FZZWDrawing != NULL ? new FZZWDrawing(*obj.m_FZZWDrawing) : NULL;
    m_FZZMCAlternateContent = obj.m_FZZMCAlternateContent != NULL ? new FZZMCAlternateContent(*obj.m_FZZMCAlternateContent) : NULL;
    m_FZZWSeparator = obj.m_FZZWSeparator != NULL ? new FZZWSeparator(*obj.m_FZZWSeparator) : NULL;
    m_FZZWContinuationSeparator = obj.m_FZZWContinuationSeparator != NULL ? new FZZWContinuationSeparator(*obj.m_FZZWContinuationSeparator) : NULL;
    m_FZZWFldChar = obj.m_FZZWFldChar != NULL ? new FZZWFldChar(*obj.m_FZZWFldChar) : NULL;
    m_FZZWInstrText = obj.m_FZZWInstrText != NULL ? new FZZWInstrText(*obj.m_FZZWInstrText) : NULL;
    m_FZZWCr = obj.m_FZZWCr != NULL ? new FZZWCr(*obj.m_FZZWCr) : NULL;
    m_FZZWBr = obj.m_FZZWBr != NULL ? new FZZWBr(*obj.m_FZZWBr) : NULL;
    m_FZZWLastRenderedPageBreak = obj.m_FZZWLastRenderedPageBreak != NULL ? new FZZWLastRenderedPageBreak(*obj.m_FZZWLastRenderedPageBreak) : NULL;
    m_FZZWPict = obj.m_FZZWPict != NULL ? new FZZWPict(*obj.m_FZZWPict) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR::~FZZWR()
{
    //DLOG("~FZZWR()");
    FZZConst::delClassCount("FZZWR");
    if ( m_FZZWRPr != NULL ) {
        delete m_FZZWRPr;
        m_FZZWRPr = NULL;
    }
    if ( m_FZZWT != NULL ) {
        delete m_FZZWT;
        m_FZZWT = NULL;
    }
    if ( m_FZZWTab != NULL ) {
        delete m_FZZWTab;
        m_FZZWTab = NULL;
    }
    if ( m_FZZWDrawing != NULL ) {
        delete m_FZZWDrawing;
        m_FZZWDrawing = NULL;
    }
    if ( m_FZZMCAlternateContent != NULL ) {
        delete m_FZZMCAlternateContent;
        m_FZZMCAlternateContent = NULL;
    }
    if ( m_FZZWSeparator != NULL ) {
        delete m_FZZWSeparator;
        m_FZZWSeparator = NULL;
    }
    if ( m_FZZWContinuationSeparator != NULL ) {
        delete m_FZZWContinuationSeparator;
        m_FZZWContinuationSeparator = NULL;
    }
    if ( m_FZZWFldChar != NULL ) {
        delete m_FZZWFldChar;
        m_FZZWFldChar = NULL;
    }
    if ( m_FZZWInstrText != NULL ) {
        delete m_FZZWInstrText;
        m_FZZWInstrText = NULL;
    }
    if ( m_FZZWCr != NULL ) {
        delete m_FZZWCr;
        m_FZZWCr = NULL;
    }
    if ( m_FZZWBr != NULL ) {
        delete m_FZZWBr;
        m_FZZWBr = NULL;
    }
    if ( m_FZZWLastRenderedPageBreak != NULL ) {
        delete m_FZZWLastRenderedPageBreak;
        m_FZZWLastRenderedPageBreak = NULL;
    }
    
    if ( m_FZZWPict != NULL ) {
        delete m_FZZWPict;
        m_FZZWPict = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWR::setRPr()
{
    return m_FZZWRPr = setElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRPr * FZZWR::getRPr()
{
    return m_FZZWRPr = getElementObject(m_FZZWRPr,FZZWRPR_Find_Key,FZZWRPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWR::setRsidRPr(string value)
{
    setAttribute_String("w:rsidRPr",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWR::getRsidRPr()
{
    return getAttribute_String("w:rsidRPr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT * FZZWR::setT()
{
    return m_FZZWT = setElementObject(m_FZZWT,FZZWT_Find_Key,FZZWT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWT * FZZWR::getT()
{
    return m_FZZWT = getElementObject(m_FZZWT,FZZWT_Find_Key,FZZWT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab * FZZWR::setTab()
{
    return m_FZZWTab = setElementObject(m_FZZWTab,FZZWTAB_Find_Key,FZZWTAB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTab * FZZWR::getTab()
{
    return m_FZZWTab = getElementObject(m_FZZWTab,FZZWTAB_Find_Key,FZZWTAB_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing * FZZWR::setDrawing()
{
    return m_FZZWDrawing = setElementObject(m_FZZWDrawing,FZZWDRAWING_Find_Key,FZZWDRAWING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing * FZZWR::getDrawing()
{
    return m_FZZWDrawing = getElementObject(m_FZZWDrawing,FZZWDRAWING_Find_Key,FZZWDRAWING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent * FZZWR::setAlternateContent()
{
    return m_FZZMCAlternateContent = setElementObject(m_FZZMCAlternateContent,FZZMCALTERNATECONTENT_Find_Key,FZZMCALTERNATECONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent * FZZWR::getAlternateContent()
{
    return m_FZZMCAlternateContent = getElementObject(m_FZZMCAlternateContent,FZZMCALTERNATECONTENT_Find_Key,FZZMCALTERNATECONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator * FZZWR::setSeparator()
{
    return m_FZZWSeparator = setElementObject(m_FZZWSeparator,FZZWSEPARATOR_Find_Key,FZZWSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator * FZZWR::getSeparator()
{
    return m_FZZWSeparator = getElementObject(m_FZZWSeparator,FZZWSEPARATOR_Find_Key,FZZWSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator * FZZWR::setContinuationSeparator()
{
    return m_FZZWContinuationSeparator = setElementObject(m_FZZWContinuationSeparator,FZZWCONTINUATIONSEPARATOR_Find_Key,FZZWCONTINUATIONSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator * FZZWR::getContinuationSeparator()
{
    return m_FZZWContinuationSeparator = getElementObject(m_FZZWContinuationSeparator,FZZWCONTINUATIONSEPARATOR_Find_Key,FZZWCONTINUATIONSEPARATOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar * FZZWR::setFldChar()
{
    return m_FZZWFldChar = setElementObject(m_FZZWFldChar,FZZWFLDCHAR_Find_Key,FZZWFLDCHAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFldChar * FZZWR::getFldChar()
{
    return m_FZZWFldChar = getElementObject(m_FZZWFldChar,FZZWFLDCHAR_Find_Key,FZZWFLDCHAR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText * FZZWR::setInstrText()
{
    return m_FZZWInstrText = setElementObject(m_FZZWInstrText,FZZWINSTRTEXT_Find_Key,FZZWINSTRTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInstrText * FZZWR::getInstrText()
{
    return m_FZZWInstrText = getElementObject(m_FZZWInstrText,FZZWINSTRTEXT_Find_Key,FZZWINSTRTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr * FZZWR::setCr()
{
    return m_FZZWCr = setElementObject(m_FZZWCr,FZZWCR_Find_Key,FZZWCR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCr * FZZWR::getCr()
{
    return m_FZZWCr = getElementObject(m_FZZWCr,FZZWCR_Find_Key,FZZWCR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr * FZZWR::setBr()
{
    return m_FZZWBr = setElementObject(m_FZZWBr,FZZWBR_Find_Key,FZZWBR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBr * FZZWR::getBr()
{
    return m_FZZWBr = getElementObject(m_FZZWBr,FZZWBR_Find_Key,FZZWBR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak * FZZWR::setLastRenderedPageBreak()
{
    return m_FZZWLastRenderedPageBreak = setElementObject(m_FZZWLastRenderedPageBreak,FZZWLASTRENDEREDPAGEBREAK_Find_Key,FZZWLASTRENDEREDPAGEBREAK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLastRenderedPageBreak * FZZWR::getLastRenderedPageBreak()
{
    return m_FZZWLastRenderedPageBreak = getElementObject(m_FZZWLastRenderedPageBreak,FZZWLASTRENDEREDPAGEBREAK_Find_Key,FZZWLASTRENDEREDPAGEBREAK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict * FZZWR::setPict()
{
    return m_FZZWPict = setElementObject(m_FZZWPict,FZZWPICT_Find_Key,FZZWPICT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict * FZZWR::getPict()
{
    return m_FZZWPict = getElementObject(m_FZZWPict,FZZWPICT_Find_Key,FZZWPICT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
