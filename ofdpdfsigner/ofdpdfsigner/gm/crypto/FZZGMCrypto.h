//
//  Created by zizheng fan on 2022/10/26.
//
#ifndef FZZGMCRYPTO_H
#define FZZGMCRYPTO_H


#include "gm/crypto/FZZKeyPair.h"

#include "gmssl/digest.h"

class FZZGMCrypto
{
public:
    static const string CRYPTOTYPE_SM4_CBC;
    static const string CRYPTOTYPE_SM4_GCM;
    static const string CRYPTOTYPE_SM4_CTR;
    static const string CRYPTOTYPE_SM2;
public:
    FZZGMCrypto();
    FZZGMCrypto(const FZZGMCrypto& obj);
	virtual ~FZZGMCrypto();
public:
    FZZBytes generateRandom(int len);
    FZZKey generateKey();
    //SM2 max len 255 => SM2_MAX_PLAINTEXT_SIZE
    //sm4GCM_Mac => CRYPTOTYPE_SM4_GCM 
    FZZBytes Encrypt(FZZKey key,string cryptoType,FZZBytes & sourceData,/*out*/FZZBytes & sm4GCM_Mac);
    FZZBytes Decrypt(FZZKey key,string cryptoType,FZZBytes & EncData,/*in*/FZZBytes & sm4GCM_Mac);
    FZZKeyPair generateKeyPair();
    FZZBytes sign(const FZZKey& priKey,const FZZBytes & sourceData);
    bool verifySign(const FZZKey& pubKey,const FZZBytes & sourceData,const FZZBytes & signData);
    void Digest(const char * const algname,FZZBytes & inData,FZZBytes & outdata);
    int Digest_Init(const char * const algname);
    int Digest_Update(const uint8_t *data, size_t datalen);
    int Digest_Finish(FZZBytes & outdata);
    
    FZZBytes Encrypt_SM4_CBC(FZZKey & key,FZZBytes * iv,FZZBytes & sourceData);
    FZZBytes Decrypt_SM4_CBC(FZZKey & key,FZZBytes * iv,FZZBytes & EncData);
protected:
	
private:

private:
    DIGEST_CTX m_DigestCTX;
};

#endif //FZZGMCRYPTO_H

