//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDACTIONS_H
#define FZZOFDACTIONS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDAction.h"

#define FZZOFDACTIONS_Name "ofd:Actions"

class FZZOFDActions : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDActions(FZZOFDXMLFileObject * parent);
    FZZOFDActions(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDActions(const FZZOFDActions& obj);
    virtual ~FZZOFDActions();
    
public:
   
    FZZOFDAction * addAction();
    vector<FZZOFDAction*> * getActionList();
    
protected:
    FZZOFDActions();
private:
    vector<FZZOFDAction*> m_FZZOFDActions;
};

#endif //FZZOFDACTIONS_H
