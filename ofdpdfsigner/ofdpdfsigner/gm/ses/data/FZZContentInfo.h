//
//  Created by zizheng fan on 2022/11/04.
//
#ifndef FZZCONTENTINFO_H
#define FZZCONTENTINFO_H

#include "basic/FZZBytes.h"
#include "gm/ses/data/FZZSignedData.h"



class FZZContentInfo 
{
public:
    FZZContentInfo();
    FZZContentInfo(const unsigned char * data,size_t datalen);
    FZZContentInfo(const FZZBytes & data);
    FZZContentInfo(const FZZContentInfo& obj);
    virtual ~FZZContentInfo();
public:
    FZZBytes* getContentType() { return &m_contentType; }
    void setContentType(const FZZBytes & contentType) { m_contentType.setData(contentType.getData(),contentType.getLen()); }
    
    FZZSignedData* getContent() { return m_SignedData; }
    void setContent(FZZSignedData* content) {
        if ( m_SignedData != NULL ) {
            delete m_SignedData;
            m_SignedData = NULL;
        }
        m_SignedData = new FZZSignedData(*content);
    }
    
    FZZBytes* getDataContent() { return &m_dataContent; }
    void setDataContent(const FZZBytes & datacontent) { m_dataContent.setData(datacontent.getData(),datacontent.getLen()); }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:

private:
    
private:
    FZZBytes m_contentType;
    FZZSignedData* m_SignedData;
    FZZBytes m_dataContent;
    
};

#endif //FZZCONTENTINFO_H


