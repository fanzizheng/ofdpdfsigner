//
//  Created by zizheng fan on 2024/10/20.
//
#include "basic/FZZConst.h"
#include "ofd/encrypt/FZZOFDUserPasswordEncryptor.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gmssl/sm4.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDUserPasswordEncryptor*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserPasswordEncryptor::FZZOFDUserPasswordEncryptor() : FZZOFDUserFEKEncryptor(),m_EncSm4CBC(NULL),m_DecSm4CBC(NULL),m_CallBack_Param(NULL)
{
    //DLOG("FZZOFDUserPasswordEncryptor()");
    FZZConst::addClassCount("FZZOFDUserPasswordEncryptor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserPasswordEncryptor::FZZOFDUserPasswordEncryptor(string password,string userName, string userType) : FZZOFDUserPasswordEncryptor()
{
    m_UserInfo.userName = userName;
    if ( userType.empty() ) {
        m_UserInfo.userType = "User";
    } else {
        m_UserInfo.userType = userType;
    }
    m_UserInfo.encryptedWK = "";
    m_UserInfo.ivValue = "";
    m_UserInfo.userCert = "";
    genKey(password,16);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDUserPasswordEncryptor::~FZZOFDUserPasswordEncryptor()
{
    //DLOG("~FZZOFDUserPasswordEncryptor()");
    FZZConst::delClassCount("FZZOFDUserPasswordEncryptor");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserPasswordEncryptor::genKey(string password,int klen)
{
    //国密派生key 密钥交换协议 实现
    //固定为 sm3
    int v = 32; //sm3 文摘长度
    uint32_t ct = 1; // a) 初始化一个32比特构成的计数器 ct = 0x00000001
    unsigned char * K = NULL;
    FZZBytes hai;
    unsigned char tempbuf[4] = {0};
    int len = 0;
    int i = 0;
    FZZGMCrypto gmCrypto;
    
    K = (unsigned char *)malloc(klen);
    if ( K == NULL ) {
        goto err;
    }
    
    // 向上取整 ⌈klen/v⌉
    len = klen / v + (klen % v == 0 ? 0 : 1);
   
    for (i = 0; i < len; i++) {
        // 1) 计算 Hai = Hv(Z || ct);
        gmCrypto.Digest_Init("SM3");
   
        gmCrypto.Digest_Update((unsigned char *)password.c_str(), password.length());
        tempbuf[0] = (uint8_t)(ct >> 24);
        tempbuf[1] = (uint8_t)(ct >> 16);
        tempbuf[2] = (uint8_t)(ct >> 8);
        tempbuf[3] = (uint8_t)ct;
        gmCrypto.Digest_Update((unsigned char *)tempbuf, 4);
        gmCrypto.Digest_Finish(hai);
        // 2) ct++
        ct++;
        // c) 若 ⌈klen/v⌉  是整数，令 Ha!⌈klen/v⌉  =  Ha⌈klen/v⌉
        //    否则，令 Ha!⌈klen/v⌉  为 Ha⌈klen/v⌉ 最左边的(klen-(v*⌊klen/v⌋))比特
        if (i + 1 == len && klen % v != 0) {
            memcpy(K+v * (klen / v), hai.getData(), klen - (v * (klen / v)));
        } else {
            memcpy(K+v*i, hai.getData(), v);
        }
        // d) 令 K = Ha1 || Ha2 || ... || Ha⌈klen/v⌉-1 || Ha!⌈klen/v⌉
    }
    m_fKek.setData(K, klen);
    
    //DLOG("FZZOFDUserPasswordEncryptor::genKey => %s",FZZConst::HexEncode(m_fKek.getData(), m_fKek.getLen()).c_str());
err:
    if ( K != NULL ) {
        free(K);
        K = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
TUserInfo* FZZOFDUserPasswordEncryptor::encrypt(FZZBytes & fek,FZZBytes & iv)
{
    if ( m_fKek.getLen() <= 0 ) {
        return &m_UserInfo;
    }
    FZZBytes wk;
//    SM4_KEY enc_key;
//    sm4_set_encrypt_key(&enc_key, m_fKek.getData());
//
//    size_t outWklen = 0;
//    wk.setMaxLen(fek.getLen()+16);
//
//    int retint = sm4_cbc_padding_encrypt(&enc_key, iv.getData(), fek.getData(), fek.getLen(), wk.getData(), &outWklen);
//    if ( retint == 1 ) {
//        wk.setLen(outWklen);
//    } else {
//        wk.clear();
//    }
    FZZKey key;
    key.setKeyType(FZZKey::KEYTYPE_SM4);
    key.setKeyData(m_fKek.getData(),(int)m_fKek.getLen());
    if ( m_EncSm4CBC == NULL ) {
        FZZGMCrypto crypto;
        wk = crypto.Encrypt_SM4_CBC(key, &iv, fek);
    } else {
        wk = Encrypt_SM4CBC(key, iv, &fek);
    }
    m_UserInfo.ivValue = FZZConst::Base64Encode(iv.getData(), iv.getLen());
    m_UserInfo.encryptedWK = FZZConst::Base64Encode(wk.getData(), wk.getLen());
    
    return &m_UserInfo;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDUserPasswordEncryptor::decrypt(FZZBytes & ewk,FZZBytes & iv)
{
    FZZBytes wk;
    if ( m_fKek.getLen() <= 0 ) {
        return wk;
    }
    
    FZZKey key;
    key.setKeyType(FZZKey::KEYTYPE_SM4);
    key.setKeyData(m_fKek.getData(),(int)m_fKek.getLen());
    
    if ( m_DecSm4CBC == NULL ) {
        FZZGMCrypto crypto;
        wk = crypto.Decrypt_SM4_CBC(key, &iv, ewk);
    } else {
        wk = Decrypt_SM4CBC(key, iv, &ewk);
    }
    return wk;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserPasswordEncryptor::encryptCaseId()
{
    return FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMPassword);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDUserPasswordEncryptor::userCert()
{
    return "";
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDUserPasswordEncryptor::Encrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata)
{
    FZZBytes encFileData;
    if ( m_EncSm4CBC != NULL ) {
        size_t encBufferLen = 0;
        m_EncSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),NULL, &encBufferLen);
        
        if ( encBufferLen <= 0 ) {
            return encFileData;
        }
        unsigned char * encbuffer = (unsigned char *)malloc(encBufferLen);
        if ( encbuffer == NULL ) {
            return encFileData;
        }
        m_EncSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),&encbuffer, &encBufferLen);
        if (encBufferLen <= 0) {
            free(encbuffer);
            encbuffer = NULL;
            return encFileData;
        }
        
        encFileData.setData(encbuffer, encBufferLen);
        
        free(encbuffer);
        encbuffer = NULL;
    }
    return encFileData;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDUserPasswordEncryptor::Decrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata)
{
    FZZBytes decFileData;
    if ( m_DecSm4CBC != NULL ) {
        size_t decBufferLen = 0;
        m_DecSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),NULL, &decBufferLen);
        
        if ( decBufferLen <= 0 ) {
            return decFileData;
        }
        unsigned char * decbuffer = (unsigned char *)malloc(decBufferLen);
        if ( decbuffer == NULL ) {
            return decFileData;
        }
        m_DecSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),&decbuffer, &decBufferLen);
        if (decBufferLen <= 0) {
            free(decbuffer);
            decbuffer = NULL;
            return decFileData;
        }
        
        decFileData.setData(decbuffer, decBufferLen);
        
        free(decbuffer);
        decbuffer = NULL;
    }
    return decFileData;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDUserPasswordEncryptor::setCryptCallBack(CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,void * callBack_Param)
{
    m_EncSm4CBC = encSm4CBC;
    m_DecSm4CBC = decSm4CBC;
    m_CallBack_Param = callBack_Param;
}
//-----------------------------------------------------------------------------------------------------------------
