//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDGOURAUDSHD_H
#define FZZOFDGOURAUDSHD_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPoint.h"

#define FZZOFDGOURAUDSHD_Name "ofd:GouraudShd"

class FZZOFDBackColor;

class FZZOFDGouraudShd : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDGouraudShd(FZZOFDXMLFileObject * parent);
    FZZOFDGouraudShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDGouraudShd(const FZZOFDGouraudShd& obj);
    virtual ~FZZOFDGouraudShd();
    
public:
    void setExtend(bool value);
    bool getExtend();
    
    FZZOFDBackColor * setBackColor();
    FZZOFDBackColor * getBackColor();
    
    FZZOFDPoint * addPoint();
    vector<FZZOFDPoint*> * getPointList();
    
protected:
    FZZOFDGouraudShd();
private:
    FZZOFDBackColor * m_FZZOFDBackColor;
    vector<FZZOFDPoint*> m_FZZOFDPoints;
};

#endif //FZZOFDGOURAUDSHD_H
