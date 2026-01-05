//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWENDNOTE_H
#define FZZWENDNOTE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"


#define FZZWENDNOTE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWENDNOTE_Name "endnote"

class FZZWEndnote : public FZZXMLElementObject
{
public:
    
    FZZWEndnote(FZZOfficeObject * parent);
    FZZWEndnote(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWEndnote(const FZZWEndnote& obj);
    virtual ~FZZWEndnote();
    
public:
    void setType(string value);
    string getType();
    
    void setId(string value);
    string getId();
    
    FZZWP * setP();
    FZZWP * getP();
    
protected:
    FZZWEndnote();
private:
    FZZWP * m_FZZWP;
    
};

#endif //FZZWENDNOTE_H
