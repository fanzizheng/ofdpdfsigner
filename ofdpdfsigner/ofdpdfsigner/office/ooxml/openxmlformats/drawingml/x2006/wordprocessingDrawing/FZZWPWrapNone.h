//
//  Created by zizheng fan on 2023/06/09
//
#ifndef FZZWPWRAPNONE_H
#define FZZWPWRAPNONE_H

#include "office/FZZXMLElementObject.h"


#define FZZWPWRAPNONE_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPWRAPNONE_Name "wrapNone"

class FZZWPWrapNone : public FZZXMLElementObject
{
public:
    
    FZZWPWrapNone(FZZOfficeObject * parent);
    FZZWPWrapNone(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPWrapNone(const FZZWPWrapNone& obj);
    virtual ~FZZWPWrapNone();
    
public:
    
    
    
protected:
    FZZWPWrapNone();
private:
    
    
};

#endif //FZZWPWRAPNONE_H
