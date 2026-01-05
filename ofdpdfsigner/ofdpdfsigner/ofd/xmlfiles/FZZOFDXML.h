//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDXML_H
#define FZZOFDXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody.h"

#define FZZOFDXML_FILENAME "ofd.xml"


class FZZOFDXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDXML();
    FZZOFDXML(XMLDocument * doc);
    FZZOFDXML(const FZZOFDXML& obj);
    virtual ~FZZOFDXML();

public:
    FZZOFDDocBody* addDocBody();
    vector<FZZOFDDocBody*>* getDocBodys();
    FZZOFDDocBody* getDocBody_default();
    
    
    void setDocType(string value);
    string getDocType();
    void setVersion(string value);
    string getVersion();
    
public:
  
protected:
    
private:
    vector<FZZOFDDocBody*> m_FZZOFDDocBodys;
};

#endif //FZZOFDXML_H
