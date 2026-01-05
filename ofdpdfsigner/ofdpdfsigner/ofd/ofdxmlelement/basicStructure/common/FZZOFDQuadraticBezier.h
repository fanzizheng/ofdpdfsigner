//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDQUADRATICBEZIER_H
#define FZZOFDQUADRATICBEZIER_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDQUADRATICBEZIER_Name "ofd:QuadraticBezier"

class FZZOFDQuadraticBezier : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDQuadraticBezier(FZZOFDXMLFileObject * parent);
    FZZOFDQuadraticBezier(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDQuadraticBezier(const FZZOFDQuadraticBezier& obj);
    virtual ~FZZOFDQuadraticBezier();
    
public:
    void setPoint1(string value);
    string getPoint1();
    void setPoint2(string value);
    string getPoint2();
    
    void setPoint1(double x, double y);
    void getPoint1(/*out*/double & x, /*out*/double & y);
    void setPoint2(double x, double y);
    void getPoint2(/*out*/double & x, /*out*/double & y);
    
    
protected:
    FZZOFDQuadraticBezier();
private:
    
};

#endif //FZZOFDQUADRATICBEZIER_H



