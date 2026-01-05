//
//  Created by zizheng fan on 2024/03/14.
//
#ifndef FZZOFDVALIDATOR_H
#define FZZOFDVALIDATOR_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"
#include "sign/verify/FZZSignedDataValidateContainer.h"

class FZZOFDValidator
{
public:
    FZZOFDValidator(FZZOFD* reader);

	~FZZOFDValidator();
public:
    int exeValidate(CallBack_Verify verifyFunc,const void * callBack_Param);
    //sid->pageindxe->image 
    //free stampimages => FZZBytes*
    void getSignInfos(vector<string> & pageIndexs,vector<string> & sids,vector<string> & signTimes,vector<FZZBytes *> & stampimages);
    int Verify(string sid,CallBack_Verify verifyFunc,const void * callBack_Param,string & outsigntime,string & outsigner);
protected:
    FZZOFDValidator();
private:
    int checkFileIntegrity(FZZOFDDir* ofdDir,FZZOFDSignatureXML* sig);
    bool checkSealMatch(FZZOFDDir* ofdDir,string sealPath, string signedValuePath);
    int checkSignedValue(FZZOFDDir* ofdDir,FZZOFDSigType::TYPE type, string alg, string signatureFilePath, string signedValuePath,CallBack_Verify verifyFunc,const void * callBack_Param,string & signdn);
private:
    FZZOFD* m_reader;
  
    
};

#endif //FZZOFDVALIDATOR_H


