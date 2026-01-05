//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDREFERENCE_H
#define FZZOFDREFERENCE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDCheckValue.h"

#define FZZOFDREFERENCE_Name "ofd:Reference"

class FZZOFDReference : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDReference(FZZOFDXMLFileObject * parent);
    FZZOFDReference(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDReference(const FZZOFDReference& obj);
    virtual ~FZZOFDReference();
    
public:
    void setFileRef(string value);
    string getFileRef();
    
    FZZOFDCheckValue * setCheckValue();
    FZZOFDCheckValue * getCheckValue();
    
protected:
    FZZOFDReference();
private:
    FZZOFDCheckValue * m_FZZOFDCheckValue;
};

#endif //FZZOFDREFERENCE_H
