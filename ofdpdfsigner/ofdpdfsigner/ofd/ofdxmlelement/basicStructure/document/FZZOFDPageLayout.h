//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDPAGELAYOUT_H
#define FZZOFDPAGELAYOUT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPAGELAYOUT_Name "ofd:PageLayout"

class FZZOFDPageLayout : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        
        OnePage = 0,
        
        OneColumn = 1,
        
        TwoPageL = 2,
        
        TwoColumnL = 3,
       
        TwoPageR = 4,
       
        TwoColumnR = 5
    } TYPE;
public:
    
    FZZOFDPageLayout(FZZOFDXMLFileObject * parent);
    FZZOFDPageLayout(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageLayout(const FZZOFDPageLayout& obj);
    virtual ~FZZOFDPageLayout();
    
public:
    void setType(FZZOFDPageLayout::TYPE value);
    FZZOFDPageLayout::TYPE getType();
    
    
protected:
    FZZOFDPageLayout();
private:
    
};

#endif //FZZOFDPAGELAYOUT_H
