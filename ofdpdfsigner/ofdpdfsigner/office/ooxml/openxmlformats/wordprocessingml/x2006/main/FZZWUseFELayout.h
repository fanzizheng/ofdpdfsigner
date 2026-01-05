//
//  Created by zizheng fan on 2023/09/18
//
#ifndef FZZWUSEFELAYOUT_H
#define FZZWUSEFELAYOUT_H

#include "office/FZZXMLElementObject.h"

#define FZZWUSEFELAYOUT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWUSEFELAYOUT_Name "useFELayout"

class FZZWUseFELayout : public FZZXMLElementObject
{
public:
    
    FZZWUseFELayout(FZZOfficeObject * parent);
    FZZWUseFELayout(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWUseFELayout(const FZZWUseFELayout& obj);
    virtual ~FZZWUseFELayout();
    
public:
    
protected:
    FZZWUseFELayout();
private:
    
    
};

#endif //FZZWUSEFELAYOUT_H
