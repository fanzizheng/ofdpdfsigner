//
//  Created by zizheng fan on 2023/11/08
//
#ifndef FZZWTRPR_H
#define FZZWTRPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrHeight.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblHeader.h"


#define FZZWTRPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTRPR_Name "trPr"



class FZZWTrPr : public FZZXMLElementObject
{
public:
    
    FZZWTrPr(FZZOfficeObject * parent);
    FZZWTrPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTrPr(const FZZWTrPr& obj);
    virtual ~FZZWTrPr();
public:
    FZZWTrHeight * setTrHeight();
    FZZWTrHeight * getTrHeight();
    FZZWTblHeader * setTblHeader();
    FZZWTblHeader * getTblHeader();
    
protected:
    FZZWTrPr();
private:
    FZZWTrHeight * m_FZZWTrHeight;
    FZZWTblHeader * m_FZZWTblHeader;
};

#endif //FZZWTRPR_H
