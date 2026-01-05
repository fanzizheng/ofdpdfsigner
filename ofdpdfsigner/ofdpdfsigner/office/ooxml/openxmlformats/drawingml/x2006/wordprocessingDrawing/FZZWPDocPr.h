//
//  Created by zizheng fan on 2023/06/20
//
#ifndef FZZWPDOCPR_H
#define FZZWPDOCPR_H

#include "office/FZZXMLElementObject.h"

#define FZZWPDOCPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPDOCPR_Name "docPr"

class FZZWPDocPr : public FZZXMLElementObject
{
public:
    
    FZZWPDocPr(FZZOfficeObject * parent);
    FZZWPDocPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPDocPr(const FZZWPDocPr& obj);
    virtual ~FZZWPDocPr();
    
public:
    void setId(string value);
    string getId();
    void setName(string value);
    string getName();
protected:
    FZZWPDocPr();
private:
    
    
};

#endif //FZZWPDOCPR_H
