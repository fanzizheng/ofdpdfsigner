//
//  Created by zizheng fan on 2023/10/08
//
#ifndef FZZWSZ_H
#define FZZWSZ_H

#include "office/FZZXMLElementObject.h"

#define FZZWSZ_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSZ_Name "sz"

class FZZWSz : public FZZXMLElementObject
{
public:
    
    FZZWSz(FZZOfficeObject * parent);
    FZZWSz(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSz(const FZZWSz& obj);
    virtual ~FZZWSz();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWSz();
private:
    
    
};

#endif //FZZWSZ_H
