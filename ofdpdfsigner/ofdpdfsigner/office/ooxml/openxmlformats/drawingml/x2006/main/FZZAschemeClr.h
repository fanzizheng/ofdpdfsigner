//
//  Created by zizheng fan on 2023/08/10
//
#ifndef FZZASCHEMECLR_H
#define FZZASCHEMECLR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlumMod.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsatMod.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAtint.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAshade.h"

#define FZZASCHEMECLR_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASCHEMECLR_Name "schemeClr"

class FZZAschemeClr : public FZZXMLElementObject
{
public:
    
    FZZAschemeClr(FZZOfficeObject * parent);
    FZZAschemeClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAschemeClr(const FZZAschemeClr& obj);
    virtual ~FZZAschemeClr();
    
public:
    void setVal(string value);
    string getVal();
    
    FZZAlumMod * setLumMod();
    FZZAlumMod * getLumMod();
    FZZAsatMod * setSatMod();
    FZZAsatMod * getSatMod();
    FZZAtint * setTint();
    FZZAtint * getTint();
    FZZAshade * setShade();
    FZZAshade * getShade();
protected:
    FZZAschemeClr();
private:
    FZZAlumMod * m_CTlumMod;
    FZZAsatMod * m_CTsatMod;
    FZZAtint * m_CTtint;
    FZZAshade * m_CTshade;
};

#endif //FZZASCHEMECLR_H
