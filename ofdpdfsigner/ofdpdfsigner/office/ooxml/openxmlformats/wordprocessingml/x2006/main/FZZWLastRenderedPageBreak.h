//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWLASTRENDEREDPAGEBREAK_H
#define FZZWLASTRENDEREDPAGEBREAK_H

#include "office/FZZXMLElementObject.h"

#define FZZWLASTRENDEREDPAGEBREAK_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLASTRENDEREDPAGEBREAK_Name "lastRenderedPageBreak"

class FZZWLastRenderedPageBreak : public FZZXMLElementObject
{
public:
    
    FZZWLastRenderedPageBreak(FZZOfficeObject * parent);
    FZZWLastRenderedPageBreak(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLastRenderedPageBreak(const FZZWLastRenderedPageBreak& obj);
    virtual ~FZZWLastRenderedPageBreak();
    
public:
//    void setVal(string value);
//    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWLastRenderedPageBreak();
private:
    
    
};

#endif //FZZWLASTRENDEREDPAGEBREAK_H
