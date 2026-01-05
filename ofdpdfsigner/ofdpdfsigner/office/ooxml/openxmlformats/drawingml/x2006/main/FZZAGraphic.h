//
//  Created by zizheng fan on 2023/07/13
//
#ifndef FZZAGRAPHIC_H
#define FZZAGRAPHIC_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicData.h"

#define FZZAGRAPHIC_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAGRAPHIC_Name "graphic"

class FZZAGraphic : public FZZXMLElementObject
{
public:
    
    FZZAGraphic(FZZOfficeObject * parent);
    FZZAGraphic(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAGraphic(const FZZAGraphic& obj);
    virtual ~FZZAGraphic();
    
public:
    void setXmlnsA(string value);
    string getXmlnsA();
    
    FZZAGraphicData * setGraphicData();
    FZZAGraphicData * getGraphicData();
protected:
    FZZAGraphic();
private:
    FZZAGraphicData * m_FZZAGraphicData;
    
};

#endif //FZZAGRAPHIC_H
