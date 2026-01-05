//
//  Created by zizheng fan on 2023/05/06.
//
#ifndef FZZWPSSPPR_H
#define FZZWPSSPPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAXfrm.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstGeom.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZALn.h"

#define FZZWPSSPPR_Find_Key "schemas.microsoft.com/office/word/2010/wordprocessingShape"
#define FZZWPSSPPR_Name "spPr"

class FZZWPSSpPr : public FZZXMLElementObject
{
public:
    
    FZZWPSSpPr(FZZOfficeObject * parent);
    FZZWPSSpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPSSpPr(const FZZWPSSpPr& obj);
    virtual ~FZZWPSSpPr();
    
public:
    FZZAXfrm * setXfrm();
    FZZAXfrm * getXfrm();
    FZZAPrstGeom * setPrstGeom();
    FZZAPrstGeom * getPrstGeom();
    FZZALn * setLn();
    FZZALn * getLn();

protected:
    FZZWPSSpPr();
private:
    FZZAXfrm * m_FZZAXfrm;
    FZZAPrstGeom * m_FZZAPrstGeom;
    FZZALn * m_CTln;
    
};

#endif //FZZWPSSPPR_H
