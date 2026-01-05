//
//  Created by zizheng fan on 2023/05/11.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCChoice.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMCChoice**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice::FZZMCChoice() : FZZXMLElementObject(),m_FZZWDrawing(NULL)
{
    //DLOG("FZZMCChoice()");
    FZZConst::addClassCount("FZZMCChoice");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice::FZZMCChoice(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWDrawing(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMCChoice");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice::FZZMCChoice(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWDrawing(NULL)
{
    FZZConst::addClassCount("FZZMCChoice");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice::FZZMCChoice(const FZZMCChoice& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMCChoice");
    if ( this == &obj ) {
        return;
    }
    
 
    
    m_FZZWDrawing = obj.m_FZZWDrawing != NULL ? new FZZWDrawing(*obj.m_FZZWDrawing) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMCChoice::~FZZMCChoice()
{
    //DLOG("~FZZMCChoice()");
    FZZConst::delClassCount("FZZMCChoice");
    
    if ( m_FZZWDrawing != NULL ) {
        delete m_FZZWDrawing;
        m_FZZWDrawing = NULL;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing * FZZMCChoice::setDrawing()
{
    return m_FZZWDrawing = setElementObject(m_FZZWDrawing,FZZWDRAWING_Find_Key,FZZWDRAWING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing * FZZMCChoice::getDrawing()
{
    return m_FZZWDrawing = getElementObject(m_FZZWDrawing,FZZWDRAWING_Find_Key,FZZWDRAWING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMCChoice::setRequires(string value)
{
    setAttribute_String("Requires",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMCChoice::getRequires()
{
    return getAttribute_String("Requires");
}
//-----------------------------------------------------------------------------------------------------------------
