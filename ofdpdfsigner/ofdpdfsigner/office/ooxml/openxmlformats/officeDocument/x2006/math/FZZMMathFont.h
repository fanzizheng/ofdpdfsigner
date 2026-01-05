//
//  Created by zizheng fan on 2023/05/23
//
#ifndef FZZMMATHFONT_H
#define FZZMMATHFONT_H

#include "office/FZZXMLElementObject.h"

#define FZZMMATHFONT_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMMATHFONT_Name "mathFont"

class FZZMMathFont : public FZZXMLElementObject
{
public:
    
    FZZMMathFont(FZZOfficeObject * parent);
    FZZMMathFont(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMMathFont(const FZZMMathFont& obj);
    virtual ~FZZMMathFont();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMMathFont();
private:
    
    
};

#endif //FZZMMATHFONT_H
