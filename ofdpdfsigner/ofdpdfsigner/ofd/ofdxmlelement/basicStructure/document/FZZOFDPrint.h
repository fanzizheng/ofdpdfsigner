//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDPRINT_H
#define FZZOFDPRINT_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPRINT_Name "ofd:Print"

class FZZOFDPrint : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDPrint(FZZOFDXMLFileObject * parent);
    FZZOFDPrint(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPrint(const FZZOFDPrint& obj);
    virtual ~FZZOFDPrint();
    
public:
    void setPrintable(bool value);
    bool getPrintable();
    void setCopies(int value);
    int getCopies();
    
    
protected:
    FZZOFDPrint();
private:
    
};

#endif //FZZOFDPRINT_H
