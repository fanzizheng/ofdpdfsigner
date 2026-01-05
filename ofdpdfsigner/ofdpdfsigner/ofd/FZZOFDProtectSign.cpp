//
//  Created by zizheng fan on 2024/09/25.
//
#include "basic/FZZConst.h"
#include "ofd/FZZOFDProtectSign.h"
#include "gm/crypto/FZZGMCrypto.h"
#include "ofd/sign/signcontainer/FZZGBT35275DSContainer.h"
#include "ofd/sign/verify/container/FZZGBT35275ValidateContainer.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDProtectSign*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProtectSign::FZZOFDProtectSign() : m_reader(NULL),m_maxUnitID(0)
{
    //DLOG("FZZOFDProtectSign()");
    FZZConst::addClassCount("FZZOFDProtectSign");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProtectSign::FZZOFDProtectSign(FZZOFD* reader) : FZZOFDProtectSign()
{
    m_reader = reader;
    
    addNotProtectFileName("/OFDEntries.xml");
    addNotProtectFileName("/signedvalue.dat");
    
    //addNotProtectFileName("/Encryptions.xml");
    //addNotProtectFileName("/decryptseed.dat");
    //addNotProtectFileName("/entriesmap.dat");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDProtectSign::~FZZOFDProtectSign()
{
    //DLOG("~FZZOFDProtectSign()");
    FZZConst::delClassCount("FZZOFDProtectSign");
    m_reader = NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDProtectSign::findNotProtectFileName(string filename)
{
    bool isRet = false;
    vector<string>::const_iterator iter;
    for (iter = m_NotProtectFileName.begin(); iter != m_NotProtectFileName.end(); iter++) {
        string tempFilename = *iter;
        if ( tempFilename == filename ) {
            isRet = true;
            break;
        }
    }
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDProtectSign::exeProtect(CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param)
{
    bool isRet = false;
    if ( m_reader == NULL ) return isRet;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return isRet;
    
    FZZOFDFilesContainer* filesContainer = ofdDir->getFileContainer();
    if ( filesContainer == NULL ) {
        return isRet;
    }
    
    vector<string> FilePathList;
    filesContainer->getFilesName(ofdDir->getRoot(), FilePathList);
    
    if ( FilePathList.size() <= 0 ) return isRet;
    
    
    
    FZZOFDEntriesXML* OFDEntriesXML = ofdDir->setEntriesXML();
    if ( OFDEntriesXML == NULL ) return isRet;
    
    FZZOFDSignedValueLoc * ofdSignedValueLoc = OFDEntriesXML->setSignedValueLoc();
    FZZOFDFileList * fileList = OFDEntriesXML->setFileList();
    
    if ( ofdSignedValueLoc == NULL || fileList == NULL ) return isRet;
    
    m_reader->FlushAll();
    
    OFDEntriesXML->setID(FZZConst::fmt(m_maxUnitID.incrementAndGet()));
    OFDEntriesXML->setCreatorName(OFD_CREATOR);
    OFDEntriesXML->setVersion(OFD_VERSION);
    time_t createDate;
    time(&createDate);
    OFDEntriesXML->setCreationDate(FZZConst::format_time_YYYY_MM_DD(createDate));
    
    ofdSignedValueLoc->setValue("/signedvalue.dat");
    fileList->clearFile();
    
    
    vector<string>::const_iterator iter;
    for (iter = FilePathList.begin(); iter != FilePathList.end(); iter++) {
        string tempFilename = *iter;
        tempFilename = "/"+tempFilename;
        
        if ( findNotProtectFileName(tempFilename) ) {
            continue;
        }
        
        FZZOFDFile * ofdFile = fileList->addFile();
        if ( ofdFile == NULL ) continue;
        
        ofdFile->setID(FZZConst::fmt(m_maxUnitID.incrementAndGet()));
        ofdFile->setFileLoc(tempFilename);
        
    }
    
    ofdDir->FlushEntriesXML();
    
    FZZBytes * tempXmlData = ofdDir->getResFile(FZZOFDENTRIESXML_FILENAME);
  
//    FZZGMCrypto gmCrypto;
//    FZZBytes hashData;
//    gmCrypto.Digest("SM3", *tempXmlData, hashData);
//    if ( hashData.getLen() < 8 ) {
//        return isRet;
//    }
    
    //sign GBT35275 8 签名数据类型 signedData
    FZZBytes singData;
    FZZBytes hashData(*tempXmlData);
    FZZGBT35275DSContainer gbt35275DSContainer(signFunc,getCertFunc,callBack_Param);
    gbt35275DSContainer.sign(hashData, "", singData);
    
    if ( singData.getLen() <= 8 ) {
        return isRet;
    }
    
    ofdDir->FlushResFile("signedvalue.dat", &singData);
    
    isRet = true;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDProtectSign::generateOFD(FZZBytes & outOFDData)
{
    if ( m_reader != NULL ) {
        m_reader->Close(outOFDData);
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDProtectSign::isIntegrity(CallBack_Verify verifyFunc,const void * callBack_Param,vector<string> & outNotHaveFileName)
{
    bool isRet = false;
    
    if ( m_reader == NULL ) return isRet;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return isRet;
    
    FZZOFDEntriesXML* ofdEntriesXML = ofdDir->getEntriesXML();
    if ( ofdEntriesXML == NULL ) {
        return true;
    }
    
    FZZOFDFileList * ofdFileList = ofdEntriesXML->getFileList();
    if ( ofdFileList == NULL ) return isRet;
        
    vector<FZZOFDFile*> * ofdFiles = ofdFileList->getFileList();
    if ( ofdFiles == NULL || ofdFiles->size() <= 0 ) return isRet;
    
    FZZOFDFilesContainer* filesContainer = ofdDir->getFileContainer();
    if ( filesContainer == NULL ) {
        return isRet;
    }
    
    vector<string> FilePathList;
    filesContainer->getFilesName(ofdDir->getRoot(), FilePathList);
    
    if ( FilePathList.size() <= 0 ) return isRet;
    
    
    FZZBytes * tempXmlData = ofdDir->getResFile(FZZOFDENTRIESXML_FILENAME);
    FZZBytes * tempSignData = ofdDir->getResFile("signedvalue.dat");
    
    if ( tempXmlData->getLen() <= 0 || tempSignData->getLen() <= 0 ) {
        return isRet;
    }
    
    FZZBytes srcData(*tempXmlData);
    FZZBytes signData(*tempSignData);
    string certDn;
    FZZGBT35275ValidateContainer verify;
    
    if (verify.validate(FZZOFDSigType::TYPE::TYPE_Sign,"",verifyFunc,callBack_Param,srcData,signData,certDn) != 0 ) {
        return isRet;
    }
    
    vector<string> tempFilePathList;
    vector<string>::const_iterator iter;
    for (iter = FilePathList.begin(); iter != FilePathList.end(); iter++) {
        string tempFilename = *iter;
        tempFilename = "/"+tempFilename;
        
        if ( findNotProtectFileName(tempFilename) ) {
            continue;
        }
        
        tempFilePathList.push_back(tempFilename);
    }
    
    //验证文件个数是否一致，是否有增加或减少
    if ( ofdFiles->size() != tempFilePathList.size() ) {
        return isRet;
    }
    //找丢失的文件
    vector<FZZOFDFile*>::const_iterator ofdfileitr;
    for ( ofdfileitr = ofdFiles->begin(); ofdfileitr != ofdFiles->end(); ofdfileitr++ ) {
        FZZOFDFile* tempOFDFile = *ofdfileitr;
        if ( tempOFDFile == NULL ) {
            continue;
        }
        
        string filename = tempOFDFile->getFileLoc();
        string oldFileName = filename;
        transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
        
        bool isHave = false;
        for (iter = tempFilePathList.begin(); iter != tempFilePathList.end(); iter++) {
            string tempFilename = *iter;
            
            if ( filename == tempFilename ) {
                isHave = true;
                tempFilePathList.erase(iter);
                break;
            }
            
        }
        
        if ( !isHave ) {
            outNotHaveFileName.push_back(oldFileName);
        }
    }
    
    isRet = outNotHaveFileName.size() == 0;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDProtectSign::isProtect()
{
    bool isRet = false;
    
    if ( m_reader == NULL ) return isRet;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return isRet;
    
    FZZOFDEntriesXML* ofdEntriesXML = ofdDir->getEntriesXML();
    isRet = ofdEntriesXML != NULL ;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
