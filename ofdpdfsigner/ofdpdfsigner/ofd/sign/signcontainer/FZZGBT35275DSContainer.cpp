//
//  Created by zizheng fan on 2023/03/01.
//
#include "basic/FZZConst.h"
#include "ofd/sign/signcontainer/FZZGBT35275DSContainer.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gm/ses/data/FZZContentInfo.h"
#include "gm/ses/data/FZZSignerInfo.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZGBT35275DSContainer*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275DSContainer::FZZGBT35275DSContainer() : FZZExtendSignatureContainer(), m_PrivateKey(NULL),m_SignCert(NULL),m_isCallBack(false),m_signFunc(NULL),m_callBack_Param(NULL),m_getCertFunc(NULL)
{
    //DLOG("FZZGBT35275DSContainer()");
    FZZConst::addClassCount("FZZGBT35275DSContainer");
}
//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275DSContainer::FZZGBT35275DSContainer(FZZKey * privateKey, FZZCert * signCert) : FZZGBT35275DSContainer()
{
    m_PrivateKey = privateKey;
    m_SignCert = signCert;
    m_isCallBack = false;
}
//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275DSContainer::FZZGBT35275DSContainer(CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param) : FZZGBT35275DSContainer()
{
    m_isCallBack = true;
    m_signFunc = signFunc;
    m_callBack_Param = callBack_Param;
    m_getCertFunc = getCertFunc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275DSContainer::~FZZGBT35275DSContainer()
{
    //DLOG("~FZZGBT35275DSContainer()");
    FZZConst::delClassCount("FZZGBT35275DSContainer");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZGBT35275DSContainer::sign(FZZBytes & inData, string propertyInfo,FZZBytes & outSignData)
{
   
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest("SM3", inData, hashData);
    if ( hashData.getLen() < 8 ) {
        return;
    }
    
    FZZBytes signdata;
    
    if ( m_isCallBack ) {
        if ( m_signFunc == NULL ) {
            return;
        }

        size_t bufferLen = MAXBUFLEN_SIGN;
        unsigned char * buffer = (unsigned char *)malloc(bufferLen);
        if ( buffer == NULL ) {
            return ;
        }
        m_signFunc(m_callBack_Param,hashData.getData(),(int)hashData.getLen(),&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return ;
        }
        
        signdata.setData(buffer, bufferLen);
        free(buffer);
        buffer = NULL;
      
    } else {
        if ( m_PrivateKey == NULL ) {
            return;
        }
        signdata = gmCrypto.sign(*m_PrivateKey, hashData);
    }
    
    FZZCert cert;
    
    if ( m_isCallBack ) {
        if ( m_getCertFunc == NULL ) {
            return;
        }
       
        size_t bufferLen = 0;
        unsigned char * buffer = NULL;
        m_getCertFunc(m_callBack_Param,&buffer,&bufferLen);
        if ( bufferLen <= 0 ) {
            return ;
        }
        buffer = (unsigned char *)malloc(bufferLen);
        if ( buffer == NULL ) {
            return ;
        }
        m_getCertFunc(m_callBack_Param,&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return ;
        }
        
        cert.loadCert(buffer, bufferLen);
        
        free(buffer);
        buffer = NULL;
        bufferLen = 0;
     
        
    } else {
        if ( m_SignCert == NULL ) {
            return;
        }
        cert = *m_SignCert;
    }
    
    FZZContentInfo dataContent;
    uint32_t datacontentType_nodes[] = {1,2,156,10197,6,1,4,2,1};
    size_t datacontentType_nodes_count = 9;
    FZZBytes datacontentTypealg((unsigned char *)datacontentType_nodes,datacontentType_nodes_count*4);
    dataContent.setContentType(datacontentTypealg);
    dataContent.setDataContent(hashData);
    
    
    FZZContentInfo contentInfo;
    uint32_t signcontentType_nodes[] = {1,2,156,10197,6,1,4,2,2};
    size_t signcontentType_nodes_count = 9;
    FZZBytes signcontentTypealg((unsigned char *)signcontentType_nodes,signcontentType_nodes_count*4);
    contentInfo.setContentType(signcontentTypealg);
    
    FZZSignedData signedData;
    
    uint32_t digestAlg_nodes[] = {1,2,156,10197,1,401};
    size_t digestAlg_nodes_count = 6;
    FZZBytes digestAlg((unsigned char *)digestAlg_nodes,digestAlg_nodes_count*4);
    signedData.addDigestAlg(digestAlg);
    signedData.setContentInfo(&dataContent);
    signedData.addCert(cert.getCertData());
    FZZSignerInfo signerinfo;
    signerinfo.setIssuer(cert.getIssuer());
    FZZBytes certsn = cert.getSerialNumberBytes();
    signerinfo.setSerialNumber(certsn);
    signerinfo.setDigestAlgorithm(digestAlg);
    uint32_t digestEncryptionAlg_nodes[] = {1,2,156,10197,1,301,1};
    size_t digestEncryptionAlg_count = 7;
    FZZBytes digestEncryptionAlg((unsigned char *)digestEncryptionAlg_nodes,digestEncryptionAlg_count*4);
    signerinfo.setDigestEncryptionAlgorithm(digestEncryptionAlg);
    signerinfo.setEncryptedDigest(signdata);
    signedData.addSignerInfo(&signerinfo);
    
    contentInfo.setContent(&signedData);
    
    FZZBytes esesigndata = contentInfo.Encode();
    if ( esesigndata.getLen() < 10 ) {
        return;
    }
    outSignData.setData(esesigndata.getData(), esesigndata.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigType::TYPE FZZGBT35275DSContainer::getOFDSignType()
{
    return FZZOFDSigType::TYPE::TYPE_Sign;
}

//-----------------------------------------------------------------------------------------------------------------
string FZZGBT35275DSContainer::getSignAlgOID()
{
    return "1.2.156.10197.1.501";
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGBT35275DSContainer::getSeal()
{
    FZZBytes ret;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------

