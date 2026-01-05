//
//  Created by zizheng fan on 2023/10/25
//
#ifndef FZZWBOTTOM_H
#define FZZWBOTTOM_H

#include "office/FZZXMLElementObject.h"

#define FZZWBOTTOM_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBOTTOM_Name "bottom"

class FZZWBottom : public FZZXMLElementObject
{
public:
    
    FZZWBottom(FZZOfficeObject * parent);
    FZZWBottom(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBottom(const FZZWBottom& obj);
    virtual ~FZZWBottom();
    
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
    FZZWBottom();
private:
    
    
};

#endif //FZZWBOTTOM_H
