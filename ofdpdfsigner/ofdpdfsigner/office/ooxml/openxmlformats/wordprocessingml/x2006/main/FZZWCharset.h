//
//  Created by zizheng fan on 2023/09/08
//
#ifndef FZZWCHARSET_H
#define FZZWCHARSET_H

#include "office/FZZXMLElementObject.h"

#define FZZWCHARSET_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCHARSET_Name "charset"

class FZZWCharset : public FZZXMLElementObject
{
public:
    
    FZZWCharset(FZZOfficeObject * parent);
    FZZWCharset(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCharset(const FZZWCharset& obj);
    virtual ~FZZWCharset();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWCharset();
private:
    
    
};

#endif //FZZWCHARSET_H
