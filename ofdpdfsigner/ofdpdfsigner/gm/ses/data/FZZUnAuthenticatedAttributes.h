//
//  Created by zizheng fan on 2022/11/01.
//
#ifndef FZZUNAUTHENTICATEDATTRIBUTES_H
#define FZZUNAUTHENTICATEDATTRIBUTES_H

#include "basic/FZZBytes.h"

class FZZUnAuthenticatedAttributes
{
public:
    FZZUnAuthenticatedAttributes();
    FZZUnAuthenticatedAttributes(const unsigned char * data,size_t datalen);
    FZZUnAuthenticatedAttributes(const FZZBytes & data);
    FZZUnAuthenticatedAttributes(const FZZUnAuthenticatedAttributes& obj);
    virtual ~FZZUnAuthenticatedAttributes();
public:
    
    FZZBytes * getMessageDigest() {return &m_messageDigest;}
    void setMessageDigest(FZZBytes & messageDigest) { m_messageDigest.setData(messageDigest.getData(),messageDigest.getLen()); }
    
    //=> set
    FZZBytes getPlainText();
    //=>Context[0]
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
    
protected:

private:
    
private:
    FZZBytes m_messageDigest;
};

#endif //FZZUNAUTHENTICATEDATTRIBUTES_H


