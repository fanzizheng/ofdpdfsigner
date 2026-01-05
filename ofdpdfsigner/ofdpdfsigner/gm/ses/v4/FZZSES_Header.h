//
//  Created by zizheng fan on 2022/11/13.
//
#ifndef FZZSES_HEADER_H
#define FZZSES_HEADER_H



class FZZSES_Header
{
public:
    FZZSES_Header();
    FZZSES_Header(const unsigned char * data,size_t datalen);
    FZZSES_Header(const FZZBytes & data);
    FZZSES_Header(const FZZSES_Header& obj);
	virtual ~FZZSES_Header();
public:
    //IA5String Only English
    string getId() { return m_id; }
    void setId(const string& iddata) {
        m_id = iddata;
    }
    
    int getVersion() { return m_version; }
    void setVersion(int version) {
        m_version = version;
    }
    
    string getVid() { return m_vid; }
    void setVid(const string& vid) {
        m_vid = vid;
    }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    string m_id;
    uint32_t m_version;
    string m_vid;
    
};

#endif //FZZSES_HEADER_H

