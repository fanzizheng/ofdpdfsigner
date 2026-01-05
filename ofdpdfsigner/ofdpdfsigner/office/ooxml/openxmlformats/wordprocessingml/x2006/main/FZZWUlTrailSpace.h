//
//  Created by zizheng fan on 2023/09/19
//
#ifndef FZZWULTRAILSPACE_H
#define FZZWULTRAILSPACE_H

#include "office/FZZXMLElementObject.h"

#define FZZWULTRAILSPACE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWULTRAILSPACE_Name "ulTrailSpace"

class FZZWUlTrailSpace : public FZZXMLElementObject
{
public:
    
    FZZWUlTrailSpace(FZZOfficeObject * parent);
    FZZWUlTrailSpace(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWUlTrailSpace(const FZZWUlTrailSpace& obj);
    virtual ~FZZWUlTrailSpace();
    
public:
    
protected:
    FZZWUlTrailSpace();
private:
    
    
};

#endif //FZZWULTRAILSPACE_H
