//
//  Created by zizheng fan on 2023/10/20
//
#ifndef FZZWTBLCELLMAR_H
#define FZZWTBLCELLMAR_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBottom.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRight.h"

#define FZZWTBLCELLMAR_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWTBLCELLMAR_Name "tblCellMar"

class FZZWTblCellMar : public FZZXMLElementObject
{
public:
    
    FZZWTblCellMar(FZZOfficeObject * parent);
    FZZWTblCellMar(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWTblCellMar(const FZZWTblCellMar& obj);
    virtual ~FZZWTblCellMar();
    
public:
    FZZWTop * setTop();
    FZZWTop * getTop();
    FZZWLeft * setLeft();
    FZZWLeft * getLeft();
    FZZWBottom * setBottom();
    FZZWBottom * getBottom();
    FZZWRight * setRight();
    FZZWRight * getRight();
protected:
    FZZWTblCellMar();
private:
    FZZWTop * m_FZZWTop;
    FZZWLeft * m_FZZWLeft;
    FZZWBottom * m_FZZWBottom;
    FZZWRight * m_FZZWRight;
    
};

#endif //FZZWTBLCELLMAR_H
