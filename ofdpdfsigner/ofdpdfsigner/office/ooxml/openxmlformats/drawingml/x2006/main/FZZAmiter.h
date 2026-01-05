//
//  Created by zizheng fan on 2023/07/28
//
#ifndef FZZAMITER_H
#define FZZAMITER_H

#include "office/FZZXMLElementObject.h"

#define FZZAMITER_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAMITER_Name "miter"

class FZZAmiter : public FZZXMLElementObject
{
public:
    
    FZZAmiter(FZZOfficeObject * parent);
    FZZAmiter(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAmiter(const FZZAmiter& obj);
    virtual ~FZZAmiter();
    
public:
    void setLim(string value);
    string getLim();
protected:
    FZZAmiter();
private:
    
    
};

#endif //FZZAMITER_H
