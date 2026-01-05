//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWNUMPR_H
#define FZZWNUMPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWIlvl.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumId.h"

#define FZZWNUMPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNUMPR_Name "numPr"



class FZZWNumPr : public FZZXMLElementObject
{
public:
    
    FZZWNumPr(FZZOfficeObject * parent);
    FZZWNumPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNumPr(const FZZWNumPr& obj);
    virtual ~FZZWNumPr();
    
public:
    FZZWIlvl * setIlvl();
    FZZWIlvl * getIlvl();
    FZZWNumId * setNumId();
    FZZWNumId * getNumId();

protected:
    FZZWNumPr();
private:
    FZZWIlvl* m_FZZWIlvl;
    FZZWNumId * m_FZZWNumId;
    
};

#endif //FZZWNUMPR_H
