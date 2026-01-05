//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDENCRYPTSCOPE_H
#define FZZOFDENCRYPTSCOPE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDENCRYPTSCOPE_Name "ofd:EncryptScope"

class FZZOFDEncryptScope : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEncryptScope(FZZOFDXMLFileObject * parent);
    FZZOFDEncryptScope(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEncryptScope(const FZZOFDEncryptScope& obj);
    virtual ~FZZOFDEncryptScope();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDEncryptScope();
private:
    
};

#endif //FZZOFDENCRYPTSCOPE_H
