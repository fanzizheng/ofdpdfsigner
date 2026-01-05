//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDCLIP_H
#define FZZOFDCLIP_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClipArea.h"

#define FZZOFDCLIP_Name "ofd:Clip"

class FZZOFDClip : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDClip(FZZOFDXMLFileObject * parent);
    FZZOFDClip(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDClip(const FZZOFDClip& obj);
    virtual ~FZZOFDClip();
    
public:
    FZZOFDClipArea * addArea();
    vector<FZZOFDClipArea*> * getAreaList();
    
    
protected:
    FZZOFDClip();
private:
    vector<FZZOFDClipArea*> m_FZZOFDClipAreas;
};

#endif //FZZOFDCLIP_H
