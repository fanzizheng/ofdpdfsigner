//
//  Created by zizheng fan on 2023/10/30
//
#ifndef FZZWT_H
#define FZZWT_H

#include "office/FZZXMLElementObject.h"

#define FZZWT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWT_Name "t"

class FZZWT : public FZZXMLElementObject
{
public:
    
    FZZWT(FZZOfficeObject * parent);
    FZZWT(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWT(const FZZWT& obj);
    virtual ~FZZWT();
    
public:
    void setSpace(string value = "preserve");
    string getSpace();
    
    void setValue(string value);
    string getValue();
    
protected:
    FZZWT();
private:
    
    
};

#endif //FZZWT_H
