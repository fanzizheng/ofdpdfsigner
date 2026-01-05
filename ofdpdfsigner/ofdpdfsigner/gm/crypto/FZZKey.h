//
//  Created by zizheng fan on 2022/10/27.
//
#ifndef FZZKEY_H
#define FZZKEY_H

#include "basic/FZZBytes.h"

class FZZKey
{
public:
    static const string KEYTYPE_SM2_PUB_KEY;
    static const string KEYTYPE_SM2_PRI_KEY;
    static const string KEYTYPE_SM1;
    static const string KEYTYPE_SM4;
    static const string KEYTYPE_SM2_PUB_KEY_ID;
    static const string KEYTYPE_SM2_PRI_KEY_ID;
    static const string KEYTYPE_SM1_ID;
    static const string KEYTYPE_SM4_ID;
public:
    FZZKey();
    FZZKey(string keytype,string keyid,const unsigned char * const data,int len);
    FZZKey(const FZZKey& obj);
	virtual ~FZZKey();
    const FZZKey& operator=(const FZZKey& data);
    
public:
    void setKeyData(const unsigned char * const data,int len) { m_KeyData.setData(data,len); }
    unsigned char * getKeyData() const { return m_KeyData.getData(); }
    int getKeyDataLen() const { return (int)m_KeyData.getLen(); }
    void setKeyType(string type) { m_KeyType = type; }
    string getKeyType() { return m_KeyType; }
    void setKeyID( string id ) { m_KeyID = id; }
    string getKeyID() { return m_KeyID; }
    
    void clear();
protected:
	
private:

private:
    string m_KeyType;
    string m_KeyID;
    FZZBytes m_KeyData;
    
};

#endif //FZZKEY_H

