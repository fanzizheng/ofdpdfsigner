//
//  Created by zizheng fan on 2023/09/12
//
#ifndef FZZWDRAWINGGRIDVERTICALSPACING_H
#define FZZWDRAWINGGRIDVERTICALSPACING_H

#include "office/FZZXMLElementObject.h"

#define FZZWDRAWINGGRIDVERTICALSPACING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWDRAWINGGRIDVERTICALSPACING_Name "drawingGridVerticalSpacing"

class FZZWDrawingGridVerticalSpacing : public FZZXMLElementObject
{
public:
    
    FZZWDrawingGridVerticalSpacing(FZZOfficeObject * parent);
    FZZWDrawingGridVerticalSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWDrawingGridVerticalSpacing(const FZZWDrawingGridVerticalSpacing& obj);
    virtual ~FZZWDrawingGridVerticalSpacing();
    
public:
    void setVal(string value);
    string getVal();
protected:
    FZZWDrawingGridVerticalSpacing();
private:
    
    
};

#endif //FZZWDRAWINGGRIDVERTICALSPACING_H
