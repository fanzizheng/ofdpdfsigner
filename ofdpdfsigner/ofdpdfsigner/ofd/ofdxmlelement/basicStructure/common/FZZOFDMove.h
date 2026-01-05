//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDMOVE_H
#define FZZOFDMOVE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDMOVE_Name "ofd:Move"

class FZZOFDMove : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDMove(FZZOFDXMLFileObject * parent);
    FZZOFDMove(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDMove(const FZZOFDMove& obj);
    virtual ~FZZOFDMove();
    
public:
    
    void setPoint1(string value);
    string getPoint1();
    
    void setPoint1(double x, double y);
    void getPoint1(/*out*/double & x, /*out*/double & y);
    
protected:
    FZZOFDMove();
private:
    
};

#endif //FZZOFDMOVE_H
