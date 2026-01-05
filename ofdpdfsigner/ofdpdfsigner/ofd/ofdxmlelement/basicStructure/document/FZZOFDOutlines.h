//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDOUTLINES_H
#define FZZOFDOUTLINES_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlineElem.h"

#define FZZOFDOUTLINES_Name "ofd:Outlines"

class FZZOFDOutlines : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDOutlines(FZZOFDXMLFileObject * parent);
    FZZOFDOutlines(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDOutlines(const FZZOFDOutlines& obj);
    virtual ~FZZOFDOutlines();
    
public:
    FZZOFDOutlineElem * addOutlineElem();
    vector<FZZOFDOutlineElem*> * getOutlineElemList();
    
    
protected:
    FZZOFDOutlines();
private:
    vector<FZZOFDOutlineElem*> m_FZZOFDOutlineElems;
};

#endif //FZZOFDOUTLINES_H
