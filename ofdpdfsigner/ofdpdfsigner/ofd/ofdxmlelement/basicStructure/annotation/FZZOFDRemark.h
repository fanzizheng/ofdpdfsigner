//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDREMARK_H
#define FZZOFDREMARK_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDREMARK_Name "ofd:Remark"


class FZZOFDRemark : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDRemark(FZZOFDXMLFileObject * parent);
    FZZOFDRemark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDRemark(const FZZOFDRemark& obj);
    virtual ~FZZOFDRemark();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDRemark();
private:
    
};

#endif //FZZOFDREMARK_H
