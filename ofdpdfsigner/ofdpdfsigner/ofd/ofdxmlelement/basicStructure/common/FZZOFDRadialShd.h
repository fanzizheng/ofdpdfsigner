//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDRADIALSHD_H
#define FZZOFDRADIALSHD_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDMapType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDExtend.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDSegment.h"

#define FZZOFDRADIALSHD_Name "ofd:RadialShd"

class FZZOFDRadialShd : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDRadialShd(FZZOFDXMLFileObject * parent);
    FZZOFDRadialShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDRadialShd(const FZZOFDRadialShd& obj);
    virtual ~FZZOFDRadialShd();
    
public:
    void setMapType(FZZOFDMapType::TYPE type);
    FZZOFDMapType::TYPE getMapType();
    void setMapUnit(double value);
    double getMapUnit();
    void setEccentricity(double eccentricity);
    double getEccentricity();
    void setAngle(double angle);
    double getAngle();
    void setStartPoint(string angle);
    string getStartPoint();
    void setEndPoint(string angle);
    string getEndPoint();
    
    void setStartPoint(double x, double y);
    void getStartPoint(/*out*/double & x, /*out*/double & y);
    void setEndPoint(double x, double y);
    void getEndPoint(/*out*/double & x, /*out*/double & y);
    
    void setStartRadius(double angle);
    double getStartRadius();
    void setEndRadius(double angle);
    double getEndRadius();
    void setExtend(FZZOFDExtend::TYPE type);
    FZZOFDExtend::TYPE getExtend();
    FZZOFDSegment * addSegment();
    vector<FZZOFDSegment*> * getSegmentList();
    
protected:
    FZZOFDRadialShd();
private:
    vector<FZZOFDSegment*> m_FZZOFDSegments;
};

#endif //FZZOFDRADIALSHD_H
