//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDURI_H
#define FZZOFDURI_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDURI_Name "ofd:URI"

class FZZOFDURI : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDURI(FZZOFDXMLFileObject * parent);
    FZZOFDURI(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDURI(const FZZOFDURI& obj);
    virtual ~FZZOFDURI();
    
public:
    void setURI(string value);
    string getURI();
    void setBase(string value);
    string getBase();
    
protected:
    FZZOFDURI();
private:
    
};

#endif //FZZOFDURI_H
