//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDBLEEDBOX_H
#define FZZOFDBLEEDBOX_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDBLEEDBOX_Name "ofd:BleedBox"

class FZZOFDBleedBox : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDBleedBox(FZZOFDXMLFileObject * parent);
    FZZOFDBleedBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBleedBox(const FZZOFDBleedBox& obj);
    virtual ~FZZOFDBleedBox();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(double x, double y,double width, double height);
    void getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
protected:
    FZZOFDBleedBox();
private:
    
};

#endif //FZZOFDBLEEDBOX_H
