//
//  Created by zizheng fan on 2023/08/22
//
#ifndef FZZACLRSCHEME_ITEM_H
#define FZZACLRSCHEME_ITEM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASysClr.h"

#define CTCLRSCHEME_ITEM_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"


class FZZAClrScheme_Item : public FZZXMLElementObject
{
public:
    
    FZZAClrScheme_Item(FZZOfficeObject * parent);
    FZZAClrScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAClrScheme_Item(const FZZAClrScheme_Item& obj);
    virtual ~FZZAClrScheme_Item();
    
public:
    FZZASysClr * setSysClr();
    FZZASysClr * getSysClr();
    FZZASrgbClr * setSrgbClr();
    FZZASrgbClr * getSrgbClr();
protected:
    FZZAClrScheme_Item();
private:
    FZZASysClr * m_CTSysClr;
    FZZASrgbClr * m_CTSrgbClr;
    
};

#endif //CTCLRSCHEME_ITEM_H
