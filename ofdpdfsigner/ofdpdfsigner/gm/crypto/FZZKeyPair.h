//
//  Created by zizheng fan on 2022/10/27.
//
#ifndef FZZKEYPAIR_H
#define FZZKEYPAIR_H

#include "gm/crypto/FZZKey.h"

class FZZKeyPair
{
public:
    FZZKeyPair();
    FZZKeyPair(const FZZKey & Public,const FZZKey & Private);
    FZZKeyPair(const FZZKeyPair& obj);
	virtual ~FZZKeyPair();
    const FZZKeyPair& operator=(const FZZKeyPair& data);
public:
    void setPublicKey(const FZZKey& publicKey) {m_Public = publicKey;}
    FZZKey getPublicKey() const { return m_Public; }
    void setPrivateKey(const FZZKey& privateKey) {m_Private = privateKey;}
    FZZKey getPrivateKey() const { return m_Private; }
    
protected:
	
private:

private:
    FZZKey m_Public;
    FZZKey m_Private;
};

#endif //FZZKEYPAIR_H

