//
//  Created by zizheng fan on 2023/10/26
//
#ifndef FZZWPGMAR_H
#define FZZWPGMAR_H

#include "office/FZZXMLElementObject.h"

#define FZZWPGMAR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPGMAR_Name "pgMar"

class FZZWPgMar : public FZZXMLElementObject
{
public:
    
    FZZWPgMar(FZZOfficeObject * parent);
    FZZWPgMar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPgMar(const FZZWPgMar& obj);
    virtual ~FZZWPgMar();
    
public:
    void setTop(string value);
    string getTop();
    void setRight(string value);
    string getRight();
    void setBottom(string value);
    string getBottom();
    void setLeft(string value);
    string getLeft();
    void setHeader(string value);
    string getHeader();
    void setFooter(string value);
    string getFooter();
    void setGutter(string value);
    string getGutter();
protected:
    FZZWPgMar();
private:
    
    
};

#endif //FZZWPGMAR_H
