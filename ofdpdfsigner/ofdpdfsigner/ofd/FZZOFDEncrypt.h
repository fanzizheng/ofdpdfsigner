//
//  Created by zizheng fan on 2024/10/12.
//
#ifndef FZZOFDENCRYPT_H
#define FZZOFDENCRYPT_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"
#include "ofd/encrypt/FZZOFDUserCertEncryptor.h"
#include "ofd/encrypt/FZZOFDUserPasswordEncryptor.h"

/*
 OFD文档加密和解密
 执行标准 GM/T 0099-2020
 */
class FZZOFDEncrypt
{
public:
    FZZOFDEncrypt(FZZOFD* reader);
	~FZZOFDEncrypt();
	
public:
    /*
      设置回调函数
      (in param) encSm4CBC: sm4 cbc 加密回调函数
      (in param) decSm4CBC: sm4 cbc 解密回调函数
      (in param) encSM2: sm2 加密回调函数
      (in param) decSM2: sm2 解密回调函数
      (in param) genRandom: 产生随机数回调函数
      (in param) callBack_Param: 回调函数上下文参数
     */
    void setCryptCallBack(CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,void * callBack_Param);
    /*
      获取原始 OFD 文件中的文件列表，如ofd为加密文件，返回加密文件的列表。如ofd为明文文件，返回明文文件的列表
      (out param) fileList: 返回ofd 文件列表
     */
    void getSourceDocFileList(vector<string> & fileList);
    //--------------------------------
    /*
      加密时不能被加密的文件，以明文形式存在的文件，用该函数添加
      (in param) fileName: 不加密的文件，第一个字符必须是 '/'
     */
    void addNotEncryptFileName(string filename);
    /*
      添加加密用户加密器-密码模式
      (in param) password: 用户密码
      (in param) userName: 用户名称
      (in param) userType:  文档管理员 ：Owner，用户，默认值：User
     */
    void addUserPassWordMode(string password,string userName, string userType = "User");
    /*
      添加加密用户加密器-证书模式
      (in param) cert: 用户证书
      (in param) userName: 用户名称
      (in param) userType:  文档管理员 ：Owner，用户，默认值：User
     */
    void addUserCertMode(string cert,string userName, string userType = "User");
 
    /*
      文档加密
      (out param) outOFDData: 加密后的ofd文档
     */
    bool Encrypt(FZZBytes & outOFDData);
    //------------------------------------
    /*
      文档解密
     (in param) Mode: 解密模式：1: 密码 2: 证书
     (in param) priKeyOrPassword: 用户密码 或 用户SM2私钥(如果设置回调函数，这个参数为“”)
     (in param) userName: 用户名称
     (in param) userType:  文档管理员 ：Owner；用户：User
      (out param) outOFDData: 解密后的ofd文档
     (return) 加密是否成功
     */
    bool Decrypt(int Mode,string priKeyOrPassword,string userName, string userType,FZZBytes & outOFDData);
    
    /*
      判断文档是否加密
      (return) false: 未加密； true: 加密；
     */
    bool isEncrypt();
protected:
    bool findNotEncryptFileName(string filename);
    //1: 密码 2: 证书
    bool Encrypt(int mode,vector<string> &FilePathList,string strID,FZZOFDDir* ofdDir,FZZOFDDir* encryptOFDDir);
   
    FZZBytes Encrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata);
    FZZBytes Decrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata);
private:
    FZZOFDEncrypt();
private:
    FZZOFD* m_reader;
    FZZAtomicInteger m_maxUnitID;
    vector<string> m_NotEncryptFileName;
    vector<FZZOFDUserCertEncryptor*> m_UserCertEncryptorList;
    vector<FZZOFDUserPasswordEncryptor*> m_UserPasswordEncryptorList;
    
    CallBack_EncryptSM4CBC m_EncSm4CBC;
    CallBack_DecryptSM4CBC m_DecSm4CBC;
    CallBack_EncryptSM2 m_EncSM2;
    CallBack_DecryptSM2 m_DecSM2;
    CallBack_GenerateRandom m_genRandom;
    void * m_CallBack_Param;
};

#endif //FZZOFDENCRYPT_H


