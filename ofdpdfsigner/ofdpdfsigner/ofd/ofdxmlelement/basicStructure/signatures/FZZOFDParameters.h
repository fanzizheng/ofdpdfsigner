//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDPARAMETERS_H
#define FZZOFDPARAMETERS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameter.h"

#define FZZOFDPARAMETERS_Name "ofd:Parameters"
#define CPARAMETERS_Name "Parameters"

class FZZOFDParameters : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDParameters(FZZOFDXMLFileObject * parent);
    FZZOFDParameters(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDParameters(const FZZOFDParameters& obj);
    virtual ~FZZOFDParameters();
    
public:
    
    //签名结构中使用
    FZZOFDParameter * addParameter_SignType();
    vector<FZZOFDParameter*> * getParameterList_SignType();
    //注释结构中使用
    FZZOFDParameter * addParameter_AnnotType();
    vector<FZZOFDParameter*> * getParameterList_AnnotType();
    
protected:
    FZZOFDParameters();
private:
    vector<FZZOFDParameter*> m_FZZOFDParameters;
};

#endif //FZZOFDPARAMETERS_H
