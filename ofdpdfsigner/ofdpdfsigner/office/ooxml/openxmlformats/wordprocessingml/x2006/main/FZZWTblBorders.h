//
//  Created by zizheng fan on 2023/11/07
//
#ifndef FZZWTBLBORDERS_H
#define FZZWTBLBORDERS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideV.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideH.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRight.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBottom.h"

#define FZZWTBLBORDERS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLBORDERS_Name "tblBorders"

class FZZWTblBorders : public FZZXMLElementObject
{
public:
    
    FZZWTblBorders(FZZOfficeObject * parent);
    FZZWTblBorders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblBorders(const FZZWTblBorders& obj);
    virtual ~FZZWTblBorders();
    
public:
    FZZWInsideV * setInsideV();
    FZZWInsideV * getInsideV();
    FZZWInsideH * setInsideH();
    FZZWInsideH * getInsideH();
    FZZWTop * setTop();
    FZZWTop * getTop();
    FZZWRight * setRight();
    FZZWRight * getRight();
    FZZWLeft * setLeft();
    FZZWLeft * getLeft();
    FZZWBottom * setBottom();
    FZZWBottom * getBottom();

protected:
    FZZWTblBorders();
private:
    FZZWInsideV* m_FZZWInsideV;
    FZZWInsideH * m_FZZWInsideH;
    FZZWTop * m_FZZWTop;
    FZZWRight * m_FZZWRight;
    FZZWLeft * m_FZZWLeft;
    FZZWBottom * m_FZZWBottom;
};

#endif //FZZWTBLBORDERS_H
