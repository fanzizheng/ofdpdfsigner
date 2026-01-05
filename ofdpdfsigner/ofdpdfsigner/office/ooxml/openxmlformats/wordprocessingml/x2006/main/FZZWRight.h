//
//  Created by zizheng fan on 2023/10/24
//
#ifndef FZZWRIGHT_H
#define FZZWRIGHT_H

#include "office/FZZXMLElementObject.h"

#define FZZWRIGHT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRIGHT_Name "right"

class FZZWRight : public FZZXMLElementObject
{
public:
    
    FZZWRight(FZZOfficeObject * parent);
    FZZWRight(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRight(const FZZWRight& obj);
    virtual ~FZZWRight();
    
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
    FZZWRight();
private:
    
    
};

#endif //FZZWRIGHT_H
