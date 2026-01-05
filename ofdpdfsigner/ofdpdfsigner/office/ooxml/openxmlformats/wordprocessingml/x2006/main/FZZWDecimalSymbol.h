//
//  Created by zizheng fan on 2023/09/28
//
#ifndef FZZWDECIMALSYMBOL_H
#define FZZWDECIMALSYMBOL_H

#include "office/FZZXMLElementObject.h"

#define FZZWDECIMALSYMBOL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDECIMALSYMBOL_Name "decimalSymbol"

class FZZWDecimalSymbol : public FZZXMLElementObject
{
public:
    
    FZZWDecimalSymbol(FZZOfficeObject * parent);
    FZZWDecimalSymbol(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDecimalSymbol(const FZZWDecimalSymbol& obj);
    virtual ~FZZWDecimalSymbol();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWDecimalSymbol();
private:
    
    
};

#endif //FZZWDECIMALSYMBOL_H
