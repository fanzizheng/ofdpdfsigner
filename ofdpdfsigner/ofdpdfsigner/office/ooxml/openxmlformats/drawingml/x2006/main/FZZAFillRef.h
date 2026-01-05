//
//  Created by zizheng fan on 2023/06/29
//
#ifndef FZZAFILLREF_H
#define FZZAFILLREF_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"


#define FZZAFILLREF_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAFILLREF_Name "fillRef"

class FZZAFillRef : public FZZXMLElementObject
{
public:
    
    FZZAFillRef(FZZOfficeObject * parent);
    FZZAFillRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAFillRef(const FZZAFillRef& obj);
    virtual ~FZZAFillRef();
    
public:
    void setIdx(string value);
    string getIdx();
    
    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
protected:
    FZZAFillRef();
private:
    FZZAschemeClr * m_FZZAschemeClr;
};

#endif //FZZAFILLREF_H
