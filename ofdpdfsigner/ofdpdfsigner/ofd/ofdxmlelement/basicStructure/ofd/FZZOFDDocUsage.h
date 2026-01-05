//
//  Created by zizheng fan on 2024/02/26.
//
#ifndef FZZOFDDOCUSAGE_H
#define FZZOFDDOCUSAGE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDDOCUSAGE_Name "ofd:DocUsage"

class FZZOFDDocUsage : public FZZOFDXMLElementObject
{
public:
    typedef enum {
        
        Normal,
        
        EBook,
        
        ENewsPaper,
        
        EMagzine
    } TYPE;
public:
    FZZOFDDocUsage(FZZOFDXMLFileObject * parent);
    FZZOFDDocUsage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocUsage(const FZZOFDDocUsage& obj);
    virtual ~FZZOFDDocUsage();
public:
    void setType(FZZOFDDocUsage::TYPE value);
    FZZOFDDocUsage::TYPE getType();
    
protected:
    FZZOFDDocUsage();
private:

};

#endif //FZZOFDDOCUSAGE_H
