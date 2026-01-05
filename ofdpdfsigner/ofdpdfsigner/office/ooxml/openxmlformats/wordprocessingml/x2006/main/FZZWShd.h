//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWSHD_H
#define FZZWSHD_H

#include "office/FZZXMLElementObject.h"

#define FZZWSHD_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSHD_Name "shd"

class FZZWShd : public FZZXMLElementObject
{
public:
    
    FZZWShd(FZZOfficeObject * parent);
    FZZWShd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWShd(const FZZWShd& obj);
    virtual ~FZZWShd();
    
public:
    void setVal(string value);
    string getVal();
    
    void setColor(string value);
    string getColor();
    
    void setFill(string value);
    string getFill();
    
    void setThemeFill(string value);
    string getThemeFill();
    
protected:
    FZZWShd();
private:
    
    
};

#endif //FZZWSHD_H
