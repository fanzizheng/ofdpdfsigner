//
//  Created by zizheng fan on 2023/11/15
//
#ifndef FZZWTBLSTYLEPR_H
#define FZZWTBLSTYLEPR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.h"

#define FZZWTBLSTYLEPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLSTYLEPR_Name "tblStylePr"

class FZZWTblStylePr : public FZZXMLElementObject
{
public:
    
    FZZWTblStylePr(FZZOfficeObject * parent);
    FZZWTblStylePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblStylePr(const FZZWTblStylePr& obj);
    virtual ~FZZWTblStylePr();
    
public:
    void setType(string value);
    string getType();
    
//    void setValue(string value);
//    string getValue();
    
    FZZWTrPr * setTrPr();
    FZZWTrPr * getTrPr();
    FZZWTblPr * setTblPr();
    FZZWTblPr * getTblPr();
    FZZWTcPr * setTcPr();
    FZZWTcPr * getTcPr();
    
protected:
    FZZWTblStylePr();
private:
    FZZWTrPr * m_FZZWTrPr;
    FZZWTblPr * m_FZZWTblPr;
    FZZWTcPr * m_FZZWTcPr;
    
};

#endif //FZZWTBLSTYLEPR_H
