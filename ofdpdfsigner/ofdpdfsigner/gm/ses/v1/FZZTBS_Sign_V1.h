//
//  Created by zizheng fan on 2022/11/07.
//
#ifndef FZZTBS_SIGN_V1_H
#define FZZTBS_SIGN_V1_H

#include "gm/ses/v1/FZZSESeal_V1.h"


class FZZTBS_Sign_V1
{
public:
    FZZTBS_Sign_V1();
    FZZTBS_Sign_V1(const unsigned char * data,size_t datalen);
    FZZTBS_Sign_V1(const FZZTBS_Sign_V1& obj);
	virtual ~FZZTBS_Sign_V1();
public:
    uint32_t getVersion() { return m_version; }
    void setVersion(uint32_t version) {
        m_version = version;
    }
    
    FZZSESeal_V1* getEseal() {return m_SESeal_V1;}
    void setEseal(FZZSESeal_V1* seal) {
        if ( m_SESeal_V1 != NULL ) {
            delete m_SESeal_V1;
            m_SESeal_V1 = NULL;
            
        }
        m_SESeal_V1 = new FZZSESeal_V1(*seal);
    }
    
    FZZBytes getTimeStamp() { return m_timeStamp; }
    void setTimeStamp(const FZZBytes& timeStamp) {
        m_timeStamp.setData(timeStamp.getData(),timeStamp.getLen());
    }
    
    
    FZZBytes getDataHash() { return m_dataHash; }
    void setDataHash(const FZZBytes& dataHash) {
        m_dataHash.setData(dataHash.getData(),dataHash.getLen());
    }
    
    string getPropertyInfo() { return m_propertyInfo; }
    void setPropertyInfo(const string& propertyInfo) {
        m_propertyInfo = propertyInfo;
    }
    
    FZZBytes getCert() { return m_Cert; }
    void setCert(const FZZBytes& cert) {
        m_Cert.setData(cert.getData(),cert.getLen());
    }
    
    FZZBytes getSignatureAlgID() { return m_signatureAlgID; }
    void setSignatureAlgID(const FZZBytes & algid) { m_signatureAlgID.setData(algid.getData(),algid.getLen()); }
    
    
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    uint32_t m_version;
    FZZSESeal_V1 * m_SESeal_V1;
    FZZBytes m_timeStamp;
    FZZBytes m_dataHash;
    string m_propertyInfo;
    FZZBytes  m_Cert;
    FZZBytes m_signatureAlgID;
};

#endif //FZZTBS_SIGN_V1_H

