//
//  Created by zizheng fan on 2022/11/10.
//
#ifndef FZZEXTDATA_H
#define FZZEXTDATA_H



class FZZExtData
{
public:
    FZZExtData();
    FZZExtData(const unsigned char * data,size_t datalen);
    FZZExtData(const FZZBytes & data);
    FZZExtData(const FZZExtData& obj);
	virtual ~FZZExtData();
public:
    
    FZZBytes getExtnID() { return m_extnID; }
    void setExtnID(const FZZBytes& extnID) {
        m_extnID.setData(extnID.getData(),extnID.getLen());
    }
    
    int getCritical() { return m_critical; }
    void setCritical(int critical ) { m_critical = critical; }
    
    FZZBytes getExtnValue() { return m_extnValue; }
    void setExtnValue(const FZZBytes& extnValue) {
        m_extnValue.setData(extnValue.getData(),extnValue.getLen());
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    FZZBytes m_extnID;
    int m_critical;
    FZZBytes m_extnValue;
};

#endif //FZZEXTDATA_H

