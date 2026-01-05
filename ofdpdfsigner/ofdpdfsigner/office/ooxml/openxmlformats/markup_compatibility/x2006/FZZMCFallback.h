//
//  Created by zizheng fan on 2023/05/15.
//
#ifndef FZZMCFALLBACK_H
#define FZZMCFALLBACK_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPict.h"


#define FZZMCFALLBACK_Find_Key "schemas.openxmlformats.org/markup-compatibility/2006"
#define FZZMCFALLBACK_Name "Fallback"

class FZZMCFallback : public FZZXMLElementObject
{
public:
    
    FZZMCFallback(FZZOfficeObject * parent);
    FZZMCFallback(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMCFallback(const FZZMCFallback& obj);
    virtual ~FZZMCFallback();
    
public:
    FZZWPict * addPict();
    vector<FZZWPict*> * getPictList();
public:

    
protected:
    FZZMCFallback();
private:
    vector<FZZWPict*> m_FZZWPicts;
};

#endif //FZZMCFALLBACK_H
