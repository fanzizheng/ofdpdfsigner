//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDPATTERN_H
#define FZZOFDPATTERN_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"

#define FZZOFDPATTERN_Name "ofd:Pattern"

class FZZOFDPattern : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDPattern(FZZOFDXMLFileObject * parent);
    FZZOFDPattern(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPattern(const FZZOFDPattern& obj);
    virtual ~FZZOFDPattern();
    
public:
    void setWidth(double y);
    double getWidth();
    void setHeight(double y);
    double getHeight();
    void setXStep(double y);
    double getXStep();
    void setYStep(double y);
    double getYStep();
    
    void setReflectMethod(ReflectMethod reflectMethod);
    ReflectMethod getReflectMethod();
    void setRelativeTo(RelativeTo relativeTo);
    RelativeTo getRelativeTo();
    
    void setCTM(string value);
    string getCTM();
    
    FZZOFDCellContent * setCellContent();
    FZZOFDCellContent * getCellContent();
protected:
    FZZOFDPattern();
private:
    FZZOFDCellContent * m_FZZOFDCellContent;
};

#endif //FZZOFDPATTERN_H
