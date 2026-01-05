//
//  Created by zizheng fan on 2023/06/30
//
#ifndef FZZAFONTREF_H
#define FZZAFONTREF_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.h"


#define FZZAFONTREF_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAFONTREF_Name "fontRef"

class FZZAFontRef : public FZZXMLElementObject
{
public:
    
    FZZAFontRef(FZZOfficeObject * parent);
    FZZAFontRef(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAFontRef(const FZZAFontRef& obj);
    virtual ~FZZAFontRef();
    
public:
    void setIdx(string value);
    string getIdx();
    
    FZZAschemeClr * setSchemeClr();
    FZZAschemeClr * getSchemeClr();
protected:
    FZZAFontRef();
private:
    FZZAschemeClr * m_FZZAschemeClr;
};

#endif //FZZAFONTREF_H
