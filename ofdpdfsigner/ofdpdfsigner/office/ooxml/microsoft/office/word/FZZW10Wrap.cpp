//
//  Created by zizheng fan on 2023/04/25.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/FZZW10Wrap.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVStroke**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap::FZZW10Wrap() : FZZXMLElementObject()
{
    //DLOG("FZZW10Wrap()");
    FZZConst::addClassCount("FZZW10Wrap");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap::FZZW10Wrap(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW10Wrap");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap::FZZW10Wrap(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZW10Wrap");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap::FZZW10Wrap(const FZZW10Wrap& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW10Wrap");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap::~FZZW10Wrap()
{
    //DLOG("~FZZW10Wrap()");
    FZZConst::delClassCount("FZZW10Wrap");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW10Wrap::setAnchorX(string value)
{
    setAttribute_String("anchorx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW10Wrap::getAnchorX()
{
    return getAttribute_String("anchorx");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW10Wrap::setAnchorY(string value)
{
    setAttribute_String("anchory",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW10Wrap::getAnchorY()
{
    return getAttribute_String("anchory");
}
//-----------------------------------------------------------------------------------------------------------------

