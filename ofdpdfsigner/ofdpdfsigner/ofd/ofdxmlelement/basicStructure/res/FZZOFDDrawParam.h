//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDDRAWPARAM_H
#define FZZOFDDRAWPARAM_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLineJoinType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLineCapType.h"

#define FZZOFDDRAWPARAM_Name "ofd:DrawParam"

class FZZOFDDrawParam : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDrawParam(FZZOFDXMLFileObject * parent);
    FZZOFDDrawParam(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDrawParam(const FZZOFDDrawParam& obj);
    virtual ~FZZOFDDrawParam();
    
public:
    void setID(string value);
    string getID();
    void setRelative(string value);
    string getRelative();
    void setDashPattern(string value);
    string getDashPattern();
    
    void setID(long value);
    long getID_long();
    void setRelative(long value);
    long getRelative_long();
    void setDashPattern(const vector<string> & array);
    void getDashPattern(/*out*/vector<string> & array);
    
    void setLineWidth(double value);
    double getLineWidth();
    void setJoin(FZZOFDLineJoinType::TYPE type);
    FZZOFDLineJoinType::TYPE getJoin();
    void setCap(FZZOFDLineCapType::TYPE type);
    FZZOFDLineCapType::TYPE getCap();
    void setDashOffset(double value);
    double getDashOffset();
    
    void setMiterLimit(double value);
    double getMiterLimit();
    
    
    FZZOFDFillColor* setFillColor();
    FZZOFDFillColor* getFillColor();
    FZZOFDStrokeColor* setStrokeColor();
    FZZOFDStrokeColor* getStrokeColor();
    
protected:
    FZZOFDDrawParam();
private:
    FZZOFDFillColor * m_FZZOFDFillColor;
    FZZOFDStrokeColor * m_FZZOFDStrokeColor;
};

#endif //FZZOFDDRAWPARAM_H
