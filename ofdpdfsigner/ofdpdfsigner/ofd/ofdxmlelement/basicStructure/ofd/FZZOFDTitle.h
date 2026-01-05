//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDTITLE_H
#define FZZOFDTITLE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTITLE_Name "ofd:Title"

class FZZOFDTitle : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDTitle(FZZOFDXMLFileObject * parent);
    FZZOFDTitle(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTitle(const FZZOFDTitle& obj);
    virtual ~FZZOFDTitle();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDTitle();
private:
  
};

#endif //FZZOFDTITLE_H
