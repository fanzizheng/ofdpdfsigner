//
//  Created by zizheng fan on 2023/09/27
//
#ifndef FZZWLISTSEPARATOR_H
#define FZZWLISTSEPARATOR_H

#include "office/FZZXMLElementObject.h"

#define FZZWLISTSEPARATOR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLISTSEPARATOR_Name "listSeparator"

class FZZWListSeparator : public FZZXMLElementObject
{
public:
    
    FZZWListSeparator(FZZOfficeObject * parent);
    FZZWListSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWListSeparator(const FZZWListSeparator& obj);
    virtual ~FZZWListSeparator();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWListSeparator();
private:
    
    
};

#endif //FZZWLISTSEPARATOR_H
