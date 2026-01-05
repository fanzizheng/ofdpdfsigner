//
//  Created by zizheng fan on 2023/10/30
//
#ifndef FZZWOPTIMIZEFORBROWSER_H
#define FZZWOPTIMIZEFORBROWSER_H

#include "office/FZZXMLElementObject.h"

#define FZZWOPTIMIZEFORBROWSER_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWOPTIMIZEFORBROWSER_Name "optimizeForBrowser"

class FZZWOptimizeForBrowser : public FZZXMLElementObject
{
public:
    
    FZZWOptimizeForBrowser(FZZOfficeObject * parent);
    FZZWOptimizeForBrowser(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWOptimizeForBrowser(const FZZWOptimizeForBrowser& obj);
    virtual ~FZZWOptimizeForBrowser();
    
public:
   
protected:
    FZZWOptimizeForBrowser();
private:
    
    
};

#endif //FZZWOPTIMIZEFORBROWSER_H
