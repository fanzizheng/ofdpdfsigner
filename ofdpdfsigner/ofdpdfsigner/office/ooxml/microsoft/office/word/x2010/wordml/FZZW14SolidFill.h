//
//  Created by zizheng fan on 2023/05/08.
//
#ifndef FZZW14SOLIDFILL_H
#define FZZW14SOLIDFILL_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SrgbClr.h"

#define FZZW14SOLIDFILL_Find_Key "schemas.microsoft.com/office/word/2010/wordml"
#define FZZW14SOLIDFILL_Name "solidFill"

class FZZW14SolidFill : public FZZXMLElementObject
{
public:
    
    FZZW14SolidFill(FZZOfficeObject * parent);
    FZZW14SolidFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZW14SolidFill(const FZZW14SolidFill& obj);
    virtual ~FZZW14SolidFill();
    
public:
    void setVal(string value);
    string getVal();
    
    FZZW14SrgbClr * setSrgbClr();
    FZZW14SrgbClr * getSrgbClr();
protected:
    FZZW14SolidFill();
private:
    FZZW14SrgbClr * m_FZZW14SrgbClr;
    
};

#endif //FZZW14DOCID_H
