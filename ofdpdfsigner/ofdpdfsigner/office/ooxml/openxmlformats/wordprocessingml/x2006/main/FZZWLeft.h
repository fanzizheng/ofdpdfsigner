//
//  Created by zizheng fan on 2023/10/24
//
#ifndef FZZWLEFT_H
#define FZZWLEFT_H

#include "office/FZZXMLElementObject.h"

#define FZZWLEFT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLEFT_Name "left"

class FZZWLeft : public FZZXMLElementObject
{
public:
    
    FZZWLeft(FZZOfficeObject * parent);
    FZZWLeft(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLeft(const FZZWLeft& obj);
    virtual ~FZZWLeft();
    
public:
    void setW(string value);
    string getW();
    void setType(string value);
    string getType();
    void setVal(string value);
    string getVal();
    //1 pound equals 1 pixel, 1 pound = Sz / 8
    void setSz(string value);
    string getSz();
    void setSpace(string value);
    string getSpace();
    void setColor(string value);
    string getColor();
protected:
    FZZWLeft();
private:
    
    
};

#endif //FZZWLEFT_H
