//
//  Created by zizheng fan on 2023/08/11
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsolidFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAsolidFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill::FZZAsolidFill() : FZZXMLElementObject(),m_CTschemeClr(NULL),m_FZZASrgbClr(NULL)
{
    //DLOG("FZZAsolidFill()");
    FZZConst::addClassCount("FZZAsolidFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill::FZZAsolidFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_CTschemeClr(NULL),m_FZZASrgbClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAsolidFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill::FZZAsolidFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTschemeClr(NULL),m_FZZASrgbClr(NULL)
{
    FZZConst::addClassCount("FZZAsolidFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill::FZZAsolidFill(const FZZAsolidFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAsolidFill");
    if ( this == &obj ) {
        return;
    }
    m_CTschemeClr = obj.m_CTschemeClr != NULL ? new FZZAschemeClr(*obj.m_CTschemeClr) : NULL;
    m_FZZASrgbClr = obj.m_FZZASrgbClr != NULL ? new FZZASrgbClr(*obj.m_FZZASrgbClr) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZAsolidFill::~FZZAsolidFill()
{
    //DLOG("~FZZAsolidFill()");
    FZZConst::delClassCount("FZZAsolidFill");
    if ( m_CTschemeClr != NULL ) {
        delete m_CTschemeClr;
        m_CTschemeClr = NULL;
    }
    if ( m_FZZASrgbClr != NULL ) {
        delete m_FZZASrgbClr;
        m_FZZASrgbClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAsolidFill::setSchemeClr()
{
    return m_CTschemeClr = setElementObject(m_CTschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAsolidFill::getSchemeClr()
{
    return m_CTschemeClr = getElementObject(m_CTschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAsolidFill::setSrgbClr()
{
    return m_FZZASrgbClr = setElementObject(m_FZZASrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAsolidFill::getSrgbClr()
{
    return m_FZZASrgbClr = getElementObject(m_FZZASrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
