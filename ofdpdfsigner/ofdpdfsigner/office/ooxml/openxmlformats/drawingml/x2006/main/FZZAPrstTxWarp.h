//
//  Created by zizheng fan on 2023/06/27
//
#ifndef FZZAPRSTTXWARP_H
#define FZZAPRSTTXWARP_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAAvLst.h"

#define FZZAPRSTTXWARP_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAPRSTTXWARP_Name "prstTxWarp"

class FZZAPrstTxWarp : public FZZXMLElementObject
{
public:
    FZZAPrstTxWarp(FZZOfficeObject * parent);
    FZZAPrstTxWarp(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAPrstTxWarp(const FZZAPrstTxWarp& obj);
    virtual ~FZZAPrstTxWarp();

public:
    void setPrst(string uri);
    string getPrst();
    
    FZZAAvLst * setAvLst();
    FZZAAvLst * getAvLst();
    
protected:
    FZZAPrstTxWarp();
private:
    FZZAAvLst * m_FZZAAvLst;
    
};

#endif //FZZAPRSTTXWARP_H
