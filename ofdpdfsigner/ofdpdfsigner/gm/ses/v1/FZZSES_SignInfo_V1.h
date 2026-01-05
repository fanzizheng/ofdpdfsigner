//
//  Created by zizheng fan on 2022/11/07.
//
#ifndef FZZSESSIGNINFO_V1_H
#define FZZSESSIGNINFO_V1_H



class FZZSES_SignInfo_V1
{
public:
    FZZSES_SignInfo_V1();
    FZZSES_SignInfo_V1(const unsigned char * data,size_t datalen);
    FZZSES_SignInfo_V1(const FZZBytes & data);
    FZZSES_SignInfo_V1(const FZZSES_SignInfo_V1& obj);
	virtual ~FZZSES_SignInfo_V1();
public:
    
    
    FZZBytes getCert() { return m_Cert; }
    void setCert(const FZZBytes& cert) {
        m_Cert.setData(cert.getData(),cert.getLen());
    }
    
    FZZBytes getSignAlgID() { return m_signatureAlgID; }
    void setSignAlgID(const FZZBytes & algid) { m_signatureAlgID.setData(algid.getData(),algid.getLen()); }
    
    FZZBytes getSignedValue() { return m_signedValue; }
    void setSignedValue(const FZZBytes& signedValue) {
        m_signedValue.setData(signedValue.getData(),signedValue.getLen());
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    FZZBytes m_Cert;
    FZZBytes m_signatureAlgID;
    FZZBytes m_signedValue;
};

#endif //FZZSESSIGNINFO_V1_H

