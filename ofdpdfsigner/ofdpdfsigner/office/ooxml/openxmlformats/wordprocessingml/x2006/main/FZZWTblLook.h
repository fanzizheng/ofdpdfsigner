//
//  Created by zizheng fan on 2023/11/06
//
#ifndef FZZWTBLLOOK_H
#define FZZWTBLLOOK_H

#include "office/FZZXMLElementObject.h"

#define FZZWTBLLOOK_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLLOOK_Name "tblLook"

class FZZWTblLook : public FZZXMLElementObject
{
public:
    
    FZZWTblLook(FZZOfficeObject * parent);
    FZZWTblLook(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblLook(const FZZWTblLook& obj);
    virtual ~FZZWTblLook();
    
public:
    void setVal(string value);
    string getVal();
    void setFirstRow(string value);
    string getFirstRow();
    void setLastRow(string value);
    string getLastRow();
    void setFirstColumn(string value);
    string getFirstColumn();
    void setLastColumn(string value);
    string getLastColumn();
    void setNoHBand(string value);
    string getNoHBand();
    void setNoVBand(string value);
    string getNoVBand();
    
protected:
    FZZWTblLook();
private:
    
    
};

#endif //FZZWTBLLOOK_H
