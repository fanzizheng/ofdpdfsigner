//
//  Created by zizheng fan on 2022/11/10.
//
#ifndef CERTDIGESTLIST_H
#define CERTDIGESTLIST_H

#include "gm/ses/v4/FZZCertDigestObj.h"

class FZZCertDigestList
{
public:
    FZZCertDigestList();
    FZZCertDigestList( const unsigned char * data,size_t datalen);
    FZZCertDigestList(const FZZBytes & data);
    FZZCertDigestList(const FZZCertDigestList& obj);
	virtual ~FZZCertDigestList();
public:
    int size() { return (int)m_certdigestlist.size(); }
    void add(const FZZBytes & data) { m_certdigestlist.push_back(new FZZCertDigestObj(data)); }
    FZZCertDigestObj* get(int index) { return m_certdigestlist[index]; }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    vector<FZZCertDigestObj *> m_certdigestlist;
    
};

#endif //CERTDIGESTLIST_H

