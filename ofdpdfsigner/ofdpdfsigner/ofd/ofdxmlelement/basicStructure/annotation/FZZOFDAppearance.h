//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDAPPEARANCE_H
#define FZZOFDAPPEARANCE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"
#define FZZOFDAPPEARANCE_Name "ofd:Appearance"


class FZZOFDAppearance : public FZZOFDPageBlock
{

public:
    
    FZZOFDAppearance(FZZOFDXMLFileObject * parent);
    FZZOFDAppearance(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAppearance(const FZZOFDAppearance& obj);
    virtual ~FZZOFDAppearance();
    
public:
    void setBoundary(string value);
    string getBoundary();
    void setBoundary(double x, double y,double width, double height);
    void getBoundary(double &x, double &y,double &width, double &height);
    
protected:
    FZZOFDAppearance();
private:
    
};

#endif //FZZOFDAPPEARANCE_H
