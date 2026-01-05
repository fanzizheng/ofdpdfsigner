//
//  Created by zizheng fan on 2022/11/13.
//
#ifndef FZZSES_SEPROPERTY_V4_H
#define FZZSES_SEPROPERTY_V4_H

#include "gm/ses/v4/FZZSES_CertList.h"

class FZZSES_ESPropertyInfo_V4
{
public:
    FZZSES_ESPropertyInfo_V4();
    FZZSES_ESPropertyInfo_V4(const unsigned char * data,size_t datalen);
    FZZSES_ESPropertyInfo_V4(const FZZBytes & data);
    FZZSES_ESPropertyInfo_V4(const FZZSES_ESPropertyInfo_V4& obj);
	virtual ~FZZSES_ESPropertyInfo_V4();
public:
    static const uint32_t CertListType;
    static const uint32_t CertDigestListType;
public:
    uint32_t getType() { return m_type; }
    void setType(uint32_t type) {
        m_type = type;
    }
    
    string getName() { return m_name; }
    void setName(const string& name) {
        m_name = name;
    }
    
    uint32_t getCertListType() { return m_certListType; }
    void setCertListType(uint32_t certListType) {
        m_certListType = certListType;
    }
    
    FZZSES_CertList* getCertList() { return m_SES_CertList; }
    void setCertList(FZZSES_CertList* certList) {
        if ( m_SES_CertList != NULL ) {
            delete m_SES_CertList;
            m_SES_CertList = NULL;
            
        }
        m_SES_CertList = new FZZSES_CertList(*certList);
    }
    
    time_t getCreateDate() { return m_createDate; }
    void setCreateDate(time_t createDate) {
        m_createDate = createDate;
    }
    
    time_t getValidStart() { return m_validStart; }
    void setValidStart(time_t validStart) {
        m_validStart = validStart;
    }
    
    time_t getValidEnd() { return m_validEnd; }
    void setValidEnd(time_t validEnd) {
        m_validEnd = validEnd;
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    uint32_t m_type;
    string m_name;
    uint32_t m_certListType;
    FZZSES_CertList * m_SES_CertList;
    time_t m_createDate;
    time_t m_validStart;
    time_t m_validEnd;
};

#endif //FZZSES_SEPROPERTY_V4_H

