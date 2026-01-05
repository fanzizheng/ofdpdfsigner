//
//  Created by zizheng fan on 2023/04/17.
//
#ifndef FZZVFORMULAS_H
#define FZZVFORMULAS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/vml/FZZVF.h"


#define FZZVFORMULAS_Find_Key "schemas-microsoft-com:vml"
#define FZZVFORMULAS_Name "formulas"

class FZZVFormulas : public FZZXMLElementObject
{
public:
    
    FZZVFormulas(FZZOfficeObject * parent);
    FZZVFormulas(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZVFormulas(const FZZVFormulas& obj);
    virtual ~FZZVFormulas();
    
public:
    FZZVF * addF();
    vector<FZZVF*> * getFList();
protected:
    FZZVFormulas();
private:
    vector<FZZVF *> m_FZZVFList;
    
};

#endif //FZZVFORMULAS_H
