//
//  Created by zizheng fan on 2023/09/27
//
#ifndef FZZWPROOFSTATE_H
#define FZZWPROOFSTATE_H

#include "office/FZZXMLElementObject.h"

#define FZZWPROOFSTATE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPROOFSTATE_Name "proofState"

class FZZWProofState : public FZZXMLElementObject
{
public:
    
    FZZWProofState(FZZOfficeObject * parent);
    FZZWProofState(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWProofState(const FZZWProofState& obj);
    virtual ~FZZWProofState();
    
public:
    void setSpelling(string value);
    string getSpelling();
    void setGrammar(string value);
    string getGrammar();
protected:
    FZZWProofState();
private:
    
    
};

#endif //FZZWPROOFSTATE_H
