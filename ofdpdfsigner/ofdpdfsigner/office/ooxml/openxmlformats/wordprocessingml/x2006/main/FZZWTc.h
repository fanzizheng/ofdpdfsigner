//
//  Created by zizheng fan on 2023/11/03
//
#ifndef FZZWTC_H
#define FZZWTC_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"

#define FZZWTC_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTC_Name "tc"

class FZZWTc : public FZZXMLElementObject
{
public:
    
    FZZWTc(FZZOfficeObject * parent);
    FZZWTc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTc(const FZZWTc& obj);
    virtual ~FZZWTc();
    
public:
    FZZWTcPr * setTcPr();
    FZZWTcPr * getTcPr();
    FZZWP * addParagraph();
    vector<FZZWP*> * getParagraphList();
public:
    void setDocXDir(FZZDocXDir * docXDir);
protected:
    FZZWTc();
private:
    FZZWTcPr * m_FZZWTcPr;
    //FZZWP * m_FZZWP;
    vector<FZZWP*> m_FZZWPs;
    FZZDocXDir * m_DocXDir;
};

#endif //FZZWTC_H
