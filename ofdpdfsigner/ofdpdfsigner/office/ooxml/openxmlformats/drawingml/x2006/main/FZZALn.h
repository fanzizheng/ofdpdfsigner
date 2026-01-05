//
//  Created by zizheng fan on 2023/07/24
//
#ifndef FZZALN_H
#define FZZALN_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAprstDash.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAmiter.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsolidFill.h"

#define FZZALN_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZALN_Name "ln"

class FZZALn : public FZZXMLElementObject
{
public:
    
    FZZALn(FZZOfficeObject * parent);
    FZZALn(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZALn(const FZZALn& obj);
    virtual ~FZZALn();
    
public:
    void setW(string value);
    string getW();
    void setCap(string value);
    string getCap();
    void setCmpd(string value);
    string getCmpd();
    void setAlgn(string value);
    string getAlgn();
    
    FZZAsolidFill * setSolidFill();
    FZZAsolidFill * getSolidFill();
    FZZAmiter * setMiter();
    FZZAmiter * getMiter();
    FZZAprstDash * setPrstDash();
    FZZAprstDash * getPrstDash();
protected:
    FZZALn();
private:
    FZZAsolidFill * m_CTsolidFill;
    FZZAmiter * m_CTmiter;
    FZZAprstDash * m_CTprstDash;
};

#endif //FZZALN_H
