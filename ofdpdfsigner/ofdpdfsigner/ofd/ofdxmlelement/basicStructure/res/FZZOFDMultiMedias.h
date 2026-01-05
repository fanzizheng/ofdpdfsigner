//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDMULTIMEDIAS_H
#define FZZOFDMULTIMEDIAS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedia.h"

#define FZZOFDMULTIMEDIAS_Name "ofd:MultiMedias"

class FZZOFDMultiMedias : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    
    FZZOFDMultiMedias(FZZOFDXMLFileObject * parent);
    FZZOFDMultiMedias(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMultiMedias(const FZZOFDMultiMedias& obj);
    virtual ~FZZOFDMultiMedias();
    
public:
    FZZOFDMultiMedia * addMultiMedia();
    vector<FZZOFDMultiMedia*> * getMultiMediaList();
    
protected:
    FZZOFDMultiMedias();
private:
 
    vector<FZZOFDMultiMedia*> m_FZZOFDMultiMedias;
};

#endif //FZZOFDMULTIMEDIAS_H
