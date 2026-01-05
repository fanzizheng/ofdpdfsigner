//
//  Created by zizheng fan on 2022/10/28.
//
#ifndef FZZCERTGENERATOR_H
#define FZZCERTGENERATOR_H

#include "gmssl/x509.h"
#include "gm/crypto/FZZKeyPair.h"

class FZZCertGenerator
{
public:
    FZZCertGenerator();
    ~FZZCertGenerator();
    
public:
    
    void setIssuer(string Issuer) { m_Issuer = Issuer; }
    void setSubject(string Subject) { m_Subject = Subject; }
    void setNotBefore(time_t NotBefore) { m_NotBefore = NotBefore; }
    void addDays(int days) { m_AddDays = days; }
    void setSerialNumber(FZZBytes & SerialNumber) { m_SerialNumber = SerialNumber; }
    void setCertPublicKey(FZZKey& publickey) { m_PublicKey = publickey; }
    void setSignPrivateKey(FZZKey& privatekey) { m_PrivateKey = privatekey; }
    void setKeyUsage(int KeyUsage) { m_KeyUsage = KeyUsage; }
    
    void clearData();
    
    FZZBytes genCert();
    int set_x509_name(string value,uint8_t *name, size_t *namelen, size_t maxlen);
private:
    
private:
    string m_Issuer;
    string m_Subject;
    time_t m_NotBefore;
    int m_AddDays;
    FZZBytes m_SerialNumber;
    FZZKey m_PublicKey;
    FZZKey m_PrivateKey;
    int m_KeyUsage;
};

#endif //FZZCERTGENERATOR_H

