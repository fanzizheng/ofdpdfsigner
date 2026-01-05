//
//  Created by zizheng fan on 2023/06/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRef.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAFillRef**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef::FZZAFillRef() : FZZXMLElementObject(),m_FZZAschemeClr(NULL)
{
    //DLOG("FZZAFillRef()");
    FZZConst::addClassCount("FZZAFillRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef::FZZAFillRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAschemeClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAFillRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef::FZZAFillRef(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAschemeClr(NULL)
{
    FZZConst::addClassCount("FZZAFillRef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef::FZZAFillRef(const FZZAFillRef& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAFillRef");
    if ( this == &obj ) {
        return;
    }
    m_FZZAschemeClr = obj.m_FZZAschemeClr != NULL ? new FZZAschemeClr(*obj.m_FZZAschemeClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRef::~FZZAFillRef()
{
    //DLOG("~FZZAFillRef()");
    FZZConst::delClassCount("FZZAFillRef");
    if ( m_FZZAschemeClr != NULL ) {
        delete m_FZZAschemeClr;
        m_FZZAschemeClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAFillRef::setIdx(string value)
{
    setAttribute_String("idx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAFillRef::getIdx()
{
    return getAttribute_String("idx");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAFillRef::setSchemeClr()
{
    return m_FZZAschemeClr = setElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZAFillRef::getSchemeClr()
{
    return m_FZZAschemeClr = getElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
