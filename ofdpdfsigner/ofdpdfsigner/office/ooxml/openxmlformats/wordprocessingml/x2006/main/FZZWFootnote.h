//
//  Created by zizheng fan on 2023/11/09
//
#ifndef FZZWFOOTNOTE_H
#define FZZWFOOTNOTE_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"


#define FZZWFOOTNOTE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFOOTNOTE_Name "footnote"

class FZZWFootnote : public FZZXMLElementObject
{
public:
    
    FZZWFootnote(FZZOfficeObject * parent);
    FZZWFootnote(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFootnote(const FZZWFootnote& obj);
    virtual ~FZZWFootnote();
    
public:
    void setType(string value);
    string getType();
    
    void setId(string value);
    string getId();
    
    FZZWP * setP();
    FZZWP * getP();
    
protected:
    FZZWFootnote();
private:
    FZZWP * m_FZZWP;
    
};

#endif //FZZWFOOTNOTE_H
