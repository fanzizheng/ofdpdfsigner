//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDPALETTE_H
#define FZZOFDPALETTE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDCV.h"

#define FZZOFDPALETTE_Name "ofd:Palette"

class FZZOFDPalette : public FZZOFDXMLElementObject 
{
public:
    
    FZZOFDPalette(FZZOFDXMLFileObject * parent);
    FZZOFDPalette(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPalette(const FZZOFDPalette& obj);
    virtual ~FZZOFDPalette();
    
public:
    FZZOFDCV * addCV();
    vector<FZZOFDCV*> * getCVList();
    void getColorByIndex(string index,vector<string> & array);
protected:
    FZZOFDPalette();
private:
 
    vector<FZZOFDCV*> m_FZZOFDCVs;
};

#endif //FZZOFDPALETTE_H
