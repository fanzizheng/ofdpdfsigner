//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDGOTOA_H
#define FZZOFDGOTOA_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDGOTOA_Name "ofd:GotoA"

class FZZOFDGotoA : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDGotoA(FZZOFDXMLFileObject * parent);
    FZZOFDGotoA(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDGotoA(const FZZOFDGotoA& obj);
    virtual ~FZZOFDGotoA();
    
public:
    void setAttachID(string value);
    string getAttachID();
    void setNewWindow(bool value);
    bool getNewWindow();
    
protected:
    FZZOFDGotoA();
private:
    
};

#endif //FZZOFDGOTOA_H
