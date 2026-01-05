//
//  Created by zizheng fan on 2022/11/18.
//
#include "basic/FZZConst.h"
#include "gm/ses/parse/FZZSESVersionHolder.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZSESVersionHolder******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSESVersionHolder::FZZSESVersionHolder() : m_SES_Signature_V4(NULL),m_SESeal_V4(NULL),m_SES_Signature_V1(NULL),m_SESeal_V1(NULL)
{
    //DLOG("FZZSESVersionHolder()");
    FZZConst::addClassCount("FZZSESVersionHolder");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESVersionHolder::FZZSESVersionHolder(FZZSESVersion::TYPE version, const FZZBytes & objSeq):FZZSESVersionHolder()
{
    m_version = version;
    m_objSeq = objSeq;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESVersionHolder::FZZSESVersionHolder(const FZZSESVersionHolder& obj):FZZSESVersionHolder()
{
    //DLOG("FZZSESVersionHolder(const FZZSESVersionHolder& obj)");
    if ( this == &obj ) {
        return;
    }
    m_version = obj.m_version;
    m_objSeq = obj.m_objSeq;
    m_SES_Signature_V4 = NULL;
    m_SESeal_V4 = NULL;
    m_SES_Signature_V1 = NULL;
    m_SESeal_V1 = NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESVersionHolder ::~FZZSESVersionHolder()
{
    //DLOG("~FZZSESVersionHolder()");
    FZZConst::delClassCount("FZZSESVersionHolder");
    if ( m_SES_Signature_V4 != NULL ) {
        delete m_SES_Signature_V4;
        m_SES_Signature_V4 = NULL;
    }
    
    if ( m_SESeal_V4 != NULL ) {
        delete m_SESeal_V4;
        m_SESeal_V4 = NULL;
    }
    
    if ( m_SES_Signature_V1 != NULL ) {
        delete m_SES_Signature_V1;
        m_SES_Signature_V1 = NULL;
    }
    
    if ( m_SESeal_V1 != NULL ) {
        delete m_SESeal_V1;
        m_SESeal_V1 = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------






