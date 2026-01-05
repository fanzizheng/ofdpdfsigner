//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDCOMPOSITEOBJECT_H
#define FZZOFDCOMPOSITEOBJECT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPath.h"

#define FZZOFDCOMPOSITEOBJECT_Name "ofd:CompositeObject"

class FZZOFDCompositeObject : public FZZOFDPath , public FZZOFDPageBlockType
{

public:
    
    FZZOFDCompositeObject(FZZOFDXMLFileObject * parent);
    FZZOFDCompositeObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCompositeObject(const FZZOFDCompositeObject& obj);
    virtual ~FZZOFDCompositeObject();
    
public:
    void setID(string value);
    string getID();
    void setResourceID(string value);
    string getResourceID();
    void setID(long value);
    long getID_long();
    void setResourceID(long value);
    long getResourceID_long();
    
    
protected:
    FZZOFDCompositeObject();
private:
    
};

#endif //FZZOFDCOMPOSITEOBJECT_H
