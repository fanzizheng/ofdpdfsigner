//
//  Created by zizheng fan on 2022/11/17.
//
#ifndef FZZSES_SIGNATURE_V4_H
#define FZZSES_SIGNATURE_V4_H

#include "gm/ses/v4/FZZTBS_Sign_V4.h"
#include "gm/crypto/FZZCert.h"

class FZZSES_Signature_V4
{
public:
    FZZSES_Signature_V4();
    FZZSES_Signature_V4(FZZTBS_Sign_V4* TBSSign,const FZZBytes& FZZCert,const FZZBytes& signatureAlgID,const FZZBytes& signature,const FZZBytes& timeStamp);
    FZZSES_Signature_V4(const FZZBytes& data);
    FZZSES_Signature_V4(const FZZSES_Signature_V4& obj);
	virtual ~FZZSES_Signature_V4();
public:
    FZZTBS_Sign_V4* getToSign(){return m_TBSSign;}
    void setToSign(FZZTBS_Sign_V4* sign) {
        if ( m_TBSSign != NULL ) {
            delete m_TBSSign;
            m_TBSSign = NULL;
        }
        m_TBSSign = new FZZTBS_Sign_V4(*sign);
    }
    
    FZZBytes getCert() { return m_Cert; }
    void setCert(const FZZBytes& cert) {
        m_Cert.setData(cert.getData(),cert.getLen());
    }
    
    FZZBytes getSignature() { return m_signature; }
    void setSignature(const FZZBytes& signature) {
        m_signature.setData(signature.getData(),signature.getLen());
    }
    
    FZZBytes getTimeStamp() { return m_timeStamp; }
    void setTimeStamp(const FZZBytes& timeStamp) {
        m_timeStamp.setData(timeStamp.getData(),timeStamp.getLen());
    }
    
    FZZBytes getSignatureAlgID() { return m_signatureAlgID; }
    void setSignatureAlgID(const FZZBytes & algid) { m_signatureAlgID.setData(algid.getData(),algid.getLen()); }
    
    FZZBytes Encode();
    bool Deccode(const FZZBytes& seq);
protected:
	
    
private:
    
private:
    FZZTBS_Sign_V4 * m_TBSSign;
    FZZBytes  m_Cert;
    FZZBytes m_signatureAlgID;
    FZZBytes m_signature;
    FZZBytes m_timeStamp;
};

#endif //FZZSES_SIGNATURE_V4_H

