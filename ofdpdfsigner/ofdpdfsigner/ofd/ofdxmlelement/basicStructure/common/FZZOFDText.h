//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDTEXT_H
#define FZZOFDTEXT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBaseGraphic.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClipAble.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDDirection.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDWeight.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextCode.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCGTransform.h"

#define FZZOFDTEXT_Name "ofd:Text"

class FZZOFDText : public FZZOFDBaseGraphic, public FZZOFDClipAble
{

public:
    
    FZZOFDText(FZZOFDXMLFileObject * parent);
    FZZOFDText(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDText(const FZZOFDText& obj);
    virtual ~FZZOFDText();
    
public:
    void setFont(string value);
    string getFont();
    void setFont(long value);
    long getFont_long();
    void setSize(double value);
    double getSize();
    void setStroke(bool value);
    bool getStroke();
    void setFill(bool fill);
    bool getFill();
    void setHScale(double hScale);
    double getHScale();
    void setReadDirection(FZZOFDDirection::TYPE readDirection);
    FZZOFDDirection::TYPE getReadDirection();
    void setCharDirection(FZZOFDDirection::TYPE charDirection);
    FZZOFDDirection::TYPE getCharDirection();
    void setWeight(FZZOFDWeight::TYPE weight);
    FZZOFDWeight::TYPE getWeight();
    void setItalic(bool italic);
    bool getItalic();
    FZZOFDFillColor * setFillColor();
    FZZOFDFillColor * getFillColor();
    FZZOFDStrokeColor * setStrokeColor();
    FZZOFDStrokeColor * getStrokeColor();
    FZZOFDTextCode * addTextCode();
    vector<FZZOFDTextCode*> * getTextCodeList();
    FZZOFDCGTransform * addCGTransform();
    vector<FZZOFDCGTransform*> * getCGTransformList();
    
protected:
    FZZOFDText();
private:
    FZZOFDFillColor * m_FZZOFDFillColor;
    FZZOFDStrokeColor * m_FZZOFDStrokeColor;
    vector<FZZOFDTextCode*> m_FZZOFDTextCodes;
    vector<FZZOFDCGTransform*> m_FZZOFDCGTransforms;
};

#endif //FZZOFDTEXT_H
