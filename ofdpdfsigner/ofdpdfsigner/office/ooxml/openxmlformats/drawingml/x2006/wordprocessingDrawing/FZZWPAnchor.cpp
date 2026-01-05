//
//  Created by zizheng fan on 2023/06/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAnchor.h"

#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPAnchor**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor::FZZWPAnchor() : FZZXMLElementObject(),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL),m_FZZWPSimplePos(NULL),m_FZZWPPositionH(NULL),m_FZZWPPositionV(NULL),m_FZZWPWrapNone(NULL)
{
    //DLOG("FZZWPAnchor()");
    FZZConst::addClassCount("FZZWPAnchor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor::FZZWPAnchor(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL),m_FZZWPSimplePos(NULL),m_FZZWPPositionH(NULL),m_FZZWPPositionV(NULL),m_FZZWPWrapNone(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPAnchor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor::FZZWPAnchor(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL),m_FZZWPSimplePos(NULL),m_FZZWPPositionH(NULL),m_FZZWPPositionV(NULL),m_FZZWPWrapNone(NULL)
{
    FZZConst::addClassCount("FZZWPAnchor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor::FZZWPAnchor(const FZZWPAnchor& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPAnchor");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPExtent = obj.m_FZZWPExtent != NULL ? new FZZWPExtent(*obj.m_FZZWPExtent) : NULL;
    m_FZZWPEffectExtent = obj.m_FZZWPEffectExtent != NULL ? new FZZWPEffectExtent(*obj.m_FZZWPEffectExtent) : NULL;
    m_FZZWPDocPr = obj.m_FZZWPDocPr != NULL ? new FZZWPDocPr(*obj.m_FZZWPDocPr) : NULL;
    m_FZZWPCNvGraphicFramePr = obj.m_FZZWPCNvGraphicFramePr != NULL ? new FZZWPCNvGraphicFramePr(*obj.m_FZZWPCNvGraphicFramePr) : NULL;
    m_FZZAGraphic = obj.m_FZZAGraphic != NULL ? new FZZAGraphic(*obj.m_FZZAGraphic) : NULL;
    m_FZZWPSimplePos = obj.m_FZZWPSimplePos != NULL ? new FZZWPSimplePos(*obj.m_FZZWPSimplePos) : NULL;
    m_FZZWPPositionH = obj.m_FZZWPPositionH != NULL ? new FZZWPPositionH(*obj.m_FZZWPPositionH) : NULL;
    m_FZZWPPositionV = obj.m_FZZWPPositionV != NULL ? new FZZWPPositionV(*obj.m_FZZWPPositionV) : NULL;
    m_FZZWPWrapNone = obj.m_FZZWPWrapNone != NULL ? new FZZWPWrapNone(*obj.m_FZZWPWrapNone) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAnchor::~FZZWPAnchor()
{
    //DLOG("~FZZWPAnchor()");
    FZZConst::delClassCount("FZZWPAnchor");
    if ( m_FZZWPExtent != NULL ) {
        delete m_FZZWPExtent;
        m_FZZWPExtent = NULL;
    }
    if ( m_FZZWPEffectExtent != NULL ) {
        delete m_FZZWPEffectExtent;
        m_FZZWPEffectExtent = NULL;
    }
    if ( m_FZZWPDocPr != NULL ) {
        delete m_FZZWPDocPr;
        m_FZZWPDocPr = NULL;
    }
    if ( m_FZZWPCNvGraphicFramePr != NULL ) {
        delete m_FZZWPCNvGraphicFramePr;
        m_FZZWPCNvGraphicFramePr = NULL;
    }
    if ( m_FZZAGraphic != NULL ) {
        delete m_FZZAGraphic;
        m_FZZAGraphic = NULL;
    }
    if ( m_FZZWPSimplePos != NULL ) {
        delete m_FZZWPSimplePos;
        m_FZZWPSimplePos = NULL;
    }
    if ( m_FZZWPPositionH != NULL ) {
        delete m_FZZWPPositionH;
        m_FZZWPPositionH = NULL;
    }
    if ( m_FZZWPPositionV != NULL ) {
        delete m_FZZWPPositionV;
        m_FZZWPPositionV = NULL;
    }
    if ( m_FZZWPWrapNone != NULL ) {
        delete m_FZZWPWrapNone;
        m_FZZWPWrapNone = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setDistT(string value)
{
    setAttribute_String("distT",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getDistT()
{
    return getAttribute_String("distT");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setDistB(string value)
{
    setAttribute_String("distB",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getDistB()
{
    return getAttribute_String("distB");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setDistL(string value)
{
    setAttribute_String("distL",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getDistL()
{
    return getAttribute_String("distL");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setDistR(string value)
{
    setAttribute_String("distR",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getDistR()
{
    return getAttribute_String("distR");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setSimplePos(string value)
{
    setAttribute_String("simplePos",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getSimplePos()
{
    return getAttribute_String("simplePos");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setRelativeHeight(string value)
{
    setAttribute_String("relativeHeight",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getRelativeHeight()
{
    return getAttribute_String("relativeHeight");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setBehindDoc(string value)
{
    setAttribute_String("behindDoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getBehindDoc()
{
    return getAttribute_String("behindDoc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setLocked(string value)
{
    setAttribute_String("locked",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getLocked()
{
    return getAttribute_String("locked");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setLayoutInCell(string value)
{
    setAttribute_String("layoutInCell",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getLayoutInCell()
{
    return getAttribute_String("layoutInCell");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setAllowOverlap(string value)
{
    setAttribute_String("allowOverlap",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getAllowOverlap()
{
    return getAttribute_String("allowOverlap");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setAnchorId(string value)
{
    setAttribute_String("wp14:anchorId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getAnchorId()
{
    return getAttribute_String("wp14:anchorId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPAnchor::setEditId(string value)
{
    setAttribute_String("wp14:editId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPAnchor::getEditId()
{
    return getAttribute_String("wp14:editId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent * FZZWPAnchor::setExtent()
{
    return m_FZZWPExtent = setElementObject(m_FZZWPExtent,FZZWPEXTENT_Find_Key,FZZWPEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent * FZZWPAnchor::getExtent()
{
    return m_FZZWPExtent = getElementObject(m_FZZWPExtent,FZZWPEXTENT_Find_Key,FZZWPEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent * FZZWPAnchor::setEffectExtent()
{
    return m_FZZWPEffectExtent = setElementObject(m_FZZWPEffectExtent,FZZWPEFFECTEXTENT_Find_Key,FZZWPEFFECTEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent * FZZWPAnchor::getEffectExtent()
{
    return m_FZZWPEffectExtent = getElementObject(m_FZZWPEffectExtent,FZZWPEFFECTEXTENT_Find_Key,FZZWPEFFECTEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr * FZZWPAnchor::setDocPr()
{
    return m_FZZWPDocPr = setElementObject(m_FZZWPDocPr,FZZWPDOCPR_Find_Key,FZZWPDOCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr * FZZWPAnchor::getDocPr()
{
    return m_FZZWPDocPr = getElementObject(m_FZZWPDocPr,FZZWPDOCPR_Find_Key,FZZWPDOCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr * FZZWPAnchor::setCNvGraphicFramePr()
{
    return m_FZZWPCNvGraphicFramePr = setElementObject(m_FZZWPCNvGraphicFramePr,FZZWPCNVGRAPHICFRAMEPR_Find_Key,FZZWPCNVGRAPHICFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr * FZZWPAnchor::getCNvGraphicFramePr()
{
    return m_FZZWPCNvGraphicFramePr = getElementObject(m_FZZWPCNvGraphicFramePr,FZZWPCNVGRAPHICFRAMEPR_Find_Key,FZZWPCNVGRAPHICFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic * FZZWPAnchor::setGraphic()
{
    return m_FZZAGraphic = setElementObject(m_FZZAGraphic,FZZAGRAPHIC_Find_Key,FZZAGRAPHIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic * FZZWPAnchor::getGraphic()
{
    return m_FZZAGraphic = getElementObject(m_FZZAGraphic,FZZAGRAPHIC_Find_Key,FZZAGRAPHIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos * FZZWPAnchor::setSimplePos()
{
    return m_FZZWPSimplePos = setElementObject(m_FZZWPSimplePos,FZZWPSIMPLEPOS_Find_Key,FZZWPSIMPLEPOS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos * FZZWPAnchor::getSimplePos_Object()
{
    return m_FZZWPSimplePos = getElementObject(m_FZZWPSimplePos,FZZWPSIMPLEPOS_Find_Key,FZZWPSIMPLEPOS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH * FZZWPAnchor::setPositionH()
{
    return m_FZZWPPositionH = setElementObject(m_FZZWPPositionH,FZZWPPOSITIONH_Find_Key,FZZWPPOSITIONH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH * FZZWPAnchor::getPositionH()
{
    return m_FZZWPPositionH = getElementObject(m_FZZWPPositionH,FZZWPPOSITIONH_Find_Key,FZZWPPOSITIONH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV * FZZWPAnchor::setPositionV()
{
    return m_FZZWPPositionV = setElementObject(m_FZZWPPositionV,FZZWPPOSITIONV_Find_Key,FZZWPPOSITIONV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV * FZZWPAnchor::getPositionV()
{
    return m_FZZWPPositionV = getElementObject(m_FZZWPPositionV,FZZWPPOSITIONV_Find_Key,FZZWPPOSITIONV_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone * FZZWPAnchor::setWrapNone()
{
    return m_FZZWPWrapNone = setElementObject(m_FZZWPWrapNone,FZZWPWRAPNONE_Find_Key,FZZWPWRAPNONE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPWrapNone * FZZWPAnchor::getWrapNone()
{
    return m_FZZWPWrapNone = getElementObject(m_FZZWPWrapNone,FZZWPWRAPNONE_Find_Key,FZZWPWRAPNONE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
