//
//  Created by zizheng fan on 2023/11/21
//
#ifndef FZZWNUM_H
#define FZZWNUM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNumId.h"

#define FZZWNUM_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWNUM_Name "num"



class FZZWNum : public FZZXMLElementObject
{
public:
    
    FZZWNum(FZZOfficeObject * parent);
    FZZWNum(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWNum(const FZZWNum& obj);
    virtual ~FZZWNum();
    
public:
    FZZWAbstractNumId * setAbstractNumId();
    FZZWAbstractNumId * getAbstractNumId();

    void setNumId(string value);
    string getNumId();
    
protected:
    FZZWNum();
private:
    FZZWAbstractNumId* m_FZZWAbstractNumId;

    
};

#endif //FZZWNUM_H
