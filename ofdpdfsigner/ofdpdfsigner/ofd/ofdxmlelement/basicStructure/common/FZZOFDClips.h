//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDCLIPS_H
#define FZZOFDCLIPS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClip.h"

#define FZZOFDCLIPS_Name "ofd:Clips"

class FZZOFDClips : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDClips(FZZOFDXMLFileObject * parent);
    FZZOFDClips(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDClips(const FZZOFDClips& obj);
    virtual ~FZZOFDClips();
    
public:
    void setTransFlag(bool value);
    bool getTransFlag();
    FZZOFDClip * addClip();
    vector<FZZOFDClip*> * getClipList();
    
protected:
    FZZOFDClips();
private:
    vector<FZZOFDClip*> m_FZZOFDClips;
};

#endif //FZZOFDCLIPS_H
