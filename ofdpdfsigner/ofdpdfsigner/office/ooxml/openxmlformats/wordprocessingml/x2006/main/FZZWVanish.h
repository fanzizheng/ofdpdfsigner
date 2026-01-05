//
//  Created by zizheng fan on 2023/11/27
//
#ifndef FZZWVANISH_H
#define FZZWVANISH_H

#include "office/FZZXMLElementObject.h"

#define FZZWVANISH_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWVANISH_Name "vanish"

class FZZWVanish : public FZZXMLElementObject
{
public:
    
    FZZWVanish(FZZOfficeObject * parent);
    FZZWVanish(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWVanish(const FZZWVanish& obj);
    virtual ~FZZWVanish();
    
public:
    
    
protected:
    FZZWVanish();
private:
    
    
};

#endif //FZZWVANISH_H
