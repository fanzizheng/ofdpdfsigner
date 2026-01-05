//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCUSTOMDATA_H
#define FZZOFDCUSTOMDATA_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCUSTOMDATA_Name "ofd:CustomData"

class FZZOFDCustomData : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCustomData(FZZOFDXMLFileObject * parent);
    FZZOFDCustomData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCustomData(const FZZOFDCustomData& obj);
    virtual ~FZZOFDCustomData();
    
public:
    void setName(string value);
    string getName();
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDCustomData();
private:
  
};

#endif //FZZOFDCUSTOMDATA_H
