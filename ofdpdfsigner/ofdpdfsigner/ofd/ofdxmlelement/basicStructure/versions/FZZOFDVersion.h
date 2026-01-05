//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDVERSION_H
#define FZZOFDVERSION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocRoot.h"

#define FZZOFDVERSION_Name "ofd:Version"

class FZZOFDVersion : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDVersion(FZZOFDXMLFileObject * parent);
    FZZOFDVersion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDVersion(const FZZOFDVersion& obj);
    virtual ~FZZOFDVersion();
    
public:
    void setID(string value);
    string getID();
    void setIndex(int value);
    int getIndex();
    void setCurrent(bool value);
    bool getCurrent();
    void setBaseLoc(string value);
    string getBaseLoc();
    
protected:
    FZZOFDVersion();
private:
    
};

#endif //FZZOFDVERSION_H
