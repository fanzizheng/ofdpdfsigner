//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDDRAWPARAMS_H
#define FZZOFDDRAWPARAMS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParam.h"

#define FZZOFDDRAWPARAMS_Name "ofd:DrawParams"

class FZZOFDDrawParams : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    
    FZZOFDDrawParams(FZZOFDXMLFileObject * parent);
    FZZOFDDrawParams(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDrawParams(const FZZOFDDrawParams& obj);
    virtual ~FZZOFDDrawParams();
    
public:
    FZZOFDDrawParam * addDrawParam();
    vector<FZZOFDDrawParam*> * getDrawParamList();
    
protected:
    FZZOFDDrawParams();
private:
 
    vector<FZZOFDDrawParam*> m_FZZOFDDrawParams;
};

#endif //FZZOFDDRAWPARAMS_H
