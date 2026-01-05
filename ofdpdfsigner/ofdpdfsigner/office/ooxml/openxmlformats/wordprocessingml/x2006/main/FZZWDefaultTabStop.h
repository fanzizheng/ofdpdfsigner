//
//  Created by zizheng fan on 2023/09/13
//
#ifndef FZZWDEFAULTTABSTOP_H
#define FZZWDEFAULTTABSTOP_H

#include "office/FZZXMLElementObject.h"

#define FZZWDEFAULTTABSTOP_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDEFAULTTABSTOP_Name "defaultTabStop"

class FZZWDefaultTabStop : public FZZXMLElementObject
{
public:
    
    FZZWDefaultTabStop(FZZOfficeObject * parent);
    FZZWDefaultTabStop(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDefaultTabStop(const FZZWDefaultTabStop& obj);
    virtual ~FZZWDefaultTabStop();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWDefaultTabStop();
private:
    
    
};

#endif //FZZWDEFAULTTABSTOP_H
