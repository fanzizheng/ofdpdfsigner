//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDSEGMENT_H
#define FZZOFDSEGMENT_H

#include "ofd/FZZOFDXMLElementObject.h"



#define FZZOFDSEGMENT_Name "ofd:Segment"

class FZZOFDColor;

class FZZOFDSegment : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSegment(FZZOFDXMLFileObject * parent);
    FZZOFDSegment(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSegment(const FZZOFDSegment& obj);
    virtual ~FZZOFDSegment();
    
public:
    void setPosition(double position);
    double getPosition();
    FZZOFDColor * setColor();
    FZZOFDColor * getColor();
    
    
protected:
    FZZOFDSegment();
private:
    FZZOFDColor * m_FZZOFDColor;
};

#endif //FZZOFDSEGMENT_H
