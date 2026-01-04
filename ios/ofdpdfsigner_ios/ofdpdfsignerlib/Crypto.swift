//
//  Crypto.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/31.
//

import Foundation

//----------------------------------------------------------------------------------------
public typealias Type_CallBack_Sign = @convention(c) (UnsafeRawPointer?, UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_getUserCert = @convention(c) (UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_getSealCert = @convention(c) (UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_Verify = @convention(c) (UnsafeRawPointer?,Int32, UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32) -> Bool

public typealias Type_CallBack_EncryptSM4CBC = @convention(c) (UnsafeRawPointer?, UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_DecryptSM4CBC = @convention(c) (UnsafeRawPointer?, UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_EncryptSM2 = @convention(c) (UnsafeRawPointer?, UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_DecryptSM2 = @convention(c) (UnsafeRawPointer?, UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void
public typealias Type_CallBack_GenerateRandom = @convention(c) (UnsafeRawPointer?, size_t,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Void

//----------------------------------------------------------------------------------------
typealias Type_GenerateRandom = @convention(c) (Int32, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_GenerateRandom: Type_GenerateRandom? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateRandom"), to: Type_GenerateRandom.self)

typealias Type_Digest = @convention(c) (UnsafeRawPointer?, Int32, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Digest: Type_Digest? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateDigest"), to: Type_Digest.self)

typealias Type_GenerateKey = @convention(c) (UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_GenerateKey: Type_GenerateKey? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateSymKey"), to: Type_GenerateKey.self)

typealias Type_GenerateKeyPair = @convention(c) (UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_GenerateKeyPair: Type_GenerateKeyPair? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateAsymKey"), to: Type_GenerateKeyPair.self)

typealias Type_Encrypt = @convention(c) (Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Encrypt: Type_Encrypt? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "encipher"), to: Type_Encrypt.self)

typealias Type_Decrypt = @convention(c) (Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Decrypt: Type_Decrypt? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "decipher"), to: Type_Decrypt.self)

typealias Type_Sign = @convention(c) (Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Sign: Type_Sign? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "sign"), to: Type_Sign.self)

typealias Type_VerifySign = @convention(c) (Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32) -> Bool
private var Function_VerifySign: Type_VerifySign? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "verify"), to: Type_VerifySign.self)

typealias Type_GenerateRootCert = @convention(c) (Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_GenerateRootCert: Type_GenerateRootCert? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateRootCert"), to: Type_GenerateRootCert.self)

typealias Type_GenerateCert = @convention(c) (Int32,Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_GenerateCert: Type_GenerateCert? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "generateCert"), to: Type_GenerateCert.self)

typealias Type_Encrypt_SM4_CBC = @convention(c) (UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Encrypt_SM4_CBC: Type_Encrypt_SM4_CBC? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "encryptSM4CBC"), to: Type_Encrypt_SM4_CBC.self)

typealias Type_Decrypt_SM4_CBC = @convention(c) (UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeRawPointer?, Int32,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_Decrypt_SM4_CBC: Type_Decrypt_SM4_CBC? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "decryptSM4CBC"), to: Type_Decrypt_SM4_CBC.self)

//----------------------------------------------------------------------------------------
public class Crypto {
    public static let SM3 : String = "SM3"
    public static let SM2 : String = "SM2"
    public static let SM4 : String = "SM4"

    public static let SM2_ENC : String = "SM2_ENC"
    public static let SM4_CBC : String = "SM4_CBC"
    public static let SM4_GCM : String = "SM4_GCM"
    public static let SM4_CTR : String = "SM4_CTR"

    public static let SM3_SM2 : String = "SM3withSM2Encryption"

    private static let TYPE_SM2 : Int32 = 0
    private static let TYPE_SM3 : Int32 = 1
    private static let TYPE_SM4 : Int32 = 2
    
    /*
     产生随机数
     length：产生随机数的位数
     返回：随机数
     */
    public static func generateRandom(length: Int32) -> [UInt8]? {
  
        var retBytes : [UInt8]? = nil;
        
        if let function = Function_GenerateRandom {
            //print("generateRandom")
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(length, &dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        
        return retBytes;
    }
    
    /*
     计算文摘
     algType：SM3
     sourceData：原文
     返回：文摘数据
     */
    public static func generateDigest(algType: String, sourceData: [UInt8]?) -> [UInt8]? {
        var retBytes : [UInt8]? = nil;
        if algType != SM3 {
            return retBytes;
        }
        
        if sourceData == nil || sourceData!.count == 0 {
            return retBytes;
        }
        
        if let function = Function_Digest {
            
            let inDataPointer = sourceData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sourceData!.count)
            
            var outDataPtr: UnsafeMutablePointer<UInt8>? = nil
            var outDatalen: size_t = 0
            
            //print("generateDigest")
            let result = function(inDataPointer,inDatalen, &outDataPtr, &outDatalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: outDataPtr, datalen: outDatalen)
            }

            if let pOutDataPtr = outDataPtr {
                Utils.freeHandle(handlePtr: pOutDataPtr)
            }
        }
        
        return retBytes;
    }
    
    /*
     产生对称密钥
     algType：SM4
     length：保留，为以后产生其他密钥使用
     返回：对称密钥
     */
    public static func generateSymKey(algType: String,length: Int32) -> Key? {
  
        let ret : Key = Key()
        
        if algType != SM4 {
            return ret;
        }
        
        if let function = Function_GenerateKey {
            //print("generateSymKey")
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(&dataPtr, &datalen)
            
            if result {
                let retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                ret.setKeyType(Key.SM4)
                ret.setKey(Utils.convertToData(fromBytes: retBytes));
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        
        return ret;
    }
    
    /*
     产生对称密钥
     algType：SM4
     length：保留，为以后产生其他密钥使用
     返回：对称密钥
     */
    public static func generateAsymKey(algType: String,length: Int32) -> KeyPair? {
  
        let ret : KeyPair = KeyPair()
        
        if algType != SM2 {
            return ret;
        }
        
        if let function = Function_GenerateKeyPair {
            //print("generateAsymKey")
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            var dataPtr2: UnsafeMutablePointer<UInt8>? = nil
            var datalen2: size_t = 0
            
            let result = function(&dataPtr, &datalen,&dataPtr2, &datalen2)
            
            if result {
                let publicKeyBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                
                let publicKey : Key = Key()
                publicKey.setKeyType(Key.SM2_PUB_KEY)
                publicKey.setKey(Utils.convertToData(fromBytes: publicKeyBytes));
                
                let privateKeyBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr2, datalen: datalen2)
                
                let privateKey : Key = Key()
                privateKey.setKeyType(Key.SM2_PRV_KEY)
                privateKey.setKey(Utils.convertToData(fromBytes: privateKeyBytes));
                
                ret.setPublicKey(publicKey)
                ret.setPrivateKey(privateKey)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            if let pdataPtr2 = dataPtr2 {
                Utils.freeHandle(handlePtr: pdataPtr2)
            }
        }
        
        return ret;
    }
    
    /*
     加密数据
     algType：SM4_CBC，SM4_GCM,SM4_CTR,SM2_ENC
     enKey：密钥
     sourceData：明文数据，当为SM2_ENC时大小小于255
     返回：加密数据，当为SM4_GCM，数组的第二个元素为mac数据
     */
    public static func encrypt(algType : String,encryptKey : Key, sourceData: [UInt8]?) ->EncryptData? {
        let retEncryptData : EncryptData = EncryptData()
        
        if sourceData == nil || sourceData!.count == 0 {
            return retEncryptData;
        }
        
        if let keyData = encryptKey.getKey(), keyData.count == 0 {
            return retEncryptData;
        }
        
        var intKeyType : Int32 = 0;
        var intAlgType : Int32 = 0;
    
        if encryptKey.getKeyType() == Key.SM4 {
            intKeyType = 0;
        } else if  encryptKey.getKeyType() == Key.SM2_PUB_KEY {
            intKeyType = 1;
        } else {
            return retEncryptData;
        }

        if algType == SM4_CBC {
            intAlgType = 1;
        } else if algType == SM4_GCM {
            intAlgType = 2;
        } else if algType == SM4_CTR {
            intAlgType = 3;
        } else if algType == SM2_ENC {
            intAlgType = 0;
        } else {
            return retEncryptData;
        }
        
        if let function = Function_Encrypt {
            //print("encrypt")
            
            let inDataPointer = sourceData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sourceData!.count)
            
            let keyDataArray = Utils.dataToUInt8Array(data : encryptKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            var dataPtr2: UnsafeMutablePointer<UInt8>? = nil
            var datalen2: size_t = 0
            
            let result = function(intKeyType,inKeyDataPointer,inKeyDatalen,intAlgType,inDataPointer,inDatalen,&dataPtr, &datalen,&dataPtr2, &datalen2)
            
            if result {
                let encBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                retEncryptData.setEncryptData(Utils.convertToData(fromBytes: encBytes));
                
                let macBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr2, datalen: datalen2)
                retEncryptData.setMacData(Utils.convertToData(fromBytes: macBytes));
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            if let pdataPtr2 = dataPtr2 {
                Utils.freeHandle(handlePtr: pdataPtr2)
            }
        }
        
        return retEncryptData
    }
    
    /*
     解密数据
     algType：SM4_CBC，SM4_GCM,SM4_CTR,SM2_ENC
     deKey：密钥
     encryptedData：加密数据,当为SM2_ENC时大小小于364
     sm4GCMData：当为SM4_GCM，为mac数据，其他为null
     返回：解密数据
     */
    public static func decrypt( algType : String,decryptKey : Key, encryptData: EncryptData) ->[UInt8]? {
        var retBytes : [UInt8]? = nil;
        
        if let keyData = decryptKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if let encData = encryptData.getEncryptData(), encData.count == 0 {
            return retBytes;
        }
        
        var intKeyType : Int32 = 0;
        var intAlgType : Int32 = 0;
        
        if decryptKey.getKeyType() == Key.SM4 {
            intKeyType = 0;
        } else if  decryptKey.getKeyType() == Key.SM2_PRV_KEY {
            intKeyType = 2;
        } else {
            return retBytes;
        }
    
        if algType == SM4_CBC {
            intAlgType = 1;
        } else if algType == SM4_GCM {
            intAlgType = 2;
        } else if algType == SM4_CTR {
            intAlgType = 3;
        } else if algType == SM2_ENC {
            intAlgType = 0;
        } else {
            return retBytes;
        }
        
        if let function = Function_Decrypt {
            //print("decrypt")
            
            let keyDataArray = Utils.dataToUInt8Array(data : decryptKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            let encDataArray = Utils.dataToUInt8Array(data : encryptData.getEncryptData()!)
            let inEncDataPointer = encDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inEncDatalen = Int32(encDataArray.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
          
            var inMacDataPointer : UnsafeRawPointer? = nil //UnsafeRawPointer(bitPattern: 0)
            var inMacDatalen : Int32 = 0
            if let macData = encryptData.getMacData(), macData.count > 0 {
                let macDataArray = Utils.dataToUInt8Array(data : encryptData.getMacData()!)
                inMacDataPointer = macDataArray.withUnsafeBytes({ $0 }).baseAddress
                inMacDatalen = Int32(macDataArray.count)
            }
            
            
            
            let result = function(intKeyType,inKeyDataPointer,inKeyDatalen,intAlgType,inEncDataPointer,inEncDatalen,inMacDataPointer,inMacDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        return retBytes;
    }
    
    /*
     签名
     algType：SM2
     prvKey：私钥
     sourceData：原文数据
     返回：签名数据
     */
    public static func sign(algType : String, privateKey : Key, sourceData: [UInt8]?) ->[UInt8]? {
        var retBytes : [UInt8]? = nil;
        
        if let keyData = privateKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if sourceData == nil || sourceData!.count == 0 {
            return retBytes;
        }
        
        var intAlgType : Int32 = 0;
        if algType == SM3_SM2  {
            if privateKey.getKeyType() != Key.SM2_PRV_KEY  {
                return retBytes;
            }
            intAlgType = 0;
        } else {
            return retBytes;
        }
        
        if let function = Function_Sign {
            //print("sign")
            
            let keyDataArray = Utils.dataToUInt8Array(data : privateKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            let inDataPointer = sourceData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sourceData!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(2,inKeyDataPointer,inKeyDatalen,intAlgType,inDataPointer,inDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        
        return retBytes;
    }
    /*
     验签
     algType：SM2
     pubKey：公钥
     sourceData：原文数据
     signData：签名数据
     返回：验证是否通过
     */
    public static func verify(algType : String, publicKey : Key, sourceData: [UInt8]?, signData: [UInt8]? ) -> Bool {
        var ret = false
        
        if let keyData = publicKey.getKey(), keyData.count == 0 {
            return ret;
        }
        
        if sourceData == nil || sourceData!.count == 0 {
            return ret;
        }
        
        if signData == nil || signData!.count == 0 {
            return ret;
        }
        
        var intAlgType : Int32 = 0;
        if algType == SM3_SM2  {
            if publicKey.getKeyType() != Key.SM2_PUB_KEY  {
                return ret;
            }
            intAlgType = 0;
        } else {
            return ret;
        }
        
        
        if let function = Function_VerifySign {
            //print("verify")
            
            let keyDataArray = Utils.dataToUInt8Array(data : publicKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            let inDataPointer = sourceData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sourceData!.count)
            
            let inSignPointer = signData!.withUnsafeBytes({ $0 }).baseAddress
            let inSignlen = Int32(signData!.count)
            
            ret = function(1,inKeyDataPointer,inKeyDatalen,intAlgType,inDataPointer,inDatalen,inSignPointer,inSignlen)
            
        }

        return ret;
    }
    
    /*
     产生根证书
     DN：证书DN
     pubKey：公钥
     days：有效期
     rootPriKey：根证书私钥
     返回：根证书数据
     */
    public static func generateRootCert(certDN : String, publicKey : Key, validDays : Int32, rootPrivateKey : Key) ->[UInt8]? {
    
        var retBytes : [UInt8]? = nil;
        //var intAlgType : Int32 = 0;

        if let keyData = publicKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if let keyData = rootPrivateKey.getKey(), keyData.count == 0 {
            return retBytes;
        }

        if publicKey.getKeyType() == Key.SM2_PUB_KEY && rootPrivateKey.getKeyType() == Key.SM2_PRV_KEY  {
            //intAlgType = 0;
        } else {
            return retBytes;
        }
        
        if let function = Function_GenerateRootCert {
            
            
            let publicKeyDataArray = Utils.dataToUInt8Array(data : publicKey.getKey()!)
            let inPublicKeyDataPointer = publicKeyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inPublicKeyDatalen = Int32(publicKeyDataArray.count)
            
            let rootPrivateKeyDataArray = Utils.dataToUInt8Array(data : rootPrivateKey.getKey()!)
            let inRootPrivateKeyDataPointer = rootPrivateKeyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inRootPrivateKeyDatalen = Int32(rootPrivateKeyDataArray.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let certDNData = Array(certDN.data(using: .utf8)!)
            let inCertDataPointer = certDNData.withUnsafeBytes({ $0 }).baseAddress
            let inCertDatalen = Int32(certDNData.count)
            
            let result = function(0,inPublicKeyDataPointer,inPublicKeyDatalen,inCertDataPointer,inCertDatalen,validDays,inRootPrivateKeyDataPointer,inRootPrivateKeyDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        
        return retBytes;
    }
    /*
     产生证书
     isSign：是否为签名证书
     DN：证书DN
     pubKey：公钥
     days：有效期
     rootDN: 根证书DN
     rootPriKey：根证书私钥
     返回：证书数据
     */
    public static func generateCert(isSignCert : Bool, certDN : String, publicKey : Key, validDays : Int32, rootCertDN : String, rootPrivateKey : Key) ->[UInt8]? {
    
        var retBytes : [UInt8]? = nil;
        //var intAlgType : Int32 = 0;

        if let keyData = publicKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if let keyData = rootPrivateKey.getKey(), keyData.count == 0 {
            return retBytes;
        }

        if publicKey.getKeyType() == Key.SM2_PUB_KEY && rootPrivateKey.getKeyType() == Key.SM2_PRV_KEY {
            //intAlgType = 0;
        } else {
            return retBytes;
        }
        
        if let function = Function_GenerateCert {
            
            
            let publicKeyDataArray = Utils.dataToUInt8Array(data : publicKey.getKey()!)
            let inPublicKeyDataPointer = publicKeyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inPublicKeyDatalen = Int32(publicKeyDataArray.count)
            
            let rootPrivateKeyDataArray = Utils.dataToUInt8Array(data : rootPrivateKey.getKey()!)
            let inRootPrivateKeyDataPointer = rootPrivateKeyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inRootPrivateKeyDatalen = Int32(rootPrivateKeyDataArray.count)
            
            let certDNData = Array(certDN.data(using: .utf8)!)
            let inCertDataPointer = certDNData.withUnsafeBytes({ $0 }).baseAddress
            let inCertDatalen = Int32(certDNData.count)
            
            let rootCertDNData = Array(rootCertDN.data(using: .utf8)!)
            let inRootCertDataPointer = rootCertDNData.withUnsafeBytes({ $0 }).baseAddress
            let inRootCertDatalen = Int32(rootCertDNData.count)
            
            var isign : Int32 = 0
            if isSignCert {
                isign = 1
            } else {
                isign = 0
            }
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(0,isign,inPublicKeyDataPointer,inPublicKeyDatalen,inCertDataPointer,inCertDatalen,inRootCertDataPointer,inRootCertDatalen,validDays,inRootPrivateKeyDataPointer,inRootPrivateKeyDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        
        return retBytes;
    }
    
    /*
     加密数据 SM4_CBC
     enKey：密钥
     ivData：iv 参数
     sourceData：明文数据，
     返回：加密数据
     */
    public static func encryptSM4CBC(encryptKey : Key,ivData: [UInt8]?, sourceData: [UInt8]?) -> [UInt8]? {
        var retBytes : [UInt8]? = nil;
        
        if sourceData == nil || sourceData!.count == 0 {
            return retBytes;
        }
        
        if let keyData = encryptKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if ivData == nil || ivData!.count == 0 {
            return retBytes;
        }
        
        
        if let function = Function_Encrypt_SM4_CBC {
           
            let inDataPointer = sourceData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sourceData!.count)
            
            let inIVDataPointer = ivData!.withUnsafeBytes({ $0 }).baseAddress
            let inIVDatalen = Int32(ivData!.count)
            
            let keyDataArray = Utils.dataToUInt8Array(data : encryptKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(inKeyDataPointer,inKeyDatalen,inIVDataPointer,inIVDatalen,inDataPointer,inDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        
        return retBytes
    }
    
    /*
     解密数据 SM4_CBC
     decryptKey：密钥
     ivData：iv 参数
     encryptData：加密数据
     返回：解密数据
     */
    public static func decryptSM4CBC(decryptKey : Key, ivData: [UInt8]?, encryptData: [UInt8]?) ->[UInt8]? {
        var retBytes : [UInt8]? = nil;
        
        if let keyData = decryptKey.getKey(), keyData.count == 0 {
            return retBytes;
        }
        
        if ivData == nil || ivData!.count == 0 {
            return retBytes;
        }
        
        if encryptData == nil || encryptData!.count == 0 {
            return retBytes;
        }
        
        
        if let function = Function_Decrypt_SM4_CBC {
            let keyDataArray = Utils.dataToUInt8Array(data : decryptKey.getKey()!)
            let inKeyDataPointer = keyDataArray.withUnsafeBytes({ $0 }).baseAddress
            let inKeyDatalen = Int32(keyDataArray.count)
            
            let inEncDataPointer = encryptData!.withUnsafeBytes({ $0 }).baseAddress
            let inEncDatalen = Int32(encryptData!.count)
            
            let inIVDataPointer = ivData!.withUnsafeBytes({ $0 }).baseAddress
            let inIVDatalen = Int32(ivData!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
          
            let result = function(inKeyDataPointer,inKeyDatalen,inIVDataPointer,inIVDatalen,inEncDataPointer,inEncDatalen,&dataPtr, &datalen)
            
            if result {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        return retBytes;
    }
}
//----------------------------------------------------------------------------------------
