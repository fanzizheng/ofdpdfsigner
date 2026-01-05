//
//  Created by zizheng fan on 2023/03/01.
//
#ifndef FZZGBT35275DSCONTAINER_H
#define FZZGBT35275DSCONTAINER_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
#include "ofd/sign/FZZExtendSignatureContainer.h"

class FZZGBT35275DSContainer : public FZZExtendSignatureContainer
{
public:
    
    FZZGBT35275DSContainer(FZZKey * privateKey, FZZCert * signCert);
    FZZGBT35275DSContainer(CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param);
    virtual ~FZZGBT35275DSContainer();
	
public:
    //propertyInfo : 保留 ，没有用
    virtual void sign(FZZBytes & inData, string propertyInfo,FZZBytes & outSignData);



    virtual FZZOFDSigType::TYPE getOFDSignType();

    virtual string getSignAlgOID();
    virtual FZZBytes getSeal();
protected:
    FZZGBT35275DSContainer();
private:
    FZZKey * m_PrivateKey;
    FZZCert * m_SignCert;
    bool m_isCallBack;
    CallBack_Sign m_signFunc;
    CallBack_getUserCert m_getCertFunc;
    const void * m_callBack_Param;
};

#endif //FZZGBT35275DSCONTAINER_H


