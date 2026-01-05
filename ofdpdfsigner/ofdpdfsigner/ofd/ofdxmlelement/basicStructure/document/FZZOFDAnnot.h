//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDANNOT_H
#define FZZOFDANNOT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDANNOT_Name "ofd:Annot"

class FZZOFDAnnot : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDAnnot(FZZOFDXMLFileObject * parent);
    FZZOFDAnnot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAnnot(const FZZOFDAnnot& obj);
    virtual ~FZZOFDAnnot();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDAnnot();
private:
    
};

#endif //FZZOFDANNOT_H
