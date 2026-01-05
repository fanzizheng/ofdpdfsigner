//
//  Created by zizheng fan on 2022/11/02.
//
#ifndef FZZAUTHENTICATEDATTRIBUTES_H
#define FZZAUTHENTICATEDATTRIBUTES_H

#include "basic/FZZBytes.h"

class FZZAuthenticatedAttributes
{
public:
    FZZAuthenticatedAttributes();
    FZZAuthenticatedAttributes(const unsigned char * data,size_t datalen);
    FZZAuthenticatedAttributes(const FZZBytes & data);
    FZZAuthenticatedAttributes(const FZZAuthenticatedAttributes& obj);
    virtual ~FZZAuthenticatedAttributes();
public:
    
    FZZBytes * getMessageDigest() {return &m_messageDigest;}
    void setMessageDigest(FZZBytes & messageDigest) { m_messageDigest.setData(messageDigest.getData(),messageDigest.getLen()); }
    
    time_t getSigningTime() { return m_signingTime; }
    void setSigningTime(time_t signingTime) {
        m_signingTime = signingTime;
    }
    //=> set
    FZZBytes getPlainText();
    //=>Context[0]
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
    
protected:

private:
    
private:
    FZZBytes m_messageDigest;
    time_t m_signingTime;
};

#endif //FZZAUTHENTICATEDATTRIBUTES_H


