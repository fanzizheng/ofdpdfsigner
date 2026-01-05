//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDENCRYPTENTRY_H
#define FZZOFDENCRYPTENTRY_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDENCRYPTENTRY_Name "ofd:EncryptEntry"

class FZZOFDEncryptEntry : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEncryptEntry(FZZOFDXMLFileObject * parent);
    FZZOFDEncryptEntry(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEncryptEntry(const FZZOFDEncryptEntry& obj);
    virtual ~FZZOFDEncryptEntry();
    
public:
    void setPath(string value);
    string getPath();
    void setEPath(string value);
    string getEPath();
    void setDecryptSeedLoc(string value);
    string getDecryptSeedLoc();
    
    
protected:
    FZZOFDEncryptEntry();
private:
    
    
};

#endif //FZZOFDENCRYPTENTRY_H
