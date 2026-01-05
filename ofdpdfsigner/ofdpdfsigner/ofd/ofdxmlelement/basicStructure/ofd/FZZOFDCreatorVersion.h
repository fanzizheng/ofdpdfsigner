//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCREATORVERSION_H
#define FZZOFDCREATORVERSION_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCREATORVERSION_Name "ofd:CreatorVersion"

class FZZOFDCreatorVersion : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCreatorVersion(FZZOFDXMLFileObject * parent);
    FZZOFDCreatorVersion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCreatorVersion(const FZZOFDCreatorVersion& obj);
    virtual ~FZZOFDCreatorVersion();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDCreatorVersion();
private:
  
};

#endif //FZZOFDCREATORVERSION_H
