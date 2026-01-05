//
//  Created by zizheng fan on 2023/04/11.
//
#ifndef FZZFOOTERXML_H
#define FZZFOOTERXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdt.h"

//#define FOOTERXML_FILENAME "footer"



class FZZFooterXML : public FZZOfficeObject
{
public:
    FZZFooterXML();
    FZZFooterXML(XMLDocument * doc);
    FZZFooterXML(const FZZFooterXML& obj);
    virtual ~FZZFooterXML();
    
 
public:
    FZZWP * setP();
    FZZWP * getP();
    FZZWSdt * setSdt();
    FZZWSdt * getSdt();
    
public:
 
protected:
    
private:
    FZZWP * m_FZZWP;
    FZZWSdt * m_FZZWSdt;
};

#endif //FZZFOOTERXML_H
