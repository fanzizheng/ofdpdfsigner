//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDCOMPOSITEGRAPHICUNITS_H
#define FZZOFDCOMPOSITEGRAPHICUNITS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDBaseRes.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDVectorG.h"

#define FZZOFDCOMPOSITEGRAPHICUNITS_Name "ofd:CompositeGraphicUnits"

class FZZOFDCompositeGraphicUnits : public FZZOFDXMLElementObject , public FZZOFDBaseRes
{
public:
    
    FZZOFDCompositeGraphicUnits(FZZOFDXMLFileObject * parent);
    FZZOFDCompositeGraphicUnits(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCompositeGraphicUnits(const FZZOFDCompositeGraphicUnits& obj);
    virtual ~FZZOFDCompositeGraphicUnits();
    
public:
    FZZOFDVectorG * addVectorG();
    vector<FZZOFDVectorG*> * getVectorGList();
    
protected:
    FZZOFDCompositeGraphicUnits();
private:
 
    vector<FZZOFDVectorG*> m_FZZOFDVectorGs;
};

#endif //FZZOFDCOMPOSITEGRAPHICUNITS_H
