//
//  Created by zizheng fan on 2023/09/21
//
#ifndef FZZWDONOTLEAVEBACKSLASHALONE_H
#define FZZWDONOTLEAVEBACKSLASHALONE_H

#include "office/FZZXMLElementObject.h"

#define FZZWDONOTLEAVEBACKSLASHALONE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDONOTLEAVEBACKSLASHALONE_Name "doNotLeaveBackslashAlone"

class FZZWDoNotLeaveBackslashAlone : public FZZXMLElementObject
{
public:
    
    FZZWDoNotLeaveBackslashAlone(FZZOfficeObject * parent);
    FZZWDoNotLeaveBackslashAlone(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDoNotLeaveBackslashAlone(const FZZWDoNotLeaveBackslashAlone& obj);
    virtual ~FZZWDoNotLeaveBackslashAlone();
    
public:
    
protected:
    FZZWDoNotLeaveBackslashAlone();
private:
    
    
};

#endif //FZZWDONOTLEAVEBACKSLASHALONE_H
