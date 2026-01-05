//
//  Created by zizheng fan on 2022/10/25.
//
#include "basic/FZZConst.h"
#include "ofd/sign/FZZStampAnnotEntity.h"
#include "gm/ses/parse/FZZSESVersion.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
#include "gm/ses/v4/FZZTBS_Sign_V4.h"
#include "gm/ses/v4/FZZSES_ESPictrueInfo_V4.h"
#include "gm/ses/parse/FZZVersionParser.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZStampAnnotEntity******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZStampAnnotEntity::FZZStampAnnotEntity():m_imgType(""),m_ID(""),m_sesVersionHolder(NULL),m_ofdSignedInfo(NULL)
{
    //DLOG("FZZStampAnnotEntity()");
    FZZConst::addClassCount("FZZStampAnnotEntity");
}
//-----------------------------------------------------------------------------------------------------------------
FZZStampAnnotEntity::FZZStampAnnotEntity(string sid,FZZBytes * signedValueFile, FZZOFDSignedInfo * signedInfo):FZZStampAnnotEntity()
{
    if ( signedValueFile != NULL && signedValueFile->getLen() > 10 ) {
        m_sesVersionHolder = FZZVersionParser::parseSES_SignatureVersion(*signedValueFile);
    }
    this->m_ID = sid;
    m_ofdSignedInfo = signedInfo;
    init();
}
//-----------------------------------------------------------------------------------------------------------------
FZZStampAnnotEntity::FZZStampAnnotEntity(const FZZStampAnnotEntity& obj):FZZStampAnnotEntity()
{
    //DLOG("FZZStampAnnotEntity(const FZZStampAnnotEntity& obj)");
    if ( this == &obj ) {
        return;
    }
    this->m_imageByte = obj.m_imageByte;
    this->m_imgType = obj.m_imgType;
    this->m_ID = obj.m_ID;
    this->m_sesVersionHolder = obj.m_sesVersionHolder;
    this->m_ofdSignedInfo = obj.m_ofdSignedInfo;
}
//-----------------------------------------------------------------------------------------------------------------
FZZStampAnnotEntity::~FZZStampAnnotEntity()
{
    //DLOG("~FZZStampAnnotEntity()");
    FZZConst::delClassCount("FZZStampAnnotEntity");
    if ( m_sesVersionHolder != NULL ) {
        delete m_sesVersionHolder;
        m_sesVersionHolder = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZStampAnnotEntity::init()
{
    
    if (m_sesVersionHolder->getVersion() == FZZSESVersion::TYPE::v4) {
        
        FZZSES_Signature_V4* sesSignature = m_sesVersionHolder->getInstance_sign_V4();
        FZZTBS_Sign_V4* toSign = sesSignature->getToSign();
        FZZSES_ESPictrueInfo_V4* picture = NULL;
        if ( toSign != NULL && toSign->getEseal() != NULL && toSign->getEseal()->getSealInfo() != NULL) {
            picture = toSign->getEseal()->getSealInfo()->getPicture();
            m_imgType = picture->getType();
            m_imageByte = picture->getData();
            
            
            
        }
        
         
    } else {
        
        //V1 stamp is not supported
        FZZSES_Signature_V1* sesSignature = m_sesVersionHolder->getInstance_sign_V1();
        FZZTBS_Sign_V1* toSign = sesSignature->getToSign();
        FZZSES_ESPictrueInfo_V4* picture = NULL;
        if ( toSign != NULL && toSign->getEseal() != NULL && toSign->getEseal()->geteSealInfo() != NULL) {
            picture = toSign->getEseal()->geteSealInfo()->getPicture();
            m_imgType = picture->getType();
            m_imageByte = picture->getData();
        }
        
        //Another case: the signature in the public security ID card is suspected to be pkcs7. At present, we don't care about it, because we don't verify it.
    }
     
}
//-----------------------------------------------------------------------------------------------------------------





