//
//  Created by zizheng fan on 2023/08/21
//
#ifndef FZZASYSCLR_H
#define FZZASYSCLR_H

#include "office/FZZXMLElementObject.h"


#define FZZASYSCLR_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"
#define FZZASYSCLR_Name "sysClr"

class FZZASysClr : public FZZXMLElementObject
{
public:
    
    FZZASysClr(FZZOfficeObject * parent);
    FZZASysClr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZASysClr(const FZZASysClr& obj);
    virtual ~FZZASysClr();
    
public:
    void setVal(string value);
    string getVal();
    void setLastClr(string value);
    string getLastClr();
protected:
    FZZASysClr();
private:
    
    
};

#endif //FZZASYSCLR_H
