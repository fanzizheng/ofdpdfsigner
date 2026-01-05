//
//  Created by zizheng fan on 2023/07/19
//
#ifndef FZZAEFFECTLST_H
#define FZZAEFFECTLST_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAouterShdw.h"

#define FZZAEFFECTLST_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAEFFECTLST_Name "effectLst"

class FZZAeffectLst : public FZZXMLElementObject
{
public:
    
    FZZAeffectLst(FZZOfficeObject * parent);
    FZZAeffectLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAeffectLst(const FZZAeffectLst& obj);
    virtual ~FZZAeffectLst();
  
public:
    FZZAouterShdw* addOuterShdw();
    vector<FZZAouterShdw*> * getOuterShdws();
protected:
    FZZAeffectLst();
private:
    vector<FZZAouterShdw*> m_outerShdws;
    
};

#endif //FZZAEFFECTLST_H
