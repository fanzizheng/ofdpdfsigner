//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPUBLICRES_H
#define FZZOFDPUBLICRES_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPUBLICRES_Name "ofd:PublicRes"

class FZZOFDPublicRes : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPublicRes(FZZOFDXMLFileObject * parent);
    FZZOFDPublicRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPublicRes(const FZZOFDPublicRes& obj);
    virtual ~FZZOFDPublicRes();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDPublicRes();
private:
    
};

#endif //FZZOFDPUBLICRES_H
