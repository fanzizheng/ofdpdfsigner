//
//  Created by zizheng fan on 2023/08/31
//
#ifndef FZZWBODY_H
#define FZZWBODY_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSectPr.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTbl.h"

#define FZZWBody_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWBody_Name "body"

struct PageElement {
    string type;
    long pageWidth;
    long pageHeight;
    
    long pgMar_Top;
    long pgMar_Right;
    long pgMar_Bottom;
    long pgMar_Left;
    long pgMar_Header;
    long pgMar_Footer;
    long pgMar_Gutter;
    
    long colsSpace;
    long colsNum;
    
    string docGrid_type;
    long docGrid_value;
    bool titlePg;
    
    FZZXMLElementObject * object;
    
    bool isHaveHeader;
    bool isHaveFooter;
    bool isHaveHeaderOrFooter_tmp;
    
//    string footer_Default_Type;
//    string footer_Even_Type;
//    string footer_First_Type;
//    string header_Default_Type;
//    string header_Even_Type;
//    string header_First_Type;
    
    string footer_Default_rid;
    string footer_Even_rid;
    string footer_First_rid;
    string header_Default_rid;
    string header_Even_rid;
    string header_First_rid;
};

class FZZWBody : public FZZXMLElementObject
{
public:
    
    FZZWBody(FZZOfficeObject * parent);
    FZZWBody(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWBody(const FZZWBody& obj);
    virtual ~FZZWBody();
    //static CTBody* getInstance(XMLDocument* doc, XMLElement* ele);
public:
    FZZWSectPr * setSectPr();
    FZZWSectPr * getSectPr();
    
    FZZWP * addP();
    vector<FZZWP*> * getPList();
    FZZWTbl * addTable();
    vector<FZZWTbl*> * getTableList();
public:
    vector<PageElement*>* getPageElements();
protected:
    FZZWBody();
private:
    void RefreshAllPageElements(FZZWSectPr * ctwSectPr);
    void RefreshAllPageElements_HeaderAndFooter(vector<FZZWFooterReference*> * ctwFooterList,vector<FZZWHeaderReference*> * ctwHeaderList);
private:
    FZZWSectPr * m_FZZWSectPr;
    vector<FZZWP*> m_FZZWPs;
    vector<FZZWTbl*> m_FZZWTbls;
    vector<PageElement*> m_AllPageElements;
    
    
};

#endif //FZZWBODY_H
