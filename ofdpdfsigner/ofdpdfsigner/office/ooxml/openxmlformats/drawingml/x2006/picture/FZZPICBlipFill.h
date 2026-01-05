//
//  Created by zizheng fan on 2023/05/31
//
#ifndef FZZPICBLIPFILL_H
#define FZZPICBLIPFILL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZABlip.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAStretch.h"

#define FZZPICBLIPFILL_Find_Key "schemas.openxmlformats.org/drawingml/2006/picture"

#define FZZPICBLIPFILL_Name "blipFill"

class FZZPICBlipFill : public FZZXMLElementObject
{
public:
    
    FZZPICBlipFill(FZZOfficeObject * parent);
    FZZPICBlipFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZPICBlipFill(const FZZPICBlipFill& obj);
    virtual ~FZZPICBlipFill();
    
public:
//    void setXmlnsPic(string value);
//    string getXmlnsPic();
    
    FZZABlip * setBlip();
    FZZABlip * getBlip();
    
    FZZAStretch * setStretch();
    FZZAStretch * getStretch();
protected:
    FZZPICBlipFill();
private:
    FZZABlip * m_FZZABlip;
    FZZAStretch * m_FZZAStretch;
};

#endif //FZZPICBLIPFILL_H
