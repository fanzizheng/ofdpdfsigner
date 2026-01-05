//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDCUSTOMTAG_H
#define FZZOFDCUSTOMTAG_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.h"

#define FZZOFDCUSTOMTAG_Name "ofd:CustomTag"

class FZZOFDCustomTag : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDCustomTag(FZZOFDXMLFileObject * parent);
    FZZOFDCustomTag(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDCustomTag(const FZZOFDCustomTag& obj);
    virtual ~FZZOFDCustomTag();
    
public:
    void setTypeID(string value);
    string getTypeID();
    void setNameSpace(string value);
    string getNameSpace();
    FZZOFDFileLoc * setSchemaLoc();
    FZZOFDFileLoc * getSchemaLoc();
    FZZOFDFileLoc * setFileLoc();
    FZZOFDFileLoc * getFileLoc();
    
protected:
    FZZOFDCustomTag();
private:
    FZZOFDFileLoc * m_SchemaLoc;
    FZZOFDFileLoc  * m_FZZOFDFileLoc;
};

#endif //FZZOFDCUSTOMTAG_H
