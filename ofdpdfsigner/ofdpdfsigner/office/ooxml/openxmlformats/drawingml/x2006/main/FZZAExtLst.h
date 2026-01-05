//
//  Created by zizheng fan on 2023/08/28
//
#ifndef FZZAEXTLST_H
#define FZZAEXTLST_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExt.h"

#define FZZAEXTLST_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAEXTLST_Name "extLst"

class FZZAExtLst : public FZZXMLElementObject
{
public:
    
    FZZAExtLst(FZZOfficeObject * parent);
    FZZAExtLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAExtLst(const FZZAExtLst& obj);
    virtual ~FZZAExtLst();
    
public:
    FZZAExt* addExt();
    vector<FZZAExt*> * getExtList();
protected:
    FZZAExtLst();
private:
    vector<FZZAExt*> m_ExtList;
    
};

#endif //FZZAEXTLST_H
