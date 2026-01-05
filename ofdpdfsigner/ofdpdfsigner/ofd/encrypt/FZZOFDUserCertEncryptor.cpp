//
//  Created by zizheng fan on 2024/10/20.
//
#include "basic/FZZConst.h"
#include "ofd/encrypt/FZZOFDUserCertEncryptor.h"
#include "gm/crypto/FZZCert.h"
#include "gm/crypto/FZZGMCrypto.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDUserCertEncryptor*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserCertEncryptor::FZZOFDUserCertEncryptor() : FZZOFDUserFEKEncryptor(),m_EncSM2(NULL),m_CallBack_Param(NULL)
{
    //DLOG("FZZOFDUserCertEncryptor()");
    FZZConst::addClassCount("FZZOFDUserCertEncryptor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserCertEncryptor::FZZOFDUserCertEncryptor(string cert,string userName, string userType) : FZZOFDUserCertEncryptor()
{
    m_UserInfo.userName = userName;
    if ( userType.empty() ) {
        m_UserInfo.userType = "User";
    } else {
        m_UserInfo.userType = userType;
    }
    m_UserInfo.encryptedWK = "";
    m_UserInfo.ivValue = "";
    m_UserInfo.userCert = cert;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserCertEncryptor::~FZZOFDUserCertEncryptor()
{
    //DLOG("~FZZOFDUserCertEncryptor()");
    FZZConst::delClassCount("FZZOFDUserCertEncryptor");
    
}
//-----------------------------------------------------------------------------------------------------------------
TUserInfo* FZZOFDUserCertEncryptor::encrypt(FZZBytes & fek,FZZBytes & iv)
{
    FZZBytes certData;
    FZZConst::Base64_decode(m_UserInfo.userCert.c_str(), m_UserInfo.userCert.length(), certData);
    if ( certData.getLen() <= 0 ) {
        return &m_UserInfo;
    }

    FZZCert cert;
    if ( !cert.loadCert(certData) ) {
        return &m_UserInfo;
    }

    FZZKey* publicKey = cert.getPublicKey();
    if ( publicKey == NULL ) {
        return &m_UserInfo;
    }
    
    //-------test---------
//    string strpubkey = "MFkwEwYHKoZIzj0CAQYIKoEcz1UBgi0DQgAEiKRjRJJYpcPlbBpXJPsSnnw0xNvoVzh11bT0i6svautmucaQ97WRHcU14BOQjRQafc2th6zcvOeJ+Ii+NlIFDQ==";
//    FZZBytes pkdata;
//    FZZConst::Base64_decode(strpubkey.c_str(), strpubkey.length(), pkdata);
//    FZZKey publicKeyi;
//    FZZKey* publicKey = &publicKeyi;
//    publicKeyi.setKeyID("");
//    publicKeyi.setKeyType(FZZKey::KEYTYPE_SM2_PUB_KEY);
//    publicKey->setKeyData(pkdata.getData(), pkdata.getLen());
    //--------------------
    FZZBytes wk;
    if ( m_EncSM2 == NULL ) {
        FZZGMCrypto crypto;
        FZZBytes sm4GCM_Mac;
        wk = crypto.Encrypt(*publicKey, "", fek, sm4GCM_Mac);
    } else {
        size_t encBufferLen = 0;
        m_EncSM2(m_CallBack_Param,publicKey->getKeyData(),(int)publicKey->getKeyDataLen(),fek.getData(),(int)fek.getLen(),NULL, &encBufferLen);
        
        if ( encBufferLen <= 0 ) {
            return &m_UserInfo;
        }
        unsigned char * encbuffer = (unsigned char *)malloc(encBufferLen);
        if ( encbuffer == NULL ) {
            return &m_UserInfo;
        }
        m_EncSM2(m_CallBack_Param,publicKey->getKeyData(),(int)publicKey->getKeyDataLen(),fek.getData(),(int)fek.getLen(),&encbuffer, &encBufferLen);
        if (encBufferLen <= 0) {
            free(encbuffer);
            encbuffer = NULL;
            return &m_UserInfo;
        }
        
        wk.setData(encbuffer, encBufferLen);
        
        free(encbuffer);
        encbuffer = NULL;
    }
    
    m_UserInfo.ivValue = FZZConst::Base64Encode(iv.getData(), iv.getLen());
    m_UserInfo.encryptedWK = FZZConst::Base64Encode(wk.getData(), wk.getLen());
    
    return &m_UserInfo;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserCertEncryptor::encryptCaseId()
{
    return FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMCert);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserCertEncryptor::userCert()
{
    
    return m_UserInfo.userCert;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserCertEncryptor::setCryptCallBack(CallBack_EncryptSM2 encSM2,void * callBack_Param)
{
    
    m_EncSM2 = encSM2;
    m_CallBack_Param = callBack_Param;
}
//-----------------------------------------------------------------------------------------------------------------
