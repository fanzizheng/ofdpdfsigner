//
//  Created by zizheng fan on 2023/01/05.
//
#ifndef FZZNUMBERFORMATATOMICSIGNID_H
#define FZZNUMBERFORMATATOMICSIGNID_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "basic/FZZAtomicInteger.h"
#include "ofd/sign/FZZSignIDProvider.h"

class FZZNumberFormatAtomicSignID : public FZZSignIDProvider
{
public:
    FZZNumberFormatAtomicSignID();
    FZZNumberFormatAtomicSignID(bool enableZeroPrefix);
    FZZNumberFormatAtomicSignID(string maxSignID);
    FZZNumberFormatAtomicSignID(const FZZNumberFormatAtomicSignID& obj);
    const FZZNumberFormatAtomicSignID& operator=(const FZZNumberFormatAtomicSignID& obj);
    virtual ~FZZNumberFormatAtomicSignID();
	
public:
    virtual void setCurrentMaxSignId(string maxSignId);
    void setCurrentMaxSignId(long maxSignId);
    
    virtual string incrementAndGet();
    virtual string get();
    
    void setEnableZeroPrefix(bool enableZeroPrefix) { m_enableZeroPrefix = enableZeroPrefix; }
    bool isEnableZeroPrefix() { return m_enableZeroPrefix; }
    
    virtual long parse(string id);
protected:
	
private:
    FZZAtomicInteger m_provider;
    //Add 0 prefix, defualt false
    bool m_enableZeroPrefix;
};

#endif //FZZNUMBERFORMATATOMICSIGNID_H


