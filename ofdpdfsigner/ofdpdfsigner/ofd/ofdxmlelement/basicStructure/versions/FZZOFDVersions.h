//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDVERSIONS_H
#define FZZOFDVERSIONS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersion.h"

#define FZZOFDVERSIONS_Name "ofd:Versions"

class FZZOFDVersions : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDVersions(FZZOFDXMLFileObject * parent);
    FZZOFDVersions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDVersions(const FZZOFDVersions& obj);
    virtual ~FZZOFDVersions();
    
public:

    
    FZZOFDVersion * addVersion();
    vector<FZZOFDVersion*> * getVersions();
    
protected:
    FZZOFDVersions();
private:
    vector<FZZOFDVersion*> m_FZZOFDVersions;
};

#endif //FZZOFDVERSIONS_H
