//
//  Created by zizheng fan on 2023/11/14
//
#ifndef FZZWTBLPPR_H
#define FZZWTBLPPR_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLPPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLPPR_Name "tblpPr"

class FZZWTblpPr : public FZZXMLElementObject
{
public:
    
    FZZWTblpPr(FZZOfficeObject * parent);
    FZZWTblpPr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblpPr(const FZZWTblpPr& obj);
    virtual ~FZZWTblpPr();
    
public:
    void setVertAnchor(string value);
    string getVertAnchor();
    void setHorzAnchor(string value);
    string getHorzAnchor();
    void setTblpY(string value);
    string getTblpY();
    void setTblpX(string value);
    string getTblpX();
    
    void setLeftFromText(string value);
    string getLeftFromText();
    void setRightFromText(string value);
    string getRightFromText();
    void setTopFromText(string value);
    string getTopFromText();
    void setBottomFromText(string value);
    string getBottomFromText();
//    void setValue(string value);
//    string getValue();
    
protected:
    FZZWTblpPr();
private:
    
    
};

#endif //FZZWTBLPPR_H
