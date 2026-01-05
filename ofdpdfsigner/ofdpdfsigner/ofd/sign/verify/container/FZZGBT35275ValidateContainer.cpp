//
//  Created by zizheng fan on 2023/03/05.
//
#include "basic/FZZConst.h"
#include "ofd/sign/verify/container/FZZGBT35275ValidateContainer.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gm/ses/data/FZZContentInfo.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZGBT35275ValidateContainer*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275ValidateContainer::FZZGBT35275ValidateContainer() : FZZSignedDataValidateContainer()
{
    //DLOG("FZZGBT35275ValidateContainer()");
    FZZConst::addClassCount("FZZGBT35275ValidateContainer");
    
    
}
//-----------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------
FZZGBT35275ValidateContainer::~FZZGBT35275ValidateContainer()
{
    //DLOG("~FZZGBT35275ValidateContainer()");
    FZZConst::delClassCount("FZZGBT35275ValidateContainer");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-1 : must seal type
//-20 : Digest error
//-30 : The Signature.xml file has been tampered with
//-100 : get TBS_Sign error;
//-101 : Unsupported data structure
//-200 :  verifySign error;
//-201 :  load cert error;
int FZZGBT35275ValidateContainer::validate(FZZOFDSigType::TYPE type, string signAlgName, CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN)
{
    if (type != FZZOFDSigType::TYPE::TYPE_Sign) {
        return -1;
    }
    
    FZZContentInfo contentInfo(signedValue.getData(),signedValue.getLen());
    //test begin
    //FZZBytes testContent = contentInfo.Encode();
    //FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/sign/signdata.dat",testContent.getData(),testContent.getLen());
    //test end;
    FZZBytes * oidsignedData = contentInfo.getContentType();
    uint32_t oidsignedData_nodes[] = {1,2,156,10197,6,1,4,2,2};
    if ( memcmp(oidsignedData_nodes,oidsignedData->getData(),oidsignedData->getLen() ) != 0 ) {
        return -101;
    }
    FZZSignedData* signedData = contentInfo.getContent();
    if ( signedData == NULL ) {
        return -100;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes digestAct;
    string digestalg = "SM3";
    if ( signAlgName == "1.2.156.10197.1.501" ) {
        digestalg = "SM3";
    }
    gmCrypto.Digest(digestalg.c_str(), tbsContent, digestAct);
    if ( digestAct.getLen() < 8 ) {
        return -20;
    }
    
    FZZContentInfo * tempContentInfo = signedData->getContentInfo();
    if ( tempContentInfo == NULL ) {
        return -100;
    }
    FZZBytes* plaintext = tempContentInfo->getDataContent();
    FZZBytes plaintext_src;
    if ( plaintext->getLen() > 0 ) {
        if ( memcmp(plaintext->getData(),digestAct.getData(),digestAct.getLen() ) != 0 ) {
            //[Compatible with non-standard format] Try to compare after Base64 decoding
            FZZBytes decode;
            FZZConst::Base64_decode((char *)plaintext->getData(), plaintext->getLen(), decode);
            if ( decode.getLen() == 0  ) {
                return -20;
            } else {
                if ( memcmp(decode.getData(),digestAct.getData(),digestAct.getLen() ) != 0 ) {
                    return -20;
                } else {
                    plaintext_src.setData(decode.getData(), decode.getLen()) ;
                }
            }
        } else {
            plaintext_src.setData(plaintext->getData(), plaintext->getLen()) ;
        }
    }
    
    int ret = -20;
    vector<FZZSignerInfo*>* signerInfoList = signedData->getSignerInfos();
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = signerInfoList->begin(); SignerInfo_itr != signerInfoList->end(); SignerInfo_itr++ ) {
        FZZSignerInfo* signerInfo = *SignerInfo_itr;
        if ( signerInfo == NULL ) {
            continue;
        }
        FZZAuthenticatedAttributes* authenticatedAttributes = signerInfo->getAuthenticatedAttributes();
        if ( authenticatedAttributes != NULL ) {
            //pkcs9
            FZZBytes * digest = authenticatedAttributes->getMessageDigest();
            if ( digest->getLen() == 0 ) {
                continue;
            }
            if ( memcmp(digest->getData(),digestAct.getData(),digestAct.getLen() ) != 0 ) {
                return -20;
            }
            plaintext_src = authenticatedAttributes->getPlainText();
            if ( plaintext_src.getLen() <= 0 ) {
                return -101;
            }
        }
        
        //test begin
        //DLOG("plaintext: %s",FZZConst::HexEncode(plaintext_src.getData(), plaintext_src.getLen()).c_str());
        //test end
        FZZCert cert = signedData->getCertSignCert(signerInfo->getIssuer(),signerInfo->getSerialNumber());
        
        signDN = cert.getSubject();
        
        FZZKey* pubkey = cert.getPublicKey();
        if ( pubkey->getKeyDataLen() <= 0 ) {
            return -101;
        }
        FZZBytes * signature = signerInfo->getEncryptedDigest();
        
        if ( verifyFunc == NULL ) {
            if ( !gmCrypto.verifySign(*pubkey,plaintext_src,*signature) ) {
                return -200;
            } else {
                ret = 0;
            }
        } else {
            FZZBytes keyData;
            keyData.setData(pubkey->getKeyData(), pubkey->getKeyDataLen());
            //fzz edit begin 2024.06.07
            //if ( !verifyFunc(callBack_Param,0,keyData,plaintext_src,*signature) ) {
            if ( !verifyFunc(callBack_Param,0,keyData.getData(),(int)keyData.getLen(),plaintext_src.getData(),(int)plaintext_src.getLen(),signature->getData(),(int)signature->getLen()) ) {
            //fzz edit end 2024.06.07
                return -200;
            } else {
                ret = 0;
            }
            
            
        }
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------

