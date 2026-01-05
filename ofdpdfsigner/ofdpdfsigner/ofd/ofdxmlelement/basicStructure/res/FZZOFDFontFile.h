//
//  Created by zizheng fan on 2024/03/01.
//
#ifndef FZZOFDFONTFILE_H
#define FZZOFDFONTFILE_H

#include "ofd/FZZOFDXMLElementObject.h"


#define FZZOFDFONTFILE_Name "ofd:FontFile"

class FZZOFDFontFile : public FZZOFDXMLElementObject
{
public:
    
public:
    
    FZZOFDFontFile(FZZOFDXMLFileObject * parent);
    FZZOFDFontFile(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFontFile(const FZZOFDFontFile& obj);
    virtual ~FZZOFDFontFile();
    
public:
   
    void setValue(string value);
    string getValue();
protected:
    FZZOFDFontFile();
private:
 
    
};

#endif //FZZOFDFONTFILE_H
