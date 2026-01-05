//
//  Created by zizheng fan on 2023/03/04.
//
#ifndef FZZSESV1VALIDATECONTAINER_H
#define FZZSESV1VALIDATECONTAINER_H

#include "basic/FZZBytes.h"
#include "ofd/sign/verify/FZZSignedDataValidateContainer.h"


class FZZSESV1ValidateContainer : public FZZSignedDataValidateContainer
{
public:
    FZZSESV1ValidateContainer();
    virtual ~FZZSESV1ValidateContainer();
public:
    
    virtual int validate(FZZOFDSigType::TYPE type, string signAlgName,CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN);
protected:

private:
    
private:
    
    
};

#endif //FZZSESV1VALIDATECONTAINER_H


