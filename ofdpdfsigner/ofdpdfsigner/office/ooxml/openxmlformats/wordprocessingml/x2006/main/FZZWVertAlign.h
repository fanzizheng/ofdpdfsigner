//
//  Created by zizheng fan on 2023/11/01
//
#ifndef FZZWVERTALIGN_H
#define FZZWVERTALIGN_H

#include "office/FZZXMLElementObject.h"


#define FZZWVERTALIGN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWVERTALIGN_Name "vertAlign"

class FZZWVertAlign : public FZZXMLElementObject
{
public:
    
    FZZWVertAlign(FZZOfficeObject * parent);
    FZZWVertAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWVertAlign(const FZZWVertAlign& obj);
    virtual ~FZZWVertAlign();
    
public:
    // superscript
    void setVal(string value);
    string getVal();
    
protected:
    FZZWVertAlign();
private:
    
};

#endif //FZZWVERTALIGN_H
