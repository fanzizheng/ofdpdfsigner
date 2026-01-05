//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDLAGOURAUDSHD_H
#define FZZOFDLAGOURAUDSHD_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDGouraudShd.h"

#define FZZOFDLAGOURAUDSHD_Name "ofd:LaGouraudShd"

class FZZOFDLaGouraudShd : public FZZOFDGouraudShd
{

public:
    
    FZZOFDLaGouraudShd(FZZOFDXMLFileObject * parent);
    FZZOFDLaGouraudShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDLaGouraudShd(const FZZOFDLaGouraudShd& obj);
    virtual ~FZZOFDLaGouraudShd();
    
public:
    void setVerticesPerRow(int value);
    int getVerticesPerRow();
protected:
    FZZOFDLaGouraudShd();
private:
    
};

#endif //FZZOFDLAGOURAUDSHD_H
