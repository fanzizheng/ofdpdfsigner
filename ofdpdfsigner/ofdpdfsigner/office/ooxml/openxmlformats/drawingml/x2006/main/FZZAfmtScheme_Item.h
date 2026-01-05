//
//  Created by zizheng fan on 2023/08/14
//
#ifndef FZZAFMTSCHEME_ITEM_H
#define FZZAFMTSCHEME_ITEM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsolidFill.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgradFill.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZALn.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectStyle.h"

#define FZZAFMTSCHEME_ITEM_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"


class FZZAfmtScheme_Item : public FZZXMLElementObject
{
public:
    
    FZZAfmtScheme_Item(FZZOfficeObject * parent);
    FZZAfmtScheme_Item(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAfmtScheme_Item(const FZZAfmtScheme_Item& obj);
    virtual ~FZZAfmtScheme_Item();
   
public:

    FZZAsolidFill * addsolidFill();
    vector<FZZAsolidFill *>* getsolidFills();
    FZZAgradFill * addgradFill();
    vector<FZZAgradFill *>* getgradFills();
    FZZALn * addLn();
    vector<FZZALn *>* getLns();
    FZZAeffectStyle * addEffectStyle();
    vector<FZZAeffectStyle *>* getEffectStyles();
protected:
    FZZAfmtScheme_Item();
private:

    vector<FZZAsolidFill *> m_CTsolidFills;
    vector<FZZAgradFill *> m_CTgradFills;
    vector<FZZALn *> m_CTlns;
    vector<FZZAeffectStyle *> m_CTeffectStyles;
};

#endif //FZZAFMTSCHEME_ITEM_H
