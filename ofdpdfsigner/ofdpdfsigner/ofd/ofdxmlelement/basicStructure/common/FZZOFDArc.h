//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDARC_H
#define FZZOFDARC_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDARC_Name "ofd:Arc"

class FZZOFDArc : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDArc(FZZOFDXMLFileObject * parent);
    FZZOFDArc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDArc(const FZZOFDArc& obj);
    virtual ~FZZOFDArc();
    
public:
    void setEllipseSize(string value);
    string getEllipseSize();
    void setEllipseSize(const vector<string> & array);
    void getEllipseSize(/*out*/vector<string> & array);
    void setEndPoint(string value);
    string getEndPoint();
    void setEndPoint(double x, double y);
    void getEndPoint(/*out*/double & x, /*out*/double & y);
    
    void setSweepDirection(bool value);
    bool getSweepDirection();
    void setLargeArc(bool value);
    bool getLargeArc();
    void setRotationAngle(double value);
    double getRotationAngle();
    
    
protected:
    FZZOFDArc();
private:
    
};

#endif //FZZOFDARC_H
