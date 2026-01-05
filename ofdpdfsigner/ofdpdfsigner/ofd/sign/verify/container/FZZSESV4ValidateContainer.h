//
//  Created by zizheng fan on 2023/03/03.
//
#ifndef FZZSESV4VALIDATECONTAINER_H
#define FZZSESV4VALIDATECONTAINER_H

#include "basic/FZZBytes.h"
#include "ofd/sign/verify/FZZSignedDataValidateContainer.h"


class FZZSESV4ValidateContainer : public FZZSignedDataValidateContainer
{
public:
    FZZSESV4ValidateContainer();
    virtual ~FZZSESV4ValidateContainer();
public:
    virtual int validate(FZZOFDSigType::TYPE type, string signAlgName,CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN);
protected:

private:
    
private:
    
    
};

#endif //FZZSESV4VALIDATECONTAINER_H


