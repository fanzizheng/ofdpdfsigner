//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWTRHEIGHT_H
#define FZZWTRHEIGHT_H

#include "office/FZZXMLElementObject.h"

#define FZZWTRHEIGHT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTRHEIGHT_Name "trHeight"

class FZZWTrHeight : public FZZXMLElementObject
{
public:
    
    FZZWTrHeight(FZZOfficeObject * parent);
    FZZWTrHeight(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTrHeight(const FZZWTrHeight& obj);
    virtual ~FZZWTrHeight();
    
public:
    void setVal(string value);
    string getVal();
    void setHRule(string value);
    string getHRule();
protected:
    FZZWTrHeight();
private:
    
    
};

#endif //FZZWTRHEIGHT_H
