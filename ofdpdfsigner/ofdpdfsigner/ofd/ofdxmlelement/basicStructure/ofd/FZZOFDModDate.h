//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDMODDATE_H
#define FZZOFDMODDATE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDMODDATE_Name "ofd:ModDate"

class FZZOFDModDate : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDModDate(FZZOFDXMLFileObject * parent);
    FZZOFDModDate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDModDate(const FZZOFDModDate& obj);
    virtual ~FZZOFDModDate();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDModDate();
private:
  
};

#endif //FZZOFDMODDATE_H
