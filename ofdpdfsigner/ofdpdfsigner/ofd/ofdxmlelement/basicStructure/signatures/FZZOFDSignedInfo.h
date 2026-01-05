//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGNEDINFO_H
#define FZZOFDSIGNEDINFO_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureMethod.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureDateTime.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDProvider.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameters.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSeal.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDStampAnnot.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReferences.h"

#define FZZOFDSIGNEDINFO_Name "ofd:SignedInfo"

class FZZOFDSignedInfo : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDSignedInfo(FZZOFDXMLFileObject * parent);
    FZZOFDSignedInfo(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDSignedInfo(const FZZOFDSignedInfo& obj);
    virtual ~FZZOFDSignedInfo();
    
public:
    
    
    FZZOFDSignatureMethod * setSignatureMethod();
    FZZOFDSignatureMethod * getSignatureMethod();
    FZZOFDSignatureDateTime * setSignatureDateTime();
    FZZOFDSignatureDateTime * getSignatureDateTime();
    FZZOFDProvider * setProvider();
    FZZOFDProvider * getProvider();
    FZZOFDReferences * setReferences();
    FZZOFDReferences * getReferences();
    FZZOFDSeal * setSeal();
    FZZOFDSeal * getSeal();
    /*
     GM/T 0099-2020
    ofd 2.0 新增 （可选）
     签名扩展属性集
     */
    FZZOFDParameters * setParameters();
    FZZOFDParameters * getParameters();
    
    FZZOFDStampAnnot * addStampAnnot();
    vector<FZZOFDStampAnnot*> * getStampAnnotList();
    
protected:
    FZZOFDSignedInfo();
private:
    FZZOFDSignatureMethod * m_FZZOFDSignatureMethod;
    FZZOFDSignatureDateTime * m_FZZOFDSignatureDateTime;
    FZZOFDProvider * m_FZZOFDProvider;
    FZZOFDReferences * m_FZZOFDReferences;
    FZZOFDSeal * m_FZZOFDSeal;
    FZZOFDParameters * m_FZZOFDParameters;
    
    vector<FZZOFDStampAnnot*> m_FZZOFDStampAnnots;
};

#endif //FZZOFDSIGNEDINFO_H
