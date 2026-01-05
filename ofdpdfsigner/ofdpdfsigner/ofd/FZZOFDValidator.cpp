//
//  Created by zizheng fan on 2024/03/14.
//
#include "basic/FZZConst.h"
#include "ofd/FZZOFDValidator.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "gm/ses/parse/FZZVersionParser.h"
#include "gm/ses/v4/FZZSES_Signature_V4.h"
#include "gm/ses/v1/FZZSES_Signature_V1.h"
#include "sign/verify/container/FZZSESV4ValidateContainer.h"
#include "sign/verify/container/FZZSESV1ValidateContainer.h"
#include "sign/verify/container/FZZGBT35275ValidateContainer.h"

#include "converter/image/FZZOFDToImage.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDValidator*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidator::FZZOFDValidator() : m_reader(NULL)
{
    //DLOG("FZZOFDValidator()");
    FZZConst::addClassCount("FZZOFDValidator");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidator::FZZOFDValidator(FZZOFD* reader) : FZZOFDValidator()
{
    m_reader = reader;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidator::~FZZOFDValidator()
{
    //DLOG("~FZZOFDValidator()");
    FZZConst::delClassCount("FZZOFDValidator");
}
//-----------------------------------------------------------------------------------------------------------------
//-1 : must seal type
//-20 : Digest error
//-30 : The Signature.xml file has been tampered with
//-100 : get TBS_Sign error;
//-101 : Unsupported data structure
//-200 :  verifySign error;
//-201 :  load cert error;
//-300 : reader ofd error;
//-301 : stamp error;
//-302 : m_validator not set
//-303 : sign data is null
int FZZOFDValidator::Verify(string sid,CallBack_Verify verifyFunc,const void * callBack_Param,string & outsigntime,string & outsigner)
{
    if ( m_reader == NULL ) {
        return -300;
    }
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) {
        return -300;
    }
    FZZOFDDocDir * docDir = m_reader->getDocDir_default();
    if ( docDir == NULL ) return -300;
    
    FZZOFDSignsDir* signsDir = docDir->getSignsDir();
    if ( signsDir == NULL ) return -300;
    
    FZZOFDSignaturesXML* sigList = signsDir->getSignaturesXML();
    if ( sigList == NULL ) {
        return -300;
    }
    
    vector<FZZOFDSignDir *> * signDirList = signsDir->getSignDirList();
    if ( signDirList == NULL ) {
        return -300;
    }
    
    vector<FZZOFDSignature*>*  signatures = sigList->getSignatureList();
    if ( signatures == NULL ) {
        return -300;
    }
    
    int ret = 0;
    
    vector<FZZOFDSignature*>::const_iterator signatures_it;
    for( signatures_it = signatures->begin(); signatures_it != signatures->end(); signatures_it++ ) {
        FZZOFDSignature* sigRecord = *signatures_it;
        if ( sigRecord == NULL ) {
            continue;
        }
        
        if (  sid == sigRecord->getID() )  {
            
            FZZOFDSigType::TYPE type = sigRecord->getType();
           
            
            string baseLoc = sigRecord->getBaseLoc();
            string tempsignpath = baseLoc;
            if ( tempsignpath.empty() ) {
                return -303;
            }
            
            tempsignpath = FZZConst::replace_all(tempsignpath,"\\","/");
            if ( tempsignpath[0] == '/' ) {
                tempsignpath = tempsignpath.substr(1);
            }
            size_t pos = tempsignpath.find_last_of("/");
            if ( pos != string::npos ) {
                FZZOFDSignatureXML * signatureXML = signsDir->getSignatureXML(tempsignpath.substr(0, pos + 1));
                if ( signatureXML == NULL ) {
                    return -303;
                }
                if ( (ret = checkFileIntegrity(ofdDir,signatureXML)) != 0 ) {
                    return ret;
                }
                FZZOFDSignedValue * signedValue = signatureXML->getSignedValue();
                if ( signedValue == NULL ) {
                    return -303;
                }
                string signedValueFilePath = signedValue->getValue();

                FZZOFDSignedInfo * si = signatureXML->getSignedInfo();
                if ( si == NULL ) {
                    return -303;
                }
                
                if (type == FZZOFDSigType::TYPE::TYPE_Seal) {
                    
                    FZZOFDSeal * seal = si->getSeal();
                    if (seal != NULL) {
                        FZZOFDFileLoc * sealloc = seal->getBaseLoc();
                  
                        if ( sealloc != NULL ) {
                             if (!checkSealMatch(ofdDir,sealloc->getValue(), signedValueFilePath)){
                                 return -301;
                             }
                        }
                    }
                    
                }
                FZZOFDSignatureDateTime * signatureDateTime = si->getSignatureDateTime();
                if ( signatureDateTime != NULL ) {
                    outsigntime = signatureDateTime->getValue();
                }
                FZZOFDSignatureMethod * signatureMethod = si->getSignatureMethod();
                if ( signatureMethod != NULL ) {
                    string alg = signatureMethod->getValue();
                    ret = checkSignedValue(ofdDir,type, alg, baseLoc, signedValueFilePath,verifyFunc,callBack_Param,outsigner);
                    if ( ret != 0 ) {
                        return ret;
                    }
                } else {
                    return -301;
                }
                break;
            }//if ( pos != string::npos )
        } //sid == sigRecord->getID()
        
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//-1 : must seal type
//-20 : Digest error
//-30 : The Signature.xml file has been tampered with
//-100 : get TBS_Sign error;
//-101 : Unsupported data structure
//-200 :  verifySign error;
//-201 :  load cert error;
//-300 : reader ofd error;
//-301 : stamp error;
//-302 : m_validator not set
//-303 : sign data is null

int FZZOFDValidator::exeValidate(CallBack_Verify verifyFunc,const void * callBack_Param)
{
    if ( m_reader == NULL ) {
        return -300;
    }
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) {
        return -300;
    }
    FZZOFDDocDir * docDir = m_reader->getDocDir_default();
    if ( docDir == NULL ) return -300;
    
    FZZOFDSignsDir* signsDir = docDir->getSignsDir();
    if ( signsDir == NULL ) return -300;
    
    FZZOFDSignaturesXML* sigList = signsDir->getSignaturesXML();
    if ( sigList == NULL ) {
        return -300;
    }
    
    vector<FZZOFDSignDir *> * signDirList = signsDir->getSignDirList();
    if ( signDirList == NULL ) {
        return -300;
    }
    
    vector<FZZOFDSignature*>*  signatures = sigList->getSignatureList();
    if ( signatures == NULL ) {
        return -300;
    }
    
    int ret = 0;
    
    vector<FZZOFDSignature*>::const_iterator signatures_it;
    for( signatures_it = signatures->begin(); signatures_it != signatures->end(); signatures_it++ ) {
        FZZOFDSignature* sigRecord = *signatures_it;
        if ( sigRecord == NULL ) {
            continue;
        }
        
       
            
        FZZOFDSigType::TYPE type = sigRecord->getType();
       
        
        string baseLoc = sigRecord->getBaseLoc();
        string tempsignpath = baseLoc;
        if ( tempsignpath.empty() ) {
            return -303;
        }
        
        tempsignpath = FZZConst::replace_all(tempsignpath,"\\","/");
        if ( tempsignpath[0] == '/' ) {
            tempsignpath = tempsignpath.substr(1);
        }
        size_t pos = tempsignpath.find_last_of("/");
        if ( pos != string::npos ) {
            FZZOFDSignatureXML * signatureXML = signsDir->getSignatureXML(tempsignpath.substr(0, pos + 1));
            if ( signatureXML == NULL ) {
                return -303;
            }
            if ( (ret = checkFileIntegrity(ofdDir,signatureXML)) != 0 ) {
                return ret;
            }
            FZZOFDSignedValue * signedValue = signatureXML->getSignedValue();
            if ( signedValue == NULL ) {
                return -303;
            }
            string signedValueFilePath = signedValue->getValue();

            FZZOFDSignedInfo * si = signatureXML->getSignedInfo();
            if ( si == NULL ) {
                return -303;
            }
            
            if (type == FZZOFDSigType::TYPE::TYPE_Seal) {
                
                FZZOFDSeal * seal = si->getSeal();
                if (seal != NULL) {
                    FZZOFDFileLoc * sealloc = seal->getBaseLoc();
              
                    if ( sealloc != NULL ) {
                         if (!checkSealMatch(ofdDir,sealloc->getValue(), signedValueFilePath)){
                             return -301;
                         }
                    }
                }
                
            }
            
            FZZOFDSignatureMethod * signatureMethod = si->getSignatureMethod();
            if ( signatureMethod != NULL ) {
                string alg = signatureMethod->getValue();
                string outsigner;
                ret = checkSignedValue(ofdDir,type, alg, baseLoc, signedValueFilePath,verifyFunc,callBack_Param,outsigner);
                if ( ret != 0 ) {
                    return ret;
                }
            } else {
                return -301;
            }
            break;
        }//if ( pos != string::npos )
      
        
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDValidator::checkFileIntegrity(FZZOFDDir* ofdDir,FZZOFDSignatureXML* sig)
{
    if ( sig == NULL || ofdDir == NULL ) {
        return -300;
    }
    FZZOFDSignedInfo *  signedInfo = sig->getSignedInfo();
    if ( signedInfo == NULL ) {
        return -300;
    }
    FZZOFDReferences * references = signedInfo->getReferences();
    if ( references == NULL ) {
        return -300;
    }
    string checkMethod = references->getCheckMethod_String();
    
    vector<FZZOFDReference*>* referenceList= references->getReferenceList();
    if ( referenceList == NULL ) {
        return -300;
    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes* tempFiledata;
    vector<FZZOFDReference*>::const_iterator reference_it;
    for( reference_it = referenceList->begin(); reference_it != referenceList->end(); reference_it++ ) {
        FZZOFDReference* ref = *reference_it;
        if ( ref == NULL ) {
            continue;
        }
        
        string fileRef = ref->getFileRef();
        fileRef = FZZConst::replace_all(fileRef,"\\","/");
        if ( fileRef[0] == '/' ) {
            fileRef = fileRef.substr(1);
        }
        
        tempFiledata = ofdDir->getResFile(fileRef);
        if ( tempFiledata == NULL || tempFiledata->getLen() == 0 ) {
            continue;
        }
        FZZOFDCheckValue * checkValue = ref->getCheckValue();
        string expectDataHash = checkValue->getValue();
        
        FZZBytes hashData;
        gmCrypto.Digest(checkMethod.c_str(), *tempFiledata, hashData);
        if ( hashData.getLen() < 8 ) {
            return -20;
        }
        
        string actualDataHash = FZZConst::Base64Encode(hashData.getData(),hashData.getLen());
        
        if ( expectDataHash != actualDataHash ) {
            return -30;
        }
        
        
    }
    return 0;
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDValidator::checkSealMatch(FZZOFDDir* ofdDir,string sealPath, string signedValuePath)
{
    if ( ofdDir == NULL ) {
        return false;
    }
    sealPath = FZZConst::replace_all(sealPath,"\\","/");
    if ( sealPath[0] == '/' ) {
        sealPath = sealPath.substr(1);
    }
    
    signedValuePath = FZZConst::replace_all(signedValuePath,"\\","/");
    if ( signedValuePath[0] == '/' ) {
        signedValuePath = signedValuePath.substr(1);
    }
    
    FZZBytes * tempSignedValue = ofdDir->getResFile(signedValuePath);
    if ( tempSignedValue == NULL || tempSignedValue->getLen() < 10 ) {
        return false;
    }
    
    FZZSESVersionHolder* v = FZZVersionParser::parseSES_SignatureVersion(*tempSignedValue);
    if ( v == NULL ) {
        return false;
    }
    
    FZZBytes expect;
    if (v->getVersion() == FZZSESVersion::TYPE::v4) {
        FZZSES_Signature_V4 sesSignature(*tempSignedValue);
        FZZTBS_Sign_V4* tbssign = sesSignature.getToSign();
        if ( tbssign == NULL ) {
            delete v;
            return false;
        }
        FZZSESeal_V4* eseal = tbssign->getEseal();
        if ( eseal == NULL ) {
            delete v;
            return false;
        }
        expect = eseal->Encode();
    } else if (v->getVersion() == FZZSESVersion::TYPE::v1) {
        FZZSES_Signature_V1 sesSignature(*tempSignedValue);
        FZZTBS_Sign_V1* tbssign = sesSignature.getToSign();
        if ( tbssign == NULL ) {
            delete v;
            return false;
        }
        FZZSESeal_V1* eseal = tbssign->getEseal();
        if ( eseal == NULL ) {
            delete v;
            return false;
        }
        expect = eseal->Encode();
    } else {
        delete v;
        return false;
    }
    
//    if ( sealPath[0] != '/' ) {
//        sealPath = "/"+sealPath;
//    }
    
    FZZBytes * tempsealdata = ofdDir->getResFile(sealPath);
    if ( tempsealdata != NULL ) {
        if ( memcmp(expect.getData(),tempsealdata->getData(),expect.getLen() ) != 0 ) {
            delete v;
            return false;
        }
    } else {
        delete v;
        return false;
    }
        
    delete v;
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDValidator::checkSignedValue(FZZOFDDir* ofdDir,FZZOFDSigType::TYPE type, string alg, string signatureFilePath, string signedValuePath,CallBack_Verify verifyFunc,const void * callBack_Param,string & signdn)
{
    if ( ofdDir == NULL ) {
        return false;
    }
    signatureFilePath = FZZConst::replace_all(signatureFilePath,"\\","/");
    if ( signatureFilePath[0] == '/' ) {
        signatureFilePath = signatureFilePath.substr(1);
    }
    
    signedValuePath = FZZConst::replace_all(signedValuePath,"\\","/");
    if ( signedValuePath[0] == '/' ) {
        signedValuePath = signedValuePath.substr(1);
    }
    
    FZZBytes * tempsealsourcedata = ofdDir->getResFile(signatureFilePath);
    FZZBytes * tempSignedValue = ofdDir->getResFile(signedValuePath);
    if ( tempsealsourcedata == NULL || tempsealsourcedata->getLen() < 10 || tempSignedValue == NULL || tempSignedValue->getLen() < 10 ) {
        return -303;
    }
    
    FZZSESVersionHolder* v = FZZVersionParser::parseSES_SignatureVersion(*tempSignedValue);
    if ( v == NULL ) {
        return -301;
    }
    
    FZZSignedDataValidateContainer * validator = NULL;
    if (v->getVersion() == FZZSESVersion::TYPE::v4) {
        validator = new FZZSESV4ValidateContainer();
    } else if (v->getVersion() == FZZSESVersion::TYPE::v1) {
        validator = new FZZSESV1ValidateContainer();
    } else {
        validator = new FZZGBT35275ValidateContainer();
    }

    
    int ret = 0;
    if ( validator != NULL ) {
        ret = validator->validate(type, alg,verifyFunc,callBack_Param, *tempsealsourcedata, *tempSignedValue,signdn);
        if (v->getVersion() == FZZSESVersion::TYPE::v4) {
            delete (FZZSESV4ValidateContainer*)validator;
        } else if (v->getVersion() == FZZSESVersion::TYPE::v1) {
            delete (FZZSESV1ValidateContainer*)validator;
        } else {
            delete (FZZGBT35275ValidateContainer*)validator;
        }
    }
    
    
    
    delete v;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDValidator::getSignInfos(vector<string> & pageIndexs,vector<string> & sids,vector<string> & signTimes,vector<FZZBytes *> & stampimages)
{

    if ( m_reader == NULL ) return;
    
    vector<TPageInfo*> * pageInfoList = m_reader->getPageInfoList();

    if ( pageInfoList != NULL && pageInfoList->size() > 0 ) {
    
        vector<FZZStampAnnotEntity*> * stampAnnotEntityList = m_reader->getStampAnnots();

        vector<FZZStampAnnotEntity*>::const_iterator StampAnnotEntity_iter;
        for (StampAnnotEntity_iter = stampAnnotEntityList->begin(); StampAnnotEntity_iter != stampAnnotEntityList->end(); StampAnnotEntity_iter++) {
            FZZStampAnnotEntity* stampAnnotVo = *StampAnnotEntity_iter;
            if ( stampAnnotVo != NULL ) {
                FZZBytes imageData = stampAnnotVo->getImageByte();
                
                if ( stampAnnotVo->getImgType() == "ofd" ) {
                    
                    FZZOFD tempreader;
                    if ( tempreader.Read(imageData) ) {

                        FZZOFDToImage imagemaker(&tempreader,3);

                        if ( imagemaker.pageSize() > 0 ) {
                            imageData = imagemaker.makePage(0, "PNG");
                        }
                    }
                }
            
                string strsid = stampAnnotVo->getSid();
                string strsigntime = stampAnnotVo->getSignatureDateTime_OFD();
                string pagenums = "";
                
            
                vector<FZZOFDStampAnnot*>* stampAnnots = stampAnnotVo->getStampAnnots_OFD();
                if ( stampAnnots != NULL ) {
                    for ( int i = 0; i < stampAnnots->size(); i++ ) {
                        FZZOFDStampAnnot * stampAnnot = (*stampAnnots)[i];
                        if ( stampAnnot != NULL ) {
                            
                            string temprefid = stampAnnot->getPageRef();
                            if ( !temprefid.empty() ) {
                                
                                //int pageindex = 0;
                                vector<TPageInfo*>::const_iterator pageinfositer;
                                for (pageinfositer = pageInfoList->begin(); pageinfositer != pageInfoList->end(); pageinfositer++) {
                                    TPageInfo * tempPageInfo = *pageinfositer;
                                    if ( tempPageInfo != NULL && temprefid ==  tempPageInfo->id ) {
                                        if ( !pagenums.empty() ) {
                                            pagenums += ",";
                                        }
                                        pagenums += FZZConst::fmt(pageinfositer-pageInfoList->begin()+1);
                                        break;
                                    }
                                }
                            }
                        
                            
                            
                            
                        }
                    }
                    
                }
                    
                
                //DLOG("stamp : pagenums %s,sigintime %s,len %d",pagenums.c_str(),strsigntime.c_str(),imageData.getLen());

                pageIndexs.push_back(pagenums);
                sids.push_back(strsid);
                signTimes.push_back(strsigntime);
                FZZBytes * tempImage = new FZZBytes(imageData.getData(),imageData.getLen());
                stampimages.push_back(tempImage);
                //const char* ppagenums = pagenums.c_str();
                //const char* pTime = strsigntime.c_str();
                //const char* psid = strsid.c_str();
                
                //stampsFunc(ppagenums, pTime,psid,imageData.getData(),imageData.getLen());
                
            }
        }

      
    }

}
//-----------------------------------------------------------------------------------------------------------------
