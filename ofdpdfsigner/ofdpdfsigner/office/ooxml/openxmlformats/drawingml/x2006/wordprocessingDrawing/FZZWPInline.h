//
//  Created by zizheng fan on 2023/06/23
//
#ifndef FZZWPINLINE_H
#define FZZWPINLINE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPExtent.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPEffectExtent.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPDocPr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPCNvGraphicFramePr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphic.h"

#define FZZWPINLINE_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"

#define FZZWPINLINE_Name "inline"

class FZZWPInline : public FZZXMLElementObject
{
public:
    
    FZZWPInline(FZZOfficeObject * parent);
    FZZWPInline(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPInline(const FZZWPInline& obj);
    virtual ~FZZWPInline();
    
public:
    void setDistT(string value);
    string getDistT();
    void setDistB(string value);
    string getDistB();
    void setDistL(string value);
    string getDistL();
    void setDistR(string value);
    string getDistR();
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
protected:
    FZZWPInline();
private:
    FZZWPExtent * m_FZZWPExtent;
    FZZWPEffectExtent * m_FZZWPEffectExtent;
    FZZWPDocPr * m_FZZWPDocPr;
    FZZWPCNvGraphicFramePr * m_FZZWPCNvGraphicFramePr;
    FZZAGraphic * m_FZZAGraphic;
};

#endif //FZZWPINLINE_H
