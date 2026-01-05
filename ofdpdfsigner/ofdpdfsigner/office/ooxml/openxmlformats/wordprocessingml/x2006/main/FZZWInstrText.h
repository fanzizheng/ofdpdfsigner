//
//  Created by zizheng fan on 2023/11/13
//
#ifndef FZZWINSTRTEXT_H
#define FZZWINSTRTEXT_H

#include "office/FZZXMLElementObject.h"

#define FZZWINSTRTEXT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWINSTRTEXT_Name "instrText"

class FZZWInstrText : public FZZXMLElementObject
{
public:
    
    FZZWInstrText(FZZOfficeObject * parent);
    FZZWInstrText(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWInstrText(const FZZWInstrText& obj);
    virtual ~FZZWInstrText();
    
public:
    void setSpace(string value = "preserve");
    string getSpace();
    
    void setValue(string value);
    string getValue();
    
protected:
    FZZWInstrText();
private:
    
    
};

#endif //FZZWINSTRTEXT_H
