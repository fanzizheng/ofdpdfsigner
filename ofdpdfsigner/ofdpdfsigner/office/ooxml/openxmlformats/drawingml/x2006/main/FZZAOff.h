//
//  Created by zizheng fan on 2023/07/06
//
#ifndef FZZAOFF_H
#define FZZAOFF_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.h"

#define FZZAOFF_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAOFF_Name "off"

class FZZAOff : public FZZXMLElementObject
{
public:
    
    FZZAOff(FZZOfficeObject * parent);
    FZZAOff(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAOff(const FZZAOff& obj);
    virtual ~FZZAOff();
    
public:
    void setX(string value);
    string getX();
    void setY(string value);
    string getY();

//    FZZAExtLst * setExtLst();
//    FZZAExtLst * getExtLst();
protected:
    FZZAOff();
private:
  
    //FZZAExtLst * m_FZZAExtLst;
};

#endif //FZZAOFF_H
