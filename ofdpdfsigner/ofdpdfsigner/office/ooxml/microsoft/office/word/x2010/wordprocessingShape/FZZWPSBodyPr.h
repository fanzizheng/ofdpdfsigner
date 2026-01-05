//
//  Created by zizheng fan on 2023/04/28.
//
#ifndef FZZWPSBODYPR_H
#define FZZWPSBODYPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstTxWarp.h"


#define FZZWPSBODYPR_Find_Key "schemas.microsoft.com/office/word/2010/wordprocessingShape"
#define FZZWPSBODYPR_Name "bodyPr"

class FZZWPSBodyPr : public FZZXMLElementObject
{
public:
    
    FZZWPSBodyPr(FZZOfficeObject * parent);
    FZZWPSBodyPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSBodyPr(const FZZWPSBodyPr& obj);
    virtual ~FZZWPSBodyPr();
    
public:
    FZZAPrstTxWarp * setPrstTxWarp();
    FZZAPrstTxWarp * getPrstTxWarp();

protected:
    FZZWPSBodyPr();
private:
    FZZAPrstTxWarp * m_FZZAPrstTxWarp;
    
};

#endif //FZZWPSBODYPR_H
