//
//  Created by zizheng fan on 2023/03/05.
//
#ifndef FZZGBT35275VALIDATECONTAINER_H
#define FZZGBT35275VALIDATECONTAINER_H

#include "basic/FZZBytes.h"
#include "ofd/sign/verify/FZZSignedDataValidateContainer.h"


class FZZGBT35275ValidateContainer : public FZZSignedDataValidateContainer
{
public:
    FZZGBT35275ValidateContainer();
    virtual ~FZZGBT35275ValidateContainer();
public:
    
    virtual int validate(FZZOFDSigType::TYPE type, string signAlgName,CallBack_Verify verifyFunc,const void * callBack_Param, FZZBytes& tbsContent, FZZBytes& signedValue,string & signDN);
protected:

private:
    
private:
    
    
};

#endif //FZZGBT35275VALIDATECONTAINER_H


