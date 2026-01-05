//
//  Created by zizheng fan on 2023/01/07.
//
#ifndef FZZSIGNIDPROVIDER_H
#define FZZSIGNIDPROVIDER_H

//#include "basic/FZZConst.h"

class FZZSignIDProvider
{
public:
    virtual ~FZZSignIDProvider() {}

public:
    virtual void setCurrentMaxSignId(string maxSignId) = 0;
    virtual string incrementAndGet() = 0;
    virtual string get() = 0;
    virtual long parse(string id) = 0;
};

#endif //FZZSIGNIDPROVIDER_H
