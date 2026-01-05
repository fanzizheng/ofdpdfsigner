//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDAPPLICATIONBOX_H
#define FZZOFDAPPLICATIONBOX_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDAPPLICATIONBOX_Name "ofd:ApplicationBox"

class FZZOFDApplicationBox : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDApplicationBox(FZZOFDXMLFileObject * parent);
    FZZOFDApplicationBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDApplicationBox(const FZZOFDApplicationBox& obj);
    virtual ~FZZOFDApplicationBox();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(double x, double y,double width, double height);
    void getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
protected:
    FZZOFDApplicationBox();
private:
    
};

#endif //FZZOFDAPPLICATIONBOX_H
