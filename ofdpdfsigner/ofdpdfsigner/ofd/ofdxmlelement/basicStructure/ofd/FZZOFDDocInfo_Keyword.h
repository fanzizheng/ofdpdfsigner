//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCINFOKEYWORD_H
#define FZZOFDDOCINFOKEYWORD_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCINFOKEYWORD_Name "ofd:Keyword"

class FZZOFDDocInfo_Keyword : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocInfo_Keyword(FZZOFDXMLFileObject * parent);
    FZZOFDDocInfo_Keyword(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocInfo_Keyword(const FZZOFDDocInfo_Keyword& obj);
    virtual ~FZZOFDDocInfo_Keyword();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDDocInfo_Keyword();
private:
  
};

#endif //FZZOFDDOCINFOKEYWORD_H
