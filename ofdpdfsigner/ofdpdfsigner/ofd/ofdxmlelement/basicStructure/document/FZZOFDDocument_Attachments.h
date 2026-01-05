//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDOCUMENT_ATTACHMENTS_H
#define FZZOFDDOCUMENT_ATTACHMENTS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUMENT_ATTACHMENTS_Name "ofd:Attachments"

class FZZOFDDocument_Attachments : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocument_Attachments(FZZOFDXMLFileObject * parent);
    FZZOFDDocument_Attachments(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocument_Attachments(const FZZOFDDocument_Attachments& obj);
    virtual ~FZZOFDDocument_Attachments();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDDocument_Attachments();
private:
    
};

#endif //FZZOFDDOCUMENT_ATTACHMENTS_H
