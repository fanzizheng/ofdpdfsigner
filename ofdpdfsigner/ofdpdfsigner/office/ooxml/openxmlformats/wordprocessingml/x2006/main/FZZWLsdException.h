//
//  Created by zizheng fan on 2023/10/16
//
#ifndef FZZWLSDEXCEPTION_H
#define FZZWLSDEXCEPTION_H

#include "office/FZZXMLElementObject.h"

#define FZZWLSDEXCEPTION_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLSDEXCEPTION_Name "lsdException"

class FZZWLsdException : public FZZXMLElementObject
{
public:
    
    FZZWLsdException(FZZOfficeObject * parent);
    FZZWLsdException(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLsdException(const FZZWLsdException& obj);
    virtual ~FZZWLsdException();
    
public:
    void setName(string value);
    string getName();
    void setUiPriority(string value);
    string getUiPriority();
    void setQFormat(string value);
    string getQFormat();
    void setSemiHidden(string value);
    string getSemiHidden();
    void setUnhideWhenUsed(string value);
    string getUnhideWhenUsed();
protected:
    FZZWLsdException();
private:
    
    
};

#endif //FZZWLSDEXCEPTION_H
