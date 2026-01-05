//
//  Created by zizheng fan on 2023/06/15
//
#ifndef FZZWPSIMPLEPOS_H
#define FZZWPSIMPLEPOS_H

#include "office/FZZXMLElementObject.h"


#define FZZWPSIMPLEPOS_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPSIMPLEPOS_Name "simplePos"

class FZZWPSimplePos : public FZZXMLElementObject
{
public:
    
    FZZWPSimplePos(FZZOfficeObject * parent);
    FZZWPSimplePos(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSimplePos(const FZZWPSimplePos& obj);
    virtual ~FZZWPSimplePos();
    
public:
   
    void setX(string value);
    string getX();
    void setY(string value);
    string getY();
    
protected:
    FZZWPSimplePos();
private:
    
    
};

#endif //FZZWPSIMPLEPOS_H
