//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDCLOSE_H
#define FZZOFDCLOSE_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCommand.h"

#define FZZOFDCLOSE_Name "ofd:Close"

class FZZOFDClose : public FZZOFDXMLElementObject , public FZZOFDCommand
{

public:
    
    FZZOFDClose(FZZOFDXMLFileObject * parent);
    FZZOFDClose(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDClose(const FZZOFDClose& obj);
    virtual ~FZZOFDClose();
    
public:
   
    
    
    
protected:
    FZZOFDClose();
private:
    
};

#endif //FZZOFDCLOSE_H
