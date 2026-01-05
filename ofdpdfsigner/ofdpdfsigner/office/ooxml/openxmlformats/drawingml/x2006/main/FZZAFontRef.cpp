//
//  Created by zizheng fan on 2023/06/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFontRef.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAFontRef**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef::FZZAFontRef() : FZZXMLElementObject(),m_FZZAschemeClr(NULL)
{
    //DLOG("FZZAFontRef()");
    FZZConst::addClassCount("FZZAFontRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef::FZZAFontRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAschemeClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAFontRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef::FZZAFontRef(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAschemeClr(NULL)
{
    FZZConst::addClassCount("FZZAFontRef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef::FZZAFontRef(const FZZAFontRef& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAFontRef");
    if ( this == &obj ) {
        return;
    }
    m_FZZAschemeClr = obj.m_FZZAschemeClr != NULL ? new FZZAschemeClr(*obj.m_FZZAschemeClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFontRef::~FZZAFontRef()
{
    //DLOG("~FZZAFontRef()");
    FZZConst::delClassCount("FZZAFontRef");
    if ( m_FZZAschemeClr != NULL ) {
        delete m_FZZAschemeClr;
        m_FZZAschemeClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAFontRef::setIdx(string value)
{
    setAttribute_String("idx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAFontRef::getIdx()
{
    return getAttribute_String("idx");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAFontRef::setSchemeClr()
{
    return m_FZZAschemeClr = setElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAFontRef::getSchemeClr()
{
    return m_FZZAschemeClr = getElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
