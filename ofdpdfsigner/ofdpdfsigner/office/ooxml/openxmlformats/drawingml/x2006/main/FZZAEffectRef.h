//
//  Created by zizheng fan on 2023/06/28
//
#ifndef FZZAEFFECTREF_H
#define FZZAEFFECTREF_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"


#define FZZAEFFECTREF_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAEFFECTREF_Name "effectRef"

class FZZAEffectRef : public FZZXMLElementObject
{
public:
    
    FZZAEffectRef(FZZOfficeObject * parent);
    FZZAEffectRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAEffectRef(const FZZAEffectRef& obj);
    virtual ~FZZAEffectRef();
    
public:
    void setIdx(string value);
    string getIdx();

    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
protected:
    FZZAEffectRef();
private:
    FZZAschemeClr * m_FZZAschemeClr;
};

#endif //FZZAEFFECTREF_H
