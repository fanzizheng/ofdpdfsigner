//
//  Created by zizheng fan on 2023/04/08.
//
#ifndef FZZSTYLESXML_H
#define FZZSTYLESXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocDefaults.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLatentStyles.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStyle.h"


#define STYLESXML_FILENAME "styles.xml"

class FZZStylesXML : public FZZOfficeObject
{
public:
    FZZStylesXML();
    FZZStylesXML(XMLDocument * doc);
    FZZStylesXML(const FZZStylesXML& obj);
    virtual ~FZZStylesXML();
    
 
public:
    FZZWDocDefaults * setDocDefaults();
    FZZWDocDefaults * getDocDefaults();
    FZZWLatentStyles * setLatentStyles();
    FZZWLatentStyles * getLatentStyles();
    
    FZZWStyle * addStyle();
    vector<FZZWStyle*> * getStyles();
    FZZWStyle * getStyle(string styleId);
    
public:
    string getNextStyleID_ToString();
    string getCurrStyleID_ToString();
protected:
    void defaultInit();
private:
    FZZWDocDefaults * m_FZZWDocDefaults;
    FZZWLatentStyles * m_FZZWLatentStyles;
    vector<FZZWStyle*> m_FZZWStyles;
    
    int m_StyleId;
};

#endif //FZZSTYLESXML_H
