//
//  Created by zizheng fan on 2022/11/15.
//
#ifndef FZZSES_SEALINFO_V4_H
#define FZZSES_SEALINFO_V4_H

#include "gm/ses/v4/FZZSES_ESPictrueInfo_V4.h"
#include "gm/ses/v4/FZZSES_Header.h"
#include "gm/ses/v4/FZZSES_ESPropertyInfo_V4.h"
#include "gm/ses/v4/FZZExtensionDatas.h"

class FZZSES_SealInfo_V4
{
public:
    FZZSES_SealInfo_V4();
    FZZSES_SealInfo_V4(const unsigned char * data,size_t datalen);
    FZZSES_SealInfo_V4(const FZZBytes & data);
    FZZSES_SealInfo_V4(const FZZSES_SealInfo_V4& obj);
	virtual ~FZZSES_SealInfo_V4();
public:
    FZZSES_ESPictrueInfo_V4* getPicture() {return m_picture;}
    void setPicture(FZZSES_ESPictrueInfo_V4 * picture)
    {
        if ( m_picture != NULL ) {
            delete m_picture;
            m_picture = NULL;
        }
        m_picture = new FZZSES_ESPictrueInfo_V4(*picture);
    }
    
    FZZSES_Header* getHeader() {return m_header;}
    void setHeader(FZZSES_Header * head)
    {
        if ( m_header != NULL ) {
            delete m_header;
            m_header = NULL;
        }
        m_header = new FZZSES_Header(*head);
    }
    
    FZZSES_ESPropertyInfo_V4* getPropertInfo() {return m_property;}
    void setPropertInfo(FZZSES_ESPropertyInfo_V4 * property)
    {
        if ( m_property != NULL ) {
            delete m_property;
            m_property = NULL;
        }
        m_property = new FZZSES_ESPropertyInfo_V4(*property);
    }
    
    FZZExtensionDatas* getExtensionDatas() {return m_extDatas;}
    void setExtensionDatas(FZZExtensionDatas * extDatas)
    {
        if ( m_extDatas != NULL ) {
            delete m_extDatas;
            m_extDatas = NULL;
        }
        m_extDatas = new FZZExtensionDatas(*extDatas);
    }
    
    string getEsID() {return m_esID;}
    void setEsID(const string & esid) { m_esID = esid; }
    
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    string m_esID;
    FZZSES_ESPictrueInfo_V4 * m_picture;
    FZZSES_Header* m_header;
    FZZSES_ESPropertyInfo_V4 * m_property;
    FZZExtensionDatas* m_extDatas;
};

#endif //FZZSES_SEALINFO_V4_H

