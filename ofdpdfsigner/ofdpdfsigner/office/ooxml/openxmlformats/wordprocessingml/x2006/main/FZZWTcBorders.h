//
//  Created by zizheng fan on 2023/11/17
//
#ifndef FZZWTCBORDERS_H
#define FZZWTCBORDERS_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideV.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideH.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRight.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBottom.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTl2br.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTr2bl.h"

#define FZZWTCBORDERS_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTCBORDERS_Name "tcBorders"

class FZZWTcBorders : public FZZXMLElementObject
{
public:
    
    FZZWTcBorders(FZZOfficeObject * parent);
    FZZWTcBorders(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTcBorders(const FZZWTcBorders& obj);
    virtual ~FZZWTcBorders();
    
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
    FZZWTl2br * setTl2br();
    FZZWTl2br * getTl2br();
    FZZWTr2bl * setTr2bl();
    FZZWTr2bl * getTr2bl();

protected:
    FZZWTcBorders();
private:
    FZZWInsideV* m_FZZWInsideV;
    FZZWInsideH * m_FZZWInsideH;
    FZZWTop * m_FZZWTop;
    FZZWRight * m_FZZWRight;
    FZZWLeft * m_FZZWLeft;
    FZZWBottom * m_FZZWBottom;
    FZZWTl2br * m_FZZWTl2br;
    FZZWTr2bl * m_FZZWTr2bl;
};

#endif //FZZWTCBORDERS_H
