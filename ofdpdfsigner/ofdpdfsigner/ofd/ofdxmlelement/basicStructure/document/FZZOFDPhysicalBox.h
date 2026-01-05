//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDPHYSICALBOX_H
#define FZZOFDPHYSICALBOX_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPHYSICALBOX_Name "ofd:PhysicalBox"

class FZZOFDPhysicalBox : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPhysicalBox(FZZOFDXMLFileObject * parent);
    FZZOFDPhysicalBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPhysicalBox(const FZZOFDPhysicalBox& obj);
    virtual ~FZZOFDPhysicalBox();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(double x, double y,double width, double height);
    void getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
protected:
    FZZOFDPhysicalBox();
private:
    
};

#endif //FZZOFDPHYSICALBOX_H
