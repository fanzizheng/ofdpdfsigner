//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDEXTENDDATA_H
#define FZZOFDEXTENDDATA_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDEXTENDDATA_Name "ofd:ExtendData"

class FZZOFDExtendData : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDExtendData(FZZOFDXMLFileObject * parent);
    FZZOFDExtendData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDExtendData(const FZZOFDExtendData& obj);
    virtual ~FZZOFDExtendData();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDExtendData();
private:
    
};

#endif //FZZOFDEXTENDDATA_H
