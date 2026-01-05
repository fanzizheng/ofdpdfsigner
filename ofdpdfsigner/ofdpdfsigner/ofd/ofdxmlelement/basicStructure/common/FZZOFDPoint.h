//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDPOINT_H
#define FZZOFDPOINT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPOINT_Name "ofd:Point"

class FZZOFDColor;

class FZZOFDPoint : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        TYPE_0,
        TYPE_1,
        TYPE_2
    } TYPE;
public:
    
    FZZOFDPoint(FZZOFDXMLFileObject * parent);
    FZZOFDPoint(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPoint(const FZZOFDPoint& obj);
    virtual ~FZZOFDPoint();
    
public:
   
    FZZOFDColor * setColor();
    FZZOFDColor * getColor();
    void setEdgeFlag(FZZOFDPoint::TYPE type);
    FZZOFDPoint::TYPE getEdgeFlag();
    
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    
protected:
    FZZOFDPoint();
private:
    FZZOFDColor * m_FZZOFDColor;
};

#endif //FZZOFDPOINT_H
