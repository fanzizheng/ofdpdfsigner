//
//  Created by zizheng fan on 2023/08/28
//
#ifndef FZZAEXTRACLRSCHEMELST_H
#define FZZAEXTRACLRSCHEMELST_H

#include "office/FZZXMLElementObject.h"

#define FZZAEXTRACLRSCHEMELST_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAEXTRACLRSCHEMELST_Name "extraClrSchemeLst"

class FZZAExtraClrSchemeLst : public FZZXMLElementObject
{
public:
    
    FZZAExtraClrSchemeLst(FZZOfficeObject * parent);
    FZZAExtraClrSchemeLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAExtraClrSchemeLst(const FZZAExtraClrSchemeLst& obj);
    virtual ~FZZAExtraClrSchemeLst();
    
public:
    
protected:
    FZZAExtraClrSchemeLst();
private:
    
    
};

#endif //FZZAEXTRACLRSCHEMELST_H
