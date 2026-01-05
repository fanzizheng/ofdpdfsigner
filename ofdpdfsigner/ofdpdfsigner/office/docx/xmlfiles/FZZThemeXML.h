//
//  Created by zizheng fan on 2023/04/08.
//
#ifndef FZZTHEMEXML_H
#define FZZTHEMEXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAObjectDefaults.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtraClrSchemeLst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAthemeElements.h"


#define THEMEXML_FILENAME "theme1.xml"
class FZZThemeXML : public FZZOfficeObject
{
public:
    FZZThemeXML();
    FZZThemeXML(XMLDocument * doc);
    FZZThemeXML(const FZZThemeXML& obj);
    virtual ~FZZThemeXML();
    
 
public:
    FZZAObjectDefaults * setObjectDefaults();
    FZZAObjectDefaults * getObjectDefaults();
    FZZAExtraClrSchemeLst * setExtraClrSchemeLst();
    FZZAExtraClrSchemeLst * getExtraClrSchemeLst();
    FZZAExtLst * setExtLst();
    FZZAExtLst * getExtLst();
    FZZAthemeElements * setThemeElements();
    FZZAthemeElements * getThemeElements();
protected:
    
private:
    FZZAObjectDefaults * m_CTObjectDefaults;
    FZZAExtraClrSchemeLst * m_CTExtraClrSchemeLst;
    FZZAExtLst * m_CTExtLst;
    FZZAthemeElements * m_CTthemeElements;
};

#endif //FZZTHEMEXML_H
