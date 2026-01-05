//
//  Created by zizheng fan on 2023/01/06.
//
#include "basic/FZZConst.h"
#include "ofd/sign/FZZStandFormatAtomicSignID.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZStandFormatAtomicSignID*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZStandFormatAtomicSignID::FZZStandFormatAtomicSignID() : FZZSignIDProvider(), m_provider(0)
{
    //DLOG("FZZStandFormatAtomicSignID()");
    FZZConst::addClassCount("FZZStandFormatAtomicSignID");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZStandFormatAtomicSignID::FZZStandFormatAtomicSignID(string maxSignID) : FZZStandFormatAtomicSignID()
{
    setCurrentMaxSignId(maxSignID);
}
//-----------------------------------------------------------------------------------------------------------------
FZZStandFormatAtomicSignID::FZZStandFormatAtomicSignID(const FZZStandFormatAtomicSignID& obj) : FZZStandFormatAtomicSignID()
{
    if ( this == &obj ) {
        return;
    }
    this->m_provider = obj.m_provider;
    
}
//-----------------------------------------------------------------------------------------------------------------
const FZZStandFormatAtomicSignID& FZZStandFormatAtomicSignID::operator=(const FZZStandFormatAtomicSignID& obj)
{
    if ( this == &obj ) {
        return *this;
    }
    this->m_provider = obj.m_provider;
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
FZZStandFormatAtomicSignID::~FZZStandFormatAtomicSignID()
{
    //DLOG("~FZZStandFormatAtomicSignID()");
    FZZConst::delClassCount("FZZStandFormatAtomicSignID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZStandFormatAtomicSignID::setCurrentMaxSignId(string maxSignId)
{
    long maxSignIDNum = parse(maxSignId.c_str());
    m_provider.set(maxSignIDNum);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
string FZZStandFormatAtomicSignID::incrementAndGet()
{
    
    string retstr = "";
    long newSignID = m_provider.incrementAndGet();
    char buffer[200] = {0};
    sprintf(buffer, "s%03ld", newSignID);
    retstr = buffer;
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZStandFormatAtomicSignID::get()
{
    
    string retstr = "";
    long newSignID = m_provider.get();
    char buffer[200] = {0};
    sprintf(buffer, "s%03ld", newSignID);
    retstr = buffer;
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
long FZZStandFormatAtomicSignID::parse(string id)
{
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    
    if ( id[0] == 's' ) {
        id = id.substr(1);
        if ( id[0] == '\'' && id[id.length()-1] == '\'' ) {
            id = id.substr(1,id.length()-2);
        }
    }
    
    while(id[0] == '0') {
        id = id.substr(1);
    }
    
    long maxSignIDNum = strtol(id.c_str(), NULL, 10);
    return maxSignIDNum;
}
//-----------------------------------------------------------------------------------------------------------------
