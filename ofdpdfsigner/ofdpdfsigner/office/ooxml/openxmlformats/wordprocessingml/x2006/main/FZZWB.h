//
//  Created by zizheng fan on 2023/11/01
//
#ifndef FZZWB_H
#define FZZWB_H

#include "office/FZZXMLElementObject.h"

#define FZZWB_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWB_Name "b"

class FZZWB : public FZZXMLElementObject
{
public:
    
    FZZWB(FZZOfficeObject * parent);
    FZZWB(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWB(const FZZWB& obj);
    virtual ~FZZWB();
    
public:
//    void setVal(string value);
//    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWB();
private:
    
    
};

#endif //FZZWB_H
