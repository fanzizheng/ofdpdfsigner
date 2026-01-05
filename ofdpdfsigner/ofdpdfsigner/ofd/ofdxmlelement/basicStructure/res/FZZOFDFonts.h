//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDFONTS_H
#define FZZOFDFONTS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFont.h"

#define FZZOFDFONTS_Name "ofd:Fonts"

class FZZOFDFonts : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    
    FZZOFDFonts(FZZOFDXMLFileObject * parent);
    FZZOFDFonts(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFonts(const FZZOFDFonts& obj);
    virtual ~FZZOFDFonts();
    
public:
    FZZOFDFont * addFont();
    vector<FZZOFDFont*> * getFontList();
    
protected:
    FZZOFDFonts();
private:
 
    vector<FZZOFDFont*> m_FZZOFDFonts;
};

#endif //FZZOFDFONTS_H
