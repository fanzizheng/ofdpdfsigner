//
//  Created by zizheng fan on 2023/08/15
//
#ifndef FZZAFMTSCHEME_H
#define FZZAFMTSCHEME_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme_Item.h"

#define FZZAFMTSCHEME_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAFMTSCHEME_Name "fmtScheme"

class FZZAfmtScheme : public FZZXMLElementObject
{
public:
    
    FZZAfmtScheme(FZZOfficeObject * parent);
    FZZAfmtScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAfmtScheme(const FZZAfmtScheme& obj);
    virtual ~FZZAfmtScheme();
    
public:
    void setName(string value);
    string getName();
    FZZAfmtScheme_Item * setFillStyleLst();
    FZZAfmtScheme_Item * getFillStyleLst();
    FZZAfmtScheme_Item * setLnStyleLst();
    FZZAfmtScheme_Item * getLnStyleLst();
    FZZAfmtScheme_Item * setEffectStyleLst();
    FZZAfmtScheme_Item * getEffectStyleLst();
    FZZAfmtScheme_Item * setBgFillStyleLst();
    FZZAfmtScheme_Item * getBgFillStyleLst();
    
protected:
    FZZAfmtScheme();
private:
    FZZAfmtScheme_Item * m_FillStyleLst;
    FZZAfmtScheme_Item * m_LnStyleLst;
    FZZAfmtScheme_Item * m_EffectStyleLst;
    FZZAfmtScheme_Item * m_BgFillStyleLst;
};

#endif //FZZAFMTSCHEME_H
