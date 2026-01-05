//
//  Created by zizheng fan on 2023/11/09
//
#ifndef FZZWPBDR_H
#define FZZWPBDR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRight.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBottom.h"

#define FZZWPBDR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWPBDR_Name "pBdr"

class FZZWPBdr : public FZZXMLElementObject
{
public:
    
    FZZWPBdr(FZZOfficeObject * parent);
    FZZWPBdr(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWPBdr(const FZZWPBdr& obj);
    virtual ~FZZWPBdr();
    
public:
    FZZWTop * setTop();
    FZZWTop * getTop();
    FZZWRight * setRight();
    FZZWRight * getRight();
    FZZWLeft * setLeft();
    FZZWLeft * getLeft();
    FZZWBottom * setBottom();
    FZZWBottom * getBottom();
   
protected:
    FZZWPBdr();
private:
    FZZWTop * m_FZZWTop;
    FZZWRight * m_FZZWRight;
    FZZWLeft * m_FZZWLeft;
    FZZWBottom * m_FZZWBottom;
    
};

#endif //FZZWPBDR_H
