//
//  Created by zizheng fan on 2022/11/17.
//
#ifndef FZZTBS_SIGN_V4_H
#define FZZTBS_SIGN_V4_H

#include "gm/ses/v4/FZZSESeal_V4.h"
#include "gm/ses/v4/FZZExtensionDatas.h"

class FZZTBS_Sign_V4
{
public:
    FZZTBS_Sign_V4();
    FZZTBS_Sign_V4(const unsigned char * data,size_t datalen);
    FZZTBS_Sign_V4(const FZZTBS_Sign_V4& obj);
	virtual ~FZZTBS_Sign_V4();
public:
    uint32_t getVersion() { return m_version; }
    void setVersion(uint32_t version) {
        m_version = version;
    }
    
    FZZBytes getDataHash() { return m_dataHash; }
    void setDataHash(const FZZBytes& dataHash) {
        m_dataHash.setData(dataHash.getData(),dataHash.getLen());
    }
    
    string getPropertyInfo() { return m_propertyInfo; }
    void setPropertyInfo(const string& propertyInfo) {
        m_propertyInfo = propertyInfo;
    }
    
    time_t getTimeInfo() { return m_timeInfo; }
    void setTimeInfo(time_t timeInfo) {
        m_timeInfo = timeInfo;
    }
    
    FZZSESeal_V4* getEseal() {return m_SESeal_V4;}
    void setEseal(FZZSESeal_V4* seal) {
        if ( m_SESeal_V4 != NULL ) {
            delete m_SESeal_V4;
            m_SESeal_V4 = NULL;
            
        }
        m_SESeal_V4 = new FZZSESeal_V4(*seal);
    }
    
    FZZExtensionDatas* getExtDatas() {return m_extDatas;}
    void setExtDatas(FZZExtensionDatas* extDatas) {
        if ( m_extDatas != NULL ) {
            delete m_extDatas;
            m_extDatas = NULL;
            
        }
        m_extDatas = new FZZExtensionDatas(*extDatas);
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    uint32_t m_version;
    FZZSESeal_V4 * m_SESeal_V4;
    time_t m_timeInfo;
    FZZBytes m_dataHash;
    string m_propertyInfo;
    FZZExtensionDatas * m_extDatas;
};

#endif //FZZTBS_SIGN_V4_H

