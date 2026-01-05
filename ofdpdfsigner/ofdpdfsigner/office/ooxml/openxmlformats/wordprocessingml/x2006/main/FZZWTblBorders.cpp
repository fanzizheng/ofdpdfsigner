//
//  Created by zizheng fan on 2023/11/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblBorders.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblBorders**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders::FZZWTblBorders() : FZZXMLElementObject(),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL)
{
    //DLOG("FZZWTblBorders()");
    FZZConst::addClassCount("FZZWTblBorders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders::FZZWTblBorders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblBorders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders::FZZWTblBorders(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL)
{
    FZZConst::addClassCount("FZZWTblBorders");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders::FZZWTblBorders(const FZZWTblBorders& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblBorders");
    if ( this == &obj ) {
        return;
    }
    m_FZZWInsideV = obj.m_FZZWInsideV != NULL ? new FZZWInsideV(*obj.m_FZZWInsideV) : NULL;
    m_FZZWInsideH = obj.m_FZZWInsideH != NULL ? new FZZWInsideH(*obj.m_FZZWInsideH) : NULL;
    m_FZZWTop = obj.m_FZZWTop != NULL ? new FZZWTop(*obj.m_FZZWTop) : NULL;
    m_FZZWRight = obj.m_FZZWRight != NULL ? new FZZWRight(*obj.m_FZZWRight) : NULL;
    m_FZZWLeft = obj.m_FZZWLeft != NULL ? new FZZWLeft(*obj.m_FZZWLeft) : NULL;
    m_FZZWBottom = obj.m_FZZWBottom != NULL ? new FZZWBottom(*obj.m_FZZWBottom) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblBorders::~FZZWTblBorders()
{
    //DLOG("~FZZWTblBorders()");
    FZZConst::delClassCount("FZZWTblBorders");
    if ( m_FZZWInsideV != NULL ) {
        delete m_FZZWInsideV;
        m_FZZWInsideV = NULL;
    }
    if ( m_FZZWInsideH != NULL ) {
        delete m_FZZWInsideH;
        m_FZZWInsideH = NULL;
    }
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
FZZWInsideV * FZZWTblBorders::setInsideV()
{
    return m_FZZWInsideV = setElementObject(m_FZZWInsideV,FZZWINSIDEV_Find_Key,FZZWINSIDEV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV * FZZWTblBorders::getInsideV()
{
    return m_FZZWInsideV = getElementObject(m_FZZWInsideV,FZZWINSIDEV_Find_Key,FZZWINSIDEV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH * FZZWTblBorders::setInsideH()
{
    return m_FZZWInsideH = setElementObject(m_FZZWInsideH,FZZWINSIDEH_Find_Key,FZZWINSIDEH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH * FZZWTblBorders::getInsideH()
{
    return m_FZZWInsideH = getElementObject(m_FZZWInsideH,FZZWINSIDEH_Find_Key,FZZWINSIDEH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTblBorders::setTop()
{
    return m_FZZWTop = setElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTblBorders::getTop()
{
    return m_FZZWTop = getElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTblBorders::setRight()
{
    return m_FZZWRight = setElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTblBorders::getRight()
{
    return m_FZZWRight = getElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTblBorders::setLeft()
{
    return m_FZZWLeft = setElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTblBorders::getLeft()
{
    return m_FZZWLeft = getElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTblBorders::setBottom()
{
    return m_FZZWBottom = setElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTblBorders::getBottom()
{
    return m_FZZWBottom = getElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
