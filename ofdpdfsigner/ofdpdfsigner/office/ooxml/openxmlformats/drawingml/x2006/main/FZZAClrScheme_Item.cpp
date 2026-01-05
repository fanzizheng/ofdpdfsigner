//
//  Created by zizheng fan on 2023/08/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme_Item.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAClrScheme_Item**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item::FZZAClrScheme_Item() : FZZXMLElementObject(),m_CTSysClr(NULL),m_CTSrgbClr(NULL)
{
    //DLOG("FZZAClrScheme_Item()");
    FZZConst::addClassCount("FZZAClrScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item::FZZAClrScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_CTSysClr(NULL),m_CTSrgbClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAClrScheme_Item");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item::FZZAClrScheme_Item(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTSysClr(NULL),m_CTSrgbClr(NULL)
{
    FZZConst::addClassCount("FZZAClrScheme_Item");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item::FZZAClrScheme_Item(const FZZAClrScheme_Item& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAClrScheme_Item");
    if ( this == &obj ) {
        return;
    }

    m_CTSysClr = obj.m_CTSysClr != NULL ? new FZZASysClr(*obj.m_CTSysClr) : NULL;
    m_CTSrgbClr = obj.m_CTSrgbClr != NULL ? new FZZASrgbClr(*obj.m_CTSrgbClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAClrScheme_Item::~FZZAClrScheme_Item()
{
    //DLOG("~FZZAClrScheme_Item()");
    FZZConst::delClassCount("FZZAClrScheme_Item");
    if ( m_CTSysClr != NULL ) {
        delete m_CTSysClr;
        m_CTSysClr = NULL;
    }
    
    if ( m_CTSrgbClr != NULL ) {
        delete m_CTSrgbClr;
        m_CTSrgbClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr * FZZAClrScheme_Item::setSysClr()
{
    return m_CTSysClr = setElementObject(m_CTSysClr,FZZASYSCLR_Find_Key,FZZASYSCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASysClr * FZZAClrScheme_Item::getSysClr()
{
    return m_CTSysClr = getElementObject(m_CTSysClr,FZZASYSCLR_Find_Key,FZZASYSCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAClrScheme_Item::setSrgbClr()
{
    return m_CTSrgbClr = setElementObject(m_CTSrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr * FZZAClrScheme_Item::getSrgbClr()
{
    return m_CTSrgbClr = getElementObject(m_CTSrgbClr,FZZASRGBCLR_Find_Key,FZZASRGBCLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
