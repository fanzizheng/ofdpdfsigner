//
//  Created by zizheng fan on 2023/07/10
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAStretch.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAStretch**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch::FZZAStretch() : FZZXMLElementObject(),m_FZZAFillRect(NULL)
{
    //DLOG("FZZAStretch()");
    FZZConst::addClassCount("FZZAStretch");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch::FZZAStretch(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZAFillRect(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAStretch");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch::FZZAStretch(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZAFillRect(NULL)
{
    FZZConst::addClassCount("FZZAStretch");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch::FZZAStretch(const FZZAStretch& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAStretch");
    if ( this == &obj ) {
        return;
    }
    m_FZZAFillRect = obj.m_FZZAFillRect != NULL ? new FZZAFillRect(*obj.m_FZZAFillRect) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAStretch::~FZZAStretch()
{
    //DLOG("~FZZAStretch()");
    FZZConst::delClassCount("FZZAStretch");
    if ( m_FZZAFillRect != NULL ) {
        delete m_FZZAFillRect;
        m_FZZAFillRect = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZAStretch::setEmbed(string value)
//{
//    setAttribute_String("r:embed",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZAStretch::getEmbed()
//{
//    return getAttribute_String("r:embed");
//}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect * FZZAStretch::setFillRect()
{
    return m_FZZAFillRect = setElementObject(m_FZZAFillRect,FZZAFILLRECT_Find_Key,FZZAFILLRECT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAFillRect * FZZAStretch::getFillRect()
{
    return m_FZZAFillRect = getElementObject(m_FZZAFillRect,FZZAFILLRECT_Find_Key,FZZAFILLRECT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
