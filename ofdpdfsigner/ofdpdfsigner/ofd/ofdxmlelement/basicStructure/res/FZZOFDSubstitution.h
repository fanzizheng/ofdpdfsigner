//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDSUBSTITUTION_H
#define FZZOFDSUBSTITUTION_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSUBSTITUTION_Name "ofd:Substitution"

class FZZOFDSubstitution : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDSubstitution(FZZOFDXMLFileObject * parent);
    FZZOFDSubstitution(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSubstitution(const FZZOFDSubstitution& obj);
    virtual ~FZZOFDSubstitution();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(long value);
    long getLongValue();
    
protected:
    FZZOFDSubstitution();
private:
 
    
};

#endif //FZZOFDSUBSTITUTION_H
