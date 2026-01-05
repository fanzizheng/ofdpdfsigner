//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDFONT_H
#define FZZOFDFONT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFontFile.h"


#define FZZOFDFONT_Name "ofd:Font"

class FZZOFDFont : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        symbol,
        prc,
        big5,
        shift_jis,
        wansung,
        johab,
        unicode
    } TYPE; //Charset
public:
    
    FZZOFDFont(FZZOFDXMLFileObject * parent);
    FZZOFDFont(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFont(const FZZOFDFont& obj);
    virtual ~FZZOFDFont();
    
public:
    void setCharset(FZZOFDFont::TYPE value);
    FZZOFDFont::TYPE getCharset();
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setFontName(string value);
    string getFontName();
    void setFamilyName(string value);
    string getFamilyName();
    void setItalic(bool italic);
    bool getItalic();
    void setBold(bool bold);
    bool getBold();
    void setSerif(bool serif);
    bool getSerif();
    void setFixedWidth(bool fixedWidth);
    bool getFixedWidth();
    FZZOFDFontFile * setFontFile();
    FZZOFDFontFile * getFontFile();
    
protected:
    FZZOFDFont();
private:
    FZZOFDFontFile * m_FZZOFDFontFile;
    
};

#endif //FZZOFDFONT_H
