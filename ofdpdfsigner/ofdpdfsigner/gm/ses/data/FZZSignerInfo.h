//
//  Created by zizheng fan on 2022/11/03.
//
#ifndef FZZSIGNERINFO_H
#define FZZSIGNERINFO_H

#include "basic/FZZBytes.h"
#include "gm/ses/data/FZZAuthenticatedAttributes.h"
#include "gm/ses/data/FZZUnAuthenticatedAttributes.h"

class FZZSignerInfo
{
public:
    FZZSignerInfo();
    FZZSignerInfo(const unsigned char * data,size_t datalen);
    FZZSignerInfo(const FZZBytes & data);
    FZZSignerInfo(const FZZSignerInfo& obj);
    virtual ~FZZSignerInfo();
public:
    uint32_t getVersion() { return m_version; }
    void setVersion(uint32_t version) { m_version = version; }
    
    FZZBytes * getSerialNumber() { return &m_SerialNumber; }
    void setSerialNumber(FZZBytes & serialNumber) { m_SerialNumber = serialNumber; }
    
    string getIssuer() { return m_Issuer; }
    void setIssuer(string issuer) { m_Issuer = issuer; }
    
    FZZBytes* getDigestAlgorithm() { return &m_digestAlgorithm; }
    void setDigestAlgorithm(FZZBytes& digestAlgorithm) { m_digestAlgorithm = digestAlgorithm; }
    
    FZZBytes* getDigestEncryptionAlgorithm() { return &m_digestEncryptionAlgorithm; }
    void setDigestEncryptionAlgorithm(FZZBytes& digestEncryptionAlgorithm) { m_digestEncryptionAlgorithm = digestEncryptionAlgorithm; }
    
    FZZBytes* getEncryptedDigest() { return &m_encryptedDigest; }
    void setEncryptedDigest(FZZBytes& encryptedDigest) { m_encryptedDigest = encryptedDigest; }
    
    FZZAuthenticatedAttributes* getAuthenticatedAttributes() { return m_authenticatedAttributes; }
    void setAuthenticatedAttributes(FZZAuthenticatedAttributes* authenticatedAttributes) {
        if ( m_authenticatedAttributes != NULL ) {
            delete m_authenticatedAttributes;
            m_authenticatedAttributes = NULL;
        }
        m_authenticatedAttributes = new FZZAuthenticatedAttributes(*authenticatedAttributes);
    }
    
    FZZUnAuthenticatedAttributes* getUnAuthenticatedAttributes() { return m_unauthenticatedAttributes; }
    void setUnAuthenticatedAttributes(FZZUnAuthenticatedAttributes* unAuthenticatedAttributes) {
        if ( m_unauthenticatedAttributes != NULL ) {
            delete m_unauthenticatedAttributes;
            m_unauthenticatedAttributes = NULL;
        }
        m_unauthenticatedAttributes = new FZZUnAuthenticatedAttributes(*unAuthenticatedAttributes);
    }
    
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:

private:
    
private:
    uint32_t m_version;
    FZZBytes m_SerialNumber;
    string m_Issuer;
    FZZBytes m_digestAlgorithm;
    FZZBytes m_digestEncryptionAlgorithm;
    FZZBytes m_encryptedDigest;
    
    //Is a collection of attributes signed by the signer. This field is optional. If the domain exists,
    //The summary calculation method in this field is to summarize the results of the original text.
    FZZAuthenticatedAttributes* m_authenticatedAttributes;
    //Not implemented
    //vector<FZZBytes*> m_unauthenticatedAttributes;
    FZZUnAuthenticatedAttributes * m_unauthenticatedAttributes;
};

#endif //FZZSIGNERINFO_H


