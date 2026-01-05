//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPAGEELEM_H
#define FZZOFDPAGEELEM_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"

#define FZZOFDPAGEELEM_Name "ofd:Page"

class FZZOFDPageElem : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPageElem(FZZOFDXMLFileObject * parent);
    FZZOFDPageElem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageElem(const FZZOFDPageElem& obj);
    virtual ~FZZOFDPageElem();
    
public:
    void setBaseLoc(string title);
    string getBaseLoc();
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    
    
protected:
    FZZOFDPageElem();
private:
    
};

#endif //FZZOFDPAGEELEM_H
