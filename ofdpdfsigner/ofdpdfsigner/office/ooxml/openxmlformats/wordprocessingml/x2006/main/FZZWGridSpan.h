//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWGRIDSPAN_H
#define FZZWGRIDSPAN_H

#include "office/FZZXMLElementObject.h"

#define FZZWGRIDSPAN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWGRIDSPAN_Name "gridSpan"

class FZZWGridSpan : public FZZXMLElementObject
{
public:
    
    FZZWGridSpan(FZZOfficeObject * parent);
    FZZWGridSpan(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWGridSpan(const FZZWGridSpan& obj);
    virtual ~FZZWGridSpan();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWGridSpan();
private:
    
    
};

#endif //FZZWGRIDSPAN_H
