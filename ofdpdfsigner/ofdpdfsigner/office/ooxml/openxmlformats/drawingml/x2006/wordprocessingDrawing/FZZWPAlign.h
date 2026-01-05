//
//  Created by zizheng fan on 2023/06/08
//
#ifndef FZZWPALIGN_H
#define FZZWPALIGN_H

#include "office/FZZXMLElementObject.h"


#define FZZWPALIGN_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPALIGN_Name "align"

class FZZWPAlign : public FZZXMLElementObject
{
public:
    
    FZZWPAlign(FZZOfficeObject * parent);
    FZZWPAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPAlign(const FZZWPAlign& obj);
    virtual ~FZZWPAlign();
    
public:
    void setValue(string value);
    string getValue();
protected:
    FZZWPAlign();
private:
    
    
};

#endif //FZZWPALIGN_H
