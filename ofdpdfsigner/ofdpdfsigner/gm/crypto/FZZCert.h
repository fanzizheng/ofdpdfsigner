//
//  Created by zizheng fan on 2022/10/28.
//
#ifndef FZZCERT_H
#define FZZCERT_H

#include "gmssl/x509.h"
#include "gm/crypto/FZZKeyPair.h"

class FZZCert
{
public:
    FZZCert();
    FZZCert(const FZZCert& obj);
    ~FZZCert();
    const FZZCert& operator=(const FZZCert& data);
public:
    bool loadCert(const FZZBytes & certdata);
    bool loadCert(const unsigned char * certdata, size_t certdatalen);
    FZZBytes getCertData() { return m_CertData; }
    
    int getVersion() { return m_Version+1; }
    string getSerialNumber() { return m_SerialNumber; }
    FZZBytes getSerialNumberBytes() { return m_SerialNumberBytes;}
    string getIssuer() { return m_Issuer; }
    string getSubject() { return m_Subject; }
    //begin time
    string getNotBefore() { return m_NotBefore; }
    //end time
    string getNotAfter() { return m_NotAfter; }
    string getSignatureAlgor() { return m_SignatureAlgor; }
    string getInnerSignatureAlgor() { return m_InnerSignatureAlgor; }
    FZZKey* getPublicKey() { return &m_PublicKey; }
    
    bool CheckTermOfValidity();
    bool CheckCert(FZZBytes & rootCert);
    
    string get_x509_name_rdn(const uint8_t *d, size_t dlen);
    
private:
    
    string get_x509_rdn(const uint8_t *d, size_t dlen);
    string get_x509_attr_type_and_value(const uint8_t *d, size_t dlen);
    string get_format_string(const uint8_t *d, size_t dlen);
    string get_asn1_string(const uint8_t *d, size_t dlen);
private:
    
    FZZBytes m_CertData;
    X509_Version m_Version;
    string m_SerialNumber;
    FZZBytes m_SerialNumberBytes;
    string m_Issuer;
    string m_Subject;
    string m_NotBefore;
    string m_NotAfter;
    string m_SignatureAlgor;
    string m_InnerSignatureAlgor;
    FZZKey m_PublicKey;
    
};

#endif //FZZCERT_H

