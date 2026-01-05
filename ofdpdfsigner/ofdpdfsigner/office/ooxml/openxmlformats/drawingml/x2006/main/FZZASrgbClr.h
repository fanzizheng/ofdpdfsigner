//
//  Created by zizheng fan on 2023/08/18
//
#ifndef FZZASRGBCLR_H
#define FZZASRGBCLR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAalpha.h"

#define FZZASRGBCLR_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASRGBCLR_Name "srgbClr"

class FZZASrgbClr : public FZZXMLElementObject
{
public:
    
    FZZASrgbClr(FZZOfficeObject * parent);
    FZZASrgbClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZASrgbClr(const FZZASrgbClr& obj);
    virtual ~FZZASrgbClr();
    
public:
    void setVal(string value);
    string getVal();
    
    FZZAalpha * setAlpha();
    FZZAalpha * getAlpha();
protected:
    FZZASrgbClr();
private:
    
    FZZAalpha * m_CTalpha;
};

#endif //FZZASRGBCLR_H
