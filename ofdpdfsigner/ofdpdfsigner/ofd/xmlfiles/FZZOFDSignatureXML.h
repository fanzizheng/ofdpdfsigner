//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNATUREXML_H
#define FZZOFDSIGNATUREXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedValue.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedInfo.h"

#define FZZOFDSIGNATUREXML_FILENAME "Signature.xml"



class FZZOFDSignatureXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDSignatureXML();
    FZZOFDSignatureXML(XMLDocument * doc);
    FZZOFDSignatureXML(const FZZOFDSignatureXML& obj);
    virtual ~FZZOFDSignatureXML();

public:
    
    FZZOFDSignedValue * setSignedValue();
    FZZOFDSignedValue * getSignedValue();
    FZZOFDSignedInfo * setSignedInfo();
    FZZOFDSignedInfo * getSignedInfo();
public:
  
protected:
    
private:

    FZZOFDSignedValue * m_FZZOFDSignedValue;
    FZZOFDSignedInfo * m_FZZOFDSignedInfo;
};

#endif //FZZOFDSIGNATUREXML_H
