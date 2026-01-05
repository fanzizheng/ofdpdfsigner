//
//  Created by zizheng fan on 2023/11/20
//
#ifndef FZZWBACKGROUND_H
#define FZZWBACKGROUND_H

#include "office/FZZXMLElementObject.h"

#define FZZWBACKGROUND_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBACKGROUND_Name "background"

class FZZWBackGround : public FZZXMLElementObject
{
public:
    
    FZZWBackGround(FZZOfficeObject * parent);
    FZZWBackGround(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBackGround(const FZZWBackGround& obj);
    virtual ~FZZWBackGround();
    
public:
    void setColor(string value);
    string getColor();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWBackGround();
private:
    
    
};

#endif //FZZWBACKGROUND_H
