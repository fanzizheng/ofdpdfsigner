//
//  Created by zizheng fan on 2024/03/12.
//
#ifndef FZZOFDSIGNER_H
#define FZZOFDSIGNER_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"
#include "sign/FZZSignIDProvider.h"
#include "sign/FZZSignMode.h"
#include "sign/FZZExtendSignatureContainer.h"
#include "sign/stamppos/FZZStampAppearance.h"

class FZZOFDSigner
{
public:
    FZZOFDSigner(FZZOFD* reader);
    FZZOFDSigner(FZZOFD* reader,FZZSignIDProvider * signIDProvider);
	~FZZOFDSigner();
public:
    //true: can add stamp; fasle : not add stamp;
    bool isCanSign() { return m_isCanSign; }
    
    void clearApPos();
    
    FZZSignMode::TYPE getSignMode() { return m_signMode; }
    void setSignMode(FZZSignMode::TYPE signMode) { m_signMode = signMode; }
    void setSignContainer(FZZExtendSignatureContainer* signContainer) { m_signContainer = signContainer; }
    void addApPos(FZZStampAppearance* stampAppearance);
    //not hash
    void addNotDigestFile(string notDigestFile) { m_NotDigestFile.push_back(notDigestFile); }
    void setRelative(string id) { m_relativeID = id; }
    
    bool exeSign();
    
    void generateSignOFD(FZZBytes & outSignOFDData);
    
    
    
protected:
    FZZOFDSigner();
private:
    void setProperty(FZZOFD* reader, FZZSignIDProvider* idProvider);
    void preChecker();
    
    void getDigestFileList(vector<string> & digestFileList);
    string buildSignature(FZZOFDSignsDir* signsDir,FZZOFDSignDir* signDir,FZZOFDSignaturesXML* ofdSignaturesXML);
    string calculateFileDigest(FZZBytes & filedata);
private:

    FZZOFD * m_reader;
    FZZOFDDir* m_ofdDir;

    
    FZZSignIDProvider * m_MaxSignID;
    FZZSignIDProvider * m_Default_SignIDProvider;
    
    
    bool m_HasSign;
    bool m_isCanSign;
    FZZSignMode::TYPE m_signMode;
    string m_signaturesLoc;
    FZZExtendSignatureContainer * m_signContainer;
    vector<FZZStampAppearance*> m_apList;
    vector<string> m_NotDigestFile;
    string m_relativeID;
};

#endif //FZZOFDSIGNER_H


