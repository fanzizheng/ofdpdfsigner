//
//  Created by zizheng fan on 2023/06/16
//
#ifndef FZZWPANCHOR_H
#define FZZWPANCHOR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPExtent.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPEffectExtent.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPDocPr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPCNvGraphicFramePr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphic.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionH.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPSimplePos.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionV.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPWrapNone.h"

#define FZZWPANCHOR_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"

#define FZZWPANCHOR_Name "anchor"

class FZZWPAnchor : public FZZXMLElementObject
{
public:
    
    FZZWPAnchor(FZZOfficeObject * parent);
    FZZWPAnchor(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPAnchor(const FZZWPAnchor& obj);
    virtual ~FZZWPAnchor();
    
public:
    void setDistT(string value);
    string getDistT();
    void setDistB(string value);
    string getDistB();
    void setDistL(string value);
    string getDistL();
    void setDistR(string value);
    string getDistR();
    void setSimplePos(string value);
    string getSimplePos();
    void setRelativeHeight(string value);
    string getRelativeHeight();
    void setBehindDoc(string value);
    string getBehindDoc();
    void setLocked(string value);
    string getLocked();
    void setLayoutInCell(string value);
    string getLayoutInCell();
    void setAllowOverlap(string value);
    string getAllowOverlap();
    void setAnchorId(string value);
    string getAnchorId();
    void setEditId(string value);
    string getEditId();
    
    FZZWPExtent * setExtent();
    FZZWPExtent * getExtent();
    FZZWPEffectExtent * setEffectExtent();
    FZZWPEffectExtent * getEffectExtent();
    FZZWPDocPr * setDocPr();
    FZZWPDocPr * getDocPr();
    FZZWPCNvGraphicFramePr * setCNvGraphicFramePr();
    FZZWPCNvGraphicFramePr * getCNvGraphicFramePr();
    
    FZZAGraphic * setGraphic();
    FZZAGraphic * getGraphic();
    FZZWPSimplePos * setSimplePos();
    FZZWPSimplePos * getSimplePos_Object();
    FZZWPPositionH * setPositionH();
    FZZWPPositionH * getPositionH();
    FZZWPPositionV * setPositionV();
    FZZWPPositionV * getPositionV();
    FZZWPWrapNone * setWrapNone();
    FZZWPWrapNone * getWrapNone();
protected:
    FZZWPAnchor();
private:
    FZZWPExtent * m_FZZWPExtent;
    FZZWPEffectExtent * m_FZZWPEffectExtent;
    FZZWPDocPr * m_FZZWPDocPr;
    FZZWPCNvGraphicFramePr * m_FZZWPCNvGraphicFramePr;
    FZZAGraphic * m_FZZAGraphic;
    FZZWPSimplePos * m_FZZWPSimplePos;
    FZZWPPositionH * m_FZZWPPositionH;
    FZZWPPositionV * m_FZZWPPositionV;
    FZZWPWrapNone * m_FZZWPWrapNone;
};

#endif //FZZWPANCHOR_H
