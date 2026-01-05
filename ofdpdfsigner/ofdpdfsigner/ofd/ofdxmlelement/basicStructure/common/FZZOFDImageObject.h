//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDIMAGEOBJECT_H
#define FZZOFDIMAGEOBJECT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImage.h"

#define FZZOFDIMAGEOBJECT_Name "ofd:ImageObject"

class FZZOFDImageObject : public FZZOFDImage , public FZZOFDPageBlockType
{

public:
    
    FZZOFDImageObject(FZZOFDXMLFileObject * parent);
    FZZOFDImageObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDImageObject(const FZZOFDImageObject& obj);
    virtual ~FZZOFDImageObject();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    
    
protected:
    FZZOFDImageObject();
private:
    
};

#endif //FZZOFDIMAGEOBJECT_H
