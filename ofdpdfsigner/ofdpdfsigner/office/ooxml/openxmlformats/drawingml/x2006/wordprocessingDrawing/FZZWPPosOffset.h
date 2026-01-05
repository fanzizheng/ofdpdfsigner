//
//  Created by zizheng fan on 2023/06/14
//
#ifndef FZZWPPOSOFFSET_H
#define FZZWPPOSOFFSET_H

#include "office/FZZXMLElementObject.h"


#define FZZWPPOSOFFSET_Find_Key "schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing"
#define FZZWPPOSOFFSET_Name "posOffset"

class FZZWPPosOffset : public FZZXMLElementObject
{
public:
    
    FZZWPPosOffset(FZZOfficeObject * parent);
    FZZWPPosOffset(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPPosOffset(const FZZWPPosOffset& obj);
    virtual ~FZZWPPosOffset();
    
public:
    void setValue(string value);
    string getValue();
protected:
    FZZWPPosOffset();
private:
    
    
};

#endif //FZZWPPOSOFFSET_H
