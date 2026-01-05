//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDBASEGRAPHIC_H
#define FZZOFDBASEGRAPHIC_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLineJoinType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLineCapType.h"


class FZZOFDClips;
class FZZOFDActions;

class FZZOFDBaseGraphic : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDBaseGraphic(FZZOFDXMLFileObject * parent);
    FZZOFDBaseGraphic(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBaseGraphic(const FZZOFDBaseGraphic& obj);
    virtual ~FZZOFDBaseGraphic();
    
public:
    void setBoundary(string value);
    string getBoundary();
    void setBoundary(double x, double y,double width, double height);
    void getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    void setName(string value);
    string getName();
    void setVisible(bool value);
    bool getVisible();
    void setCTM(string value);
    string getCTM();
    void setCTM(const vector<string> & array);
    void getCTM(/*out*/vector<string> & array);
    void getCTM(/*out*/vector<double> & array);
    void setDrawParam(long value);
    long getDrawParam();
    string getDrawParam_String();
    void setLineWidth(double value);
    double getLineWidth();
    
    void setCap(FZZOFDLineCapType::TYPE type);
    FZZOFDLineCapType::TYPE getCap();
    void setJoin(FZZOFDLineJoinType::TYPE type);
    FZZOFDLineJoinType::TYPE getJoin();
    
    void setMiterLimit(double value);
    double getMiterLimit();
    void setDashOffset(double value);
    double getDashOffset();
    void setDashPattern(string value);
    string getDashPattern();
    void setDashPattern(const vector<string> & array);
    void getDashPattern(/*out*/vector<double> & array);
    void setAlpha(int value);
    int getAlpha();
    
    FZZOFDClips * setClips();
    FZZOFDClips * getClips();
    
    FZZOFDActions * setActions();
    FZZOFDActions * getActions();
    
protected:
    FZZOFDBaseGraphic();
private:
    FZZOFDClips * m_FZZOFDClips;
    FZZOFDActions * m_FZZOFDActions;
};

#endif //FZZOFDBASEGRAPHIC_H
