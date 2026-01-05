//
//  Created by zizheng fan on 2023/09/22
//
#ifndef FZZWADJUSTLINEHEIGHTINTABLE_H
#define FZZWADJUSTLINEHEIGHTINTABLE_H

#include "office/FZZXMLElementObject.h"

#define FZZWADJUSTLINEHEIGHTINTABLE_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWADJUSTLINEHEIGHTINTABLE_Name "adjustLineHeightInTable"

class FZZWAdjustLineHeightInTable : public FZZXMLElementObject
{
public:
    
    FZZWAdjustLineHeightInTable(FZZOfficeObject * parent);
    FZZWAdjustLineHeightInTable(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWAdjustLineHeightInTable(const FZZWAdjustLineHeightInTable& obj);
    virtual ~FZZWAdjustLineHeightInTable();
    
public:
    
protected:
    FZZWAdjustLineHeightInTable();
private:
    
    
};

#endif //FZZWADJUSTLINEHEIGHTINTABLE_H
