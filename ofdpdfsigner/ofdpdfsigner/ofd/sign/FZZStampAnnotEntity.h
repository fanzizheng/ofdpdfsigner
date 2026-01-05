//
//  Created by zizheng fan on 2022/10/25.
//
#ifndef FZZSTAMPANNOTENTITY_H
#define FZZSTAMPANNOTENTITY_H

#include "gm/ses/parse/FZZSESVersionHolder.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedInfo.h"

class FZZStampAnnotEntity
{
public:
    FZZStampAnnotEntity(string sid,FZZBytes * signedValueFile, FZZOFDSignedInfo * signedInfo);
	virtual ~FZZStampAnnotEntity();
public:

    FZZBytes getImageByte() {return m_imageByte;}
    //FZZBytes* getImageByteRef() {return &m_imageByte;}
    string getImgType() {return m_imgType;}
    FZZSESVersionHolder* getHolder() {return m_sesVersionHolder;}
    
    
    
    vector<FZZOFDStampAnnot*> * getStampAnnots_OFD() {
        if ( m_ofdSignedInfo != NULL ) {
            return m_ofdSignedInfo->getStampAnnotList();
        }
        return NULL;
    }
    
    string getSignatureDateTime_OFD() {
        if ( m_ofdSignedInfo != NULL ) {
            FZZOFDSignatureDateTime * sdt = m_ofdSignedInfo->getSignatureDateTime();
            return sdt == NULL ? "" : sdt->getValue();
        } else {
            return "";
        }
    }
    FZZOFDSignedInfo* getSignedInfo_OFD() {return m_ofdSignedInfo;}
    
    string getSid() { return m_ID; }
    
protected:
	
private:
    FZZStampAnnotEntity();
    FZZStampAnnotEntity(const FZZStampAnnotEntity& obj);
    void init();

private:
    
    
    FZZBytes m_imageByte;
    string m_imgType;
    string m_ID;
    FZZSESVersionHolder* m_sesVersionHolder;
    FZZOFDSignedInfo * m_ofdSignedInfo;
    
};

#endif //FZZSTAMPANNOTENTITY_H

