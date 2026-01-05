//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCOVER_H
#define FZZOFDCOVER_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCOVER_Name "ofd:Cover"

class FZZOFDCover : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCover(FZZOFDXMLFileObject * parent);
    FZZOFDCover(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCover(const FZZOFDCover& obj);
    virtual ~FZZOFDCover();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDCover();
private:
  
};

#endif //FZZOFDCOVER_H
