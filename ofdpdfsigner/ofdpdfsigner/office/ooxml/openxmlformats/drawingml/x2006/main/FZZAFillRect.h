//
//  Created by zizheng fan on 2023/07/05
//
#ifndef FZZAFILLRECT_H
#define FZZAFILLRECT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.h"

#define FZZAFILLRECT_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAFILLRECT_Name "fillRect"

class FZZAFillRect : public FZZXMLElementObject
{
public:
    
    FZZAFillRect(FZZOfficeObject * parent);
    FZZAFillRect(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAFillRect(const FZZAFillRect& obj);
    virtual ~FZZAFillRect();
    
public:
    //void setEmbed(string value);
    //string getEmbed();

    //FZZAExtLst * setExtLst();
    //FZZAExtLst * getExtLst();
protected:
    FZZAFillRect();
private:
  
    //FZZAExtLst * m_FZZAExtLst;
};

#endif //FZZAFILLRECT_H
