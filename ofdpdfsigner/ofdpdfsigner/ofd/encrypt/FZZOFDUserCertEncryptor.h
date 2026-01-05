//
//  Created by zizheng fan on 2024/10/20.
//
#ifndef FZZOFDUSERCERTENCRYPTOR_H
#define FZZOFDUSERCERTENCRYPTOR_H


#include "ofd/encrypt/FZZOFDUserFEKEncryptor.h"
/*
 证书加密方式的加密器
 */
class FZZOFDUserCertEncryptor : public FZZOFDUserFEKEncryptor
{
public:
    /*
      构造函数
      (in param) cert: 证书
      (in param) userName: 用户名称
      (in param) userType:  文档管理员 ：Owner，用户，默认值：User
     */
    FZZOFDUserCertEncryptor(string cert,string userName, string userType = "User");
    virtual ~FZZOFDUserCertEncryptor();
	
public:
    /*
     设置回调参数
     (in param) encSM2: SM2 加密回调函数
     (in param) callBack_Param: 回调函数上下文参数
     */
    void setCryptCallBack(CallBack_EncryptSM2 encSM2,void * callBack_Param);
    //看基类
    virtual TUserInfo* encrypt(FZZBytes & fek,FZZBytes & iv);
    //看基类
    virtual string encryptCaseId();
    //看基类
    virtual string userCert();
    
protected:
    FZZOFDUserCertEncryptor();
private:
    TUserInfo m_UserInfo;
    

    CallBack_EncryptSM2 m_EncSM2;
    void * m_CallBack_Param;
};

#endif //FZZOFDUSERCERTENCRYPTOR_H


