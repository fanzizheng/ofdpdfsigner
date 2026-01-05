//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDDEFAULTCS_H
#define FZZOFDDEFAULTCS_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDEFAULTCS_Name "ofd:DefaultCS"

class FZZOFDDefaultCS : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDDefaultCS(FZZOFDXMLFileObject * parent);
    FZZOFDDefaultCS(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDefaultCS(const FZZOFDDefaultCS& obj);
    virtual ~FZZOFDDefaultCS();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(long value);
    long getLongValue();
    
    
protected:
    FZZOFDDefaultCS();
private:
    
};

#endif //FZZOFDDEFAULTCS_H
