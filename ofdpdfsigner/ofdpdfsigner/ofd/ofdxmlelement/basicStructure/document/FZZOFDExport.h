//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDEXPORT_H
#define FZZOFDEXPORT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDEXPORT_Name "ofd:Export"

class FZZOFDExport : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDExport(FZZOFDXMLFileObject * parent);
    FZZOFDExport(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDExport(const FZZOFDExport& obj);
    virtual ~FZZOFDExport();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDExport();
private:
    
};

#endif //FZZOFDEXPORT_H
