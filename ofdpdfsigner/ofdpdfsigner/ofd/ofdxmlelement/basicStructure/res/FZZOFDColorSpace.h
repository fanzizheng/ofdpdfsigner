//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDCOLORSPACE_H
#define FZZOFDCOLORSPACE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFont.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDPalette.h"

#define FZZOFDCOLORSPACE_Name "ofd:ColorSpace"

class FZZOFDColorSpace : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    typedef enum {
        TYPE_GRAY,
        TYPE_RGB,
        TYPE_CMYK
    } TYPE;
    
    typedef enum {
        TYPE_BIT_1,
        TYPE_BIT_2,
        TYPE_BIT_4,
        TYPE_BIT_8,
        TYPE_BIT_16
    } BIT_TYPE;
public:
    
    FZZOFDColorSpace(FZZOFDXMLFileObject * parent);
    FZZOFDColorSpace(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDColorSpace(const FZZOFDColorSpace& obj);
    virtual ~FZZOFDColorSpace();
    
public:
    FZZOFDFont * addFont();
    vector<FZZOFDFont*> * getFontList();
    
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setType(FZZOFDColorSpace::TYPE type);
    FZZOFDColorSpace::TYPE getType();
    void setBitsPerComponent(FZZOFDColorSpace::BIT_TYPE type);
    FZZOFDColorSpace::BIT_TYPE getBitsPerComponent();
    void setProfile(string value);
    string getProfile();
    FZZOFDPalette * setPalette();
    FZZOFDPalette * getPalette();
    
protected:
    FZZOFDColorSpace();
private:
 
    FZZOFDPalette * m_FZZOFDPalette;
};

#endif //FZZOFDCOLORSPACE_H
