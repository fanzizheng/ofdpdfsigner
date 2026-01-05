//
//  Created by zizheng fan on 2023/09/14
//
#ifndef FZZWCHARACTERSPACINGCONTROL_H
#define FZZWCHARACTERSPACINGCONTROL_H

#include "office/FZZXMLElementObject.h"

#define FZZWCHARACTERSPACINGCONTROL_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCHARACTERSPACINGCONTROL_Name "characterSpacingControl"

class FZZWCharacterSpacingControl : public FZZXMLElementObject
{
public:
    
    FZZWCharacterSpacingControl(FZZOfficeObject * parent);
    FZZWCharacterSpacingControl(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCharacterSpacingControl(const FZZWCharacterSpacingControl& obj);
    virtual ~FZZWCharacterSpacingControl();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWCharacterSpacingControl();
private:
    
    
};

#endif //FZZWCHARACTERSPACINGCONTROL_H
