//
//  Created by zizheng fan on 2023/01/06.
//
#ifndef FZZSTANDFORMATATOMICSIGNID_H
#define FZZSTANDFORMATATOMICSIGNID_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "basic/FZZAtomicInteger.h"
#include "ofd/sign/FZZSignIDProvider.h"

class FZZStandFormatAtomicSignID : public FZZSignIDProvider
{
public:
    FZZStandFormatAtomicSignID();
    FZZStandFormatAtomicSignID(string maxSignID);
    FZZStandFormatAtomicSignID(const FZZStandFormatAtomicSignID& obj);
    const FZZStandFormatAtomicSignID& operator=(const FZZStandFormatAtomicSignID& obj);
    virtual ~FZZStandFormatAtomicSignID();
	
public:
    virtual void setCurrentMaxSignId(string maxSignId);
    virtual string incrementAndGet();
    virtual string get();
    virtual long parse(string id);
    
protected:
	
private:
    FZZAtomicInteger m_provider;
};

#endif //FZZSTANDFORMATATOMICSIGNID_H


