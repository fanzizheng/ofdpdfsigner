//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDTEMPLATE_H
#define FZZOFDTEMPLATE_H

#include "ofd/FZZOFDXMLElementObject.h"

#define FZZOFDTEMPLATE_Name "ofd:Template"



class FZZOFDTemplate : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDTemplate(FZZOFDXMLFileObject * parent);
    FZZOFDTemplate(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTemplate(const FZZOFDTemplate& obj);
    virtual ~FZZOFDTemplate();
    
public:
    void setTemplateID(string value);
    string getTemplateID();
    void setTemplateID(long value);
    long getTemplateID_long();
    
    void setZOrder(Type zOrder);
    Type getZOrder();
    
protected:
    FZZOFDTemplate();
private:
    
};

#endif //FZZOFDTEMPLATE_H
