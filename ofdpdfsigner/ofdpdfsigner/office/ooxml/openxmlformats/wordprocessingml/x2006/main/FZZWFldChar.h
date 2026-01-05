//
//  Created by zizheng fan on 2023/11/13
//
#ifndef FZZWFLDCHAR_H
#define FZZWFLDCHAR_H

#include "office/FZZXMLElementObject.h"

#define FZZWFLDCHAR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFLDCHAR_Name "fldChar"

class FZZWFldChar : public FZZXMLElementObject
{
public:
    
    FZZWFldChar(FZZOfficeObject * parent);
    FZZWFldChar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFldChar(const FZZWFldChar& obj);
    virtual ~FZZWFldChar();
    
public:
    void setFldCharType(string value);
    string getFldCharType();
protected:
    FZZWFldChar();
private:
    
    
};

#endif //FZZWFLDCHAR_H
