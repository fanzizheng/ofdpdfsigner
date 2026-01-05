//
//  Created by zizheng fan on 2023/07/12
//
#ifndef FZZABLIP_H
#define FZZABLIP_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.h"

#define FZZABLIP_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZABLIP_Name "blip"

class FZZABlip : public FZZXMLElementObject
{
public:
    
    FZZABlip(FZZOfficeObject * parent);
    FZZABlip(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZABlip(const FZZABlip& obj);
    virtual ~FZZABlip();
    
public:
    void setEmbed(string value);
    string getEmbed();

    FZZAExtLst * setExtLst();
    FZZAExtLst * getExtLst();
protected:
    FZZABlip();
private:
  
    FZZAExtLst * m_FZZAExtLst;
};

#endif //FZZABLIP_H
