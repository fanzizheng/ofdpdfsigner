//
//  Created by zizheng fan on 2023/10/25
//
#ifndef FZZWSECTPT_H
#define FZZWSECTPT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocGrid.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCols.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgMar.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgSz.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFooterReference.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHeaderReference.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTitlePg.h"

#define FZZWSECTPT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWSECTPT_Name "sectPr"

class FZZWSectPr : public FZZXMLElementObject
{
public:
    
    FZZWSectPr(FZZOfficeObject * parent);
    FZZWSectPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWSectPr(const FZZWSectPr& obj);
    virtual ~FZZWSectPr();
    
public:
    void setRsidR(string value);
    string getRsidR();
    
    FZZWDocGrid * setDocGrid();
    FZZWDocGrid * getDocGrid();
    FZZWCols * setCols();
    FZZWCols * getCols();
    FZZWPgMar * setPgMar();
    FZZWPgMar * getPgMar();
    FZZWPgSz * setPgSz();
    FZZWPgSz * getPgSz();
    FZZWTitlePg * setTitlePg();
    FZZWTitlePg * getTitlePg();
    
    FZZWFooterReference * addFooterReference();
    vector<FZZWFooterReference*> * getFooterReferences();
    FZZWHeaderReference * addHeaderReference();
    vector<FZZWHeaderReference*> * getHeaderReferences();
protected:
    FZZWSectPr();
private:
    FZZWDocGrid * m_FZZWDocGrid;
    FZZWCols * m_FZZWCols;
    FZZWPgMar * m_FZZWPgMar;
    FZZWPgSz * m_FZZWPgSz;
    FZZWTitlePg * m_FZZWTitlePg;
    vector<FZZWFooterReference*> m_FZZWFooterReferences;
    vector<FZZWHeaderReference*> m_FZZWHeaderReferences;
};

#endif //FZZWSECTPT_H
