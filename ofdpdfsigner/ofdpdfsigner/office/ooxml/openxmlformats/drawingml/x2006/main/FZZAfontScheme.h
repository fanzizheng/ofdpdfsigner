//
//  Created by zizheng fan on 2023/08/17
//
#ifndef FZZAFONTSCHEME_H
#define FZZAFONTSCHEME_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme_Item.h"

#define FZZAFONTSCHEME_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAFONTSCHEME_Name "fontScheme"

class FZZAfontScheme : public FZZXMLElementObject
{
public:
    
    FZZAfontScheme(FZZOfficeObject * parent);
    FZZAfontScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAfontScheme(const FZZAfontScheme& obj);
    virtual ~FZZAfontScheme();
  
public:
    void setName(string value);
    string getName();
    FZZAfontScheme_Item * setMajorFont();
    FZZAfontScheme_Item * getMajorFont();
    FZZAfontScheme_Item * setMinorFont();
    FZZAfontScheme_Item * getMinorFont();
    
protected:
    FZZAfontScheme();
private:
    FZZAfontScheme_Item * m_MajorFont;
    FZZAfontScheme_Item * m_MinorFont;
};

#endif //FZZAFONTSCHEME_H
