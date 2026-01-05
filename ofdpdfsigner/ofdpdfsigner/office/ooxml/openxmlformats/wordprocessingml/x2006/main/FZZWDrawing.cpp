//
//  Created by zizheng fan on 2023/11/02
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawing.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDrawing**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing::FZZWDrawing() : FZZXMLElementObject(),m_FZZWPInline(NULL),m_FZZWPAnchor(NULL)
{
    //DLOG("FZZWDrawing()");
    FZZConst::addClassCount("FZZWDrawing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing::FZZWDrawing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPInline(NULL),m_FZZWPAnchor(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDrawing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing::FZZWDrawing(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPInline(NULL),m_FZZWPAnchor(NULL)
{
    FZZConst::addClassCount("FZZWDrawing");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing::FZZWDrawing(const FZZWDrawing& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDrawing");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPInline = obj.m_FZZWPInline != NULL ? new FZZWPInline(*obj.m_FZZWPInline) : NULL;
    m_FZZWPAnchor = obj.m_FZZWPAnchor != NULL ? new FZZWPAnchor(*obj.m_FZZWPAnchor) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawing::~FZZWDrawing()
{
    //DLOG("~FZZWDrawing()");
    FZZConst::delClassCount("FZZWDrawing");
    if ( m_FZZWPInline != NULL ) {
        delete m_FZZWPInline;
        m_FZZWPInline = NULL;
    }
    if ( m_FZZWPAnchor != NULL ) {
        delete m_FZZWPAnchor;
        m_FZZWPAnchor = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void FZZWDrawing::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDrawing::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline * FZZWDrawing::setInline()
{
    return m_FZZWPInline = setElementObject(m_FZZWPInline,FZZWPINLINE_Find_Key,FZZWPINLINE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline * FZZWDrawing::getInline()
{
    return m_FZZWPInline = getElementObject(m_FZZWPInline,FZZWPINLINE_Find_Key,FZZWPINLINE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor * FZZWDrawing::setAnchor()
{
    return m_FZZWPAnchor = setElementObject(m_FZZWPAnchor,FZZWPANCHOR_Find_Key,FZZWPANCHOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor * FZZWDrawing::getAnchor()
{
    return m_FZZWPAnchor = getElementObject(m_FZZWPAnchor,FZZWPANCHOR_Find_Key,FZZWPANCHOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
