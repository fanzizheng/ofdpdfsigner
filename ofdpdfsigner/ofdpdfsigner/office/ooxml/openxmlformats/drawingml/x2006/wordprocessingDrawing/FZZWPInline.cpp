//
//  Created by zizheng fan on 2023/06/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPInline.h"

#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPInline**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline::FZZWPInline() : FZZXMLElementObject(),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL)
{
    //DLOG("FZZWPInline()");
    FZZConst::addClassCount("FZZWPInline");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline::FZZWPInline(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPInline");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline::FZZWPInline(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPExtent(NULL),m_FZZWPEffectExtent(NULL),m_FZZWPDocPr(NULL),m_FZZWPCNvGraphicFramePr(NULL),m_FZZAGraphic(NULL)
{
    FZZConst::addClassCount("FZZWPInline");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline::FZZWPInline(const FZZWPInline& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPInline");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPExtent = obj.m_FZZWPExtent != NULL ? new FZZWPExtent(*obj.m_FZZWPExtent) : NULL;
    m_FZZWPEffectExtent = obj.m_FZZWPEffectExtent != NULL ? new FZZWPEffectExtent(*obj.m_FZZWPEffectExtent) : NULL;
    m_FZZWPDocPr = obj.m_FZZWPDocPr != NULL ? new FZZWPDocPr(*obj.m_FZZWPDocPr) : NULL;
    m_FZZWPCNvGraphicFramePr = obj.m_FZZWPCNvGraphicFramePr != NULL ? new FZZWPCNvGraphicFramePr(*obj.m_FZZWPCNvGraphicFramePr) : NULL;
    m_FZZAGraphic = obj.m_FZZAGraphic != NULL ? new FZZAGraphic(*obj.m_FZZAGraphic) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPInline::~FZZWPInline()
{
    //DLOG("~FZZWPInline()");
    FZZConst::delClassCount("FZZWPInline");
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
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setDistT(string value)
{
    setAttribute_String("distT",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getDistT()
{
    return getAttribute_String("distT");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setDistB(string value)
{
    setAttribute_String("distB",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getDistB()
{
    return getAttribute_String("distB");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setDistL(string value)
{
    setAttribute_String("distL",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getDistL()
{
    return getAttribute_String("distL");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setDistR(string value)
{
    setAttribute_String("distR",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getDistR()
{
    return getAttribute_String("distR");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setAnchorId(string value)
{
    setAttribute_String("wp14:anchorId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getAnchorId()
{
    return getAttribute_String("wp14:anchorId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPInline::setEditId(string value)
{
    setAttribute_String("wp14:editId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPInline::getEditId()
{
    return getAttribute_String("wp14:editId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent * FZZWPInline::setExtent()
{
    return m_FZZWPExtent = setElementObject(m_FZZWPExtent,FZZWPEXTENT_Find_Key,FZZWPEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPExtent * FZZWPInline::getExtent()
{
    return m_FZZWPExtent = getElementObject(m_FZZWPExtent,FZZWPEXTENT_Find_Key,FZZWPEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent * FZZWPInline::setEffectExtent()
{
    return m_FZZWPEffectExtent = setElementObject(m_FZZWPEffectExtent,FZZWPEFFECTEXTENT_Find_Key,FZZWPEFFECTEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPEffectExtent * FZZWPInline::getEffectExtent()
{
    return m_FZZWPEffectExtent = getElementObject(m_FZZWPEffectExtent,FZZWPEFFECTEXTENT_Find_Key,FZZWPEFFECTEXTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr * FZZWPInline::setDocPr()
{
    return m_FZZWPDocPr = setElementObject(m_FZZWPDocPr,FZZWPDOCPR_Find_Key,FZZWPDOCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPDocPr * FZZWPInline::getDocPr()
{
    return m_FZZWPDocPr = getElementObject(m_FZZWPDocPr,FZZWPDOCPR_Find_Key,FZZWPDOCPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr * FZZWPInline::setCNvGraphicFramePr()
{
    return m_FZZWPCNvGraphicFramePr = setElementObject(m_FZZWPCNvGraphicFramePr,FZZWPCNVGRAPHICFRAMEPR_Find_Key,FZZWPCNVGRAPHICFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPCNvGraphicFramePr * FZZWPInline::getCNvGraphicFramePr()
{
    return m_FZZWPCNvGraphicFramePr = getElementObject(m_FZZWPCNvGraphicFramePr,FZZWPCNVGRAPHICFRAMEPR_Find_Key,FZZWPCNVGRAPHICFRAMEPR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic * FZZWPInline::setGraphic()
{
    return m_FZZAGraphic = setElementObject(m_FZZAGraphic,FZZAGRAPHIC_Find_Key,FZZAGRAPHIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphic * FZZWPInline::getGraphic()
{
    return m_FZZAGraphic = getElementObject(m_FZZAGraphic,FZZAGRAPHIC_Find_Key,FZZAGRAPHIC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
