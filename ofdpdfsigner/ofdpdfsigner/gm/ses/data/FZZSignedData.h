//
//  Created by zizheng fan on 2022/11/02.
//
#ifndef FZZSIGNEDDATA_H
#define FZZSIGNEDDATA_H

#include "basic/FZZBytes.h"
#include "gm/ses/data/FZZSignerInfo.h"
#include "gm/crypto/FZZCert.h"

class FZZContentInfo;

class FZZSignedData
{
public:
    FZZSignedData();
    FZZSignedData(const unsigned char * data,size_t datalen);
    FZZSignedData(const FZZBytes & data);
    FZZSignedData(const FZZSignedData& obj);
    virtual ~FZZSignedData();
public:
    uint32_t getVersion() { return m_version; }
    void setVersion(uint32_t version) { m_version = version; }
    
    int getDigestAlgs_size() { return (int)(m_digestAlgorithms.size()); }
    void addDigestAlg(const FZZBytes & data) { m_digestAlgorithms.push_back(new FZZBytes(data)); }
    FZZBytes* getDigestAlg(int index) { return m_digestAlgorithms[index]; }
    
    FZZContentInfo * getContentInfo() {return m_ContentInfo;}
    void setContentInfo(FZZContentInfo* contentInfo);
    
    int getCerts_size() { return (int)m_certificates.size(); }
    void addCert(const FZZBytes & data) { m_certificates.push_back(new FZZBytes(data)); }
    FZZBytes* getCert(int index) { return m_certificates[index]; }
    
    int getCRL_size() { return (int)m_crls.size(); }
    void addCRL(const FZZBytes & data) { m_crls.push_back(new FZZBytes(data)); }
    FZZBytes* getCRL(int index) { return m_crls[index]; }
    
    vector<FZZSignerInfo*>* getSignerInfos() { return &m_signerInfos; }
    void addSignerInfo(FZZSignerInfo * signerInfo) {
        m_signerInfos.push_back(new FZZSignerInfo(*signerInfo));
    }
    
    FZZCert getCertSignCert(string issuer,FZZBytes * SerialNumber);
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
    
    void clear_digestAlgorithms();
    void clear_certificates();
    void clear_crls();
    void clear_signerInfos();
protected:

private:
    
private:
    uint32_t m_version;
    vector<FZZBytes*> m_digestAlgorithms;
    FZZContentInfo* m_ContentInfo;
    vector<FZZBytes*> m_certificates;
    vector<FZZBytes*> m_crls;
    vector<FZZSignerInfo*> m_signerInfos;
};

#endif //FZZSIGNEDDATA_H


