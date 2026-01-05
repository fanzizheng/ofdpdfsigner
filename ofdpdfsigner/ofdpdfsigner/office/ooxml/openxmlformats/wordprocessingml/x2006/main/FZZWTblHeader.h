//
//  Created by zizheng fan on 2023/11/15
//
#ifndef FZZWTBLHEADER_H
#define FZZWTBLHEADER_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLHEADER_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLHEADER_Name "tblHeader"

class FZZWTblHeader : public FZZXMLElementObject
{
public:
    
    FZZWTblHeader(FZZOfficeObject * parent);
    FZZWTblHeader(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblHeader(const FZZWTblHeader& obj);
    virtual ~FZZWTblHeader();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTblHeader();
private:
    
    
};

#endif //FZZWTBLHEADER_H
