//
//  Created by zizheng fan on 2023/08/07
//
#ifndef FZZAGS_H
#define FZZAGS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"

#define FZZAGS_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAGS_Name "gs"

class FZZAgs : public FZZXMLElementObject
{
public:
    
    FZZAgs(FZZOfficeObject * parent);
    FZZAgs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAgs(const FZZAgs& obj);
    virtual ~FZZAgs();
    
public:
    void setPos(string value);
    string getPos();
    
    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
protected:
    FZZAgs();
private:
    FZZAschemeClr * m_CTschemeClr;
    
};

#endif //FZZAGS_H
