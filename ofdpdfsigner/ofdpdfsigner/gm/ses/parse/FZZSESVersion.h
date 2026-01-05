//
//  Created by zizheng fan on 2022/11/18.
//
#ifndef FZZSESVERSION_H
#define FZZSESVERSION_H



class FZZSESVersion
{
public:
    typedef enum {
        vdata = 0,
        v1 = 1,
        v4 = 4
        
    } TYPE;
public:
    FZZSESVersion() {//DLOG("FZZSESVersion()");
        FZZConst::addClassCount("FZZSESVersion");
    }
    FZZSESVersion(FZZSESVersion::TYPE version) :FZZSESVersion(){
        //DLOG("FZZSESVersion(FZZSESVersion::TYPE version)");
        
        m_version = version;
        
    }
    FZZSESVersion(const FZZSESVersion& obj) :FZZSESVersion() { //DLOG("FZZSESVersion(const FZZSESVersion& obj)");
        this->m_version = obj.m_version;
        
    }
    virtual ~FZZSESVersion() {//DLOG("~FZZSESVersion()");
        FZZConst::delClassCount("FZZSESVersion");
    }
public:
    FZZSESVersion::TYPE getVersion() {
        return m_version;
    }

    void setVersion(const FZZSESVersion::TYPE v) {
        m_version = v;
    }
protected:
	
private:
    
private:
    FZZSESVersion::TYPE m_version;
    
};

#endif //FZZSESVERSION_H

