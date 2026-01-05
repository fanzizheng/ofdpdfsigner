//
//  Created by zizheng fan on 2023/11/17
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcBorders.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTcBorders**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders::FZZWTcBorders() : FZZXMLElementObject(),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWTl2br(NULL),m_FZZWTr2bl(NULL)
{
    //DLOG("FZZWTcBorders()");
    FZZConst::addClassCount("FZZWTcBorders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders::FZZWTcBorders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWTl2br(NULL),m_FZZWTr2bl(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTcBorders");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders::FZZWTcBorders(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWInsideV(NULL),m_FZZWInsideH(NULL),m_FZZWTop(NULL),m_FZZWRight(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWTl2br(NULL),m_FZZWTr2bl(NULL)
{
    FZZConst::addClassCount("FZZWTcBorders");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders::FZZWTcBorders(const FZZWTcBorders& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTcBorders");
    if ( this == &obj ) {
        return;
    }
    m_FZZWInsideV = obj.m_FZZWInsideV != NULL ? new FZZWInsideV(*obj.m_FZZWInsideV) : NULL;
    m_FZZWInsideH = obj.m_FZZWInsideH != NULL ? new FZZWInsideH(*obj.m_FZZWInsideH) : NULL;
    m_FZZWTop = obj.m_FZZWTop != NULL ? new FZZWTop(*obj.m_FZZWTop) : NULL;
    m_FZZWRight = obj.m_FZZWRight != NULL ? new FZZWRight(*obj.m_FZZWRight) : NULL;
    m_FZZWLeft = obj.m_FZZWLeft != NULL ? new FZZWLeft(*obj.m_FZZWLeft) : NULL;
    m_FZZWBottom = obj.m_FZZWBottom != NULL ? new FZZWBottom(*obj.m_FZZWBottom) : NULL;
    m_FZZWTl2br = obj.m_FZZWTl2br != NULL ? new FZZWTl2br(*obj.m_FZZWTl2br) : NULL;
    m_FZZWTr2bl = obj.m_FZZWTr2bl != NULL ? new FZZWTr2bl(*obj.m_FZZWTr2bl) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTcBorders::~FZZWTcBorders()
{
    //DLOG("~FZZWTcBorders()");
    FZZConst::delClassCount("FZZWTcBorders");
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
    if ( m_FZZWTl2br != NULL ) {
        delete m_FZZWTl2br;
        m_FZZWTl2br = NULL;
    }
    if ( m_FZZWTr2bl != NULL ) {
        delete m_FZZWTr2bl;
        m_FZZWTr2bl = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV * FZZWTcBorders::setInsideV()
{
    return m_FZZWInsideV = setElementObject(m_FZZWInsideV,FZZWINSIDEV_Find_Key,FZZWINSIDEV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideV * FZZWTcBorders::getInsideV()
{
    return m_FZZWInsideV = getElementObject(m_FZZWInsideV,FZZWINSIDEV_Find_Key,FZZWINSIDEV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH * FZZWTcBorders::setInsideH()
{
    return m_FZZWInsideH = setElementObject(m_FZZWInsideH,FZZWINSIDEH_Find_Key,FZZWINSIDEH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWInsideH * FZZWTcBorders::getInsideH()
{
    return m_FZZWInsideH = getElementObject(m_FZZWInsideH,FZZWINSIDEH_Find_Key,FZZWINSIDEH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTcBorders::setTop()
{
    return m_FZZWTop = setElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTcBorders::getTop()
{
    return m_FZZWTop = getElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTcBorders::setRight()
{
    return m_FZZWRight = setElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTcBorders::getRight()
{
    return m_FZZWRight = getElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTcBorders::setLeft()
{
    return m_FZZWLeft = setElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTcBorders::getLeft()
{
    return m_FZZWLeft = getElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTcBorders::setBottom()
{
    return m_FZZWBottom = setElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTcBorders::getBottom()
{
    return m_FZZWBottom = getElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br * FZZWTcBorders::setTl2br()
{
    return m_FZZWTl2br = setElementObject(m_FZZWTl2br,FZZWTL2BR_Find_Key,FZZWTL2BR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTl2br * FZZWTcBorders::getTl2br()
{
    return m_FZZWTl2br = getElementObject(m_FZZWTl2br,FZZWTL2BR_Find_Key,FZZWTL2BR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr2bl * FZZWTcBorders::setTr2bl()
{
    return m_FZZWTr2bl = setElementObject(m_FZZWTr2bl,FZZWTR2BL_Find_Key,FZZWTR2BL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTr2bl * FZZWTcBorders::getTr2bl()
{
    return m_FZZWTr2bl = getElementObject(m_FZZWTr2bl,FZZWTR2BL_Find_Key,FZZWTR2BL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
