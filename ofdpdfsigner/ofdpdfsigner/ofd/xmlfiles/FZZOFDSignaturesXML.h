//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNATURESXML_H
#define FZZOFDSIGNATURESXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignature.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDMaxSignId.h"

#define FZZOFDSIGNATURESXML_FILENAME "Signatures.xml"


class FZZOFDSignaturesXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDSignaturesXML();
    FZZOFDSignaturesXML(XMLDocument * doc);
    FZZOFDSignaturesXML(const FZZOFDSignaturesXML& obj);
    virtual ~FZZOFDSignaturesXML();

public:
    FZZOFDSignature* addSignature();
    vector<FZZOFDSignature*>* getSignatureList();
    
    FZZOFDMaxSignId * setMaxSignId();
    FZZOFDMaxSignId * getMaxSignId();
public:
  
protected:
    
private:
    vector<FZZOFDSignature*> m_FZZOFDSignatures;
    FZZOFDMaxSignId * m_FZZOFDMaxSignId;
};

#endif //FZZOFDSIGNATURESXML_H
