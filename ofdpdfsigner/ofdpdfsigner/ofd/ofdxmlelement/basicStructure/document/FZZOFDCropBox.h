//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDCROPBOX_H
#define FZZOFDCROPBOX_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDCROPBOX_Name "ofd:CropBox"

class FZZOFDCropBox : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDCropBox(FZZOFDXMLFileObject * parent);
    FZZOFDCropBox(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCropBox(const FZZOFDCropBox& obj);
    virtual ~FZZOFDCropBox();
    
public:
    void setValue(string value);
    string getValue();
    void setValue(double x, double y,double width, double height);
    void getValue(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    
protected:
    FZZOFDCropBox();
private:
    
};

#endif //FZZOFDCROPBOX_H
