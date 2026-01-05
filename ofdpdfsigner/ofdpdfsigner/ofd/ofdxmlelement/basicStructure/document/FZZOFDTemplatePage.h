//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDTEMPLATEPAGE_H
#define FZZOFDTEMPLATEPAGE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTEMPLATEPAGE_Name "ofd:TemplatePage"

class FZZOFDTemplatePage : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDTemplatePage(FZZOFDXMLFileObject * parent);
    FZZOFDTemplatePage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTemplatePage(const FZZOFDTemplatePage& obj);
    virtual ~FZZOFDTemplatePage();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setName(string value);
    string getName();
    void setBaseLoc(string value);
    string getBaseLoc();
    void setZOrder(Type value);
    Type getZOrder();
protected:
    FZZOFDTemplatePage();
private:
    
};

#endif //FZZOFDTEMPLATEPAGE_H
