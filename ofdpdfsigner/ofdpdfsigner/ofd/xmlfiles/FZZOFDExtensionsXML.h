//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDEXTENSIONSXML_H
#define FZZOFDEXTENSIONSXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/extensions/FZZOFDExtension.h"

#define FZZOFDEXTENSIONSXML_FILENAME "Extensions.xml"




class FZZOFDExtensionsXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDExtensionsXML();
    FZZOFDExtensionsXML(XMLDocument * doc);
    FZZOFDExtensionsXML(const FZZOFDExtensionsXML& obj);
    virtual ~FZZOFDExtensionsXML();

public:
    FZZOFDExtension* addExtension();
    vector<FZZOFDExtension*>* getExtensionList();
    
public:
  
protected:
    
private:
    vector<FZZOFDExtension*> m_FZZOFDExtensions;
    
};

#endif //FZZOFDEXTENSIONSXML_H
