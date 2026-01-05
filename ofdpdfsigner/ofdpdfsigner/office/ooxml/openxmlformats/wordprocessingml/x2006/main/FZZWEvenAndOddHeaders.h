//
//  Created by zizheng fan on 2024/02/07
//
#ifndef FZZWEVENANDODDHEADERS_H
#define FZZWEVENANDODDHEADERS_H

#include "office/FZZXMLElementObject.h"

#define FZZWEVENANDODDHEADERS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWEVENANDODDHEADERS_Name "evenAndOddHeaders"

class FZZWEvenAndOddHeaders : public FZZXMLElementObject
{
public:
    
    FZZWEvenAndOddHeaders(FZZOfficeObject * parent);
    FZZWEvenAndOddHeaders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWEvenAndOddHeaders(const FZZWEvenAndOddHeaders& obj);
    virtual ~FZZWEvenAndOddHeaders();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWEvenAndOddHeaders();
private:
    
    
};

#endif //FZZWEVENANDODDHEADERS_H
