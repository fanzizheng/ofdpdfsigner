//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCUMENT_CUSTOMTAGS_H
#define FZZOFDDOCUMENT_CUSTOMTAGS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUMENT_CUSTOMTAGS_Name "ofd:CustomTags"

class FZZOFDDocument_CustomTags : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocument_CustomTags(FZZOFDXMLFileObject * parent);
    FZZOFDDocument_CustomTags(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocument_CustomTags(const FZZOFDDocument_CustomTags& obj);
    virtual ~FZZOFDDocument_CustomTags();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDDocument_CustomTags();
private:
    
};

#endif //FZZOFDDOCUMENT_CUSTOMTAGS_H
