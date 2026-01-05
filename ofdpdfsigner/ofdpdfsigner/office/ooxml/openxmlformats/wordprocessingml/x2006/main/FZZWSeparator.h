//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWSEPARATOR_H
#define FZZWSEPARATOR_H

#include "office/FZZXMLElementObject.h"

#define FZZWSEPARATOR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSEPARATOR_Name "separator"

class FZZWSeparator : public FZZXMLElementObject
{
public:
    
    FZZWSeparator(FZZOfficeObject * parent);
    FZZWSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSeparator(const FZZWSeparator& obj);
    virtual ~FZZWSeparator();
    
public:
    
protected:
    FZZWSeparator();
private:
    
    
};

#endif //FZZWSEPARATOR_H
