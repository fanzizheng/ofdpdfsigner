//
//  Created by zizheng fan on 2023/11/10
//
#ifndef FZZWSDTCONTENT_H
#define FZZWSDTCONTENT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"

#define FZZWSDTCONTENT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSDTCONTENT_Name "sdtContent"

class FZZWSdtContent : public FZZXMLElementObject
{
public:
    
    FZZWSdtContent(FZZOfficeObject * parent);
    FZZWSdtContent(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSdtContent(const FZZWSdtContent& obj);
    virtual ~FZZWSdtContent();
    
public:
    FZZWP * setP();
    FZZWP * getP();
   
protected:
    FZZWSdtContent();
private:
    FZZWP * m_FZZWP;
    
};

#endif //FZZWSDTCONTENT_H
