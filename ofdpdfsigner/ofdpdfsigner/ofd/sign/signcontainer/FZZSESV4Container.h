//
//  Created by zizheng fan on 2023/01/11.
//
#ifndef FZZSESV4CONTAINER_H
#define FZZSESV4CONTAINER_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "gm/ses/v4/FZZSESeal_V4.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
#include "ofd/sign/FZZExtendSignatureContainer.h"

class FZZSESV4Container : public FZZExtendSignatureContainer
{
public:
    
    FZZSESV4Container(FZZKey * privateKey, FZZCert * signCert, FZZSESeal_V4* seal);
    FZZSESV4Container(FZZSESeal_V4* seal,CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param);
    virtual ~FZZSESV4Container();
	
public:
    virtual void sign(FZZBytes & inData, string propertyInfo,FZZBytes & outSignData);

    virtual FZZOFDSigType::TYPE getOFDSignType();

    virtual string getSignAlgOID();
    virtual FZZBytes getSeal();
protected:
    FZZSESV4Container();
private:
    FZZKey * m_PrivateKey;
    FZZCert * m_SignCert;
    FZZSESeal_V4 * m_Seal;
    bool m_isCallBack;
    CallBack_Sign m_signFunc;
    CallBack_getUserCert m_getCertFunc;
    const void * m_callBack_Param;
};

#endif //FZZSESV4CONTAINER_H


