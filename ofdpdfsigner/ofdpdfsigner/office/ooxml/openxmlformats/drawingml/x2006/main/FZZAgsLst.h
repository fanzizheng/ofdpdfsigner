//
//  Created by zizheng fan on 2023/08/08
//
#ifndef FZZAGSLIST_H
#define FZZAGSLIST_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgs.h"

#define FZZAGSLIST_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAGSLIST_Name "gsLst"

class FZZAgsLst : public FZZXMLElementObject
{
public:
    
    FZZAgsLst(FZZOfficeObject * parent);
    FZZAgsLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAgsLst(const FZZAgsLst& obj);
    virtual ~FZZAgsLst();
    
public:
    FZZAgs * addgs();
    vector<FZZAgs *>* getgss();
protected:
    FZZAgsLst();
private:
    
    vector<FZZAgs *> m_CTgss;
};

#endif //FZZAGSLIST_H
