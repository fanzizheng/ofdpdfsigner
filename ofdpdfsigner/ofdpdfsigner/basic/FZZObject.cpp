//
//  Created by zizheng fan on 2024/07/16.
//
#include "basic/FZZConst.h"
#include "basic/FZZObject.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZObject**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZObject::FZZObject() : isFreeCTX(true)
{
    FZZConst::addClassCount("FZZObject");
    m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
}
//-----------------------------------------------------------------------------------------------------------------
FZZObject::FZZObject(fz_context * ctx) : isFreeCTX(false)
{
    FZZConst::addClassCount("FZZObject");
    m_CTX = ctx;
}
//-----------------------------------------------------------------------------------------------------------------
FZZObject::~FZZObject()
{
    FZZConst::delClassCount("FZZObject");
    
    if ( isFreeCTX ) {
        if ( m_CTX != NULL ) {
            fz_flush_warnings(m_CTX);
            fz_drop_context(m_CTX);
            m_CTX = NULL;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------


