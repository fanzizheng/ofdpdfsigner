//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDREGION_H
#define FZZOFDREGION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDArea.h"


#define FZZOFDREGION_Name "ofd:Region"

class FZZOFDRegion : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDRegion(FZZOFDXMLFileObject * parent);
    FZZOFDRegion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDRegion(const FZZOFDRegion& obj);
    virtual ~FZZOFDRegion();
    
public:
    FZZOFDArea * addArea();
    vector<FZZOFDArea*> * getAreaList();
protected:
    FZZOFDRegion();
private:
    vector<FZZOFDArea*> m_FZZOFDAreas;
};

#endif //FZZOFDREGION_H
