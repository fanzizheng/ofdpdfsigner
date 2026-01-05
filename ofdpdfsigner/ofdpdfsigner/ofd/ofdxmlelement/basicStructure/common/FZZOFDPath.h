//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDPATH_H
#define FZZOFDPATH_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBaseGraphic.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClipAble.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDRule.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDAbbreviatedData.h"

#define FZZOFDPATH_Name "ofd:Path"

class FZZOFDPath : public FZZOFDBaseGraphic, public FZZOFDClipAble
{

public:
    
    FZZOFDPath(FZZOFDXMLFileObject * parent);
    FZZOFDPath(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPath(const FZZOFDPath& obj);
    virtual ~FZZOFDPath();
    
public:
    void setStroke(bool value);
    bool getStroke();
    void setFill(bool value);
    bool getFill();
    
    void setRule(FZZOFDRule::TYPE rule);
    FZZOFDRule::TYPE getRule();
    
    FZZOFDFillColor * setFillColor();
    FZZOFDFillColor * getFillColor();
    FZZOFDStrokeColor * setStrokeColor();
    FZZOFDStrokeColor * getStrokeColor();
    FZZOFDAbbreviatedData * setAbbreviatedData();
    FZZOFDAbbreviatedData * getAbbreviatedData();
    
protected:
    FZZOFDPath();
private:
    FZZOFDFillColor * m_FZZOFDFillColor;
    FZZOFDStrokeColor * m_FZZOFDStrokeColor;
    FZZOFDAbbreviatedData * m_FZZOFDAbbreviatedData;
};

#endif //FZZOFDPATH_H
