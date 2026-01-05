//
//  Created by zizheng fan on 2023/09/06
//
#ifndef FZZWPITCH_H
#define FZZWPITCH_H

#include "office/FZZXMLElementObject.h"

#define FZZWPITCH_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPITCH_Name "pitch"

class FZZWPitch : public FZZXMLElementObject
{
public:
    
    FZZWPitch(FZZOfficeObject * parent);
    FZZWPitch(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPitch(const FZZWPitch& obj);
    virtual ~FZZWPitch();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWPitch();
private:
    
    
};

#endif //FZZWPITCH_H
