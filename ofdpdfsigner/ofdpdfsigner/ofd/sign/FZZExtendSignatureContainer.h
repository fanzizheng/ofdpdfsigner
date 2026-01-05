//
//  Created by zizheng fan on 2023/03/01.
//
#ifndef FZZEXTENDSIGNATURECONTAINER_H
#define FZZEXTENDSIGNATURECONTAINER_H


#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSigType.h"

class FZZExtendSignatureContainer
{
public:
    virtual ~FZZExtendSignatureContainer() {}

public:
    virtual void sign(FZZBytes & inData, string propertyInfo,FZZBytes & outSignData) = 0;

    virtual FZZOFDSigType::TYPE getOFDSignType() = 0;

    virtual string getSignAlgOID() = 0;
    virtual FZZBytes getSeal() = 0;
};

#endif //FZZEXTENDSIGNATURECONTAINER_H
