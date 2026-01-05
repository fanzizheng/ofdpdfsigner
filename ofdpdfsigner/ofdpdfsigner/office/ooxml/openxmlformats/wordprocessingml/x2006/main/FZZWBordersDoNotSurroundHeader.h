//
//  Created by zizheng fan on 2023/09/11
//
#ifndef FZZWBORDERSDONOTSURROUNDHEADER_H
#define FZZWBORDERSDONOTSURROUNDHEADER_H

#include "office/FZZXMLElementObject.h"

#define FZZWBORDERSDONOTSURROUNDHEADER_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBORDERSDONOTSURROUNDHEADER_Name "bordersDoNotSurroundHeader"

class FZZWBordersDoNotSurroundHeader : public FZZXMLElementObject
{
public:
    
    FZZWBordersDoNotSurroundHeader(FZZOfficeObject * parent);
    FZZWBordersDoNotSurroundHeader(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBordersDoNotSurroundHeader(const FZZWBordersDoNotSurroundHeader& obj);
    virtual ~FZZWBordersDoNotSurroundHeader();
    
public:
    
    
protected:
    FZZWBordersDoNotSurroundHeader();
private:
    
    
};

#endif //FZZWBORDERSDONOTSURROUNDHEADER_H
