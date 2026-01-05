//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCREATIONDATE_H
#define FZZOFDCREATIONDATE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCREATIONDATE_Name "ofd:CreationDate"

class FZZOFDCreationDate : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCreationDate(FZZOFDXMLFileObject * parent);
    FZZOFDCreationDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCreationDate(const FZZOFDCreationDate& obj);
    virtual ~FZZOFDCreationDate();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDCreationDate();
private:
  
};

#endif //FZZOFDCREATIONDATE_H
