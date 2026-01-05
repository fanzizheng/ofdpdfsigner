//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDZOOMMODE_H
#define FZZOFDZOOMMODE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDZOOMMODE_Name "ofd:ZoomMode"

class FZZOFDZoomMode : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        TYPE_Default,
        TYPE_FitHeight,
        TYPE_FitWidth,
        TYPT_FitRect
    } TYPE;
public:
    
    FZZOFDZoomMode(FZZOFDXMLFileObject * parent);
    FZZOFDZoomMode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDZoomMode(const FZZOFDZoomMode& obj);
    virtual ~FZZOFDZoomMode();
    
public:
    void setType(FZZOFDZoomMode::TYPE type);
    FZZOFDZoomMode::TYPE getType();
    
    
protected:
    FZZOFDZoomMode();
private:
    
};

#endif //FZZOFDZOOMMODE_H
