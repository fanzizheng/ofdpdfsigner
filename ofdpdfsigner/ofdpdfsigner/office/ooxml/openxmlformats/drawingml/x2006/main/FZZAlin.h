//
//  Created by zizheng fan on 2023/08/02
//
#ifndef FZZALIN_H
#define FZZALIN_H

#include "office/FZZXMLElementObject.h"

#define FZZALIN_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZALIN_Name "lin"

class FZZAlin : public FZZXMLElementObject
{
public:
    
    FZZAlin(FZZOfficeObject * parent);
    FZZAlin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAlin(const FZZAlin& obj);
    virtual ~FZZAlin();
    
public:
    void setAng(string value);
    string getAng();
    void setScaled(string value);
    string getScaled();
protected:
    FZZAlin();
private:
    
    
};

#endif //FZZALIN_H
