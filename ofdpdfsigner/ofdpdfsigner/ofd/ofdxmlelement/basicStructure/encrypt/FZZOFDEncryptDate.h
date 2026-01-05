//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDENCRYPTDATE_H
#define FZZOFDENCRYPTDATE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDENCRYPTDATE_Name "ofd:EncryptDate"

class FZZOFDEncryptDate : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEncryptDate(FZZOFDXMLFileObject * parent);
    FZZOFDEncryptDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEncryptDate(const FZZOFDEncryptDate& obj);
    virtual ~FZZOFDEncryptDate();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDEncryptDate();
private:
    
};

#endif //FZZOFDENCRYPTDATE_H
