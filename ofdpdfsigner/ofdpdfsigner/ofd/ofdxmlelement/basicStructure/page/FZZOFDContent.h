//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDCONTENT_H
#define FZZOFDCONTENT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"

#define FZZOFDCONTENT_Name "ofd:Content"



class FZZOFDContent : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDContent(FZZOFDXMLFileObject * parent);
    FZZOFDContent(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDContent(const FZZOFDContent& obj);
    virtual ~FZZOFDContent();
    
public:
    FZZOFDLayer* addLayer();
    vector<FZZOFDLayer*>* getLayerList();
    
    
protected:
    FZZOFDContent();
private:
    vector<FZZOFDLayer*> m_FZZOFDLayers;
};

#endif //FZZOFDCONTENT_H
