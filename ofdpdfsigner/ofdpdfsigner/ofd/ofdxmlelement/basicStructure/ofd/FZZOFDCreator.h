//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCREATOR_H
#define FZZOFDCREATOR_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCREATOR_Name "ofd:Creator"

class FZZOFDCreator : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCreator(FZZOFDXMLFileObject * parent);
    FZZOFDCreator(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCreator(const FZZOFDCreator& obj);
    virtual ~FZZOFDCreator();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDCreator();
private:
  
};

#endif //FZZOFDCREATOR_H
