//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWTL2BR_H
#define FZZWTL2BR_H

#include "office/FZZXMLElementObject.h"

#define FZZWTL2BR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTL2BR_Name "tl2br"

class FZZWTl2br : public FZZXMLElementObject
{
public:
    
    FZZWTl2br(FZZOfficeObject * parent);
    FZZWTl2br(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTl2br(const FZZWTl2br& obj);
    virtual ~FZZWTl2br();
    
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
    FZZWTl2br();
private:
    
    
};

#endif //FZZWTL2BR_H
