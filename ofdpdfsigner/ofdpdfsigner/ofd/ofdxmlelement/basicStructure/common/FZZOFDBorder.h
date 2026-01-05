//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDBORDER_H
#define FZZOFDBORDER_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"

#define FZZOFDBORDER_Name "ofd:Border"

class FZZOFDBorder : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDBorder(FZZOFDXMLFileObject * parent);
    FZZOFDBorder(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBorder(const FZZOFDBorder& obj);
    virtual ~FZZOFDBorder();
    
public:
    void setDashPattern(string value);
    string getDashPattern();
    void setDashPattern(const vector<string> & array);
    void getDashPattern(/*out*/vector<string> & array);
    void setHorizonalCornerRadius(double horizonalCornerRadius);
    double getHorizonalCornerRadius();
    void setLineWidth(double lineWidth);
    double getLineWidth();
    void setDashOffset(double dashOffset);
    double getDashOffset();
    
    FZZOFDBorderColor * setBorderColor();
    FZZOFDBorderColor * getBorderColor();
    FZZOFDColor * setColor();
    FZZOFDColor * getColor();
    
protected:
    FZZOFDBorder();
private:
    FZZOFDBorderColor * m_FZZOFDBorderColor;
    FZZOFDColor * m_FZZOFDColor;
};

#endif //FZZOFDBORDER_H
