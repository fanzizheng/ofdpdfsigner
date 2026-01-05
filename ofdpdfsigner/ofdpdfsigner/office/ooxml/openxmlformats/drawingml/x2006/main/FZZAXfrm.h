//
//  Created by zizheng fan on 2023/07/11
//
#ifndef FZZAXFRM_H
#define FZZAXFRM_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAOff.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExt.h"

#define FZZAXFRM_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAXFRM_Name "xfrm"

class FZZAXfrm : public FZZXMLElementObject
{
public:
    
    FZZAXfrm(FZZOfficeObject * parent);
    FZZAXfrm(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAXfrm(const FZZAXfrm& obj);
    virtual ~FZZAXfrm();
    
public:
    void setRot(string value);
    string getRot();

    FZZAOff * setOff();
    FZZAOff * getOff();
    FZZAExt * setExt();
    FZZAExt * getExt();
protected:
    FZZAXfrm();
private:
  
    FZZAOff * m_FZZAOff;
    FZZAExt * m_FZZAExt;
};

#endif //FZZAXFRM_H
