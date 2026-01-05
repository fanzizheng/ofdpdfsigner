//
//  Created by zizheng fan on 2023/07/20
//
#ifndef FZZAEFFECTSTYLE_H
#define FZZAEFFECTSTYLE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectLst.h"

#define FZZAEFFECTSTYLE_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAEFFECTSTYLE_Name "effectStyle"

class FZZAeffectStyle : public FZZXMLElementObject
{
public:
    
    FZZAeffectStyle(FZZOfficeObject * parent);
    FZZAeffectStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAeffectStyle(const FZZAeffectStyle& obj);
    virtual ~FZZAeffectStyle();
    
public:
    FZZAeffectLst * setEffectLst();
    FZZAeffectLst * getEffectLst();
protected:
    FZZAeffectStyle();
private:
    FZZAeffectLst * m_CTeffectLst;
    
};

#endif //FZZAEFFECTSTYLE_H
