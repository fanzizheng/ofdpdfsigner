//
//  Created by zizheng fan on 2023/09/01
//
#ifndef FZZWFONT_H
#define FZZWFONT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAltName.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSig.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPitch.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPanose1.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFamily.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharset.h"

#define FZZWFONT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFONT_Name "font"

class FZZWFont : public FZZXMLElementObject
{
public:
    
    FZZWFont(FZZOfficeObject * parent);
    FZZWFont(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFont(const FZZWFont& obj);
    virtual ~FZZWFont();
    
public:
    void setName(string value);
    string getName();
    
    FZZWAltName * setAltName();
    FZZWAltName * getAltName();
    
    FZZWSig * setSig();
    FZZWSig * getSig();
    FZZWPitch * setPitch();
    FZZWPitch * getPitch();
    FZZWPanose1 * setPanose1();
    FZZWPanose1 * getPanose1();
    FZZWFamily * setFamily();
    FZZWFamily * getFamily();
    FZZWCharset * setCharset();
    FZZWCharset * getCharset();
protected:
    FZZWFont();
private:
    FZZWAltName * m_FZZWAltName;
    FZZWSig * m_FZZWSig;
    FZZWPitch * m_FZZWPitch;
    FZZWPanose1 * m_FZZWPanose1;
    FZZWFamily * m_FZZWFamily;
    FZZWCharset * m_FZZWCharset;
    
};

#endif //FZZWFONT_H
