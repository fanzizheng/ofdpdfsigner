//
//  Created by zizheng fan on 2023/07/07
//
#ifndef FZZAPRSTGEOM_H
#define FZZAPRSTGEOM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAAvLst.h"

#define FZZAPRSTGEOM_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAPRSTGEOM_Name "prstGeom"

class FZZAPrstGeom : public FZZXMLElementObject
{
public:
    
    FZZAPrstGeom(FZZOfficeObject * parent);
    FZZAPrstGeom(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAPrstGeom(const FZZAPrstGeom& obj);
    virtual ~FZZAPrstGeom();
    
public:
    void setPrst(string value);
    string getPrst();

    FZZAAvLst * setAvLst();
    FZZAAvLst * getAvLst();
protected:
    FZZAPrstGeom();
private:
  
    FZZAAvLst * m_FZZAAvLst;
};

#endif //FZZAPRSTGEOM_H
