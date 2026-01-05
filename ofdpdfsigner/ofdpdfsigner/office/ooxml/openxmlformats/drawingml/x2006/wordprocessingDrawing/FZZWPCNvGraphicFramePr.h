//
//  Created by zizheng fan on 2023/06/19
//
#ifndef FZZWPCNVGRAPHICFRAMEPR_H
#define FZZWPCNVGRAPHICFRAMEPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicFrameLocks.h"

#define FZZWPCNVGRAPHICFRAMEPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"

#define FZZWPCNVGRAPHICFRAMEPR_Name "cNvGraphicFramePr"

class FZZWPCNvGraphicFramePr : public FZZXMLElementObject
{
public:
    
    FZZWPCNvGraphicFramePr(FZZOfficeObject * parent);
    FZZWPCNvGraphicFramePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPCNvGraphicFramePr(const FZZWPCNvGraphicFramePr& obj);
    virtual ~FZZWPCNvGraphicFramePr();
    
public:
//    void setVal(string value);
//    string getVal();
    
    FZZAGraphicFrameLocks * setGraphicFrameLocks();
    FZZAGraphicFrameLocks * getGraphicFrameLocks();
protected:
    FZZWPCNvGraphicFramePr();
private:
    FZZAGraphicFrameLocks * m_FZZAGraphicFrameLocks;
    
};

#endif //FZZWPCNVGRAPHICFRAMEPR_H
