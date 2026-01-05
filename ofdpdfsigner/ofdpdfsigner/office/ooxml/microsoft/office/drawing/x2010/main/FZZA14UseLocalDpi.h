//
//  Created by zizheng fan on 2023/04/24.
//
#ifndef FZZA14USELOCALDPI_H
#define FZZA14USELOCALDPI_H

#include "office/FZZXMLElementObject.h"

#define FZZA14USELOCALDPI_Find_Key "schemas.microsoft.com/office/drawing/2010/main"
#define FZZA14USELOCALDPI_Name "useLocalDpi"

class FZZA14UseLocalDpi : public FZZXMLElementObject
{
public:
    
    FZZA14UseLocalDpi(FZZOfficeObject * parent);
    FZZA14UseLocalDpi(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZA14UseLocalDpi(const FZZA14UseLocalDpi& obj);
    virtual ~FZZA14UseLocalDpi();
    
public:
    void setVal(string value);
    string getVal();
    void setXmlnsA14(string value);
    string getXmlnsA14();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZA14UseLocalDpi();
private:
    
    
};

#endif //FZZA14USELOCALDPI_H
