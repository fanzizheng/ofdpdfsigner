//
//  Created by zizheng fan on 2023/10/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellMar.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblCellMar**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar::FZZWTblCellMar() : FZZXMLElementObject(),m_FZZWTop(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWRight(NULL)
{
    //DLOG("FZZWTblCellMar()");
    FZZConst::addClassCount("FZZWTblCellMar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar::FZZWTblCellMar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWTop(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWRight(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblCellMar");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar::FZZWTblCellMar(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWTop(NULL),m_FZZWLeft(NULL),m_FZZWBottom(NULL),m_FZZWRight(NULL)
{
    FZZConst::addClassCount("FZZWTblCellMar");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar::FZZWTblCellMar(const FZZWTblCellMar& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblCellMar");
    if ( this == &obj ) {
        return;
    }
    m_FZZWTop = obj.m_FZZWTop != NULL ? new FZZWTop(*obj.m_FZZWTop) : NULL;
    m_FZZWLeft = obj.m_FZZWLeft != NULL ? new FZZWLeft(*obj.m_FZZWLeft) : NULL;
    m_FZZWBottom = obj.m_FZZWBottom != NULL ? new FZZWBottom(*obj.m_FZZWBottom) : NULL;
    m_FZZWRight = obj.m_FZZWRight != NULL ? new FZZWRight(*obj.m_FZZWRight) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellMar::~FZZWTblCellMar()
{
    //DLOG("~FZZWTblCellMar()");
    FZZConst::delClassCount("FZZWTblCellMar");
    if ( m_FZZWTop != NULL ) {
        delete m_FZZWTop;
        m_FZZWTop = NULL;
    }
    if ( m_FZZWLeft != NULL ) {
        delete m_FZZWLeft;
        m_FZZWLeft = NULL;
    }
    if ( m_FZZWBottom != NULL ) {
        delete m_FZZWBottom;
        m_FZZWBottom = NULL;
    }
    if ( m_FZZWRight != NULL ) {
        delete m_FZZWRight;
        m_FZZWRight = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTblCellMar::setTop()
{
    return m_FZZWTop = setElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTop * FZZWTblCellMar::getTop()
{
    return m_FZZWTop = getElementObject(m_FZZWTop,FZZWTOP_Find_Key,FZZWTOP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTblCellMar::setLeft()
{
    return m_FZZWLeft = setElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWLeft * FZZWTblCellMar::getLeft()
{
    return m_FZZWLeft = getElementObject(m_FZZWLeft,FZZWLEFT_Find_Key,FZZWLEFT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTblCellMar::setBottom()
{
    return m_FZZWBottom = setElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBottom * FZZWTblCellMar::getBottom()
{
    return m_FZZWBottom = getElementObject(m_FZZWBottom,FZZWBOTTOM_Find_Key,FZZWBOTTOM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTblCellMar::setRight()
{
    return m_FZZWRight = setElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRight * FZZWTblCellMar::getRight()
{
    return m_FZZWRight = getElementObject(m_FZZWRight,FZZWRIGHT_Find_Key,FZZWRIGHT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
