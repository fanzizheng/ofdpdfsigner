//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDREFERENCES_H
#define FZZOFDREFERENCES_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReference.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDCheckMethod.h"

#define FZZOFDREFERENCES_Name "ofd:References"

class FZZOFDReferences : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDReferences(FZZOFDXMLFileObject * parent);
    FZZOFDReferences(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDReferences(const FZZOFDReferences& obj);
    virtual ~FZZOFDReferences();
    
public:
    void setCheckMethod(FZZOFDCheckMethod::TYPE type);
    FZZOFDCheckMethod::TYPE getCheckMethod();
    string getCheckMethod_String();
    
    FZZOFDReference * addReference();
    vector<FZZOFDReference*> * getReferenceList();
    
    bool hasFile(string & absLoc);
protected:
    FZZOFDReferences();
private:
    vector<FZZOFDReference*> m_FZZOFDReferences;
};

#endif //FZZOFDREFERENCES_H
