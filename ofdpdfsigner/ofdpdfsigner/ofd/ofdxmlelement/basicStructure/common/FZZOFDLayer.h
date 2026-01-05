//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDLAYER_H
#define FZZOFDLAYER_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"

#define FZZOFDLAYER_Name "ofd:Layer"


class FZZOFDLayer : public FZZOFDPageBlock
{

public:
    
    FZZOFDLayer(FZZOFDXMLFileObject * parent);
    FZZOFDLayer(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDLayer(const FZZOFDLayer& obj);
    virtual ~FZZOFDLayer();
    
public:
    void setDrawParam(long value);
    long getDrawParam();
    string getDrawParam_String();
    void setType(Type type);
    Type getType();
    
protected:
    FZZOFDLayer();
private:
    
};

#endif //FZZOFDLAYER_H
