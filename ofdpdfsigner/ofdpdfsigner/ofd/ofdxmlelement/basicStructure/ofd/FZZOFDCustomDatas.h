//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDCUSTOMDATAS_H
#define FZZOFDCUSTOMDATAS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomData.h"

#define FZZOFDCUSTOMDATAS_Name "ofd:CustomDatas"

class FZZOFDCustomDatas : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDCustomDatas(FZZOFDXMLFileObject * parent);
    FZZOFDCustomDatas(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCustomDatas(const FZZOFDCustomDatas& obj);
    virtual ~FZZOFDCustomDatas();
    
public:
    FZZOFDCustomData * addCustomData();
    vector<FZZOFDCustomData*> * getCustomDataList();
    
protected:
    FZZOFDCustomDatas();
private:
 
    vector<FZZOFDCustomData*> m_FZZOFDCustomDatas;
};

#endif //FZZOFDCUSTOMDATAS_H
