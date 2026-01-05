//
//  Created by zizheng fan on 2022/11/18.
//
#ifndef FZZSESVERSIONHOLDER_H
#define FZZSESVERSIONHOLDER_H

#include "gm/ses/parse/FZZSESVersion.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
#include "gm/ses/v4/FZZSESeal_V4.h"
#include "gm/ses/v1/FZZSES_Signature_V1.h"
#include "gm/ses/v1/FZZSESeal_V1.h"

class FZZSESVersionHolder
{
public:
    FZZSESVersionHolder(FZZSESVersion::TYPE version, const FZZBytes & objSeq);
    FZZSESVersionHolder(const FZZSESVersionHolder& obj);
	virtual ~FZZSESVersionHolder();
public:
    FZZSESVersion::TYPE getVersion() {return m_version; }
    FZZBytes getObjSeq() { return m_objSeq; }
    FZZSES_Signature_V4* getInstance_sign_V4() {
        if ( m_SES_Signature_V4 == NULL ) {
            m_SES_Signature_V4 = new FZZSES_Signature_V4(m_objSeq);
        }
        return m_SES_Signature_V4;
    }
    FZZSESeal_V4* getInstance_Seal_V4() {
        if ( m_SESeal_V4 == NULL ) {
            m_SESeal_V4 = new FZZSESeal_V4(m_objSeq);
        }
        return m_SESeal_V4;
    }
    
    FZZSES_Signature_V1* getInstance_sign_V1() {
        if ( m_SES_Signature_V1 == NULL ) {
            m_SES_Signature_V1 = new FZZSES_Signature_V1(m_objSeq);
        }
        return m_SES_Signature_V1;
    }
    FZZSESeal_V1* getInstance_Seal_V1() {
        if ( m_SESeal_V1 == NULL ) {
            m_SESeal_V1 = new FZZSESeal_V1(m_objSeq);
        }
        return m_SESeal_V1;
    }
protected:
    FZZSESVersionHolder();
private:

private:
    FZZSESVersion::TYPE m_version;
    FZZBytes m_objSeq;
    FZZSES_Signature_V4 * m_SES_Signature_V4;
    FZZSESeal_V4 * m_SESeal_V4;
    
    FZZSES_Signature_V1 * m_SES_Signature_V1;
    FZZSESeal_V1 * m_SESeal_V1;
};

#endif //FZZSESVERSIONHOLDER_H

