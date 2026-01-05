//
//  Created by zizheng fan on 2023/06/06
//
#ifndef FZZPICSPPR_H
#define FZZPICSPPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAXfrm.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstGeom.h"

#define FZZPICSPPR_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICSPPR_Name "spPr"

class FZZPICSpPr : public FZZXMLElementObject
{
public:
    
    FZZPICSpPr(FZZOfficeObject * parent);
    FZZPICSpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICSpPr(const FZZPICSpPr& obj);
    virtual ~FZZPICSpPr();
    
public:
    //void setXmlnsPic(string value);
    //string getXmlnsPic();
    
    FZZAXfrm * setXfrm();
    FZZAXfrm * getXfrm();
    FZZAPrstGeom * setPrstGeom();
    FZZAPrstGeom * getPrstGeom();
protected:
    FZZPICSpPr();
private:
    FZZAXfrm * m_FZZAXfrm;
    FZZAPrstGeom * m_FZZAPrstGeom;
};

#endif //FZZPICSPPR_H
