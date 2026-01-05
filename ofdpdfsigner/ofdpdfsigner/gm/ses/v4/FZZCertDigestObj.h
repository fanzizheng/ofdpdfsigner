//
//  Created by zizheng fan on 2022/11/11.
//
#ifndef FZZCERTDIGESTOBJ_H
#define FZZCERTDIGESTOBJ_H



class FZZCertDigestObj
{
public:
    FZZCertDigestObj();
    FZZCertDigestObj( const unsigned char * data,size_t datalen);
    FZZCertDigestObj(const FZZBytes & data);
    FZZCertDigestObj(const FZZCertDigestObj& obj);
	virtual ~FZZCertDigestObj();
public:
    string getType() { return m_type; }
    void setType(const string& type) {
        m_type = type;
    }
    
    FZZBytes getValue() { return m_value; }
    void setValue(const FZZBytes& value) {
        m_value.setData(value.getData(),value.getLen());
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    string m_type;
    FZZBytes m_value;
    
    
};

#endif //FZZCERTDIGESTOBJ_H

