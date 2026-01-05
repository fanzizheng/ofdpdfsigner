//
//  Created by zizheng fan on 2023/11/07
//
#ifndef FZZWINSIDEH_H
#define FZZWINSIDEH_H

#include "office/FZZXMLElementObject.h"

#define FZZWINSIDEH_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWINSIDEH_Name "insideH"

class FZZWInsideH : public FZZXMLElementObject
{
public:
    
    FZZWInsideH(FZZOfficeObject * parent);
    FZZWInsideH(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWInsideH(const FZZWInsideH& obj);
    virtual ~FZZWInsideH();
    
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
    FZZWInsideH();
private:
    
    
};

#endif //FZZWINSIDEH_H
