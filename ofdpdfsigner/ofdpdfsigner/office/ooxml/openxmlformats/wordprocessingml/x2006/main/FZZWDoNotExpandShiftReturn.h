//
//  Created by zizheng fan on 2023/09/21
//
#ifndef FZZWDONOTEXPANDSHIFTRETURN_H
#define FZZWDONOTEXPANDSHIFTRETURN_H

#include "office/FZZXMLElementObject.h"

#define FZZWDONOTEXPANDSHIFTRETURN_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDONOTEXPANDSHIFTRETURN_Name "doNotExpandShiftReturn"

class FZZWDoNotExpandShiftReturn : public FZZXMLElementObject
{
public:
    
    FZZWDoNotExpandShiftReturn(FZZOfficeObject * parent);
    FZZWDoNotExpandShiftReturn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDoNotExpandShiftReturn(const FZZWDoNotExpandShiftReturn& obj);
    virtual ~FZZWDoNotExpandShiftReturn();
    
public:
    
protected:
    FZZWDoNotExpandShiftReturn();
private:
    
    
};

#endif //FZZWDONOTEXPANDSHIFTRETURN_H
