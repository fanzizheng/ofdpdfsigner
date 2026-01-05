//
//  Created by zizheng fan on 2023/08/11
//
#ifndef FZZASOLIDFILL_H
#define FZZASOLIDFILL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.h"

#define FZZASOLIDFILL_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASOLIDFILL_Name "solidFill"

class FZZAsolidFill : public FZZXMLElementObject
{
public:
    
    FZZAsolidFill(FZZOfficeObject * parent);
    FZZAsolidFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAsolidFill(const FZZAsolidFill& obj);
    virtual ~FZZAsolidFill();
    
public:
    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
    FZZASrgbClr * setSrgbClr();
    FZZASrgbClr * getSrgbClr();
protected:
    FZZAsolidFill();
private:
    FZZAschemeClr * m_CTschemeClr;
    FZZASrgbClr * m_FZZASrgbClr;
};

#endif //FZZASOLIDFILL_H
