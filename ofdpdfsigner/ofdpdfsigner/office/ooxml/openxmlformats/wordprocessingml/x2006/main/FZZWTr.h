//
//  Created by zizheng fan on 2023/11/02
//
#ifndef FZZWTR_H
#define FZZWTR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTc.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.h"

#define FZZWTR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTR_Name "tr"

class FZZWTr : public FZZXMLElementObject
{
public:
    
    FZZWTr(FZZOfficeObject * parent);
    FZZWTr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTr(const FZZWTr& obj);
    virtual ~FZZWTr();
    
public:
    FZZWTc * addTc();
    vector<FZZWTc*> * getTcList();
    FZZWTrPr * setTrPr();
    FZZWTrPr * getTrPr();
public:
    void setDocXDir(FZZDocXDir * docXDir);
    FZZWTc * addColumn();
    size_t getColumnCount();
    FZZWTc * getColumn(int index);
protected:
    FZZWTr();
private:
    vector<FZZWTc*> m_FZZWTcs;
    FZZDocXDir * m_DocXDir;
    FZZWTrPr * m_FZZWTrPr;
};

#endif //FZZWTR_H
