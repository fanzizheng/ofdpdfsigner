//
//  Created by zizheng fan on 2023/08/17
//
#ifndef FZZAFONTSCHEME_ITEM_H
#define FZZAFONTSCHEME_ITEM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfont_ea_cs.h"

#define FZZAFONTSCHEME_ITEM_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"


class FZZAfontScheme_Item : public FZZXMLElementObject
{
public:
    
    FZZAfontScheme_Item(FZZOfficeObject * parent);
    FZZAfontScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAfontScheme_Item(const FZZAfontScheme_Item& obj);
    virtual ~FZZAfontScheme_Item();
    
public:
    FZZAfont_ea_cs * setLatin();
    FZZAfont_ea_cs * getLatin();
    FZZAfont_ea_cs * setEa();
    FZZAfont_ea_cs * getEa();
    FZZAfont_ea_cs * setCs();
    FZZAfont_ea_cs * getCs();
    FZZAfont_ea_cs * addFont();
    vector<FZZAfont_ea_cs *>* getFonts();
    
protected:
    FZZAfontScheme_Item();
private:
    FZZAfont_ea_cs * m_latin;
    FZZAfont_ea_cs * m_ea;
    FZZAfont_ea_cs * m_cs;
    vector<FZZAfont_ea_cs *> m_fonts;
};

#endif //FZZAFONTSCHEME_ITEM_H
