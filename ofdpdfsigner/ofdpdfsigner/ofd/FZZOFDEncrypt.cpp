//
//  Created by zizheng fan on 2024/10/12.
//
#include "basic/FZZConst.h"
#include "ofd/FZZOFDEncrypt.h"

#include "gm/crypto/FZZGMCrypto.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDEncrypt*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncrypt::FZZOFDEncrypt() : m_reader(NULL),m_maxUnitID(0),m_EncSm4CBC(NULL),m_DecSm4CBC(NULL),m_EncSM2(NULL),m_DecSM2(NULL),m_genRandom(NULL),m_CallBack_Param(NULL)
{
    //DLOG("FZZOFDEncrypt()");
    FZZConst::addClassCount("FZZOFDEncrypt");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncrypt::FZZOFDEncrypt(FZZOFD* reader) : FZZOFDEncrypt()
{
    m_reader = reader;
    addNotEncryptFileName("/OFDEntries.xml");
    addNotEncryptFileName("/signedvalue.dat");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEncrypt::~FZZOFDEncrypt()
{
    //DLOG("~FZZOFDEncrypt()");
    FZZConst::delClassCount("FZZOFDEncrypt");
    m_reader = NULL;
    
    vector<FZZOFDUserCertEncryptor*>::const_iterator cert_itr;
    for( cert_itr = m_UserCertEncryptorList.begin(); cert_itr != m_UserCertEncryptorList.end(); cert_itr++ ) {
        FZZOFDUserCertEncryptor * temp = *cert_itr;
        if ( temp != NULL ) {
            delete temp;
        }
        
    }
    m_UserCertEncryptorList.clear();
    
    vector<FZZOFDUserPasswordEncryptor*>::const_iterator pw_itr;
    for( pw_itr = m_UserPasswordEncryptorList.begin(); pw_itr != m_UserPasswordEncryptorList.end(); pw_itr++ ) {
        FZZOFDUserPasswordEncryptor * temp = *pw_itr;
        if ( temp != NULL ) {
            delete temp;
        }
        
    }
    m_UserPasswordEncryptorList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncrypt::setCryptCallBack(CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,void * callBack_Param)
{
    m_EncSm4CBC = encSm4CBC;
    m_DecSm4CBC = decSm4CBC;
    m_EncSM2 = encSM2;
    m_DecSM2 = decSM2;
    m_genRandom = genRandom;
    m_CallBack_Param = callBack_Param;
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncrypt::getSourceDocFileList(vector<string> & fileList)
{
    if ( m_reader == NULL ) return;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return;
    
    FZZOFDFilesContainer* filesContainer = ofdDir->getFileContainer();
    if ( filesContainer == NULL ) {
        return;
    }
    
    filesContainer->getFilesName(ofdDir->getRoot(), fileList);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncrypt::addNotEncryptFileName(string filename)
{
    transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    if ( filename[0] != '/' ) {
        filename = "/" + filename;
    }
    m_NotEncryptFileName.push_back(filename);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncrypt::addUserPassWordMode(string password,string userName, string userType)
{
    if ( password.empty() || userName.empty() ) {
        return;
    }
    FZZOFDUserPasswordEncryptor * userPasswordEncryptor = new FZZOFDUserPasswordEncryptor(password,userName,userType);
    if ( userPasswordEncryptor != NULL ) {
        m_UserPasswordEncryptorList.push_back(userPasswordEncryptor);
    }
    
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEncrypt::addUserCertMode(string cert,string userName, string userType)
{
    if ( cert.empty() || userName.empty() ) {
        return;
    }
    FZZOFDUserCertEncryptor * userCertEncryptor = new FZZOFDUserCertEncryptor(cert,userName,userType);
    if ( userCertEncryptor != NULL ) {
        m_UserCertEncryptorList.push_back(userCertEncryptor);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEncrypt::findNotEncryptFileName(string filename)
{
    bool isRet = false;
    vector<string>::const_iterator iter;
    for (iter = m_NotEncryptFileName.begin(); iter != m_NotEncryptFileName.end(); iter++) {
        string tempFilename = *iter;
        if ( tempFilename == filename ) {
            isRet = true;
            break;
        }
    }
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEncrypt::Encrypt(int mode,vector<string> &FilePathList,string strID,FZZOFDDir* ofdDir,FZZOFDDir* encryptOFDDir)
{
    FZZGMCrypto crypto;
    FZZBytes keyData;
    FZZBytes keyIVData;
    if ( m_genRandom == NULL ) {
        keyData = crypto.generateRandom(16);
        keyIVData = crypto.generateRandom(16);
    } else {
        size_t bufferLen = 16;
        unsigned char * buffer = (unsigned char *)malloc(bufferLen);
        if ( buffer == NULL ) {
            return false;
        }
        m_genRandom(m_CallBack_Param,(int)bufferLen,&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return false;
        }
        
        keyData.setData(buffer, bufferLen);
        
        bufferLen = 16;
        m_genRandom(m_CallBack_Param,(int)bufferLen,&buffer,&bufferLen);
        if (bufferLen <= 0) {
            free(buffer);
            buffer = NULL;
            return false;
        }
        
        keyIVData.setData(buffer, bufferLen);
        
        free(buffer);
        buffer = NULL;
        
    }
    
    if ( keyData.getLen() != 16 || keyIVData.getLen() != 16 ) {
        return false;
    }
    
    FZZKey fkey;
    fkey.setKeyType(FZZKey::KEYTYPE_SM4);
    fkey.setKeyData(keyData.getData(),(int)keyData.getLen());
    
    bool bRet = false;
    FZZOFDEntriesMapXML entriesMapXML;
    entriesMapXML.setID(strID);
        
    vector<string>::const_iterator iter;
    for (iter = FilePathList.begin(); iter != FilePathList.end(); iter++) {
        string tempFilename = *iter;
        string oldFileName = tempFilename;
        tempFilename = "/"+tempFilename;
        
        if ( findNotEncryptFileName(tempFilename) ) {
            continue;
        }
        
        FZZBytes * filedata = ofdDir->getResFile(oldFileName);
        if ( filedata == NULL || filedata->getLen() <= 0 ) {
            continue;
        }
        
        FZZBytes encFileData;
        if ( m_EncSm4CBC == NULL ) {
            encFileData = crypto.Encrypt_SM4_CBC(fkey, &keyIVData, *filedata);
        } else {
            encFileData = Encrypt_SM4CBC(fkey, keyIVData, filedata);
        }
        if ( encFileData.getLen() <= 0 ) {
            continue;
        }
        
        size_t pos = oldFileName.find_last_of(".");
        string encfilename = oldFileName;
        if ( pos != string::npos ) {
            encfilename = oldFileName.substr(0,pos);
        }
        encfilename += "_";
        encfilename += strID;
        encfilename += ".dat";
        
        encryptOFDDir->setResFile(encfilename, &encFileData);
        
        FZZOFDEncryptEntry* encryptEntry = entriesMapXML.addEncryptEntry();
        if ( encryptEntry != NULL ) {
            encryptEntry->setPath("/"+oldFileName);
            encryptEntry->setEPath("/"+encfilename);
        }
    }
    //-----------------------
    string xmldata = entriesMapXML.getXMLData();
    FZZBytes bxmldata;
    bxmldata.setData((unsigned char *)xmldata.c_str(), xmldata.length());
    
    
    FZZBytes encxmldata;
    if ( m_EncSm4CBC == NULL ) {
        encxmldata = crypto.Encrypt_SM4_CBC(fkey, &keyIVData, bxmldata);
    } else {
        encxmldata = Encrypt_SM4CBC(fkey, keyIVData, &bxmldata);
    }
    if ( encxmldata.getLen() <= 0 ) {
        return bRet;
    }
   
    string filename_entriesmap = "entriesmap_"+strID+".dat";
    encryptOFDDir->FlushResFile(filename_entriesmap, &encxmldata);
    //-------------------
    FZZOFDDecryptSeedXML decryptSeedXML;
    
    decryptSeedXML.setID(strID);
    
    if ( mode == 1 ) {
        decryptSeedXML.setEncryptCaseId(FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMPassword));
    
        vector<FZZOFDUserPasswordEncryptor*>::const_iterator ufeke_itr;
        for (ufeke_itr = m_UserPasswordEncryptorList.begin(); ufeke_itr != m_UserPasswordEncryptorList.end(); ufeke_itr++) {
            FZZOFDUserPasswordEncryptor * UserFEKEncryptor = *ufeke_itr;
            if ( UserFEKEncryptor == NULL ) {
                continue;
            }
            
            UserFEKEncryptor->setCryptCallBack(m_EncSm4CBC, m_DecSm4CBC, m_CallBack_Param);
            TUserInfo * tUserInfo = UserFEKEncryptor->encrypt(keyData, keyIVData);
            if ( tUserInfo == NULL ) {
                continue;
            }
            
            FZZOFDUserInfo* UserInfo = decryptSeedXML.addUserInfo();
            if ( UserInfo == NULL ) {
                continue;
            }
            
            FZZOFDUserInfoItem * ivitem =  UserInfo->setIVValue();
            if ( ivitem != NULL ) {
                ivitem->setValue(tUserInfo->ivValue);
            }
            
            FZZOFDUserInfoItem * ewkitem =  UserInfo->setEncryptedWK();
            if ( ewkitem != NULL ) {
                ewkitem->setValue(tUserInfo->encryptedWK);
            }
            UserInfo->setUserName(tUserInfo->userName);
            UserInfo->setUserType(tUserInfo->userType);
        }
    } else {
        decryptSeedXML.setEncryptCaseId(FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMCert));
        
        vector<FZZOFDUserCertEncryptor*>::const_iterator ufeke_itr;
        for (ufeke_itr = m_UserCertEncryptorList.begin(); ufeke_itr != m_UserCertEncryptorList.end(); ufeke_itr++) {
            FZZOFDUserCertEncryptor * UserFEKEncryptor = *ufeke_itr;
            if ( UserFEKEncryptor == NULL ) {
                continue;
            }
            UserFEKEncryptor->setCryptCallBack(m_EncSM2, m_CallBack_Param);
            TUserInfo * tUserInfo = UserFEKEncryptor->encrypt(keyData, keyIVData);
            if ( tUserInfo == NULL ) {
                continue;
            }
            
            FZZOFDUserInfo* UserInfo = decryptSeedXML.addUserInfo();
            if ( UserInfo == NULL ) {
                continue;
            }
            
            FZZOFDUserInfoItem * certitem = UserInfo->setUserCert();
            if ( certitem != NULL ) {
                certitem->setValue(tUserInfo->userCert);
            }

            FZZOFDUserInfoItem * ivitem =  UserInfo->setIVValue();
            if ( ivitem != NULL ) {
                ivitem->setValue(tUserInfo->ivValue);
            }
            
            FZZOFDUserInfoItem * ewkitem =  UserInfo->setEncryptedWK();
            if ( ewkitem != NULL ) {
                ewkitem->setValue(tUserInfo->encryptedWK);
            }
            UserInfo->setUserName(tUserInfo->userName);
            UserInfo->setUserType(tUserInfo->userType);
        }
    }
    
    xmldata = decryptSeedXML.getXMLData();
    
    bxmldata.setData((unsigned char *)xmldata.c_str(), xmldata.length());
    
    string filename_decryptseed = "decryptseed_"+strID+".dat";
    encryptOFDDir->FlushResFile(filename_decryptseed, &bxmldata);
    //--------------------
    FZZOFDEncryptionsXML* EncryptionsXML= encryptOFDDir->setEncryptionsXML();
    if ( EncryptionsXML == NULL ) {
        return bRet;
    }
    
    FZZOFDEncryptInfo* EncryptInfo = EncryptionsXML->addEncryptInfo();
    if ( EncryptInfo == NULL ) {
        return bRet;
    }
    EncryptInfo->setID(strID);
    FZZOFDProvider * Provider = EncryptInfo->setProvider();
    if ( Provider == NULL ) {
        return bRet;
    }
    Provider->setName(OFD_CREATOR);
    Provider->setCompany(OFD_COMPANY);
    Provider->setVersion(OFD_VERSION);
    
    FZZOFDEncryptScope * EncryptScope = EncryptInfo->setEncryptScope();
    if ( EncryptScope == NULL ) {
        return bRet;
    }
    //ALL 和 PART 是我自己想的，标准中没有定义，待后面看看其他家的文件，这里做修改
    EncryptScope->setValue(m_NotEncryptFileName.size() <= 2 ? "ALL" : "PART" );
    
    FZZOFDEncryptDate * EncryptDate = EncryptInfo->setEncryptDate();
    if ( EncryptDate == NULL ) {
        return bRet;
    }
    time_t createDate;
    time(&createDate);
    EncryptDate->setValue(FZZConst::format_time_YYYY_MM_DD(createDate));
    
    FZZOFDEntriesMapLoc * EntriesMapLoc = EncryptInfo->setEntriesMapLoc();
    if ( EntriesMapLoc == NULL ) {
        return bRet;
    }
    string mapfilename = "/";
    mapfilename += filename_entriesmap;
    EntriesMapLoc->setValue(mapfilename);
    
    FZZOFDDecryptSeedLoc * DecryptSeedLoc = EncryptInfo->setDecryptSeedLoc();
    if ( DecryptSeedLoc == NULL ) {
        return bRet;
    }
    mapfilename = "/";
    mapfilename += filename_decryptseed;
    DecryptSeedLoc->setValue(mapfilename);
    
    encryptOFDDir->FlushEncryptionsXML();
    //--------------------------
    
    
    bRet = true;

    return bRet;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEncrypt::Encrypt(FZZBytes & outOFDData)
{
    bool iRet_pw = false;
    bool iRet_cert = false;
    
    if ( m_reader == NULL ) return false;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return false;
    
    vector<string> FilePathList;
    getSourceDocFileList(FilePathList);
    
    if ( FilePathList.size() <= 0 ) {
        return false;
    }
    
    FZZOFD EncryptOFD;
    FZZOFDDir* encryptOFDDir = EncryptOFD.getOFDDir();
    if ( encryptOFDDir == NULL ) {
        return false;
    }
    
    if ( m_UserPasswordEncryptorList.size() > 0 ) {
        iRet_pw = Encrypt(1,FilePathList,FZZConst::fmt(m_maxUnitID.incrementAndGet()),ofdDir,encryptOFDDir);
    }
    
    if ( m_UserCertEncryptorList.size() > 0 ) {
        iRet_cert = Encrypt(2,FilePathList,FZZConst::fmt(m_maxUnitID.incrementAndGet()),ofdDir,encryptOFDDir);
    }
    
    bool bRet = iRet_pw || iRet_cert;
    if ( bRet ) {
//        vector<string>::const_iterator iter;
//        for (iter = FilePathList.begin(); iter != FilePathList.end(); iter++) {
//            string tempFilename = *iter;
//            string oldFileName = tempFilename;
//            tempFilename = "/"+tempFilename;
//
//            if ( findNotEncryptFileName(tempFilename) ) {
//                continue;
//            }
//
//            ofdDir->deleteResFile(oldFileName);
//        }
//
//        m_reader->Close(outOFDData);
        FZZOFDEntriesXML * EntriesXML = NULL;
        if ( (EntriesXML = m_reader->getEntriesXML()) != NULL ) {
            FZZOFDSignedValueLoc * SignedValueLoc = EntriesXML->getSignedValueLoc();
            if ( SignedValueLoc != NULL ) {
                string filename = SignedValueLoc->getValue();
                if ( !filename.empty() ) {
                
                    if ( filename[0] == '/' ) {
                        filename = filename.substr(1);
                    }
                    
                    FZZBytes * filedata = ofdDir->getResFile(filename);
                    if ( filedata != NULL && filedata->getLen() > 0 ) {
                        encryptOFDDir->setResFile(filename, filedata);
                    }
                }
            }
            FZZBytes * xmlfiledata = ofdDir->getResFile(FZZOFDENTRIESXML_FILENAME);
            
            if ( xmlfiledata != NULL && xmlfiledata->getLen() > 0 ) {
                encryptOFDDir->setResFile(FZZOFDENTRIESXML_FILENAME, xmlfiledata);
            }
        }
    
        EncryptOFD.Close(outOFDData);
        
    }
    
    return bRet;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEncrypt::Decrypt(int Mode,string priKeyOrPassword,string userName, string userType,FZZBytes & outOFDData)
{
    if ( m_reader == NULL ) return false;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return false;
    
    FZZOFD DecryptOFD;
    FZZOFDDir* decryptOFDDir = DecryptOFD.getOFDDir();
    if ( decryptOFDDir == NULL ) {
        return false;
    }
    
    FZZOFDEncryptionsXML* EncryptionsXML = ofdDir->getEncryptionsXML();
    if ( EncryptionsXML == NULL )  return false;
    
    vector<FZZOFDEncryptInfo*>* encInfoList = EncryptionsXML->getEncryptInfoList();
    if ( encInfoList == NULL || encInfoList->size() <= 0 ) return false;
    
    
    
    FZZGMCrypto crypto;
    bool iRet = false;
    vector<FZZOFDEncryptInfo*>::const_iterator encInfo_Itr;
    for (encInfo_Itr = encInfoList->begin(); encInfo_Itr != encInfoList->end(); encInfo_Itr++) {
        FZZOFDEncryptInfo * EncryptInfo = *encInfo_Itr;
        if ( EncryptInfo == NULL ) {
            continue;
        }
        //---------------------
        FZZOFDDecryptSeedLoc * DecryptSeedLoc = EncryptInfo->getDecryptSeedLoc();
        if ( DecryptSeedLoc == NULL ) continue;
        
        string decSeedFileName = DecryptSeedLoc->getValue();
        if ( decSeedFileName.empty() ) continue;
        
        if ( decSeedFileName[0] == '/' ) {
            decSeedFileName = decSeedFileName.substr(1);
        }
        
        FZZBytes * filedata = ofdDir->getResFile(decSeedFileName);
        if ( filedata == NULL || filedata->getLen() <= 0 ) continue;
        
        XMLDocument * doc = new XMLDocument();
        if ( doc == NULL ) {
            continue;
        }
        doc->Parse((char *)filedata->getData(),filedata->getLen());
        if (doc->Error()) {
            delete doc;
            doc = NULL;
            continue;
        }
        // FZZOFDDecryptSeedXML 管理 doc 的释放
        FZZOFDDecryptSeedXML DecryptSeedXML(doc);
        //密码
        if ( Mode == 1 && DecryptSeedXML.getEncryptCaseId() != FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMPassword) )  {
            continue;
        }
        //证书
        if ( Mode == 2 && DecryptSeedXML.getEncryptCaseId() != FZZOFDProtectionCaseIDType::toString(FZZOFDProtectionCaseIDType::TYPE::TYPE_EncryptGMCert) ) {
            continue;
        }
        
        if ( Mode == 2 && m_DecSM2 == NULL && priKeyOrPassword.length() == 0 ) {
            continue;
        }
        
        vector<FZZOFDUserInfo*>* UserInfoList = DecryptSeedXML.getUserInfoList();
        if ( UserInfoList == NULL || UserInfoList->size() <= 0 ) continue;
        
        vector<FZZOFDUserInfo*>::const_iterator userInfo_Itr;
        for (userInfo_Itr = UserInfoList->begin(); userInfo_Itr != UserInfoList->end(); userInfo_Itr++) {
            FZZOFDUserInfo * UserInfo = *userInfo_Itr;
            if ( UserInfo == NULL ) {
                continue;
            }
            
            if ( !(UserInfo->getUserName() == userName && UserInfo->getUserType() == userType) ) {
                continue;
            }
            //iv
            FZZOFDUserInfoItem * ivItem = UserInfo->getIVValue();
            if ( ivItem == NULL ) continue;
            string strIV = ivItem->getValue();
            if ( strIV.empty() ) {
                continue;
            }
            FZZBytes ivData;
            FZZConst::Base64_decode(strIV.c_str(), strIV.length(), ivData);
            if ( ivData.getLen() <= 0 ) {
                continue;
            }
            //ewk
            FZZOFDUserInfoItem * ewkItem = UserInfo->getEncryptedWK();
            if ( ewkItem == NULL ) continue;
            string strEWK = ewkItem->getValue();
            if ( strEWK.empty() ) {
                continue;
            }
            FZZBytes EWKData;
            FZZConst::Base64_decode(strEWK.c_str(), strEWK.length(), EWKData);
            if ( EWKData.getLen() <= 0 ) {
                continue;
            }
            
            FZZBytes WK;
            if ( Mode == 1 ) {
                FZZOFDUserPasswordEncryptor UserPasswordEncryptor(priKeyOrPassword,userName,userType);
                UserPasswordEncryptor.setCryptCallBack(m_EncSm4CBC, m_DecSm4CBC, m_CallBack_Param);
                WK = UserPasswordEncryptor.decrypt(EWKData, ivData);
            } else {
                
                
                if ( m_DecSM2 == NULL ) {
                    FZZBytes SM2PriKeyData;
                    FZZConst::Base64_decode(priKeyOrPassword.c_str(), priKeyOrPassword.length(), SM2PriKeyData);
                    if ( SM2PriKeyData.getLen() <= 0 ) {
                        continue;
                    }
                    
                    FZZKey privateKey;
                    privateKey.setKeyID("");
                    privateKey.setKeyType(FZZKey::KEYTYPE_SM2_PRI_KEY);
                    privateKey.setKeyData(SM2PriKeyData.getData(), (int)SM2PriKeyData.getLen());
                    
                    FZZBytes sm4GCM_Mac;
                    WK = crypto.Decrypt(privateKey, "", EWKData, sm4GCM_Mac);
                } else {
                    size_t sm2DecBufferLen = 0;
                    m_DecSM2(m_CallBack_Param,EWKData.getData(),(int)EWKData.getLen(),NULL, &sm2DecBufferLen);
                    
                    if ( sm2DecBufferLen <= 0 ) {
                        continue;
                    }
                    unsigned char * sm2Decbuffer = (unsigned char *)malloc(sm2DecBufferLen);
                    if ( sm2Decbuffer == NULL ) {
                        continue;
                    }
                    m_DecSM2(m_CallBack_Param,EWKData.getData(),(int)EWKData.getLen(),&sm2Decbuffer, &sm2DecBufferLen);
                    if (sm2DecBufferLen <= 0) {
                        free(sm2Decbuffer);
                        sm2Decbuffer = NULL;
                        continue;
                    }
                    
                    WK.setData(sm2Decbuffer, sm2DecBufferLen);
                    
                    free(sm2Decbuffer);
                    sm2Decbuffer = NULL;
                }
            }
            
            if ( WK.getLen() <= 0 ) {
                continue;
            }
            
            FZZKey fkey;
            fkey.setKeyType(FZZKey::KEYTYPE_SM4);
            fkey.setKeyData(WK.getData(),(int)WK.getLen());
            
            //------------------------
            FZZOFDEntriesMapLoc * EntriesMapLoc = EncryptInfo->getEntriesMapLoc();
            if ( EntriesMapLoc == NULL ) continue;
            
            string EntriesMapFileName = EntriesMapLoc->getValue();
            if ( EntriesMapFileName.empty() ) continue;
            
            if ( EntriesMapFileName[0] == '/' ) {
                EntriesMapFileName = EntriesMapFileName.substr(1);
            }
            
            filedata = ofdDir->getResFile(EntriesMapFileName);
            if ( filedata == NULL || filedata->getLen() <= 0 ) continue;
            
            FZZBytes decFileData;
            if ( m_DecSm4CBC == NULL ) {
                decFileData = crypto.Decrypt_SM4_CBC(fkey, &ivData, *filedata);
            } else {
                decFileData = Decrypt_SM4CBC(fkey, ivData, filedata);
            }
            if ( decFileData.getLen() <= 0 ) continue;
            
            doc = new XMLDocument();
            if ( doc == NULL ) {
                continue;
            }
            doc->Parse((char *)decFileData.getData(),decFileData.getLen());
            if (doc->Error()) {
                delete doc;
                doc = NULL;
                continue;
            }
            // FZZOFDEntriesMapXML 管理 doc 的释放
            FZZOFDEntriesMapXML EntriesMapXML(doc);
            
            
            
            vector<FZZOFDEncryptEntry*>* EncryptEntryList = EntriesMapXML.getEncryptEntryList();
            if ( EncryptEntryList == NULL || EncryptEntryList->size() <= 0 ) continue;
            
            vector<FZZOFDEncryptEntry*>::const_iterator EncEntry_Itr;
            for (EncEntry_Itr = EncryptEntryList->begin(); EncEntry_Itr != EncryptEntryList->end(); EncEntry_Itr++) {
                FZZOFDEncryptEntry * EncryptEntry = *EncEntry_Itr;
                if ( EncryptEntry == NULL ) {
                    continue;
                }
                FZZKey useKey = fkey;
                FZZBytes useIV = ivData;
                string strSourceFileName = EncryptEntry->getPath();
                string EncFileName = EncryptEntry->getEPath();
                
                string decryptSeedloc = EncryptEntry->getDecryptSeedLoc();
                if ( !decryptSeedloc.empty() ) {
                    //使用该 FZZOFDDecryptSeedXML 中的 sm4 密钥
                    //useKey = ？？？
                    //useIV = ？？？
                    DLOG("暂不支持此解密方式！");
                }
                
                if ( strSourceFileName[0] == '/' ) {
                    strSourceFileName = strSourceFileName.substr(1);
                }
                
                if ( EncFileName[0] == '/' ) {
                    EncFileName = EncFileName.substr(1);
                }
                
                FZZBytes *xmlEncData = ofdDir->getResFile(EncFileName);
                
                FZZBytes xmlDecData;
                if ( m_DecSm4CBC == NULL ) {
                    xmlDecData = crypto.Decrypt_SM4_CBC(useKey, &useIV, *xmlEncData);
                } else {
                    xmlDecData = Decrypt_SM4CBC(useKey, useIV, xmlEncData);
                }
                
                if ( xmlDecData.getLen() <= 0 ) {
                    continue;
                }
                
                decryptOFDDir->setResFile(strSourceFileName,&xmlDecData);
                
            }// for EncryptEntryList
            //------------------------
            
            iRet = true;
            break;
        }//for UserInfoList
        
        
        
        
    }//for encInfoList

    if ( iRet ) {
        FZZOFDEntriesXML * EntriesXML = NULL;
        if ( (EntriesXML = m_reader->getEntriesXML()) != NULL ) {
            FZZOFDSignedValueLoc * SignedValueLoc = EntriesXML->getSignedValueLoc();
            if ( SignedValueLoc != NULL ) {
                string filename = SignedValueLoc->getValue();
                if ( !filename.empty() ) {
                
                    if ( filename[0] == '/' ) {
                        filename = filename.substr(1);
                    }
                    
                    FZZBytes * filedata = ofdDir->getResFile(filename);
                    if ( filedata != NULL && filedata->getLen() > 0 ) {
                        decryptOFDDir->setResFile(filename, filedata);
                    }
                }
            }
            FZZBytes * xmlfiledata = ofdDir->getResFile(FZZOFDENTRIESXML_FILENAME);
            
            if ( xmlfiledata != NULL && xmlfiledata->getLen() > 0 ) {
                decryptOFDDir->setResFile(FZZOFDENTRIESXML_FILENAME, xmlfiledata);
            }
        }
        DecryptOFD.Close(outOFDData);
    }
    return iRet;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDEncrypt::isEncrypt()
{
    if ( m_reader == NULL ) return false;
    
    FZZOFDDir* ofdDir = m_reader->getOFDDir();
    if ( ofdDir == NULL ) return false;
    
    FZZOFDEncryptionsXML* EncryptionsXML = ofdDir->getEncryptionsXML();
    if ( EncryptionsXML == NULL )  return false;
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDEncrypt::Encrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata)
{
    FZZBytes encFileData;
    if ( m_EncSm4CBC != NULL ) {
        size_t encBufferLen = 0;
        m_EncSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),NULL, &encBufferLen);
        
        if ( encBufferLen <= 0 ) {
            return encFileData;
        }
        unsigned char * encbuffer = (unsigned char *)malloc(encBufferLen);
        if ( encbuffer == NULL ) {
            return encFileData;
        }
        m_EncSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),&encbuffer, &encBufferLen);
        if (encBufferLen <= 0) {
            free(encbuffer);
            encbuffer = NULL;
            return encFileData;
        }
        
        encFileData.setData(encbuffer, encBufferLen);
        
        free(encbuffer);
        encbuffer = NULL;
    }
    return encFileData;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDEncrypt::Decrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata)
{
    FZZBytes decFileData;
    if ( m_DecSm4CBC != NULL ) {
        size_t decBufferLen = 0;
        m_DecSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),NULL, &decBufferLen);
        
        if ( decBufferLen <= 0 ) {
            return decFileData;
        }
        unsigned char * decbuffer = (unsigned char *)malloc(decBufferLen);
        if ( decbuffer == NULL ) {
            return decFileData;
        }
        m_DecSm4CBC(m_CallBack_Param,fkey.getKeyData(),(int)fkey.getKeyDataLen(),keyIVData.getData(),(int)keyIVData.getLen(),filedata->getData(),(int)filedata->getLen(),&decbuffer, &decBufferLen);
        if (decBufferLen <= 0) {
            free(decbuffer);
            decbuffer = NULL;
            return decFileData;
        }
        
        decFileData.setData(decbuffer, decBufferLen);
        
        free(decbuffer);
        decbuffer = NULL;
    }
    return decFileData;
}
//-----------------------------------------------------------------------------------------------------------------
