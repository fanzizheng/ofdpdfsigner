//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDAREA_H
#define FZZOFDAREA_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDMove.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLine.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDQuadraticBezier.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClose.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDArc.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCubicBezier.h"

#define FZZOFDAREA_Name "ofd:Area"

class FZZOFDArea : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDArea(FZZOFDXMLFileObject * parent);
    FZZOFDArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDArea(const FZZOFDArea& obj);
    virtual ~FZZOFDArea();
    
public:
    void setStart(string value);
    string getStart();
    void setStart(double x, double y);
    void getStart(/*out*/double & x, /*out*/double & y);
    
    vector<FZZOFDCommand*> * getCommands();
    FZZOFDMove * addMove();
    FZZOFDLine * addLine();
    FZZOFDQuadraticBezier * addQuadraticBezier();
    FZZOFDCubicBezier * addCubicBezier();
    FZZOFDArc * addArc();
    FZZOFDClose * addClose();
    
protected:
    FZZOFDArea();
private:
    vector<FZZOFDCommand *> m_FZZOFDCommands;
};

#endif //FZZOFDAREA_H
