//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDAUTHOR_H
#define FZZOFDAUTHOR_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDAUTHOR_Name "ofd:Author"

class FZZOFDAuthor : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDAuthor(FZZOFDXMLFileObject * parent);
    FZZOFDAuthor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAuthor(const FZZOFDAuthor& obj);
    virtual ~FZZOFDAuthor();
    
public:
    void setValue(string value);
    string getValue();

    
protected:
    FZZOFDAuthor();
private:
  
};

#endif //FZZOFDAUTHOR_H
