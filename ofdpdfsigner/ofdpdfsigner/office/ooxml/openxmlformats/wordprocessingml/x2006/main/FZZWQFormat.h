//
//  Created by zizheng fan on 2023/10/24
//
#ifndef FZZWQFORMAT_H
#define FZZWQFORMAT_H

#include "office/FZZXMLElementObject.h"

#define FZZWQFORMAT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWQFORMAT_Name "qFormat"

class FZZWQFormat : public FZZXMLElementObject
{
public:
    
    FZZWQFormat(FZZOfficeObject * parent);
    FZZWQFormat(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWQFormat(const FZZWQFormat& obj);
    virtual ~FZZWQFormat();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWQFormat();
private:
    
    
};

#endif //FZZWQFORMAT_H
