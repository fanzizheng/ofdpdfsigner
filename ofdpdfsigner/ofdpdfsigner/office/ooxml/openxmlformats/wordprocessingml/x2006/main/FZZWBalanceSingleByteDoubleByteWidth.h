//
//  Created by zizheng fan on 2023/09/22
//
#ifndef FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_H
#define FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_H

#include "office/FZZXMLElementObject.h"

#define FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Name "balanceSingleByteDoubleByteWidth"

class FZZWBalanceSingleByteDoubleByteWidth : public FZZXMLElementObject
{
public:
    
    FZZWBalanceSingleByteDoubleByteWidth(FZZOfficeObject * parent);
    FZZWBalanceSingleByteDoubleByteWidth(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBalanceSingleByteDoubleByteWidth(const FZZWBalanceSingleByteDoubleByteWidth& obj);
    virtual ~FZZWBalanceSingleByteDoubleByteWidth();
    
public:
    
protected:
    FZZWBalanceSingleByteDoubleByteWidth();
private:
    
    
};

#endif //FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_H
