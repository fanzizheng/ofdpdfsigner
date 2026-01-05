//
//  Created by zizheng fan on 2023/08/09
//
#ifndef FZZAGRADFILL_H
#define FZZAGRADFILL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgsLst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlin.h"

#define FZZAGRADFILL_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZAGRADFILL_Name "gradFill"

class FZZAgradFill : public FZZXMLElementObject
{
public:
    
    FZZAgradFill(FZZOfficeObject * parent);
    FZZAgradFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAgradFill(const FZZAgradFill& obj);
    virtual ~FZZAgradFill();
    
public:
    void setRotWithShape(string value);
    string getRotWithShape();
    
    FZZAgsLst * setgsLst();
    FZZAgsLst * getgsLst();
    FZZAlin * setLin();
    FZZAlin * getLin();
protected:
    FZZAgradFill();
private:
    
    FZZAgsLst * m_CTgsLst;
    FZZAlin * m_CTlin;
};

#endif //FZZAGRADFILL_H
