//
//  Created by zizheng fan on 2023/08/23
//
#ifndef FZZACLRSCHEME_H
#define FZZACLRSCHEME_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme_Item.h"

#define FZZACLRSCHEME_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZACLRSCHEME_Name "clrScheme"

class FZZAClrScheme : public FZZXMLElementObject
{
public:
    
    FZZAClrScheme(FZZOfficeObject * parent);
    FZZAClrScheme(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAClrScheme(const FZZAClrScheme& obj);
    virtual ~FZZAClrScheme();
  
public:
    void setName(string value);
    string getName();
    
    FZZAClrScheme_Item * setHlink();
    FZZAClrScheme_Item * getHlink();
    FZZAClrScheme_Item * setFolHlink();
    FZZAClrScheme_Item * getFolHlink();
    
    FZZAClrScheme_Item * addDk();
    FZZAClrScheme_Item * addLt();
    FZZAClrScheme_Item * addAccent();
protected:
    FZZAClrScheme();
private:
    int m_dkCount;
    int m_ltCount;
    int m_accentCount;
    FZZAClrScheme_Item * m_hlink;
    FZZAClrScheme_Item * m_folHlink;
    
    vector<FZZAClrScheme_Item *> m_dkList;
    vector<FZZAClrScheme_Item *> m_ltList;
    vector<FZZAClrScheme_Item *> m_accentList;
    
};

#endif //FZZACLRSCHEME_H
