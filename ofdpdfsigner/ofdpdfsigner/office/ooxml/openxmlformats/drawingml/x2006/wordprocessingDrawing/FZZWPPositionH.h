//
//  Created by zizheng fan on 2023/06/13
//
#ifndef FZZWPPOSITIONH_H
#define FZZWPPOSITIONH_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPosOffset.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAlign.h"

#define FZZWPPOSITIONH_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPPOSITIONH_Name "positionH"

class FZZWPPositionH : public FZZXMLElementObject
{
public:
    
    FZZWPPositionH(FZZOfficeObject * parent);
    FZZWPPositionH(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPPositionH(const FZZWPPositionH& obj);
    virtual ~FZZWPPositionH();
    
public:
    
    void setRelativeFrom(string value);
    string getRelativeFrom();
    
    FZZWPPosOffset * setPosOffset();
    FZZWPPosOffset * getPosOffset();
    FZZWPAlign * setAlign();
    FZZWPAlign * getAlign();
    
protected:
    FZZWPPositionH();
private:
    FZZWPPosOffset * m_FZZWPPosOffset;
    FZZWPAlign * m_FZZWPAlign;
};

#endif //FZZWPPOSITIONH_H
