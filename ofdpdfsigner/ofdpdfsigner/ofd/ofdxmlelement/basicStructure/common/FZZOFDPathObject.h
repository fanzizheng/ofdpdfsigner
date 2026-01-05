//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDPATHOBJECT_H
#define FZZOFDPATHOBJECT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPath.h"

#define FZZOFDPATHOBJECT_Name "ofd:PathObject"

class FZZOFDPathObject : public FZZOFDPath , public FZZOFDPageBlockType
{

public:
    
    FZZOFDPathObject(FZZOFDXMLFileObject * parent);
    FZZOFDPathObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPathObject(const FZZOFDPathObject& obj);
    virtual ~FZZOFDPathObject();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    
    
protected:
    FZZOFDPathObject();
private:
    
};

#endif //FZZOFDPATHOBJECT_H
