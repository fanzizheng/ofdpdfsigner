//
//  Created by zizheng fan on 2023/11/16
//
#ifndef FZZWFRAMEPR_H
#define FZZWFRAMEPR_H

#include "office/FZZXMLElementObject.h"

#define FZZWFRAMEPR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWFRAMEPR_Name "framePr"

class FZZWFramePr : public FZZXMLElementObject
{
public:
    
    FZZWFramePr(FZZOfficeObject * parent);
    FZZWFramePr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWFramePr(const FZZWFramePr& obj);
    virtual ~FZZWFramePr();
    
public:
    void setWrap(string value);
    string getWrap();
    void setVAnchor(string value);
    string getVAnchor();
    void setHAnchor(string value);
    string getHAnchor();
    void setX(string value);
    string getX();
    void setY(string value);
    string getY();
    void setXAlign(string value);
    string getXAlign();
    void setYAlign(string value);
    string getYAlign();
protected:
    FZZWFramePr();
private:
    
    
};

#endif //FZZWFRAMEPR_H
