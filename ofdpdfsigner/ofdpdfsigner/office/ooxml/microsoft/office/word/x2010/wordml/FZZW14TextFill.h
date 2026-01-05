//
//  Created by zizheng fan on 2023/05/09.
//
#ifndef FZZW14TEXTFILL_H
#define FZZW14TEXTFILL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SolidFill.h"

#define FZZW14TEXTFILL_Find_Key "schemas.microsoft.com/office/word/2010/wordml"
#define FZZW14TEXTFILL_Name "textFill"

class FZZW14TextFill : public FZZXMLElementObject
{
public:
    
    FZZW14TextFill(FZZOfficeObject * parent);
    FZZW14TextFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW14TextFill(const FZZW14TextFill& obj);
    virtual ~FZZW14TextFill();
    
public:
    void setVal(string value);
    string getVal();
    
    FZZW14SolidFill * setSolidFill();
    FZZW14SolidFill * getSolidFill();
protected:
    FZZW14TextFill();
private:
    FZZW14SolidFill * m_FZZW14SolidFill;
    
};

#endif //FZZW14TEXTFILL_H
