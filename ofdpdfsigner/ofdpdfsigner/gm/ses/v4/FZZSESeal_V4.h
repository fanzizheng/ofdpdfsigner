//
//  Created by zizheng fan on 2022/11/15.
//
#ifndef FZZSESEAL_V4_H
#define FZZSESEAL_V4_H

#include "gm/ses/v4/FZZSES_SealInfo_V4.h"
#include "gm/crypto/FZZKey.h"

class FZZSESeal_V4
{
public:
    FZZSESeal_V4();
    FZZSESeal_V4(const unsigned char * data,size_t datalen);
    FZZSESeal_V4(const FZZBytes & data);
    FZZSESeal_V4(const FZZSESeal_V4& obj);
	virtual ~FZZSESeal_V4();
public:
    FZZSES_SealInfo_V4* getSealInfo() {return m_SealInfo;}
    void setSealInfo(FZZSES_SealInfo_V4 * sealinfo)
    {
        if ( m_SealInfo != NULL ) {
            delete m_SealInfo;
            m_SealInfo = NULL;
        }
        m_SealInfo = new FZZSES_SealInfo_V4(*sealinfo);
    }
    
    FZZBytes getCert() { return m_Cert; }
    void setCert(const FZZBytes& cert) {
        m_Cert.setData(cert.getData(),cert.getLen());
    }
    
    FZZBytes getSignAlgID() { return m_signatureAlgID; }
    void setSignAlgID(const FZZBytes & algid) { m_signatureAlgID.setData(algid.getData(),algid.getLen()); }
    
    FZZBytes getSignedValue() { return m_signedValue; }
    void setSignedValue(const FZZBytes& signedValue) {
        m_signedValue.setData(signedValue.getData(),signedValue.getLen());
    }
    
    FZZBytes getUserCert();
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
    
    bool Verify();
    int Verify(CallBack_Verify verifyFunc,const void * callBack_Param);
protected:
	
private:

private:
    FZZSES_SealInfo_V4 * m_SealInfo;
    FZZBytes m_Cert;
    FZZBytes m_signatureAlgID;
    FZZBytes m_signedValue;
};

class FZZCreateSESeal_V4
{
public:
    FZZBytes CreateSeal(FZZBytes & cert_sealUser,FZZBytes & cert_seal,FZZKey & PriKey_cert_seal,
                     string sealname,time_t createDate,time_t startDate,int addDay,
                     string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                     string sealID);
    
    FZZBytes CreateSeal(CallBack_getUserCert getCertFunc,CallBack_getSealCert getSealCertFunc,CallBack_Sign signFunc,
                     const void * callBack_Param,
                     string sealname,time_t createDate,time_t startDate,int addDay,
                     string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                     string sealID);
    
    FZZBytes CreateSeal(CallBack_getUserCert getCertFunc,CallBack_getSealCert getSealCertFunc,CallBack_Sign signFunc,
                     const void * callBack_Param,
                     int type,string sealname,time_t createDate,time_t startDate,time_t endDate,
                     string imageType,FZZBytes &imageData,int imageWidth,int imageHeight,
                     string sealID);
};

#endif //FZZSESEAL_V4_H

