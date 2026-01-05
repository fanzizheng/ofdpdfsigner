//
//  Created by zizheng fan on 2023/10/18
//
#ifndef FZZWTOP_H
#define FZZWTOP_H

#include "office/FZZXMLElementObject.h"

#define FZZWTOP_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTOP_Name "top"

class FZZWTop : public FZZXMLElementObject
{
public:
    
    FZZWTop(FZZOfficeObject * parent);
    FZZWTop(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTop(const FZZWTop& obj);
    virtual ~FZZWTop();
    
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
    FZZWTop();
private:
    
    
};

#endif //FZZWTOP_H
