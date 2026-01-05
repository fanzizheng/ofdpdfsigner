//
//  Created by zizheng fan on 2022/11/08.
//
#ifndef FZZSES_SIGNATURE_V1_H
#define FZZSES_SIGNATURE_V1_H

#include "gm/ses/v1/FZZTBS_Sign_V1.h"
#include "gm/crypto/FZZCert.h"

class FZZSES_Signature_V1
{
public:
    FZZSES_Signature_V1();
    FZZSES_Signature_V1(FZZTBS_Sign_V1* TBSSign,const FZZBytes& signature);
    FZZSES_Signature_V1(const FZZBytes& data);
    FZZSES_Signature_V1(const FZZSES_Signature_V1& obj);
	virtual ~FZZSES_Signature_V1();
public:
    FZZTBS_Sign_V1* getToSign(){return m_TBSSign;}
    void setToSign(FZZTBS_Sign_V1* sign) {
        if ( m_TBSSign != NULL ) {
            delete m_TBSSign;
            m_TBSSign = NULL;
        }
        m_TBSSign = new FZZTBS_Sign_V1(*sign);
    }
    
    FZZBytes getSignature() { return m_signature; }
    void setSignature(const FZZBytes& signature) {
        m_signature.setData(signature.getData(),signature.getLen());
    }
  
    FZZBytes Encode();
    bool Deccode(const FZZBytes& seq);
protected:
	
    
private:
    
private:
    FZZTBS_Sign_V1 * m_TBSSign;
    FZZBytes m_signature;
};

#endif //FZZSES_SIGNATURE_V1_H

