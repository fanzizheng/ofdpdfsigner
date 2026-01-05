//
//  Created by zizheng fan on 2023/10/18
//
#ifndef FZZWUIPRIORITY_H
#define FZZWUIPRIORITY_H

#include "office/FZZXMLElementObject.h"

#define FZZWUIPRIORITY_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWUIPRIORITY_Name "uiPriority"

class FZZWUiPriority : public FZZXMLElementObject
{
public:
    
    FZZWUiPriority(FZZOfficeObject * parent);
    FZZWUiPriority(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWUiPriority(const FZZWUiPriority& obj);
    virtual ~FZZWUiPriority();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWUiPriority();
private:
    
    
};

#endif //FZZWUIPRIORITY_H
