//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDDOCBODY_H
#define FZZOFDDOCBODY_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocRoot.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody_Signatures.h"
#include "ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersions.h"


#define FZZOFDDOCBODY_Name "ofd:DocBody"

class FZZOFDDocBody : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDDocBody(FZZOFDXMLFileObject * parent);
    FZZOFDDocBody(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDDocBody(const FZZOFDDocBody& obj);
    virtual ~FZZOFDDocBody();
    
public:

    FZZOFDDocInfo * setDocInfo();
    FZZOFDDocInfo * getDocInfo();
    FZZOFDDocRoot * setDocRoot();
    FZZOFDDocRoot * getDocRoot();
    FZZOFDDocBody_Signatures * setSignatures();
    FZZOFDDocBody_Signatures * getSignatures();
    FZZOFDVersions * setVersions();
    FZZOFDVersions * getVersions();

    
protected:
    FZZOFDDocBody();
private:
    FZZOFDDocInfo * m_FZZOFDDocInfo;
    FZZOFDDocRoot * m_FZZOFDDocRoot;
    FZZOFDDocBody_Signatures * m_FZZOFDDocBody_Signatures;
    FZZOFDVersions * m_FZZOFDVersions;
    
};

#endif //FZZOFDDOCBODY_H
