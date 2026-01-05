//
//  Created by zizheng fan on 2023/11/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPBdr.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPBdr**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr::FZZWPBdr() : FZZXMLElementObject(),m_FZZWBottom(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL)
{
    //DLOG("FZZWPBdr()");
    FZZConst::addClassCount("FZZWPBdr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr::FZZWPBdr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWBottom(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPBdr");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr::FZZWPBdr(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWBottom(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL)
{
    FZZConst::addClassCount("FZZWPBdr");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr::FZZWPBdr(const FZZWPBdr& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPBdr");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTop = obj.m_FZZWTop != NULL ? new FZZWTop(*obj.m_FZZWTop) : NULL;
    m_FZZWRight = obj.m_FZZWRight != NULL ? new FZZWRight(*obj.m_FZZWRight) : NULL;
    m_FZZWLeft = obj.m_FZZWLeft != NULL ? new FZZWLeft(*obj.m_FZZWLeft) : NULL;
    m_FZZWBottom = obj.m_FZZWBottom != NULL ? new FZZWBottom(*obj.m_FZZWBottom) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPBdr::~FZZWPBdr()
{
    //DLOG("~FZZWPBdr()");
    FZZConst::delClassCount("FZZWPBdr");
    
    if ( m_FZZWTop != NULL ) {
        delete m_FZZWTop;
        m_FZZWTop = NULL;
    }
    if ( m_FZZWRight != NULL ) {
        delete m_FZZWRight;
        m_FZZWRight = NULL;
    }
    if ( m_FZZWLeft != NULL ) {
        delete m_FZZWLeft;
        m_FZZWLeft = NULL;
    }
    
    if ( m_FZZWBottom != NULL ) {
        delete m_FZZWBottom;
        m_FZZWBottom = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWPBdr::setBottom()
{
    return m_FZZWBottom = setElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWPBdr::getBottom()
{
    return m_FZZWBottom = getElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWPBdr::setTop()
{
    return m_FZZWTop = setElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWPBdr::getTop()
{
    return m_FZZWTop = getElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWPBdr::setRight()
{
    return m_FZZWRight = setElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWPBdr::getRight()
{
    return m_FZZWRight = getElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWPBdr::setLeft()
{
    return m_FZZWLeft = setElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWPBdr::getLeft()
{
    return m_FZZWLeft = getElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
