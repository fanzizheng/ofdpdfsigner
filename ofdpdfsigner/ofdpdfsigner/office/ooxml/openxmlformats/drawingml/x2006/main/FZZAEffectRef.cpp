//
//  Created by zizheng fan on 2023/06/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAEffectRef.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAEffectRef**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef::FZZAEffectRef() : FZZXMLElementObject(),m_FZZAschemeClr(NULL)
{
    //DLOG("FZZAEffectRef()");
    FZZConst::addClassCount("FZZAEffectRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef::FZZAEffectRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAschemeClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAEffectRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef::FZZAEffectRef(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAschemeClr(NULL)
{
    FZZConst::addClassCount("FZZAEffectRef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef::FZZAEffectRef(const FZZAEffectRef& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAEffectRef");
    if ( this == &obj ) {
        return;
    }
    m_FZZAschemeClr = obj.m_FZZAschemeClr != NULL ? new FZZAschemeClr(*obj.m_FZZAschemeClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAEffectRef::~FZZAEffectRef()
{
    //DLOG("~FZZAEffectRef()");
    FZZConst::delClassCount("FZZAEffectRef");
    if ( m_FZZAschemeClr != NULL ) {
        delete m_FZZAschemeClr;
        m_FZZAschemeClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAEffectRef::setIdx(string value)
{
    setAttribute_String("idx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAEffectRef::getIdx()
{
    return getAttribute_String("idx");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAEffectRef::setSchemeClr()
{
    return m_FZZAschemeClr = setElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAEffectRef::getSchemeClr()
{
    return m_FZZAschemeClr = getElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
