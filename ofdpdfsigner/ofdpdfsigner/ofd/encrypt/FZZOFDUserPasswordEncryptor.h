//
//  Created by zizheng fan on 2024/10/20.
//
#ifndef FZZOFDUSERPASSWORDENCRYPTOR_H
#define FZZOFDUSERPASSWORDENCRYPTOR_H


#include "ofd/encrypt/FZZOFDUserFEKEncryptor.h"
#include "gm/crypto/FZZKey.h"
/*
 密码加密方式的加密器
 */
class FZZOFDUserPasswordEncryptor : public FZZOFDUserFEKEncryptor
{
public:
    /*
     构造函数
     (in param) password: 密码
     (in param) userName: 用户名称
     (in param) userType:  文档管理员 ：Owner，用户，默认值：User
     */
    FZZOFDUserPasswordEncryptor(string password,string userName, string userType = "User");
    virtual ~FZZOFDUserPasswordEncryptor();
	
public:
    /*
     设置回调参数
     (in param) encSm4CBC: SM4 CBC 模式 加密回调函数
     (in param) decSm4CBC: SM4 CBC 模式 解密回调函数
     (in param) callBack_Param: 回调函数上下文参数
     */
    void setCryptCallBack(CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,void * callBack_Param);
    //看基类
    virtual TUserInfo* encrypt(FZZBytes & fek,FZZBytes & iv);
    //看基类
    virtual string encryptCaseId();
    //看基类
    virtual string userCert();
    /*
     解密 文件加密密钥 并返回 SM4 密钥
     (in param) ewk: 文件加密密钥密文
     (in param) iv:  加密向量IV
     (return) SM4 密钥明文
     */
    FZZBytes decrypt(FZZBytes & ewk,FZZBytes & iv);
private:
    void genKey(string password,int klen);
    
    FZZBytes Encrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata);
    FZZBytes Decrypt_SM4CBC(FZZKey & fkey, FZZBytes & keyIVData, FZZBytes * filedata);
protected:
    FZZOFDUserPasswordEncryptor();
private:
    FZZBytes m_fKek;
    TUserInfo m_UserInfo;
    
    CallBack_EncryptSM4CBC m_EncSm4CBC;
    CallBack_DecryptSM4CBC m_DecSm4CBC;
    void * m_CallBack_Param;
};

#endif //FZZOFDUSERPASSWORDENCRYPTOR_H


