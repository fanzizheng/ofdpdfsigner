//
//  Created by zizheng fan on 2023/09/11
//
#ifndef FZZWZOOM_H
#define FZZWZOOM_H

#include "office/FZZXMLElementObject.h"

#define FZZWZOOM_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWZOOM_Name "zoom"

class FZZWZoom : public FZZXMLElementObject
{
public:
    
    FZZWZoom(FZZOfficeObject * parent);
    FZZWZoom(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWZoom(const FZZWZoom& obj);
    virtual ~FZZWZoom();
    
public:
    void setPercent(string value);
    string getPercent();
    
protected:
    FZZWZoom();
private:
    
    
};

#endif //FZZWZOOM_H
