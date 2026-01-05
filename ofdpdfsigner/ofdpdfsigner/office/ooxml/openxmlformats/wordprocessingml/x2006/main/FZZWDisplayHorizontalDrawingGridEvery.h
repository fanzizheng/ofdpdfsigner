//
//  Created by zizheng fan on 2023/09/13
//
#ifndef FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_H
#define FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_H

#include "office/FZZXMLElementObject.h"

#define FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_Name "displayHorizontalDrawingGridEvery"

class FZZWDisplayHorizontalDrawingGridEvery : public FZZXMLElementObject
{
public:
    
    FZZWDisplayHorizontalDrawingGridEvery(FZZOfficeObject * parent);
    FZZWDisplayHorizontalDrawingGridEvery(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDisplayHorizontalDrawingGridEvery(const FZZWDisplayHorizontalDrawingGridEvery& obj);
    virtual ~FZZWDisplayHorizontalDrawingGridEvery();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWDisplayHorizontalDrawingGridEvery();
private:
    
    
};

#endif //FZZWDISPLAYHORIZONTALDRAWINGGRIDEVERY_H
