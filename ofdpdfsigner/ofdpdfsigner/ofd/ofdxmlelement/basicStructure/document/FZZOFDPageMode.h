//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDPAGEMODE_H
#define FZZOFDPAGEMODE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDPAGEMODE_Name "ofd:PageMode"

class FZZOFDPageMode : public FZZOFDXMLElementObject
{
public:
    typedef enum {
       
        None = 0,
        
        FullScreen = 1,
      
        UseOutlines = 2,
       
        UseThumbs = 3,
       
        UseCustomTags = 4,
       
        UseLayers = 5,
      
        UseAttatchs = 6,

       
        UseBookmarks = 7
    } TYPE;
public:
    
    FZZOFDPageMode(FZZOFDXMLFileObject * parent);
    FZZOFDPageMode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDPageMode(const FZZOFDPageMode& obj);
    virtual ~FZZOFDPageMode();
    
public:
    void setType(FZZOFDPageMode::TYPE value);
    FZZOFDPageMode::TYPE getType();
    
    
protected:
    FZZOFDPageMode();
private:
    
};

#endif //FZZOFDPAGEMODE_H
