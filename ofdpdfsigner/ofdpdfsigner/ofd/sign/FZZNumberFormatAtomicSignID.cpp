//
//  Created by zizheng fan on 2023/01/05.
//
#include "basic/FZZConst.h"
#include "ofd/sign/FZZNumberFormatAtomicSignID.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZNumberFormatAtomicSignID*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZNumberFormatAtomicSignID::FZZNumberFormatAtomicSignID() : FZZSignIDProvider(), m_provider(0),m_enableZeroPrefix(false)
{
    //DLOG("FZZNumberFormatAtomicSignID()");
    FZZConst::addClassCount("FZZNumberFormatAtomicSignID");
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberFormatAtomicSignID::FZZNumberFormatAtomicSignID(bool enableZeroPrefix) : FZZNumberFormatAtomicSignID()
{
    m_enableZeroPrefix = enableZeroPrefix;
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberFormatAtomicSignID::FZZNumberFormatAtomicSignID(string maxSignID) : FZZNumberFormatAtomicSignID()
{
    setCurrentMaxSignId(maxSignID);
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberFormatAtomicSignID::FZZNumberFormatAtomicSignID(const FZZNumberFormatAtomicSignID& obj) : FZZNumberFormatAtomicSignID()
{
    if ( this == &obj ) {
        return;
    }
    this->m_provider = obj.m_provider;
    this->m_enableZeroPrefix = obj.m_enableZeroPrefix;
}
//-----------------------------------------------------------------------------------------------------------------
const FZZNumberFormatAtomicSignID& FZZNumberFormatAtomicSignID::operator=(const FZZNumberFormatAtomicSignID& obj)
{
    if ( this == &obj ) {
        return *this;
    }
    this->m_provider = obj.m_provider;
    this->m_enableZeroPrefix = obj.m_enableZeroPrefix;
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
FZZNumberFormatAtomicSignID::~FZZNumberFormatAtomicSignID()
{
    //DLOG("~FZZNumberFormatAtomicSignID()");
    FZZConst::delClassCount("FZZNumberFormatAtomicSignID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZNumberFormatAtomicSignID::setCurrentMaxSignId(string maxSignId)
{
    
    long maxSignIDNum = parse(maxSignId.c_str());
    m_provider.set(maxSignIDNum);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZNumberFormatAtomicSignID::setCurrentMaxSignId(long maxSignId)
{
    m_provider.set(maxSignId);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZNumberFormatAtomicSignID::incrementAndGet()
{
    long newSignID = m_provider.incrementAndGet();
    string retstr = "";
    if (m_enableZeroPrefix) {
        char buffer[200] = {0};
        sprintf(buffer, "%03ld", newSignID);
        retstr = buffer;
    } else {
        retstr = FZZConst::fmt(newSignID);
    }
    
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZNumberFormatAtomicSignID::get()
{
    long newSignID = m_provider.get();
    string retstr = "";
    if (m_enableZeroPrefix) {
        char buffer[200] = {0};
        sprintf(buffer, "%03ld", newSignID);
        retstr = buffer;
    } else {
        retstr = FZZConst::fmt(newSignID);
    }
    
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
long FZZNumberFormatAtomicSignID::parse(string id)
{
//    if ( id.length() == 3 && id[0] == '0' ) {
//        id = id.substr(1);
//        if ( id[0] == '0' ) {
//            id = id.substr(1);
//        }
//        m_enableZeroPrefix = true;
//    }
    while(id[0] == '0') {
        m_enableZeroPrefix = true;
        id = id.substr(1);
    }
    long maxSignIDNum = atol(id.c_str());
    return maxSignIDNum;
}
//-----------------------------------------------------------------------------------------------------------------
