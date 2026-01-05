//
//  Created by zizheng fan on 2023/11/03
//
#ifndef FZZWTCW_H
#define FZZWTCW_H

#include "office/FZZXMLElementObject.h"

#define FZZWTCW_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTCW_Name "tcW"

class FZZWTcW : public FZZXMLElementObject
{
public:
    
    FZZWTcW(FZZOfficeObject * parent);
    FZZWTcW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTcW(const FZZWTcW& obj);
    virtual ~FZZWTcW();
    
public:
    void setW(string value);
    string getW();
    
    void setType(string value);
    string getType();
    
protected:
    FZZWTcW();
private:
    
    
};

#endif //FZZWTCW_H
