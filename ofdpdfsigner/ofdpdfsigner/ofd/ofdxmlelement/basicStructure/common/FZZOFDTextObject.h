//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDTEXTOBJECT_H
#define FZZOFDTEXTOBJECT_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDText.h"

#define FZZOFDTEXTOBJECT_Name "ofd:TextObject"

class FZZOFDTextObject : public FZZOFDText , public FZZOFDPageBlockType
{

public:
    
    FZZOFDTextObject(FZZOFDXMLFileObject * parent);
    FZZOFDTextObject(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTextObject(const FZZOFDTextObject& obj);
    virtual ~FZZOFDTextObject();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    
    
protected:
    FZZOFDTextObject();
private:
    
};

#endif //FZZOFDTEXTOBJECT_H
