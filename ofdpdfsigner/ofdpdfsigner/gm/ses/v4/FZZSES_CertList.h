//
//  Created by zizheng fan on 2022/11/12.
//
#ifndef FZZSES_CERTLIST_H
#define FZZSES_CERTLIST_H

#include "gm/ses/v4/FZZCertDigestList.h"
#include "gm/ses/v4/FZZCertInfoList.h"

class FZZSES_CertList
{
public:
    
    FZZSES_CertList(FZZCertInfoList * certs);
    FZZSES_CertList(FZZCertDigestList * certDigestList);
    FZZSES_CertList(uint32_t type, const unsigned char * data,size_t datalen);
    FZZSES_CertList(uint32_t type,const FZZBytes & data);
    FZZSES_CertList(const FZZSES_CertList& obj);
	virtual ~FZZSES_CertList();
public:
    FZZCertInfoList* getCerts() { return m_certs;}
    FZZCertDigestList* getCertDigestList() { return m_certDigestList;}
    
    FZZBytes Encode();
    bool Deccode(uint32_t type,const unsigned char * indata,size_t inlenght);
protected:
	
private:
    FZZSES_CertList();
private:
    FZZCertInfoList * m_certs;
    FZZCertDigestList * m_certDigestList;
    
};

#endif //FZZSES_CERTLIST_H

