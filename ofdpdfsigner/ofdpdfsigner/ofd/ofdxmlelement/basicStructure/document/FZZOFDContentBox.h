//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDCONTENTBOX_H
#define FZZOFDCONTENTBOX_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCONTENTBOX_Name "ofd:ContentBox"

class FZZOFDContentBox : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDContentBox(FZZOFDXMLFileObject * parent);
    FZZOFDContentBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDContentBox(const FZZOFDContentBox& obj);
    virtual ~FZZOFDContentBox();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(double x, double y,double width, double height);
    void getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
protected:
    FZZOFDContentBox();
private:
    
};

#endif //FZZOFDCONTENTBOX_H
