//
//  Created by zizheng fan on 2022/10/27.
//
#include "basic/FZZConst.h"
#include "gm/crypto/FZZKeyPair.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZKeyPair******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZKeyPair::FZZKeyPair()
{
    //DLOG("FZZKeyPair()");
    FZZConst::addClassCount("FZZKeyPair");
   
}
//-----------------------------------------------------------------------------------------------------------------
FZZKeyPair::FZZKeyPair(const FZZKey & Public,const FZZKey & Private):FZZKeyPair()
{
    m_Public = Public;
    m_Private = Private;
}
//-----------------------------------------------------------------------------------------------------------------
FZZKeyPair::FZZKeyPair(const FZZKeyPair& obj):FZZKeyPair()
{
    //DLOG("FZZKeyPair(const FZZKeyPair& obj)");
    m_Public = obj.m_Public;
    m_Private = obj.m_Private;
}
//-----------------------------------------------------------------------------------------------------------------
FZZKeyPair::~FZZKeyPair()
{
    //DLOG("~FZZKeyPair()");
    FZZConst::delClassCount("FZZKeyPair");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
const FZZKeyPair& FZZKeyPair::operator=(const FZZKeyPair& data)
{
    if ( this == &data ) {
        return *this;
    }
    m_Public = data.m_Public;
    m_Private = data.m_Private;
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------




