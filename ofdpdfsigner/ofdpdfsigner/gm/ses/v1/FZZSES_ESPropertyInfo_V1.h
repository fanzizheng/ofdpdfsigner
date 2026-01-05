//
//  Created by zizheng fan on 2022/11/05.
//
#ifndef SES_SEPROPERTY_V1_H
#define SES_SEPROPERTY_V1_H

#include "gm/ses/v4/FZZSES_CertList.h"

class FZZSES_ESPropertyInfo_V1
{
public:
    FZZSES_ESPropertyInfo_V1();
    FZZSES_ESPropertyInfo_V1(const unsigned char * data,size_t datalen);
    FZZSES_ESPropertyInfo_V1(const FZZBytes & data);
    FZZSES_ESPropertyInfo_V1(const FZZSES_ESPropertyInfo_V1& obj);
	virtual ~FZZSES_ESPropertyInfo_V1();
    
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
    //1 : Company seal
    // 2 : Personal seal
    uint32_t m_type;
    string m_name;
    FZZSES_CertList * m_SES_CertList;
    time_t m_createDate;
    time_t m_validStart;
    time_t m_validEnd;
};

#endif //SES_SEPROPERTY_V4_H

