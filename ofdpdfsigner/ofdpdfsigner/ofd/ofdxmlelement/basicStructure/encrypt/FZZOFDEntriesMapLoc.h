//
//  Created by zizheng fan on 2024/10/19.
//
#ifndef FZZOFDENRIESMAPLOC_H
#define FZZOFDENRIESMAPLOC_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDENRIESMAPLOC_Name "ofd:EntriesMapLoc"

class FZZOFDEntriesMapLoc : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDEntriesMapLoc(FZZOFDXMLFileObject * parent);
    FZZOFDEntriesMapLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDEntriesMapLoc(const FZZOFDEntriesMapLoc& obj);
    virtual ~FZZOFDEntriesMapLoc();
    
public:
    void setValue(string value);
    string getValue();
    
protected:
    FZZOFDEntriesMapLoc();
private:
    
};

#endif //FZZOFDENRIESMAPLOC_H
