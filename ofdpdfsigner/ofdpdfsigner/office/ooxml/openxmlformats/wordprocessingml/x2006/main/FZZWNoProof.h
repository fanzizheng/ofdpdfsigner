//
//  Created by zizheng fan on 2023/11/01
//
#ifndef FZZWNOPROOF_H
#define FZZWNOPROOF_H

#include "office/FZZXMLElementObject.h"


#define FZZWNOPROOF_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNOPROOF_Name "noProof"

class FZZWNoProof : public FZZXMLElementObject
{
public:
    
    FZZWNoProof(FZZOfficeObject * parent);
    FZZWNoProof(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNoProof(const FZZWNoProof& obj);
    virtual ~FZZWNoProof();
    
public:
  
    void setVal(string value);
    string getVal();
    
protected:
    FZZWNoProof();
private:
    
};

#endif //FZZWNOPROOF_H
