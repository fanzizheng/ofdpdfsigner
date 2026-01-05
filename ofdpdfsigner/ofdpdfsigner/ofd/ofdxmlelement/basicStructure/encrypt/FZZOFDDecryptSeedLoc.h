//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDDECRYPTSEEDLOC_H
#define FZZOFDDECRYPTSEEDLOC_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDECRYPTSEEDLOC_Name "ofd:DecryptSeedLoc"

class FZZOFDDecryptSeedLoc : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDDecryptSeedLoc(FZZOFDXMLFileObject * parent);
    FZZOFDDecryptSeedLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDecryptSeedLoc(const FZZOFDDecryptSeedLoc& obj);
    virtual ~FZZOFDDecryptSeedLoc();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDDecryptSeedLoc();
private:
    
};

#endif //FZZOFDDECRYPTSEEDLOC_H
