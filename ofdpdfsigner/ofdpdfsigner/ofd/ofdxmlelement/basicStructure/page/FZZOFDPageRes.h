//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDPAGERES_H
#define FZZOFDPAGERES_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDPAGERES_Name "ofd:PageRes"


class FZZOFDPageRes : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDPageRes(FZZOFDXMLFileObject * parent);
    FZZOFDPageRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageRes(const FZZOFDPageRes& obj);
    virtual ~FZZOFDPageRes();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDPageRes();
private:
    
};

#endif //FZZOFDPAGERES_H
