//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDFILELOC_H
#define FZZOFDFILELOC_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDFILELOC_Name "ofd:FileLoc"
#define FZZOFDIMAGELOC_Name "ofd:ImageLoc"
#define FZZOFDBASELOC_Name "ofd:BaseLoc"
#define FZZOFDSCHEMALOC_Name "ofd:SchemaLoc"
#define FZZOFDMEDIAFILELOC_Name "ofd:MediaFile"

class FZZOFDFileLoc : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDFileLoc(FZZOFDXMLFileObject * parent);
    FZZOFDFileLoc(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFileLoc(const FZZOFDFileLoc& obj);
    virtual ~FZZOFDFileLoc();
    
public:
    void setValue(string value);
    string getValue();
    
    
protected:
    FZZOFDFileLoc();
private:
    
};

#endif //FZZOFDFILELOC_H
