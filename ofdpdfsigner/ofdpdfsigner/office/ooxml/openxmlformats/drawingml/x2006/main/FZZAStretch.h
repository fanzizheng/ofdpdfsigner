//
//  Created by zizheng fan on 2023/07/10
//
#ifndef FZZASTRETCH_H
#define FZZASTRETCH_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRect.h"

#define FZZASTRETCH_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZASTRETCH_Name "stretch"

class FZZAStretch : public FZZXMLElementObject
{
public:
    
    FZZAStretch(FZZOfficeObject * parent);
    FZZAStretch(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAStretch(const FZZAStretch& obj);
    virtual ~FZZAStretch();
    
public:
//    void setEmbed(string value);
//    string getEmbed();

    FZZAFillRect * setFillRect();
    FZZAFillRect * getFillRect();
protected:
    FZZAStretch();
private:
  
    FZZAFillRect * m_FZZAFillRect;
};

#endif //FZZASTRETCH_H
