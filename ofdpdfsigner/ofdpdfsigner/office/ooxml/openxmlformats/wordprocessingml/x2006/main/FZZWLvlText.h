//
//  Created by zizheng fan on 2023/11/24
//
#ifndef FZZWLVLTEXT_H
#define FZZWLVLTEXT_H

#include "office/FZZXMLElementObject.h"

#define FZZWLVLTEXT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLVLTEXT_Name "lvlText"

class FZZWLvlText : public FZZXMLElementObject
{
public:
    
    FZZWLvlText(FZZOfficeObject * parent);
    FZZWLvlText(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLvlText(const FZZWLvlText& obj);
    virtual ~FZZWLvlText();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWLvlText();
private:
    
    
};

#endif //FZZWLVLTEXT_H
