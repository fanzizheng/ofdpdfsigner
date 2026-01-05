//
//  Created by zizheng fan on 2023/05/06.
//
#ifndef FZZWPSSTYLE_H
#define FZZWPSSTYLE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZALnRef.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFontRef.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRef.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAEffectRef.h"

#define FZZWPSSTYLE_Find_Key "schemas.microsoft.com/office/word/2010/wordprocessingShape"
#define FZZWPSSTYLE_Name "style"

class FZZWPSStyle : public FZZXMLElementObject
{
public:
    
    FZZWPSStyle(FZZOfficeObject * parent);
    FZZWPSStyle(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSStyle(const FZZWPSStyle& obj);
    virtual ~FZZWPSStyle();
    
public:
    FZZALnRef * setLnRef();
    FZZALnRef * getLnRef();
    FZZAFontRef * setFontRef();
    FZZAFontRef * getFontRef();
    FZZAFillRef * setFillRef();
    FZZAFillRef * getFillRef();
    FZZAEffectRef * setEffectRef();
    FZZAEffectRef * getEffectRef();
protected:
    FZZWPSStyle();
private:
    FZZALnRef * m_FZZALnRef;
    FZZAFontRef * m_FZZAFontRef;
    FZZAFillRef * m_FZZAFillRef;
    FZZAEffectRef * m_FZZAEffectRef;
};

#endif //FZZWPSSTYLE_H
