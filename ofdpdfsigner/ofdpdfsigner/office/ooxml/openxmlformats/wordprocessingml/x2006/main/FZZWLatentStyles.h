//
//  Created by zizheng fan on 2023/10/17
//
#ifndef FZZWLATENTSTYLES_H
#define FZZWLATENTSTYLES_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLsdException.h"


#define FZZWLATENTSTYLES_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWLATENTSTYLES_Name "latentStyles"

class FZZWLatentStyles : public FZZXMLElementObject
{
public:
    
    FZZWLatentStyles(FZZOfficeObject * parent);
    FZZWLatentStyles(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWLatentStyles(const FZZWLatentStyles& obj);
    virtual ~FZZWLatentStyles();
    
public:
    void setDefLockedState(string value);
    string getDefLockedState();
    void setDefUIPriority(string value);
    string getDefUIPriority();
    void setDefSemiHidden(string value);
    string getDefSemiHidden();
    void setDefUnhideWhenUsed(string value);
    string getDefUnhideWhenUsed();
    void setDefQFormat(string value);
    string getDefQFormat();
    void setCount(string value);
    string getCount();
    
    FZZWLsdException * addFZZWLsdException();
    vector<FZZWLsdException*> * getFZZWLsdExceptions();


protected:
    FZZWLatentStyles();
private:
    vector<FZZWLsdException*> m_FZZWLsdExceptions;
    
};

#endif //FZZWLATENTSTYLES_H
