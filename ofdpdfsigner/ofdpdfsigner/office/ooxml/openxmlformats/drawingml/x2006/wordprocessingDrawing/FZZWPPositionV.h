//
//  Created by zizheng fan on 2023/06/12
//
#ifndef FZZWPPOSITIONV_H
#define FZZWPPOSITIONV_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPosOffset.h"

#define FZZWPPOSITIONV_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPPOSITIONV_Name "positionV"

class FZZWPPositionV : public FZZXMLElementObject
{
public:
    
    FZZWPPositionV(FZZOfficeObject * parent);
    FZZWPPositionV(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPPositionV(const FZZWPPositionV& obj);
    virtual ~FZZWPPositionV();
    
public:
    
    void setRelativeFrom(string value);
    string getRelativeFrom();
    
    FZZWPPosOffset * setPosOffset();
    FZZWPPosOffset * getPosOffset();
    
protected:
    FZZWPPositionV();
private:
    FZZWPPosOffset * m_FZZWPPosOffset;
    
};

#endif //FZZWPPOSITIONV_H
