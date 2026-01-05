//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCUMENT_ANNOTATIONS_H
#define FZZOFDDOCUMENT_ANNOTATIONS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUMENT_ANNOTATIONS_Name "ofd:Annotations"

class FZZOFDDocument_Annotations : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocument_Annotations(FZZOFDXMLFileObject * parent);
    FZZOFDDocument_Annotations(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocument_Annotations(const FZZOFDDocument_Annotations& obj);
    virtual ~FZZOFDDocument_Annotations();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDDocument_Annotations();
private:
    
};

#endif //FZZOFDDOCUMENT_ANNOTATIONS_H
