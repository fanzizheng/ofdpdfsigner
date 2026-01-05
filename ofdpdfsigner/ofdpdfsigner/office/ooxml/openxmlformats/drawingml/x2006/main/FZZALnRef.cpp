//
//  Created by zizheng fan on 2023/07/03
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZALnRef.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZALnRef**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef::FZZALnRef() : FZZXMLElementObject(),m_FZZAschemeClr(NULL)
{
    //DLOG("FZZALnRef()");
    FZZConst::addClassCount("FZZALnRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef::FZZALnRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAschemeClr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZALnRef");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef::FZZALnRef(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAschemeClr(NULL)
{
    FZZConst::addClassCount("FZZALnRef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef::FZZALnRef(const FZZALnRef& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZALnRef");
    if ( this == &obj ) {
        return;
    }
    m_FZZAschemeClr = obj.m_FZZAschemeClr != NULL ? new FZZAschemeClr(*obj.m_FZZAschemeClr) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZALnRef::~FZZALnRef()
{
    //DLOG("~FZZALnRef()");
    FZZConst::delClassCount("FZZALnRef");
    if ( m_FZZAschemeClr != NULL ) {
        delete m_FZZAschemeClr;
        m_FZZAschemeClr = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZALnRef::setIdx(string value)
{
    setAttribute_String("idx",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZALnRef::getIdx()
{
    return getAttribute_String("idx");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZALnRef::setSchemeClr()
{
    return m_FZZAschemeClr = setElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAschemeClr * FZZALnRef::getSchemeClr()
{
    return m_FZZAschemeClr = getElementObject(m_FZZAschemeClr,FZZASCHEMECLR_Find_Key,FZZASCHEMECLR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
