//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDMAXUNITID_H
#define FZZOFDMAXUNITID_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDMAXUNITID_Name "ofd:MaxUnitID"

class FZZOFDMaxUnitID : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDMaxUnitID(FZZOFDXMLFileObject * parent);
    FZZOFDMaxUnitID(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMaxUnitID(const FZZOFDMaxUnitID& obj);
    virtual ~FZZOFDMaxUnitID();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(long value);
    long getLongValue();
    
    
protected:
    FZZOFDMaxUnitID();
private:
    
};

#endif //FZZOFDMAXUNITID_H
