//
//  Created by zizheng fan on 2023/11/23
//
#ifndef FZZWNUMFMT_H
#define FZZWNUMFMT_H

#include "office/FZZXMLElementObject.h"

#define FZZWNUMFMT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNUMFMT_Name "numFmt"

class FZZWNumFmt : public FZZXMLElementObject
{
public:
    
    FZZWNumFmt(FZZOfficeObject * parent);
    FZZWNumFmt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNumFmt(const FZZWNumFmt& obj);
    virtual ~FZZWNumFmt();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWNumFmt();
private:
    
    
};

#endif //FZZWNUMFMT_H
