//
//  Created by zizheng fan on 2023/10/10
//
#ifndef FZZWRFONTS_H
#define FZZWRFONTS_H

#include "office/FZZXMLElementObject.h"

#define FZZWRFONTS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRFONTS_Name "rFonts"

class FZZWRFonts : public FZZXMLElementObject
{
public:
    
    FZZWRFonts(FZZOfficeObject * parent);
    FZZWRFonts(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRFonts(const FZZWRFonts& obj);
    virtual ~FZZWRFonts();
    
public:
    void setAsciiTheme(string value);
    string getAsciiTheme();
    void setEastAsiaTheme(string value);
    string getEastAsiaTheme();
    void setHAnsiTheme(string value);
    string getHAnsiTheme();
    void setCstheme(string value);
    string getCstheme();
    void setHint(string value);
    string getHint();
    //0--127
    void setAscii(string value);
    string getAscii();
    //128--255
    void setEastAsia(string value);
    string getEastAsia();
    //Unicode > 128
    void setHAnsi(string value);
    string getHAnsi();
    
    void setCS(string value);
    string getCS();
protected:
    FZZWRFonts();
private:
    
    
};

#endif //FZZWRFONTS_H
