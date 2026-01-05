//
//  Created by zizheng fan on 2023/05/22
//
#ifndef FZZMLMARGIN_H
#define FZZMLMARGIN_H

#include "office/FZZXMLElementObject.h"

#define FZZMLMARGIN_Find_Key "schemas.openxmlformats.org/officeDocument/2006/math"
#define FZZMLMARGIN_Name "lMargin"

class FZZMLMargin : public FZZXMLElementObject
{
public:
    
    FZZMLMargin(FZZOfficeObject * parent);
    FZZMLMargin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMLMargin(const FZZMLMargin& obj);
    virtual ~FZZMLMargin();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZMLMargin();
private:
    
    
};

#endif //FZZMLMARGIN_H
