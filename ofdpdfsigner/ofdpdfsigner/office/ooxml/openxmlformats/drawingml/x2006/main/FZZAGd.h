//
//  Created by zizheng fan on 2023/06/26
//
#ifndef FZZAGD_H
#define FZZAGD_H

#include "office/FZZXMLElementObject.h"



#define FZZAGD_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAGD_Name "gd"

class FZZAGd : public FZZXMLElementObject
{
public:
    
    FZZAGd(FZZOfficeObject * parent);
    FZZAGd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAGd(const FZZAGd& obj);
    virtual ~FZZAGd();
    
public:
    void setName(string value);
    string getName();
    void setFmla(string value);
    string getFmla();
  
protected:
    FZZAGd();
private:
    
};

#endif //FZZAGD_H
