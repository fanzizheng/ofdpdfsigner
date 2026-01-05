//
//  Created by zizheng fan on 2022/10/26.
//
#include "basic/FZZConst.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gmssl/sm2.h"
#include "gmssl/rand.h"
#include "gmssl/sm4.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZGMCrypto******************************************************/
//-----------------------------------------------------------------------------------------------------------------
const string FZZGMCrypto::CRYPTOTYPE_SM4_CBC = "SM4_CBC";
const string FZZGMCrypto::CRYPTOTYPE_SM4_GCM = "SM4_GCM";
const string FZZGMCrypto::CRYPTOTYPE_SM4_CTR = "SM4_CTR";
const string FZZGMCrypto::CRYPTOTYPE_SM2 = "SM2";
//-----------------------------------------------------------------------------------------------------------------
FZZGMCrypto::FZZGMCrypto()
{
    //DLOG("FZZGMCrypto()");
    FZZConst::addClassCount("FZZGMCrypto");
   
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZGMCrypto::FZZGMCrypto(const FZZGMCrypto& obj):FZZGMCrypto()
{
    //DLOG("FZZGMCrypto(const FZZGMCrypto& obj)");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZGMCrypto::~FZZGMCrypto()
{
    //DLOG("~FZZGMCrypto()");
    FZZConst::delClassCount("FZZGMCrypto");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::generateRandom(int len)
{
    FZZBytes ret;
    if ( len <= 4000 ) {
        ret.setMaxLen(len);
        if ( rand_bytes(ret.getData(),len) != 1 ) {
            ret.clear();
            return ret;
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZKey FZZGMCrypto::generateKey()
{
    FZZBytes keyData = generateRandom(16);
    FZZKey key;
    if ( keyData.getLen() == 16 ) {
        key.setKeyType(FZZKey::KEYTYPE_SM4);
        key.setKeyData(keyData.getData(),(int)keyData.getLen());
    }
    return key;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::Encrypt(FZZKey key,string cryptoType,FZZBytes & sourceData,/*out*/FZZBytes & sm4GCM_Mac)
{
    FZZBytes ret;
    sm4GCM_Mac.clear();
    int retint = -1;
    size_t outlen = 0;
    if ( key.getKeyType() == FZZKey::KEYTYPE_SM4 ) {
        SM4_KEY enc_key;
        sm4_set_encrypt_key(&enc_key, key.getKeyData());
        
        uint8_t iv_cbc[16] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F'};
        uint8_t iv_GCM[12] = {0x00,0x00,0x12,0x34,0x56,0x78,0x00,0x00,0x00,0x00,0xAB,0xCD};
        uint8_t aad_GCM[20] = {0xFE,0xED,0xFA,0xCE,0xDE,0xAD,0xBE,0xEF,0xFE,0xED,0xFA,0xCE,0xDE,0xAD,0xBE,0xEF,0xAB,0xAD,0xDA,0xD2};
        //uint8_t tag_GCM[16] = {0x83,0xDE,0x35,0x41,0xE4,0xC2,0xB5,0x81,0x77,0xE0,0x65,0xA9,0xBF,0x7B,0x62,0xEC};
        
        ret.setMaxLen(sourceData.getLen()+16);
      
    
        if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_CBC ) {
            retint = sm4_cbc_padding_encrypt(&enc_key, iv_cbc, sourceData.getData(), sourceData.getLen(), ret.getData(), &outlen);
        } else if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_GCM ) {
            sm4GCM_Mac.setMaxLen(16);
            retint = sm4_gcm_encrypt(&enc_key, iv_GCM, 12, aad_GCM, 20, sourceData.getData(), sourceData.getLen(), ret.getData(), 16, sm4GCM_Mac.getData());
            outlen = sourceData.getLen();
            sm4GCM_Mac.setLen(16);
        } else if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_CTR ) {
            sm4_ctr_encrypt(&enc_key, iv_cbc, sourceData.getData(), sourceData.getLen(), ret.getData());
            outlen = sourceData.getLen();
            retint = 1;
        }
        
    } else if ( key.getKeyType() == FZZKey::KEYTYPE_SM2_PUB_KEY ) {
        SM2_KEY sm2_key;
        memset(&sm2_key,0x00,sizeof(SM2_KEY));
        size_t len = key.getKeyDataLen();
        const uint8_t *cp = key.getKeyData();
        if (sm2_public_key_info_from_der(&sm2_key, &cp, &len) != 1 ) {
            return ret;
        }
        ret.setMaxLen(sourceData.getLen()+120);
        retint = sm2_encrypt(&sm2_key, sourceData.getData(), sourceData.getLen(), ret.getData(), &outlen);
    }
    
    if ( retint == 1 ) {
        ret.setLen(outlen);
    } else {
        ret.clear();
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::Decrypt(FZZKey key,string cryptoType,FZZBytes & EncData,/*in*/FZZBytes & sm4GCM_Mac)
{
    FZZBytes ret;
    size_t outlen = 0;
    int retint = -1;
    if ( key.getKeyType() == FZZKey::KEYTYPE_SM4 ) {
        SM4_KEY dec_key;
        
        uint8_t iv_cbc[16] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F'};
        uint8_t iv_GCM[12] = {0x00,0x00,0x12,0x34,0x56,0x78,0x00,0x00,0x00,0x00,0xAB,0xCD};
        uint8_t aad_GCM[20] = {0xFE,0xED,0xFA,0xCE,0xDE,0xAD,0xBE,0xEF,0xFE,0xED,0xFA,0xCE,0xDE,0xAD,0xBE,0xEF,0xAB,0xAD,0xDA,0xD2};
        
        ret.setMaxLen(EncData.getLen()+16);
        
        if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_CBC ) {
            sm4_set_decrypt_key(&dec_key, key.getKeyData());
            retint = sm4_cbc_padding_decrypt(&dec_key, iv_cbc, EncData.getData(), (size_t)EncData.getLen(), ret.getData(), &outlen);
        } else if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_GCM ) {
            sm4_set_encrypt_key(&dec_key, key.getKeyData());
            retint = sm4_gcm_decrypt(&dec_key, iv_GCM, 12, aad_GCM, 20, EncData.getData(), (size_t)EncData.getLen(), sm4GCM_Mac.getData(), sm4GCM_Mac.getLen(), ret.getData());
            outlen = (size_t)EncData.getLen();
        } else if ( cryptoType == FZZGMCrypto::CRYPTOTYPE_SM4_CTR ) {
            sm4_set_encrypt_key(&dec_key, key.getKeyData());
            sm4_ctr_decrypt(&dec_key, iv_cbc, EncData.getData(), (size_t)EncData.getLen(), ret.getData());
            outlen = (size_t)EncData.getLen();
            retint = 1;
        }
        
    } else if ( key.getKeyType() == FZZKey::KEYTYPE_SM2_PRI_KEY ) {
        SM2_KEY sm2_key;
        memset(&sm2_key,0x00,sizeof(SM2_KEY));
        size_t len = key.getKeyDataLen();
        const uint8_t *cp = key.getKeyData();
        if (sm2_private_key_from_der(&sm2_key, &cp, &len) != 1 ) {
            return ret;
        }
        ret.setMaxLen(EncData.getLen());
        retint = sm2_decrypt(&sm2_key, EncData.getData(), (size_t)EncData.getLen(), ret.getData(), &outlen);
    }
    
    if ( retint == 1 ) {
        ret.setLen(outlen);
    } else {
        ret.clear();
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::Encrypt_SM4_CBC(FZZKey &key,FZZBytes * iv,FZZBytes & sourceData)
{
    FZZBytes ret;
    int retint = -1;
    size_t outretlen = 0;
    if ( key.getKeyType() == FZZKey::KEYTYPE_SM4 ) {
        SM4_KEY enc_key;
        sm4_set_encrypt_key(&enc_key, key.getKeyData());

        uint8_t iv_cbc[16] = {0};
        memcpy(iv_cbc,iv->getData(),iv->getLen() > 16? 16 : iv->getLen());
        //DLOG("enc iv:%s",FZZConst::HexEncode(iv->getData(),iv->getLen()).c_str());
        
        ret.setMaxLen(sourceData.getLen()+16);

        retint = sm4_cbc_padding_encrypt(&enc_key, iv_cbc, sourceData.getData(), sourceData.getLen(), ret.getData(), &outretlen);

    }
    if ( retint == 1 ) {
        ret.setLen(outretlen);
    } else {
        ret.clear();
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::Decrypt_SM4_CBC(FZZKey &key,FZZBytes * iv,FZZBytes & EncData)
{
    FZZBytes ret;
    size_t outlen = 0;
    int retint = -1;
    if ( key.getKeyType() == FZZKey::KEYTYPE_SM4 ) {
        SM4_KEY dec_key;
        uint8_t iv_cbc[16] = {0};
        memcpy(iv_cbc,iv->getData(),iv->getLen() > 16? 16 : iv->getLen());
        //DLOG("enc iv:%s",FZZConst::HexEncode(iv->getData(),iv->getLen()).c_str());
        
        ret.setMaxLen(EncData.getLen()+16);
        
        sm4_set_decrypt_key(&dec_key, key.getKeyData());
        retint = sm4_cbc_padding_decrypt(&dec_key, iv_cbc, EncData.getData(), (size_t)EncData.getLen(), ret.getData(), &outlen);
        
    }
    if ( retint == 1 ) {
        ret.setLen(outlen);
    } else {
        ret.clear();
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
FZZKeyPair FZZGMCrypto::generateKeyPair()
{
    FZZKeyPair retKeyPair;
    SM2_KEY sm2_key;
    memset(&sm2_key,0x00,sizeof(SM2_KEY));
    if ( sm2_key_generate(&sm2_key) == 1 ) {
        uint8_t pub_buf[256] = {0};
        uint8_t pri_buf[256] = {0};
        size_t pub_len = 0,pri_len = 0;
        uint8_t *p = pub_buf;
        
        if (sm2_public_key_info_to_der(&sm2_key, &p, &pub_len) != 1) {
            return retKeyPair;
        }
        
        p = pri_buf;
        if (sm2_private_key_to_der(&sm2_key, &p, &pri_len) != 1) {
            return retKeyPair;
        }
        
        FZZKey pubKey(FZZKey::KEYTYPE_SM2_PUB_KEY,"",pub_buf,(int)pub_len);
        FZZKey priKey(FZZKey::KEYTYPE_SM2_PRI_KEY,"",pri_buf,(int)pri_len);
        retKeyPair.setPublicKey(pubKey);
        retKeyPair.setPrivateKey(priKey);
    }
     
    return retKeyPair;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZGMCrypto::sign(const FZZKey& priKey,const FZZBytes & sourceData)
{
    FZZBytes ret;
    SM2_SIGN_CTX ctx;
    SM2_KEY sm2_key;
    
    memset(&sm2_key,0x00,sizeof(SM2_KEY));
    size_t len = priKey.getKeyDataLen();
    const uint8_t *cp = priKey.getKeyData();
    if (sm2_private_key_from_der(&sm2_key, &cp, &len) != 1 ) {
        return ret;
    }
    
    if (sm2_sign_init(&ctx, &sm2_key, SM2_DEFAULT_ID,strlen(SM2_DEFAULT_ID))!= 1 ) {
        return ret;
    }
    if (sm2_sign_update(&ctx, sourceData.getData(), sourceData.getLen())!= 1 ) {
        return ret;
    }
    
    uint8_t sig[128] = {0};
    size_t siglen = sizeof(sig);
    
    if (sm2_sign_finish(&ctx, sig, &siglen)!= 1 ) {
        return ret;
    }
    
    ret.setData(sig, siglen);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZGMCrypto::verifySign(const FZZKey& pubKey,const FZZBytes & sourceData,const FZZBytes & signData)
{
    SM2_KEY sm2_key;
    memset(&sm2_key,0x00,sizeof(SM2_KEY));
    size_t len = pubKey.getKeyDataLen();
    const uint8_t *cp = pubKey.getKeyData();
    if (sm2_public_key_info_from_der(&sm2_key, &cp, &len) != 1 ) {
        return false;
    }
    SM2_SIGN_CTX ctx;
    
    if ( sm2_verify_init(&ctx, &sm2_key, SM2_DEFAULT_ID,strlen(SM2_DEFAULT_ID)) != 1) {
        return false;
    }
    if ( sm2_verify_update(&ctx, sourceData.getData(), sourceData.getLen()) != 1) {
        return false;
    }
    if ( sm2_verify_finish(&ctx, signData.getData(), signData.getLen()) == 1 ) {
        return true;
    } else {
        return false;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/*
 "md5",
"sha1",
"sm3",
"sha224",
"sha256",
"sha384",
"sha512",
"sha512-224",
"sha512-256",
 */
void FZZGMCrypto::Digest(const char * const algname,FZZBytes & inData,FZZBytes & outdata)
{
    uint8_t dgst[64];
    size_t dgstlen;
    const DIGEST *algor = digest_from_name(algname);
    digest(algor, (uint8_t *)inData.getData(), inData.getLen(), dgst, &dgstlen);
    if ( dgstlen > 0 ) {
        outdata.setData(dgst, dgstlen);
    }
}
//-----------------------------------------------------------------------------------------------------------------
/*
 "md5",
"sha1",
"sm3",
"sha224",
"sha256",
"sha384",
"sha512",
"sha512-224",
"sha512-256",
 */
int FZZGMCrypto::Digest_Init(const char * const algname)
{
    memset(&m_DigestCTX, 0, sizeof(DIGEST_CTX));
    const DIGEST *algor = digest_from_name(algname);
    if (digest_init(&m_DigestCTX, algor) != 1 ) {
        return -1;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZGMCrypto::Digest_Update(const uint8_t *data, size_t datalen)
{
    if ( digest_update(&m_DigestCTX, data, datalen) < 0 ) {
        return -1;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZGMCrypto::Digest_Finish(FZZBytes & outdata)
{
    uint8_t dgst[64];
    size_t dgstlen;
    if ( digest_finish(&m_DigestCTX, dgst, &dgstlen) != 1) {
        return -1;
    }
    if ( dgstlen > 0 ) {
        outdata.setData(dgst, dgstlen);
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------


