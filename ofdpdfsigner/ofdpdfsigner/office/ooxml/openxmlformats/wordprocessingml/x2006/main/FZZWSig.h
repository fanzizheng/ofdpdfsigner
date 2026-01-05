//
//  Created by zizheng fan on 2023/09/05
//
#ifndef FZZWSIG_H
#define FZZWSIG_H

#include "office/FZZXMLElementObject.h"

#define FZZWSIG_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSIG_Name "sig"

class FZZWSig : public FZZXMLElementObject
{
public:
    
    FZZWSig(FZZOfficeObject * parent);
    FZZWSig(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSig(const FZZWSig& obj);
    virtual ~FZZWSig();
    
public:
    void setUsb0(string value);
    string getUsb0();
    void setUsb1(string value);
    string getUsb1();
    void setUsb2(string value);
    string getUsb2();
    void setUsb3(string value);
    string getUsb3();
    void setCsb0(string value);
    string getCsb0();
    void setCsb1(string value);
    string getCsb1();
protected:
    FZZWSig();
private:
    
    
};

#endif //FZZWSIG_H
