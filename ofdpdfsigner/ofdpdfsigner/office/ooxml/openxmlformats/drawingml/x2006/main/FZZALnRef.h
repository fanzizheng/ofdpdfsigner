//
//  Created by zizheng fan on 2023/07/03
//
#ifndef FZZALNREF_H
#define FZZALNREF_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"


#define FZZALNREF_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZALNREF_Name "lnRef"

class FZZALnRef : public FZZXMLElementObject
{
public:
    
    FZZALnRef(FZZOfficeObject * parent);
    FZZALnRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZALnRef(const FZZALnRef& obj);
    virtual ~FZZALnRef();
    
public:
    void setIdx(string value);
    string getIdx();

    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
protected:
    FZZALnRef();
private:
    FZZAschemeClr * m_FZZAschemeClr;
};

#endif //FZZALNREF_H
