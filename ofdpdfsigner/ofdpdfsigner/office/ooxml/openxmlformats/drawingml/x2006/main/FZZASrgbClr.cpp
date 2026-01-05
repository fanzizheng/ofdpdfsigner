//
//  Created by zizheng fan on 2023/08/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZASrgbClr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr::FZZASrgbClr() : FZZXMLElementObject(),m_CTalpha(NULL)
{
    //DLOG("FZZASrgbClr()");
    FZZConst::addClassCount("FZZASrgbClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr::FZZASrgbClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_CTalpha(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZASrgbClr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr::FZZASrgbClr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_CTalpha(NULL)
{
    FZZConst::addClassCount("FZZASrgbClr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr::FZZASrgbClr(const FZZASrgbClr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZASrgbClr");
    if ( this == &obj ) {
        return;
    }

    m_CTalpha = obj.m_CTalpha != NULL ? new FZZAalpha(*obj.m_CTalpha) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZASrgbClr::~FZZASrgbClr()
{
    //DLOG("~FZZASrgbClr()");
    FZZConst::delClassCount("FZZASrgbClr");
    if ( m_CTalpha != NULL ) {
        delete m_CTalpha;
        m_CTalpha = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZASrgbClr::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZASrgbClr::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha * FZZASrgbClr::setAlpha()
{
    return m_CTalpha = setElementObject(m_CTalpha,FZZAALPHA_Find_Key,FZZAALPHA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha * FZZASrgbClr::getAlpha()
{
    return m_CTalpha = getElementObject(m_CTalpha,FZZAALPHA_Find_Key,FZZAALPHA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
