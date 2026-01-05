//
//  Created by zizheng fan on 2023/04/12.
//
#ifndef FZZHEADERXML_H
#define FZZHEADERXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdt.h"

//#define HEADERXML_FILENAME "header"



class FZZHeaderXML : public FZZOfficeObject
{
public:
    FZZHeaderXML();
    FZZHeaderXML(XMLDocument * doc);
    FZZHeaderXML(const FZZHeaderXML& obj);
    virtual ~FZZHeaderXML();
    
 
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

#endif //FZZHEADERXML_H
