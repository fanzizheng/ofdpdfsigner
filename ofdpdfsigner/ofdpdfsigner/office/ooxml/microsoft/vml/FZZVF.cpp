//
//  Created by zizheng fan on 2023/04/17.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVF.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVF**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVF::FZZVF() : FZZXMLElementObject()
{
    //DLOG("FZZVF()");
    FZZConst::addClassCount("FZZVF");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVF::FZZVF(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVF");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVF::FZZVF(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVF");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVF::FZZVF(const FZZVF& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVF");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVF::~FZZVF()
{
    //DLOG("~FZZVF()");
    FZZConst::delClassCount("FZZVF");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVF::setEqn(string value)
{
    setAttribute_String("eqn",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVF::getEqn()
{
    return getAttribute_String("eqn");
}
//-----------------------------------------------------------------------------------------------------------------

