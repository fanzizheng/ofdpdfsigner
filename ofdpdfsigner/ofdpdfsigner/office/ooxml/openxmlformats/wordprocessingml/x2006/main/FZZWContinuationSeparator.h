//
//  Created by zizheng fan on 2023/11/09
//
#ifndef FZZWCONTINUATIONSEPARATOR_H
#define FZZWCONTINUATIONSEPARATOR_H

#include "office/FZZXMLElementObject.h"

#define FZZWCONTINUATIONSEPARATOR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCONTINUATIONSEPARATOR_Name "continuationSeparator"

class FZZWContinuationSeparator : public FZZXMLElementObject
{
public:
    
    FZZWContinuationSeparator(FZZOfficeObject * parent);
    FZZWContinuationSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWContinuationSeparator(const FZZWContinuationSeparator& obj);
    virtual ~FZZWContinuationSeparator();
    
public:
    
protected:
    FZZWContinuationSeparator();
private:
    
    
};

#endif //FZZWCONTINUATIONSEPARATOR_H
