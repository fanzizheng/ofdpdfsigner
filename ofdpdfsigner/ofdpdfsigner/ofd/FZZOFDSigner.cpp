//
//  Created by zizheng fan on 2024/03/12.
//
#include "basic/FZZConst.h"
#include "ofd/FZZOFDSigner.h"
#include "sign/FZZStandFormatAtomicSignID.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "sign/FZZNumberFormatAtomicSignID.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDSigner*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigner::FZZOFDSigner() : m_reader(NULL),m_MaxSignID(NULL),m_ofdDir(NULL),m_HasSign(false),
    m_signMode(FZZSignMode::TYPE::TYPE_WholeProtected),m_signaturesLoc(""),m_isCanSign(true)
    ,m_signContainer(NULL),m_relativeID("")
{
    //DLOG("FZZOFDSigner()");
    FZZConst::addClassCount("FZZOFDSigner");
    //m_Default_SignIDProvider = new FZZStandFormatAtomicSignID();
    m_Default_SignIDProvider = new FZZNumberFormatAtomicSignID();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigner::FZZOFDSigner(FZZOFD* reader) : FZZOFDSigner()
{
    m_reader = reader;
    m_MaxSignID = m_Default_SignIDProvider;
    setProperty(m_reader,m_MaxSignID);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigner::FZZOFDSigner(FZZOFD* reader,FZZSignIDProvider * signIDProvider) : FZZOFDSigner()
{
    m_reader = reader;
    m_MaxSignID = signIDProvider;
    setProperty(m_reader,m_MaxSignID);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSigner::~FZZOFDSigner()
{
    //DLOG("~FZZOFDSigner()");
    FZZConst::delClassCount("FZZOFDSigner");
    if ( m_Default_SignIDProvider != NULL ) {
        delete m_Default_SignIDProvider;
        m_Default_SignIDProvider = NULL;
    }
    
   
    
    m_NotDigestFile.clear();
    m_apList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::setProperty(FZZOFD* reader, FZZSignIDProvider* idProvider)
{
    if ( reader == NULL ) {
        return;
    }
    m_ofdDir = reader->getOFDDir();
    m_HasSign = false;
    m_signMode = FZZSignMode::TYPE::TYPE_WholeProtected;
    m_signaturesLoc = "";
    preChecker();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::preChecker()
{
    if ( m_ofdDir == NULL ) {
        return;
    }

    
    vector<FZZOFDDocDir *> * ofdDocDirList = m_ofdDir->getDocDirList();
    if ( ofdDocDirList == NULL ) {
        return;
    }
    vector<FZZOFDDocDir*>::const_iterator docdir_iter;
    for (docdir_iter = ofdDocDirList->begin(); docdir_iter != ofdDocDirList->end(); docdir_iter++) {
        FZZOFDDocDir * ofdDocDir = *docdir_iter;
        if ( ofdDocDir == NULL ) {
            continue;
        }
        FZZOFDSignsDir * ofdSignsDir = ofdDocDir->getSignsDir();
        if ( ofdSignsDir == NULL ) {
            continue;
        }
        FZZOFDSignaturesXML* ofdSignaturesXML = ofdSignsDir->getSignaturesXML();
        if ( ofdSignaturesXML == NULL ) {
            continue;
        }
        FZZOFDMaxSignId * ofdMaxSignId = ofdSignaturesXML->getMaxSignId();
        if ( ofdMaxSignId == NULL ) {
            continue;
        }
        
        m_signaturesLoc = ofdSignsDir->getPath() + ofdSignaturesXML->getFileName();
        
        string maxSignId = ofdMaxSignId->getValue();
        m_MaxSignID->setCurrentMaxSignId(maxSignId);
        
        vector<FZZOFDSignDir *>* ofdSignDirList = ofdSignsDir->getSignDirList();
        if ( ofdSignDirList == NULL ) {
            continue;
        }
        vector<FZZOFDSignDir*>::const_iterator signdir_iter;
        for (signdir_iter = ofdSignDirList->begin(); signdir_iter != ofdSignDirList->end(); signdir_iter++) {
            FZZOFDSignDir * ofdSignDir = *signdir_iter;
            if ( ofdSignDir == NULL ) {
                continue;
            }
            FZZOFDSignatureXML* ofdSignatureXML = ofdSignDir->getSignatureXML();
            if ( ofdSignatureXML == NULL ) {
                continue;
            }
            FZZOFDSignedInfo * ofdSignedInfo = ofdSignatureXML->getSignedInfo();
            if ( ofdSignedInfo == NULL ) {
                continue;
            }
            FZZOFDReferences * OFDReferences = ofdSignedInfo->getReferences();
            if ( OFDReferences == NULL ) {
                continue;
            }
            string SignsXml_FileName = ofdSignsDir->getPath() + ofdSignaturesXML->getFileName();
            if (OFDReferences->hasFile( SignsXml_FileName )) {
                m_isCanSign = false;
                break;
            }
            
        }//for (signdir_iter = ofdSignDirList->begin(); signdir_iter != ofdSignDirList->end(); signdir_iter++)
        
    }//for (docdir_iter = ofdDocDirList->begin(); docdir_iter != ofdDocDirList->end(); docdir_iter++)
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::addApPos(FZZStampAppearance* stampAppearance)
{
    if (stampAppearance != NULL) {
        m_apList.push_back(stampAppearance);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::clearApPos()
{
    m_apList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDSigner::exeSign()
{
    if ( !m_isCanSign ) {
        return false;
    }
    if ( m_signContainer == NULL ) {
        return false;
    }
    if ( m_ofdDir == NULL ) {
        return false;
    }
    m_HasSign = true;
    FZZOFDDocDir * ofdDocDir = m_ofdDir->getDocDir_default();
    if ( ofdDocDir == NULL ) {
        return false;
    }
    FZZOFDSignsDir * ofdSignsDir = ofdDocDir->getSignsDir();
    if ( ofdSignsDir == NULL ) {
        return false;
    }
   
    FZZOFDSignDir * ofdSignDir = ofdSignsDir->addSignDir();
    if ( ofdSignDir == NULL ) {
        return false;
    }
    FZZOFDSignaturesXML* ofdSignaturesXML = ofdSignsDir->setSignaturesXML();
    if ( ofdSignaturesXML == NULL ) {
        return false;
    }
    
    FZZOFDXML* ofdXML = m_ofdDir->getOFDXML();
    if ( ofdXML == NULL ) {
        return false;
    }
    FZZOFDDocBody* ofdDocBody = ofdXML->getDocBody_default();
    if ( ofdDocBody == NULL ) {
        return false;
    }
    FZZOFDDocBody_Signatures * ofdDocBody_Signatures = ofdDocBody->setSignatures();
    if ( ofdDocBody_Signatures == NULL ) {
        return false;
    }
    
    m_signaturesLoc = ofdSignsDir->getPath() + ofdSignaturesXML->getFileName();
    //fzz edit begin
    ofdDocBody_Signatures->setValue(m_signaturesLoc);
    //ofdDocBody_Signatures->setValue("/"+m_signaturesLoc);
    //fzz edit end
    m_ofdDir->FlushXMLObject(ofdXML);
    
    FZZOFDSignature* ofdSignature = ofdSignaturesXML->addSignature();
    if ( ofdSignature == NULL ) {
        return false;
    }
    
    FZZOFDSignatureXML* ofdSignatureXML = ofdSignDir->setSignatureXML();
    
    ofdSignature->setID(m_MaxSignID->incrementAndGet().c_str());
    
    ofdSignature->setType(m_signContainer->getOFDSignType());
    //fzz edit begin
    ofdSignature->setBaseLoc(ofdSignDir->getPath()+ofdSignatureXML->getFileName());
    //ofdSignature->setBaseLoc("/"+ofdSignDir->getPath()+ofdSignatureXML->getFileName());
    //fzz edit end
    if (!m_relativeID.empty() && FZZConst::Trim(m_relativeID).length() > 0) {
        ofdSignature->setRelative(m_relativeID);
    }
    string signatureFilePath = buildSignature(ofdSignsDir, ofdSignDir, ofdSignaturesXML);
    FZZBytes * tempFiledata = m_ofdDir->getResFile(signatureFilePath);
    if ( tempFiledata == NULL || tempFiledata->getLen() == 0 ) {
        return false;
    }
    
    string propertyInfo = ofdSignDir->getPath()+ofdSignatureXML->getFileName();
    //fzz del begin
//    if ( propertyInfo[0] != '/' ) {
//        propertyInfo = "/"+propertyInfo;
//    }
    //fzz del begin
    FZZBytes outsigndata;
    m_signContainer->sign(*tempFiledata, propertyInfo, outsigndata);
    
    ofdSignDir->FlushResFile("SignedValue.dat", &outsigndata);
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::generateSignOFD(FZZBytes & outSignOFDData)
{
    if ( m_reader != NULL ) {
        //m_reader->FlushAll();
        m_reader->Close(outSignOFDData);
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSigner::buildSignature(FZZOFDSignsDir* signsDir,FZZOFDSignDir* signDir,FZZOFDSignaturesXML* ofdSignaturesXML)
{
    string retstr = "";
    FZZOFDSignatureXML* ofdSignatureXML = NULL;
    FZZOFDSignedInfo * ofdSignedInfo = NULL;
    FZZOFDProvider * ofdProvider = NULL;
    FZZOFDSignatureMethod * ofdSignatureMethod = NULL;
    FZZOFDParameters * ofdParameters = NULL;
    FZZOFDSignatureDateTime * ofdSignatureDateTime = NULL;
    FZZOFDMaxSignId * ofdMaxSignId = NULL;
    FZZOFDSeal * seal = NULL;
    FZZOFDFileLoc * fileLoc = NULL;
    FZZOFDReferences * ofdReferences = NULL;
    FZZOFDReference * ofdReference = NULL;
    FZZOFDCheckValue * ofdCheckValue = NULL;
    FZZOFDSignedValue * ofdSignedValue = NULL;
    time_t createDate;
    FZZBytes sealBin;
    vector<FZZStampAppearance *>::const_iterator iter;
    FZZStampAppearance * tempStampAppearance = NULL;
    vector<string> toDigestFileInfos;
    vector<string>::const_iterator striter;
    FZZBytes * tempFiledata = NULL;
    string tempDigestFilename;
    
    if ( signsDir == NULL ) {
        goto err;
    }
    
    if ( signDir == NULL ) {
        goto err;
    }
    
    if ( ofdSignaturesXML == NULL ) {
        goto err;
    }
    
    ofdSignatureXML = signDir->setSignatureXML();
    if ( ofdSignatureXML == NULL ) {
        goto err;
    }
    ofdSignedInfo = ofdSignatureXML->setSignedInfo();
    if ( ofdSignedInfo == NULL ) {
        goto err;
    }
    ofdSignatureMethod = ofdSignedInfo->setSignatureMethod();
    if ( ofdSignatureMethod == NULL ) {
        goto err;
    }
    ofdSignatureMethod->setValue(m_signContainer->getSignAlgOID().c_str());
    
    ofdProvider = ofdSignedInfo->setProvider();
    if ( ofdProvider == NULL ) {
        goto err;
    }
    ofdProvider->setProviderName(OFD_CREATOR);
    ofdProvider->setCompany(OFD_COMPANY);
    ofdProvider->setVersion(OFD_VERSION);
    ofdParameters = ofdSignedInfo->setParameters();
    if ( ofdParameters == NULL ) {
        goto err;
    }
    time(&createDate);
    ofdSignatureDateTime = ofdSignedInfo->setSignatureDateTime();
    if ( ofdSignatureDateTime == NULL ) {
        goto err;
    }
    ofdSignatureDateTime->setValue(FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(createDate).c_str());
    if (m_signContainer->getOFDSignType() == FZZOFDSigType::TYPE::TYPE_Seal) {
        sealBin = m_signContainer->getSeal();
        if (sealBin.getLen() > 0) {
       
            signDir->FlushResFile("Seal.esl", &sealBin);
            seal = ofdSignedInfo->setSeal();
            if ( seal == NULL ) {
                goto err;
            }
            fileLoc = seal->setBaseLoc();
            if ( fileLoc == NULL ) {
                goto err;
            }
            //fzz edit begin
            fileLoc->setValue(signDir->getPath()+"Seal.esl");
            //fileLoc->setValue("/"+signDir->getPath()+SignDir::SealFileName);
            //fzz edit end
        }
    }
    if ( m_apList.size() > 0 ) {
        for (iter = m_apList.begin(); iter != m_apList.end(); iter++) {
            tempStampAppearance = *iter;
            tempStampAppearance->getAppearance(m_reader, m_MaxSignID, ofdSignedInfo);
        }
    }
    ofdMaxSignId = ofdSignaturesXML->setMaxSignId();
    if ( ofdMaxSignId == NULL ) {
        goto err;
    }
    ofdMaxSignId->setValue(m_MaxSignID->get().c_str());
    
    signsDir->FlushXMLObject(ofdSignaturesXML);
    
    ofdReferences = ofdSignedInfo->setReferences();
    if ( ofdReferences == NULL ) {
        goto err;
    }
    ofdReferences->setCheckMethod(FZZOFDCheckMethod::TYPE::TYPE_SM3);
    
    getDigestFileList(toDigestFileInfos);
    
    for (striter = toDigestFileInfos.begin(); striter != toDigestFileInfos.end(); striter++) {
        tempDigestFilename = *striter;
        tempFiledata = m_ofdDir->getResFile(tempDigestFilename);
        if ( tempFiledata == NULL || tempFiledata->getLen() == 0 ) {
            goto err;
        }
        string digest = calculateFileDigest(*tempFiledata);
        ofdReference = ofdReferences->addReference();
        if ( ofdReference == NULL ) {
            goto err;
        }
        //fzz edit begin
        ofdReference->setFileRef("/"+tempDigestFilename);
        //ofdReference->setFileRef(tempDigestFilename);
        //fzz edit end
        ofdCheckValue = ofdReference->setCheckValue();
        if ( ofdCheckValue == NULL ) {
            goto err;
        }
        ofdCheckValue->setValue(digest);
    }
    
    ofdSignedValue = ofdSignatureXML->setSignedValue();
    if ( ofdSignedValue == NULL ) {
        goto err;
    }
    ofdSignedValue->setValue(signDir->getPath()+FZZOFDSignDir::SignedValueFileName);
    signDir->FlushXMLObject(ofdSignatureXML);
    
    
    retstr = signDir->getPath()+ofdSignatureXML->getFileName();
    
err:
    
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSigner::calculateFileDigest(FZZBytes & filedata)
{
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest("SM3", filedata, hashData);
    if ( hashData.getLen() < 8 ) {
        return "";
    }
    return FZZConst::Base64Encode(hashData.getData(),hashData.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSigner::getDigestFileList(vector<string> & digestFileList)
{
    if ( m_ofdDir == NULL ) {
        return;
    }
    
    FZZOFDFilesContainer* filesContainer = m_ofdDir->getFileContainer();
    if ( filesContainer == NULL ) {
        return;
    }
    vector<string> FileList;
    filesContainer->getFilesName(m_ofdDir->getRoot(), FileList);
    vector<string>::const_iterator iter;
    
    string strsignaturesloc = "";
    if ( !m_signaturesLoc.empty() ) {
        strsignaturesloc = m_signaturesLoc;
        transform(strsignaturesloc.begin(), strsignaturesloc.end(), strsignaturesloc.begin(), ::tolower);
    }
    
    for (iter = FileList.begin(); iter != FileList.end(); iter++) {
        string tempFilename = *iter;
        if ( m_signMode == FZZSignMode::TYPE::TYPE_ContinueSign && tempFilename ==  strsignaturesloc ) {
            continue;
        }
        if ( m_NotDigestFile.size() > 0 ) {
            vector<string>::const_iterator striter;
            bool isfind = false;
            for (striter = m_NotDigestFile.begin(); striter != m_NotDigestFile.end(); striter++) {
                string tempNotDigestFilename = *striter;
                transform(tempNotDigestFilename.begin(), tempNotDigestFilename.end(), tempNotDigestFilename.begin(), ::tolower);
                if ( tempNotDigestFilename == tempFilename ) {
                    isfind = true;
                    break;
                }
            }
            if ( !isfind ) {
                digestFileList.push_back(tempFilename);
            }
        } else {
            digestFileList.push_back(tempFilename);
        }
    }
     
}
//-----------------------------------------------------------------------------------------------------------------




