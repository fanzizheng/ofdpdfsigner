//
//  Created by zizheng fan on 2023/07/15
//
#ifndef FZZAGRAPHICFRAMELOCKS_H
#define FZZAGRAPHICFRAMELOCKS_H

#include "office/FZZXMLElementObject.h"

#define FZZAGRAPHICFRAMELOCKS_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAGRAPHICFRAMELOCKS_Name "graphicFrameLocks"

class FZZAGraphicFrameLocks : public FZZXMLElementObject
{
public:
    
    FZZAGraphicFrameLocks(FZZOfficeObject * parent);
    FZZAGraphicFrameLocks(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAGraphicFrameLocks(const FZZAGraphicFrameLocks& obj);
    virtual ~FZZAGraphicFrameLocks();
    
public:
    void setNoChangeAspect(string value);
    string getNoChangeAspect();
    
    void setXmlnsA(string value);
    string getXmlnsA();
protected:
    FZZAGraphicFrameLocks();
private:
    
    
};

#endif //FZZAGRAPHICFRAMELOCKS_H
