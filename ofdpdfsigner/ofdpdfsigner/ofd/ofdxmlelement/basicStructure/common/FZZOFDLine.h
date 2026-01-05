//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDLINE_H
#define FZZOFDLINE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDLINE_Name "ofd:Line"

class FZZOFDLine : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDLine(FZZOFDXMLFileObject * parent);
    FZZOFDLine(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDLine(const FZZOFDLine& obj);
    virtual ~FZZOFDLine();
    
public:
    void setPoint1(string value);
    string getPoint1();
    void setPoint1(double x, double y);
    void getPoint1(/*out*/double & x, /*out*/double & y);
    
    
protected:
    FZZOFDLine();
private:
    
};

#endif //FZZOFDLINE_H
