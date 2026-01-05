//
//  Created by zizheng fan on 2023/09/28
//
#ifndef FZZWCLRSCHEMEMAPPING_H
#define FZZWCLRSCHEMEMAPPING_H

#include "office/FZZXMLElementObject.h"

#define FZZWCLRSCHEMEMAPPING_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCLRSCHEMEMAPPING_Name "clrSchemeMapping"

class FZZWClrSchemeMapping : public FZZXMLElementObject
{
public:
    
    FZZWClrSchemeMapping(FZZOfficeObject * parent);
    FZZWClrSchemeMapping(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWClrSchemeMapping(const FZZWClrSchemeMapping& obj);
    virtual ~FZZWClrSchemeMapping();
    
public:
    void setBg1(string value);
    string getBg1();
    void setBg2(string value);
    string getBg2();
    void setT1(string value);
    string getT1();
    void setT2(string value);
    string getT2();
    void setAccent1(string value);
    string getAccent1();
    void setAccent2(string value);
    string getAccent2();
    void setAccent3(string value);
    string getAccent3();
    void setAccent4(string value);
    string getAccent4();
    void setAccent5(string value);
    string getAccent5();
    void setAccent6(string value);
    string getAccent6();
    void setHyperlink(string value);
    string getHyperlink();
    void setFollowedHyperlink(string value);
    string getFollowedHyperlink();
    
protected:
    FZZWClrSchemeMapping();
private:
    
    
};

#endif //FZZWCLRSCHEMEMAPPING_H
