//
//  Created by zizheng fan on 2023/09/12
//
#ifndef FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_H
#define FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_H

#include "office/FZZXMLElementObject.h"

#define FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_Name "displayVerticalDrawingGridEvery"

class FZZWDisplayVerticalDrawingGridEvery : public FZZXMLElementObject
{
public:
    
    FZZWDisplayVerticalDrawingGridEvery(FZZOfficeObject * parent);
    FZZWDisplayVerticalDrawingGridEvery(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDisplayVerticalDrawingGridEvery(const FZZWDisplayVerticalDrawingGridEvery& obj);
    virtual ~FZZWDisplayVerticalDrawingGridEvery();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWDisplayVerticalDrawingGridEvery();
private:
    
    
};

#endif //FZZWDISPLAYVERTICALDRAWINGGRIDEVERY_H
