//
//  Created by zizheng fan on 2023/05/08.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SolidFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW14SolidFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill::FZZW14SolidFill() : FZZXMLElementObject(),m_FZZW14SrgbClr(NULL)
{
    //DLOG("FZZW14SolidFill()");
    FZZConst::addClassCount("FZZW14SolidFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill::FZZW14SolidFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZW14SrgbClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW14SolidFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill::FZZW14SolidFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZW14SrgbClr(NULL)
{
    FZZConst::addClassCount("FZZW14SolidFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill::FZZW14SolidFill(const FZZW14SolidFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW14SolidFill");
    if ( this == &obj ) {
        return;
    }
    m_FZZW14SrgbClr = obj.m_FZZW14SrgbClr != NULL ? new FZZW14SrgbClr(*obj.m_FZZW14SrgbClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill::~FZZW14SolidFill()
{
    //DLOG("~FZZW14SolidFill()");
    FZZConst::delClassCount("FZZW14SolidFill");
    if ( m_FZZW14SrgbClr != NULL ) {
        delete m_FZZW14SrgbClr;
        m_FZZW14SrgbClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW14SolidFill::setVal(string value)
{
    setAttribute_String("w14:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW14SolidFill::getVal()
{
    return getAttribute_String("w14:val");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr * FZZW14SolidFill::setSrgbClr()
{
    return m_FZZW14SrgbClr = setElementObject(m_FZZW14SrgbClr,FZZW14SRGBCLR_Find_Key,FZZW14SRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SrgbClr * FZZW14SolidFill::getSrgbClr()
{
    return m_FZZW14SrgbClr = getElementObject(m_FZZW14SrgbClr,FZZW14SRGBCLR_Find_Key,FZZW14SRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
