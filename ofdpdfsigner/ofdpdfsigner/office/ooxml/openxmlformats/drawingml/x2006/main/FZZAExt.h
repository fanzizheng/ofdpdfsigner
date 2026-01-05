//
//  Created by zizheng fan on 2023/08/25
//
#ifndef FZZAEXT_H
#define FZZAEXT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/office/thememl/x2012/main/FZZThemeFamily.h"
#include "office/ooxml/microsoft/office/drawing/x2010/main/FZZA14UseLocalDpi.h"

#define FZZAEXT_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAEXT_Name "ext"

class FZZAExt : public FZZXMLElementObject
{
public:
    FZZAExt(FZZOfficeObject * parent);
    FZZAExt(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAExt(const FZZAExt& obj);
    virtual ~FZZAExt();

public:
    void setUri(string uri);
    string getUri();
    void setCx(string uri);
    string getCx();
    void setCy(string uri);
    string getCy();
    
    FZZThemeFamily * setCTThemeFamily();
    FZZThemeFamily * getCTThemeFamily();
    
    FZZA14UseLocalDpi * setUseLocalDpi();
    FZZA14UseLocalDpi * getUseLocalDpi();
protected:
    FZZAExt();
private:
    FZZThemeFamily * m_CTThemeFamily;
    FZZA14UseLocalDpi * m_FZZA14UseLocalDpi;
};

#endif //FZZAEXT_H
