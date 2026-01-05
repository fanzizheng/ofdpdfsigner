//
//  Created by zizheng fan on 2023/10/25
//
#ifndef FZZWPGSZ_H
#define FZZWPGSZ_H

#include "office/FZZXMLElementObject.h"

#define FZZWPGSZ_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPGSZ_Name "pgSz"

class FZZWPgSz : public FZZXMLElementObject
{
public:
    
    FZZWPgSz(FZZOfficeObject * parent);
    FZZWPgSz(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPgSz(const FZZWPgSz& obj);
    virtual ~FZZWPgSz();
    
public:
    void setW(string value);
    string getW();
    void setH(string value);
    string getH();
protected:
    FZZWPgSz();
private:
    
    
};

#endif //FZZWPGSZ_H
