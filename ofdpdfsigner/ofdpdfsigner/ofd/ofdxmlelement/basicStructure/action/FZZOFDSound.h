//
//  Created by zizheng fan on 2024/02/28.
//
#ifndef FZZOFDSOUND_H
#define FZZOFDSOUND_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDSOUND_Name "ofd:Sound"

class FZZOFDSound : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDSound(FZZOFDXMLFileObject * parent);
    FZZOFDSound(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSound(const FZZOFDSound& obj);
    virtual ~FZZOFDSound();
    
public:
    void setResourceID(string value);
    string getResourceID();
    void setVolume(int volume);
    int getVolume();
    void setRepeat(bool value);
    bool getRepeat();
    void setSynchronous(bool value);
    bool getSynchronous();
    
protected:
    FZZOFDSound();
private:
    
};

#endif //FZZOFDSOUND_H
