//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDAXIALSHD_H
#define FZZOFDAXIALSHD_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDMapType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDExtend.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDSegment.h"

#define FZZOFDAXIALSHD_Name "ofd:AxialShd"

class FZZOFDAxialShd : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDAxialShd(FZZOFDXMLFileObject * parent);
    FZZOFDAxialShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAxialShd(const FZZOFDAxialShd& obj);
    virtual ~FZZOFDAxialShd();
    
public:
    void setMapType(FZZOFDMapType::TYPE type);
    FZZOFDMapType::TYPE getMapType();
    void setMapUnit(double value);
    double getMapUnit();
    
    void setStartPoint(string angle);
    string getStartPoint();
    void setEndPoint(string angle);
    string getEndPoint();
    
    void setStartPoint(double x, double y);
    void getStartPoint(/*out*/double & x, /*out*/double & y);
    void setEndPoint(double x, double y);
    void getEndPoint(/*out*/double & x, /*out*/double & y);
    
    void setExtend(FZZOFDExtend::TYPE type);
    FZZOFDExtend::TYPE getExtend();
    FZZOFDSegment * addSegment();
    vector<FZZOFDSegment*> * getSegmentList();
    
protected:
    FZZOFDAxialShd();
private:
    vector<FZZOFDSegment*> m_FZZOFDSegments;
};

#endif //FZZOFDAXIALSHD_H
