//
//  Created by zizheng fan on 2022/11/09.
//
#ifndef FZZSESEAL_V1_H
#define FZZSESEAL_V1_H

#include "gm/ses/v1/FZZSES_SealInfo_V1.h"
#include "gm/ses/v1/FZZSES_SignInfo_V1.h"

class FZZSESeal_V1
{
public:
    FZZSESeal_V1();
    FZZSESeal_V1(const unsigned char * data,size_t datalen);
    FZZSESeal_V1(const FZZBytes & data);
    FZZSESeal_V1(const FZZSESeal_V1& obj);
	virtual ~FZZSESeal_V1();
public:
    FZZSES_SealInfo_V1* geteSealInfo() {return m_SealInfo;}
    void seteSealInfo(FZZSES_SealInfo_V1 * sealinfo)
    {
        if ( m_SealInfo != NULL ) {
            delete m_SealInfo;
            m_SealInfo = NULL;
        }
        m_SealInfo = new FZZSES_SealInfo_V1(*sealinfo);
    }
    
    FZZSES_SignInfo_V1* getSignInfo() {return m_SignInfo;}
    void setSignInfo(FZZSES_SignInfo_V1 * signinfo)
    {
        if ( m_SignInfo != NULL ) {
            delete m_SignInfo;
            m_SignInfo = NULL;
        }
        m_SignInfo = new FZZSES_SignInfo_V1(*signinfo);
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
    
    bool Verify();
protected:
	
private:
    FZZBytes GenSignSource(FZZBytes &sealinfo,FZZBytes& certdata,FZZBytes alg);
private:
    FZZSES_SealInfo_V1 * m_SealInfo;
    FZZSES_SignInfo_V1* m_SignInfo;
 
};

#endif //FZZSESEAL_V1_H

