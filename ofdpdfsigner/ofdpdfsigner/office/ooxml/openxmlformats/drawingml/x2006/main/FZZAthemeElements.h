//
//  Created by zizheng fan on 2023/08/24
//
#ifndef FZZATHEMEELEMENTS_H
#define FZZATHEMEELEMENTS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme.h"

#define FZZATHEMEELEMENTS_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZATHEMEELEMENTS_Name "themeElements"

class FZZAthemeElements : public FZZXMLElementObject
{
public:
    
    FZZAthemeElements(FZZOfficeObject * parent);
    FZZAthemeElements(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAthemeElements(const FZZAthemeElements& obj);
    virtual ~FZZAthemeElements();
  
public:
    FZZAClrScheme * setClrScheme();
    FZZAClrScheme * getClrScheme();
    FZZAfontScheme * setfontScheme();
    FZZAfontScheme * getfontScheme();
    FZZAfmtScheme * setfmtScheme();
    FZZAfmtScheme * getfmtScheme();
protected:
    FZZAthemeElements();
private:
    FZZAClrScheme * m_CTClrScheme;
    FZZAfontScheme * m_CTfontScheme;
    FZZAfmtScheme * m_CTfmtScheme;
};

#endif //FZZATHEMEELEMENTS_H
