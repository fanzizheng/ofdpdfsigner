//
//  Created by zizheng fan on 2023/03/02.
//
#ifndef FZZSIGNEDDATAVALIDATECONTAINER_H
#define FZZSIGNEDDATAVALIDATECONTAINER_H

#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSigType.h"

class FZZSignedDataValidateContainer
{
public:
    virtual ~FZZSignedDataValidateContainer() {}

public:
    
    virtual int validate(FZZOFDSigType::TYPE type, string signAlgName,CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN) = 0;
};

#endif //FZZSIGNEDDATAVALIDATECONTAINER_H
