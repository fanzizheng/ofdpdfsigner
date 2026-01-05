//
//  Created by zizheng fan on 2023/01/08.
//
#ifndef FZZSTAMPAPPEARANCE_H
#define FZZSTAMPAPPEARANCE_H


#include "ofd/sign/FZZSignIDProvider.h"
#include "ofd/FZZOFD.h"

class FZZStampAppearance
{
public:
    virtual ~FZZStampAppearance() {}

public:
    virtual void getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo) = 0;
};

#endif //FZZSTAMPAPPEARANCE_H
