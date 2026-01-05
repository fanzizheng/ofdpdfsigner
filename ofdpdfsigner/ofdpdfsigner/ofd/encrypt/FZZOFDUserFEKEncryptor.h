//
//  Created by zizheng fan on 2024/10/20.
//
#ifndef FZZOFDUSERFEKENCRYPTOR_H
#define FZZOFDUSERFEKENCRYPTOR_H
/*
 用户信息映射结构体
 */
typedef struct s_UserInfo {
    string userName;
    string userType;
    string userCert;
    string encryptedWK;
    string ivValue;
    vector<map<string,string>> extendParams; //extendParamlist -> parameter -> < name,value >
} TUserInfo;

/*
 加密保护方案标识
 */
class FZZOFDProtectionCaseIDType
{
public:
    typedef enum {
        TYPE_EncryptGMPassword, //密码
        TYPE_EncryptGMCert,     //证书
        TYPE_Signature          //签名
    } TYPE;

    /*
     将 加密保护方案标识 转换 为字符串
     (in param) type: 加密保护方案标识
     (return) 加密保护方案标识对应的字符串
     */
    static string toString(FZZOFDProtectionCaseIDType::TYPE type) {
        string temp = "1.2.1"; //TYPE_Signature
        switch (type) {
        case TYPE_EncryptGMPassword:
            temp = "1.1.1";
            break;
        case TYPE_EncryptGMCert:
            temp = "1.1.2";
            break;
        case TYPE_Signature:
            temp = "1.2.1";
            break;
        }
        return temp;
    }
//
//    static FZZOFDProtectionCaseIDType::TYPE toType(const char * const strtype) {
//        FZZOFDProtectionCaseIDType::TYPE temp = TYPE_Signature;
//        if (strcmp(strtype, "1.2.1") == 0) {
//            temp = TYPE_Signature;
//        } else if (strcmp(strtype, "1.1.1") == 0) {
//            temp = TYPE_EncryptGMPassword;
//        }
//        else if (strcmp(strtype, "1.1.2") == 0) {
//            temp = TYPE_EncryptGMCert;
//        }
//
//        return temp;
//    }

};

class FZZOFDUserFEKEncryptor
{
public:
    virtual ~FZZOFDUserFEKEncryptor() {}

public:
    /*
     加密 文件加密密钥 并封装为 TUserInfo
     (in param) fek: 文件加密密钥（File Encrypt FZZKey ）
     (in param) iv:  加密向量IV
     (return) 用户信息（包含加密的文件加密密钥）
     */
    virtual TUserInfo* encrypt(FZZBytes & fek,FZZBytes & iv) = 0;
    /*
     获取加密保护方案标识
     (return) 返回 加密保护方案标识
     */
    virtual string encryptCaseId() = 0;
    /*
     获取证书
     (return) 返回 证书
     */
    virtual string userCert() = 0;
};

#endif //FZZOFDUSERFEKENCRYPTOR_H
