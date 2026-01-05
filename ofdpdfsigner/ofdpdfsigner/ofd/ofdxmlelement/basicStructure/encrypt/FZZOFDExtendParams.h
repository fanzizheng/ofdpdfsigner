//
//  Created by zizheng fan on 2024/10/16.
//
#ifndef FZZOFDEXTENDPARAMS_H
#define FZZOFDEXTENDPARAMS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncParameter.h"


#define FZZOFDEXTENDPARAMS_Name "ofd:ExtendParams"
#define FZZOFDENCINFOPARAMETERS_Name "ofd:Parameters"

class FZZOFDExtendParams : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDExtendParams(FZZOFDXMLFileObject * parent);
    FZZOFDExtendParams(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDExtendParams(const FZZOFDExtendParams& obj);
    virtual ~FZZOFDExtendParams();
    
public:
    
    FZZOFDEncParameter * addParameter();
    vector<FZZOFDEncParameter*> * getParameterList();
    
protected:
    FZZOFDExtendParams();
private:
    vector<FZZOFDEncParameter*> m_FZZOFDEncParameters;
    
};

#endif //FZZOFDEXTENDPARAMS_H
