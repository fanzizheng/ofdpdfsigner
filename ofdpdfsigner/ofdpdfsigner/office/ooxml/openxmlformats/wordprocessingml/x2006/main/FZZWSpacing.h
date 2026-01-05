//
//  Created by zizheng fan on 2023/10/09
//
#ifndef FZZWSPACING_H
#define FZZWSPACING_H

#include "office/FZZXMLElementObject.h"

#define FZZWSPACING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSPACING_Name "spacing"

class FZZWSpacing : public FZZXMLElementObject
{
public:
    
    FZZWSpacing(FZZOfficeObject * parent);
    FZZWSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSpacing(const FZZWSpacing& obj);
    virtual ~FZZWSpacing();
    
public:
    void setBefore(string value);
    string getBefore();
    void setAfter(string value);
    string getAfter();
    void setLine(string value);
    string getLine();
    void setLineRule(string value);
    string getLineRule();
    void setAfterLines(string value);
    string getAfterLines();
    void setBeforeLines(string value);
    string getBeforeLines();
    
protected:
    FZZWSpacing();
private:
    
    
};

#endif //FZZWSPACING_H
