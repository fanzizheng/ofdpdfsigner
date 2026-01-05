//
//  Created by zizheng fan on 2022/11/12.
//
#ifndef FZZCERTINFOLIST_H
#define FZZCERTINFOLIST_H



class FZZCertInfoList
{
public:
    FZZCertInfoList();
    FZZCertInfoList( const unsigned char * data,size_t datalen);
    FZZCertInfoList(const FZZBytes & data);
    FZZCertInfoList(const FZZCertInfoList& obj);
	virtual ~FZZCertInfoList();
public:
    int size() { return (int)m_certinfolist.size(); }
    void add(const FZZBytes & data) { m_certinfolist.push_back(new FZZBytes(data)); }
    FZZBytes* get(int index) { return m_certinfolist[index]; }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    vector<FZZBytes *> m_certinfolist;
    
};

#endif //FZZCERTINFOLIST_H

