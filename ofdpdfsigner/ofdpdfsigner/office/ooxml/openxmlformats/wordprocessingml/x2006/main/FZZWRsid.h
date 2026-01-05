//
//  Created by zizheng fan on 2023/09/26
//
#ifndef FZZWRSID_H
#define FZZWRSID_H

#include "office/FZZXMLElementObject.h"

#define FZZWRSID_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWRSID_Name "rsid"

class FZZWRsid : public FZZXMLElementObject
{
public:
    
    FZZWRsid(FZZOfficeObject * parent);
    FZZWRsid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWRsid(const FZZWRsid& obj);
    virtual ~FZZWRsid();
    
public:
    void setVal(string value);
    string getVal();
public:
    static string ToString(unsigned int data);
    static unsigned int ToUInt(string data);
    static unsigned int GetCurrRsid();
    static string GetCurrRsid_String();
    static unsigned int GetCurrRsid_Next();
    static string GetCurrRsid_Next_String();

    static void SetCurrRsid(string rsid);
protected:
    FZZWRsid();
private:
    static unsigned int g_CurrRsid;
    
};

#endif //FZZWRSID_H
