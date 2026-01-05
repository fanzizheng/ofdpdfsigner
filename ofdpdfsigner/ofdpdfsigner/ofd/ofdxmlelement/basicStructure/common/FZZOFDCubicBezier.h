//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDCUBICBEZIER_H
#define FZZOFDCUBICBEZIER_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDCUBICBEZIER_Name "ofd:CubicBezier"

class FZZOFDCubicBezier : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDCubicBezier(FZZOFDXMLFileObject * parent);
    FZZOFDCubicBezier(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCubicBezier(const FZZOFDCubicBezier& obj);
    virtual ~FZZOFDCubicBezier();
    
public:
    void setPoint1(string value);
    string getPoint1();
    void setPoint2(string value);
    string getPoint2();
    void setPoint3(string value);
    string getPoint3();
    
    void setPoint1(double x, double y);
    void getPoint1(/*out*/double & x, /*out*/double & y);
    void setPoint2(double x, double y);
    void getPoint2(/*out*/double & x, /*out*/double & y);
    void setPoint3(double x, double y);
    void getPoint3(/*out*/double & x, /*out*/double & y);
    
protected:
    FZZOFDCubicBezier();
private:
    
};

#endif //FZZOFDCUBICBEZIER_H
