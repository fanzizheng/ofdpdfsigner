//
//  Created by zizheng fan on 2023/05/08.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SrgbClr.h"
#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWColor.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW14SrgbClr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr::FZZW14SrgbClr() : FZZXMLElementObject(),m_FZZW14Alpha(NULL)
{
    //DLOG("FZZW14SrgbClr()");
    FZZConst::addClassCount("FZZW14SrgbClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr::FZZW14SrgbClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZW14Alpha(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW14SrgbClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr::FZZW14SrgbClr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZW14Alpha(NULL)
{
    FZZConst::addClassCount("FZZW14SrgbClr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr::FZZW14SrgbClr(const FZZW14SrgbClr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW14SrgbClr");
    if ( this == &obj ) {
        return;
    }
    m_FZZW14Alpha = obj.m_FZZW14Alpha != NULL ? new FZZW14Alpha(*obj.m_FZZW14Alpha) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr::~FZZW14SrgbClr()
{
    //DLOG("~FZZW14SrgbClr()");
    FZZConst::delClassCount("FZZW14SrgbClr");
    if ( m_FZZW14Alpha != NULL ) {
        delete m_FZZW14Alpha;
        m_FZZW14Alpha = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW14SrgbClr::setVal(string value)
{
    setAttribute_String("w14:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW14SrgbClr::getVal()
{
    return getAttribute_String("w14:val");
}
//-----------------------------------------------------------------------------------------------------------------

FZZW14Alpha * FZZW14SrgbClr::setAlpha()
{
    return m_FZZW14Alpha = setElementObject(m_FZZW14Alpha,FZZW14ALPHA_Find_Key,FZZW14ALPHA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha * FZZW14SrgbClr::getAlpha()
{
    return m_FZZW14Alpha = getElementObject(m_FZZW14Alpha,FZZW14ALPHA_Find_Key,FZZW14ALPHA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
