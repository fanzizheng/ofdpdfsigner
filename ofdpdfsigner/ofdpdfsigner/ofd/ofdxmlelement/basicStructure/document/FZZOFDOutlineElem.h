//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDOUTLINEELEM_H
#define FZZOFDOUTLINEELEM_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"

#define FZZOFDOUTLINEELEM_Name "ofd:OutlineElem"

class FZZOFDOutlineElem : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDOutlineElem(FZZOFDXMLFileObject * parent);
    FZZOFDOutlineElem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDOutlineElem(const FZZOFDOutlineElem& obj);
    virtual ~FZZOFDOutlineElem();
    
public:
    void setTitle(string title);
    string getTitle();
    void setCount(int count);
    int getCount();
    void setExpanded(bool expanded);
    bool getExpanded();
    
    FZZOFDActions * setActions();
    FZZOFDActions * getActions();
    FZZOFDOutlineElem * addOutlineElem();
    vector<FZZOFDOutlineElem*> * getOutlineElemList();
    
protected:
    FZZOFDOutlineElem();
private:
    FZZOFDActions * m_FZZOFDActions;
    vector<FZZOFDOutlineElem*> m_FZZOFDOutlineElems;
};

#endif //FZZOFDOUTLINEELEM_H
