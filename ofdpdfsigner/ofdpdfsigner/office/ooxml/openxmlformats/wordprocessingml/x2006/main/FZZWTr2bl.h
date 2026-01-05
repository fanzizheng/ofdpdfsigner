//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWTR2BL_H
#define FZZWTR2BL_H

#include "office/FZZXMLElementObject.h"

#define FZZWTR2BL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTR2BL_Name "tr2bl"

class FZZWTr2bl : public FZZXMLElementObject
{
public:
    
    FZZWTr2bl(FZZOfficeObject * parent);
    FZZWTr2bl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTr2bl(const FZZWTr2bl& obj);
    virtual ~FZZWTr2bl();
    
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
    FZZWTr2bl();
private:
    
    
};

#endif //FZZWTR2BL_H
