//
//  Created by zizheng fan on 2023/05/12.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCAlternateContent.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMCAlternateContent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent::FZZMCAlternateContent() : FZZXMLElementObject(),m_FZZMCFallback(NULL),m_FZZMCChoice(NULL)
{
    //DLOG("FZZMCFallback()");
    FZZConst::addClassCount("FZZMCAlternateContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent::FZZMCAlternateContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZMCFallback(NULL),m_FZZMCChoice(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMCAlternateContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent::FZZMCAlternateContent(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZMCFallback(NULL),m_FZZMCChoice(NULL)
{
    FZZConst::addClassCount("FZZMCAlternateContent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent::FZZMCAlternateContent(const FZZMCAlternateContent& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMCAlternateContent");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZMCFallback = obj.m_FZZMCFallback != NULL ? new FZZMCFallback(*obj.m_FZZMCFallback) : NULL;
    m_FZZMCChoice = obj.m_FZZMCChoice != NULL ? new FZZMCChoice(*obj.m_FZZMCChoice) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCAlternateContent::~FZZMCAlternateContent()
{
    //DLOG("~FZZMCAlternateContent()");
    FZZConst::delClassCount("FZZMCAlternateContent");
    
    if ( m_FZZMCFallback != NULL ) {
        delete m_FZZMCFallback;
        m_FZZMCFallback = NULL;
    }
    if ( m_FZZMCChoice != NULL ) {
        delete m_FZZMCChoice;
        m_FZZMCChoice = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback * FZZMCAlternateContent::setFallback()
{
    return m_FZZMCFallback = setElementObject(m_FZZMCFallback,FZZMCFALLBACK_Find_Key,FZZMCFALLBACK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCFallback * FZZMCAlternateContent::getFallback()
{
    return m_FZZMCFallback = getElementObject(m_FZZMCFallback,FZZMCFALLBACK_Find_Key,FZZMCFALLBACK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice * FZZMCAlternateContent::setChoice()
{
    return m_FZZMCChoice = setElementObject(m_FZZMCChoice,FZZMCCHOICE_Find_Key,FZZMCCHOICE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice * FZZMCAlternateContent::getChoice()
{
    return m_FZZMCChoice = getElementObject(m_FZZMCChoice,FZZMCCHOICE_Find_Key,FZZMCCHOICE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
