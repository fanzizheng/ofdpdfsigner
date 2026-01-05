//
//  Created by zizheng fan on 2023/11/14
//
#ifndef FZZWTBLOVERLAP_H
#define FZZWTBLOVERLAP_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLOVERLAP_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLOVERLAP_Name "tblOverlap"

class FZZWTblOverlap : public FZZXMLElementObject
{
public:
    
    FZZWTblOverlap(FZZOfficeObject * parent);
    FZZWTblOverlap(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblOverlap(const FZZWTblOverlap& obj);
    virtual ~FZZWTblOverlap();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTblOverlap();
private:
    
    
};

#endif //FZZWTBLOVERLAP_H
