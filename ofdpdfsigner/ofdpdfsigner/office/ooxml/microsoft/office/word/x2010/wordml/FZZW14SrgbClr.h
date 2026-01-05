//
//  Created by zizheng fan on 2023/05/08.
//
#ifndef FZZW14SRGBCLR_H
#define FZZW14SRGBCLR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14Alpha.h"

#define FZZW14SRGBCLR_Find_Key "schemas.microsoft.com/office/word/2010/wordml"
#define FZZW14SRGBCLR_Name "srgbClr"

class FZZW14SrgbClr : public FZZXMLElementObject
{
public:
    
    FZZW14SrgbClr(FZZOfficeObject * parent);
    FZZW14SrgbClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW14SrgbClr(const FZZW14SrgbClr& obj);
    virtual ~FZZW14SrgbClr();
    
public:
    void setVal(string value);
    string getVal();
    
    FZZW14Alpha * setAlpha();
    FZZW14Alpha * getAlpha();
    
protected:
    FZZW14SrgbClr();
private:
    
    FZZW14Alpha * m_FZZW14Alpha;
};

#endif //FZZW14SRGBCLR_H
