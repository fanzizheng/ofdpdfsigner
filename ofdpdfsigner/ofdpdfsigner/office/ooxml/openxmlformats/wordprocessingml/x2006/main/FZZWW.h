//
//  Created by zizheng fan on 2023/11/16
//
#ifndef FZZWW_H
#define FZZWW_H

#include "office/FZZXMLElementObject.h"

#define FZZWW_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWW_Name "w"

class FZZWW : public FZZXMLElementObject
{
public:
    
    FZZWW(FZZOfficeObject * parent);
    FZZWW(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWW(const FZZWW& obj);
    virtual ~FZZWW();
    
public:
    void setVal(string value);
    string getVal();
    
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWW();
private:
    
    
};

#endif //FZZWW_H
