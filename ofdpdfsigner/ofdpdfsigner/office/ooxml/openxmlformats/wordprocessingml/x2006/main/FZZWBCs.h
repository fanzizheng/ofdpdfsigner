//
//  Created by zizheng fan on 2023/10/31
//
#ifndef FZZWBCS_H
#define FZZWBCS_H

#include "office/FZZXMLElementObject.h"

#define FZZWBCS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBCS_Name "bCs"

class FZZWBCs : public FZZXMLElementObject
{
public:
    
    FZZWBCs(FZZOfficeObject * parent);
    FZZWBCs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBCs(const FZZWBCs& obj);
    virtual ~FZZWBCs();
    
public:
//    void setVal(string value);
//    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWBCs();
private:
    
    
};

#endif //FZZWBCS_H
