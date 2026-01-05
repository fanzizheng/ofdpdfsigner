//
//  Created by zizheng fan on 2023/07/21
//
#ifndef FZZAOUTERSHDW_H
#define FZZAOUTERSHDW_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.h"


#define FZZAOUTERSHDW_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAOUTERSHDW_Name "outerShdw"

class FZZAouterShdw : public FZZXMLElementObject
{
public:
    
    FZZAouterShdw(FZZOfficeObject * parent);
    FZZAouterShdw(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAouterShdw(const FZZAouterShdw& obj);
    virtual ~FZZAouterShdw();
    
public:
    void setBlurRad(string value);
    string getBlurRad();
    void setDist(string value);
    string getDist();
    void setDir(string value);
    string getDir();
    void setAlgn(string value);
    string getAlgn();
    void setRotWithShape(string value);
    string getRotWithShape();
    
    FZZASrgbClr * setSrgbClr();
    FZZASrgbClr * getSrgbClr();

protected:
    FZZAouterShdw();
private:
    FZZASrgbClr * m_CTSrgbClr;
    
};

#endif //FZZAOUTERSHDW_H
