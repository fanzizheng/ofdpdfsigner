//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDCOLORSPACES_H
#define FZZOFDCOLORSPACES_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFont.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpace.h"

#define FZZOFDCOLORSPACES_Name "ofd:ColorSpaces"

class FZZOFDColorSpaces : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    
    FZZOFDColorSpaces(FZZOFDXMLFileObject * parent);
    FZZOFDColorSpaces(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDColorSpaces(const FZZOFDColorSpaces& obj);
    virtual ~FZZOFDColorSpaces();
    
public:
    FZZOFDColorSpace * addColorSpace();
    vector<FZZOFDColorSpace*> * getColorSpaceList();
    
protected:
    FZZOFDColorSpaces();
private:
 
    vector<FZZOFDColorSpace*> m_FZZOFDColorSpaces;
};

#endif //FZZOFDCOLORSPACES_H
