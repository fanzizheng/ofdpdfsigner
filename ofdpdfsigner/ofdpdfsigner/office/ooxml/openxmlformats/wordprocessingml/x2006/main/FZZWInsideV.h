//
//  Created by zizheng fan on 2023/11/07
//
#ifndef FZZWINSIDEV_H
#define FZZWINSIDEV_H

#include "office/FZZXMLElementObject.h"

#define FZZWINSIDEV_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWINSIDEV_Name "insideV"

class FZZWInsideV : public FZZXMLElementObject
{
public:
    
    FZZWInsideV(FZZOfficeObject * parent);
    FZZWInsideV(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWInsideV(const FZZWInsideV& obj);
    virtual ~FZZWInsideV();
    
public:
    void setW(string value);
    string getW();
    void setType(string value);
    string getType();
    void setVal(string value);
    string getVal();
    void setSz(string value);
    string getSz();
    void setSpace(string value);
    string getSpace();
    void setColor(string value);
    string getColor();
protected:
    FZZWInsideV();
private:
    
    
};

#endif //FZZWINSIDEV_H
