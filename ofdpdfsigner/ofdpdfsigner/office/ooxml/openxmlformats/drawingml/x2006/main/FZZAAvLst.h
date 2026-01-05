//
//  Created by zizheng fan on 2023/07/04
//
#ifndef FZZAAVLST_H
#define FZZAAVLST_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGd.h"

#define FZZAAVLST_Find_Key "schemas.openxmlformats.org/drawingml/2006/main"

#define FZZAAVLST_Name "avLst"

class FZZAAvLst : public FZZXMLElementObject
{
public:
    
    FZZAAvLst(FZZOfficeObject * parent);
    FZZAAvLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZAAvLst(const FZZAAvLst& obj);
    virtual ~FZZAAvLst();
    
public:
    //void setEmbed(string value);
    //string getEmbed();

    FZZAGd * setGd();
    FZZAGd * getGd();
protected:
    FZZAAvLst();
private:
  
    FZZAGd * m_FZZAGd;
};

#endif //FZZAAVLST_H
