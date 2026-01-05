//
//  Created by zizheng fan on 2023/11/02
//
#ifndef FZZWDRAWING_H
#define FZZWDRAWING_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPInline.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAnchor.h"

#define FZZWDRAWING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDRAWING_Name "drawing"

class FZZWDrawing : public FZZXMLElementObject
{
public:
    
    FZZWDrawing(FZZOfficeObject * parent);
    FZZWDrawing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDrawing(const FZZWDrawing& obj);
    virtual ~FZZWDrawing();
    
public:
  
    void setVal(string value);
    string getVal();
    
    FZZWPInline * setInline();
    FZZWPInline * getInline();
    FZZWPAnchor * setAnchor();
    FZZWPAnchor * getAnchor();
protected:
    FZZWDrawing();
private:
    FZZWPInline * m_FZZWPInline;
    FZZWPAnchor * m_FZZWPAnchor;
};

#endif //FZZWDRAWING_H
