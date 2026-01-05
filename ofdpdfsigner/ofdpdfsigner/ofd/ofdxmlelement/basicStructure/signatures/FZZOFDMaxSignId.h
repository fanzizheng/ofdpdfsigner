//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDMAXSIGNID_H
#define FZZOFDMAXSIGNID_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDMAXSIGNID_Name "ofd:MaxSignId"

class FZZOFDMaxSignId : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDMaxSignId(FZZOFDXMLFileObject * parent);
    FZZOFDMaxSignId(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMaxSignId(const FZZOFDMaxSignId& obj);
    virtual ~FZZOFDMaxSignId();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDMaxSignId();
private:
  
};

#endif //FZZOFDMAXSIGNID_H
