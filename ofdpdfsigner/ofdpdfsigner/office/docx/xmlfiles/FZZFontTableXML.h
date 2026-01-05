//
//  Created by zizheng fan on 2023/04/16.
//
#ifndef FZZFONTTABLEXML_H
#define FZZFONTTABLEXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFont.h"

#define FONTTABLEXML_FILENAME "fontTable.xml"

class FZZFontTableXML : public FZZOfficeObject
{
public:
    FZZFontTableXML();
    FZZFontTableXML(XMLDocument * doc);
    FZZFontTableXML(const FZZFontTableXML& obj);
    virtual ~FZZFontTableXML();
    
 
public:
    FZZWFont* addFont();
    vector<FZZWFont*> * getFontList();
protected:
    void defaultInit();
    
private:

    vector<FZZWFont*> m_FontList;
    
};

#endif //FZZFONTTABLEXML_H
