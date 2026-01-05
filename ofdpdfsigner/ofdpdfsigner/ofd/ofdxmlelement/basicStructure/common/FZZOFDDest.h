//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDDEST_H
#define FZZOFDDEST_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLeft.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBottom.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDRight.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTop.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDZoom.h"

#define FZZOFDDEST_Name "ofd:Dest"

class FZZOFDDest : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDest(FZZOFDXMLFileObject * parent);
    FZZOFDDest(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDest(const FZZOFDDest& obj);
    virtual ~FZZOFDDest();
    
public:
    void setType(DestType type);
    DestType getType();
    void setPageID(string value);
    string getPageID();
    void setPageID(long value);
    long getPageID_long();
    
    FZZOFDLeft * setLeft();
    FZZOFDLeft * getLeft();
    FZZOFDRight * setRight();
    FZZOFDRight * getRight();
    FZZOFDTop * setTop();
    FZZOFDTop * getTop();
    FZZOFDBottom * setBottom();
    FZZOFDBottom * getBottom();
    FZZOFDZoom * setZoom();
    FZZOFDZoom * getZoom();
    
protected:
    FZZOFDDest();
private:
    FZZOFDLeft * m_FZZOFDLeft;
    FZZOFDRight * m_FZZOFDRight;
    FZZOFDTop * m_FZZOFDTop;
    FZZOFDBottom * m_FZZOFDBottom;
    FZZOFDZoom * m_FZZOFDZoom;
    
};

#endif //FZZOFDDEST_H
