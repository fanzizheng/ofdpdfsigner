//
//  Created by zizheng fan on 2022/11/14.
//
#ifndef FZZEXTENSIONDATAS_H
#define FZZEXTENSIONDATAS_H

#include "gm/ses/v4/FZZExtData.h"

class FZZExtensionDatas
{
public:
    FZZExtensionDatas();
    FZZExtensionDatas(const unsigned char * data,size_t datalen);
    FZZExtensionDatas(const FZZBytes & data);
    FZZExtensionDatas(const FZZExtensionDatas& obj);
	virtual ~FZZExtensionDatas();
public:
    int size() { return (int)m_ExtDatalist.size(); }
    void add(const FZZBytes & data) { m_ExtDatalist.push_back(new FZZExtData(data)); }
    FZZExtData* get(int index) { return m_ExtDatalist[index]; }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    vector<FZZExtData *> m_ExtDatalist;
    
};

#endif //FZZEXTENSIONDATAS_H

