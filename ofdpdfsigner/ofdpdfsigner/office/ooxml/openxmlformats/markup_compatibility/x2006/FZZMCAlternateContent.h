//
//  Created by zizheng fan on 2023/05/12.
//
#ifndef FZZMCALTERNATECONTENT_H
#define FZZMCALTERNATECONTENT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCFallback.h"
#include "office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCChoice.h"

#define FZZMCALTERNATECONTENT_Find_Key "schemas.openxmlformats.org/markup-compatibility/2006"
#define FZZMCALTERNATECONTENT_Name "AlternateContent"

class FZZMCAlternateContent : public FZZXMLElementObject
{
public:
    
    FZZMCAlternateContent(FZZOfficeObject * parent);
    FZZMCAlternateContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZMCAlternateContent(const FZZMCAlternateContent& obj);
    virtual ~FZZMCAlternateContent();
    
public:
   
    FZZMCFallback * setFallback();
    FZZMCFallback * getFallback();
    FZZMCChoice * setChoice();
    FZZMCChoice * getChoice();
public:

    
protected:
    FZZMCAlternateContent();
private:
    FZZMCFallback * m_FZZMCFallback;
    FZZMCChoice * m_FZZMCChoice;

};

#endif //FZZMCALTERNATECONTENT_H
