//
//  Created by zizheng fan on 2024/09/25.
//
#ifndef FZZOFDFILE_H
#define FZZOFDFILE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDFILE_Name "ofd:File"

class FZZOFDFile : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDFile(FZZOFDXMLFileObject * parent);
    FZZOFDFile(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFile(const FZZOFDFile& obj);
    virtual ~FZZOFDFile();
    
public:
    void setID(string value);
    string getID();
    void setFileLoc(string value);
    string getFileLoc();
  
    
protected:
    FZZOFDFile();
private:
    
};

#endif //FZZOFDFILE_H
