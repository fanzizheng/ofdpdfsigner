//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDTABDISPLAY_H
#define FZZOFDTABDISPLAY_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDTABDISPLAY_Name "ofd:TabDisplay"

class FZZOFDTabDisplay : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        
        FileName = 0,
        
        DocTitle = 1
    } TYPE;
public:
    
    FZZOFDTabDisplay(FZZOFDXMLFileObject * parent);
    FZZOFDTabDisplay(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDTabDisplay(const FZZOFDTabDisplay& obj);
    virtual ~FZZOFDTabDisplay();
    
public:
    void setType(FZZOFDTabDisplay::TYPE value);
    FZZOFDTabDisplay::TYPE getType();
    
    
protected:
    FZZOFDTabDisplay();
private:
    
};

#endif //FZZOFDTABDISPLAY_H
