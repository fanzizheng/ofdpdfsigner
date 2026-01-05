//
//  Created by zizheng fan on 2023/09/20
//
#ifndef FZZWSPACEFORUL_H
#define FZZWSPACEFORUL_H

#include "office/FZZXMLElementObject.h"

#define FZZWSPACEFORUL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSPACEFORUL_Name "spaceForUL"

class FZZWSpaceForUL : public FZZXMLElementObject
{
public:
    
    FZZWSpaceForUL(FZZOfficeObject * parent);
    FZZWSpaceForUL(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSpaceForUL(const FZZWSpaceForUL& obj);
    virtual ~FZZWSpaceForUL();
    
public:
    
protected:
    FZZWSpaceForUL();
private:
    
    
};

#endif //FZZWSPACEFORUL_H
