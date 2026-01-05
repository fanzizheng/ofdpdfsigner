//
//  Created by zizheng fan on 2023/03/03.
//
#include "basic/FZZConst.h"
#include "ofd/sign/verify/container/FZZSESV4ValidateContainer.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
#include "gm/ses/v4/FZZTBS_Sign_V4.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
#include "gm/crypto/FZZGMCrypto.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESV4ValidateContainer*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSESV4ValidateContainer::FZZSESV4ValidateContainer() : FZZSignedDataValidateContainer()
{
    //DLOG("FZZSESV4ValidateContainer()");
    FZZConst::addClassCount("FZZSESV4ValidateContainer");
    
    
}
//-----------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------
FZZSESV4ValidateContainer::~FZZSESV4ValidateContainer()
{
    //DLOG("~FZZSESV4ValidateContainer()");
    FZZConst::delClassCount("FZZSESV4ValidateContainer");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-1 : must seal type
//-20 : Digest error
//-30 : The Signature.xml file has been tampered with
//-100 : get TBS_Sign error;
//-200 :  verifySign error;
//-201 :  load cert error;
int FZZSESV4ValidateContainer::validate(FZZOFDSigType::TYPE type, string signAlgName, CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN)
{
    if (type == FZZOFDSigType::TYPE::TYPE_Sign) {
        return -1;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes actualDataHash;
    string digestalg = "SM3";
    if ( signAlgName == "1.2.156.10197.1.501" ) {
        digestalg = "SM3";
    }
    gmCrypto.Digest(digestalg.c_str(), tbsContent, actualDataHash);
    if ( actualDataHash.getLen() < 8 ) {
        return -20;
    }
    
    FZZSES_Signature_V4 sesSignature(signedValue);
    FZZTBS_Sign_V4* toSign = sesSignature.getToSign();
    if ( toSign == NULL ) {
        return -100;
    }
    
    FZZBytes expectDataHash = toSign->getDataHash();
    if ( memcmp(actualDataHash.getData(),expectDataHash.getData(),actualDataHash.getLen() ) != 0 ) {
        return -30;
    }
    
    FZZBytes expSigVal = sesSignature.getSignature();
    FZZBytes certDER = sesSignature.getCert();
    FZZBytes sourcedata = toSign->Encode();
    
    FZZCert cert;
    if ( !cert.loadCert(certDER) ) {
        return -201;
    }
    signDN = cert.getSubject();
    FZZKey* pubkey = cert.getPublicKey();
    
    
    if ( verifyFunc == NULL ) {
        if ( !gmCrypto.verifySign(*pubkey,sourcedata,expSigVal) ) {
            return -200;
        }
    } else {
        FZZBytes keyData;
        keyData.setData(pubkey->getKeyData(), pubkey->getKeyDataLen());
        //fzz edit edit 2024.06.07
//        if ( !verifyFunc(callBack_Param,0,keyData,sourcedata,expSigVal) ) {
//            return -200;
//        }
        if ( !verifyFunc(callBack_Param,0,keyData.getData(),(int)keyData.getLen(),sourcedata.getData(),(int)sourcedata.getLen(),expSigVal.getData(),(int)expSigVal.getLen()) ) {
            return -200;
        }
        //fzz edit end 2024.06.07
    }
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------

