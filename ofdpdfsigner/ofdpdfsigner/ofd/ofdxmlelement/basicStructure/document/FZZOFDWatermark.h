//
//  Created by zizheng fan on 2024/02/29.
//
#ifndef FZZOFDWATERMARK_H
#define FZZOFDWATERMARK_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDWATERMARK_Name "ofd:Watermark"

class FZZOFDWatermark : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDWatermark(FZZOFDXMLFileObject * parent);
    FZZOFDWatermark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDWatermark(const FZZOFDWatermark& obj);
    virtual ~FZZOFDWatermark();
    
public:
    void setValue(bool value);
    bool getValue();
    
    
protected:
    FZZOFDWatermark();
private:
    
};

#endif //FZZOFDWATERMARK_H
