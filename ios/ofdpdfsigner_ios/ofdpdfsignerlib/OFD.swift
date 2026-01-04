//
//  OFD.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/5.
//

import Foundation

//----------------------------------------------------------------------------------------
typealias Type_CreateOFDObject = @convention(c) (UnsafeRawPointer?, Int32) -> UnsafeMutableRawPointer
private var Function_CreateOFDObject: Type_CreateOFDObject? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_open"), to: Type_CreateOFDObject.self)

typealias Type_FreeOFDObject = @convention(c) (UnsafeMutableRawPointer) -> Void
private var Function_FreeOFDObject: Type_FreeOFDObject? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_close"), to: Type_FreeOFDObject.self)

typealias Type_GetOFDPageCount_Handle = @convention(c) (UnsafeMutableRawPointer) -> Int32
private var Function_GetOFDPageCount_Handle: Type_GetOFDPageCount_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_getPageCount"), to: Type_GetOFDPageCount_Handle.self)

typealias Type_GetOFDPageSize_Handle = @convention(c) (UnsafeMutableRawPointer, Int32, UnsafeMutablePointer<Double>, UnsafeMutablePointer<Double>) -> Int32
private var Function_GetOFDPageSize_Handle: Type_GetOFDPageSize_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_getPageSize"), to: Type_GetOFDPageSize_Handle.self)

typealias Type_OFDIsProtect = @convention(c) (UnsafeMutableRawPointer) -> Bool
private var Function_OFDIsProtect: Type_OFDIsProtect? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_isProtect"), to: Type_OFDIsProtect.self)

typealias Type_OFDIsEncrypt = @convention(c) (UnsafeMutableRawPointer) -> Bool
private var Function_OFDIsEncrypt: Type_OFDIsEncrypt? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_isEncrypt"), to: Type_OFDIsEncrypt.self)

typealias Type_OFDProtect_Handle = @convention(c) (UnsafeMutableRawPointer,Type_CallBack_Sign,Type_CallBack_getUserCert,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDProtect_Handle: Type_OFDProtect_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_protect"), to: Type_OFDProtect_Handle.self)

public typealias Type_OFDProtectionVerify_Handle = @convention(c) (UnsafeRawPointer?,Type_CallBack_Verify,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
public var Function_OFDProtectionVerify_Handle: Type_OFDProtectionVerify_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_protectionVerify"), to: Type_OFDProtectionVerify_Handle.self)


typealias Type_OFDEncryptDocument_Handle = @convention(c) (UnsafeMutableRawPointer,UnsafePointer<CChar>?,Type_CallBack_EncryptSM4CBC,Type_CallBack_DecryptSM4CBC,Type_CallBack_EncryptSM2,Type_CallBack_DecryptSM2,Type_CallBack_GenerateRandom,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDEncryptDocument_Handle: Type_OFDEncryptDocument_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_encryptDocument"), to: Type_OFDEncryptDocument_Handle.self)


typealias Type_OFDDecryptDocument_Handle = @convention(c) (UnsafeMutableRawPointer,Int32,UnsafePointer<CChar>?,UnsafePointer<CChar>?,UnsafePointer<CChar>?,Type_CallBack_EncryptSM4CBC,Type_CallBack_DecryptSM4CBC,Type_CallBack_EncryptSM2,Type_CallBack_DecryptSM2,Type_CallBack_GenerateRandom,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDDecryptDocument_Handle: Type_OFDDecryptDocument_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_decryptDocument"), to: Type_OFDDecryptDocument_Handle.self)


//----------------------------------------------------------------------------------------
public class OFD {
    /*
     打开PDF文件
     fileData：PDF 文件数据
     返回：文件句柄
     */
    public static func open(fileData : [UInt8]?) -> UInt
    {
        var ret : UInt = 0;
        if fileData == nil || fileData!.count == 0 {
            return ret;
        }
        
        if let function = Function_CreateOFDObject {
            //print("open")
            
            let inDataPointer = fileData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(fileData!.count)
            
            let handle = function(inDataPointer,inDatalen)
            ret = UInt(bitPattern: handle)
            
        }
        return ret;
    }

    /*
     关闭PDF文件
     handle：文件句柄
     返回：无
     */
    public static func close(handle:UInt)
    {
        if ( handle == 0 ) {
            return
        }
        
        if let fileHandle = UnsafeMutableRawPointer(bitPattern: handle) {
            if let function = Function_FreeOFDObject {
                //print("close")
                function(fileHandle)
            }
        }
        
    }
    
    /*
     获得OFD文件的总页数
     fileHandle：文件句柄
     返回：OFD文件的总页数
     */
    public static func getOfdPageCount(fileHandle : UInt) -> Int64
    {
        var ret : Int64 = 0;
        if ( fileHandle == 0 ) {
            return ret;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_GetOFDPageCount_Handle {
                
                ret = Int64(function(handle))
            }
        }
        return ret;
    }
    
    /*
     获得OFD文件的页面宽高
     fileHandle：文件句柄
     pageNumber: 页码
     返回：PageSize 页面的宽高
     */
    public static func getOfdPageSize(fileHandle : UInt,  pageNumber : Int32) -> PageSize?
    {
        let  pageSize : PageSize = PageSize();
        if ( fileHandle == 0 ) {
            return pageSize;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_GetOFDPageSize_Handle {
                var pageWidth: Double = 0
                var pageHeight: Double = 0
                let ret = function(handle,pageNumber,&pageWidth,&pageHeight)
                if ret != 0 {
                    print("PDF::getPdfPageSize error code:")
                    print(ret)
                } else {
                    pageSize.width = pageWidth
                    pageSize.height = pageHeight
                }
            }
        }


        return pageSize;
    }
    
    /*
     OFD文档是否被完整性保护
     fileHandle：ofd文件句柄
     返回：-1：fileHandle错误； 0：没有被完整性保护 ； 1： 被完整性保护
     */
    public static func IsProtect(fileHandle : UInt) -> Int64
    {
        var ret : Int64 = 0;
        if fileHandle == 0 {
            return -1;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDIsProtect {
                var isEnc = false
                isEnc = function(handle)
                if ( isEnc == true ) {
                    ret = 1
                } else {
                    ret = 0
                }
            }
        }
        return ret;
    }
    
    /*
     OFD文档是否被加密
     fileHandle：ofd文件句柄
     返回：-1：fileHandle错误； 0：没有加密 ； 1： 加密
     */
    public static func IsEncrypt(fileHandle : UInt) -> Int64
    {
        var ret : Int64 = 0;
        if fileHandle == 0 {
            return -1;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDIsEncrypt {
                var isEnc = false
                isEnc = function(handle)
                if ( isEnc == true ) {
                    ret = 1
                } else {
                    ret = 0
                }
            }
        }
        return ret;
    }
    
    /*
     OFD 文档完整性保护
     (in param) fileHandle: ofd 文件句柄
     (in param) signCallback: 签名回调函数
     (in param) getUserCertCallback: 证书回调函数
     (return) 返回完整性保护的文档数据；
     */
    public static func protect(fileHandle : UInt,
                                    withClosure signCallback: @escaping Type_CallBack_Sign,withClosure getUserCertCallback: @escaping Type_CallBack_getUserCert) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDProtect_Handle {
                
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,signCallback,getUserCertCallback,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("protect error:")
                    print(result)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
            }
        }

        return retBytes;
    }
    /*
     OFD 文档完整性保护验证
     (in param) handle: ofd 文件句柄
     (in param) verifyFunc: 验证签名回调函数
     (return) 验证结果，json数据,如果为""字符串，函数执行失败了
     {"verify":false,nothavefile:[]}
     1。验证签名失败 {"verify":false,nothavefile:[]}
     2。验证签名成功，但 文档的文件有增加或减少 {"verify":false,nothavefile:[]}
     3。验证签名成功，文档的文件个数相等，但文件名称不同 {"verify":false,nothavefile:[保护前缺少的文件名]}
       比如将 /doc_0/annots/page_0/annotation.xml 改名为 /doc_0/annots/page_0/annotation_1.xml
       nothavefile中的文件名为 /doc_0/annots/page_0/annotation.xml
     */
    public static func protectionVerify(fileHandle : UInt,withClosure verifyCallback: @escaping Type_CallBack_Verify) -> String?
    {
        var ret : String = ""
        if fileHandle == 0 {
            return ret;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDProtectionVerify_Handle {
                
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,verifyCallback,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    ret = String(data: Utils.convertToData(bytes: dataPtr, lenght: Int32(datalen))!, encoding: .utf8)!
                } else {
                    print("protectionVerify error:")
                    print(result)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
                
            }
        }
        
        return ret;
    }
    
    /*
     OFD 加密文档
     fileHandle：ofd 文件句柄
    userInfo：用户信息json:[{mode:1,passWordCert:"12345678",userName:"user 1",userType:"User"},
        {mode:2,passWordCert:"证书base64",userName:"user 1",userType:"Owner"}]
                mode：1 密码，2 证书
                passWordCert：密码 或 证书base64
                userName：用户名
                userType：用户类型：User 普通用户；Owner 文档管理员；
    encryptCallBack：加解密回调
    返回：ofd 加密文档数据
     */
    public static func encryptDocument(fileHandle : UInt, userInfo:String ,
                                       withClosure encryptSm4CBCCallBack: @escaping Type_CallBack_EncryptSM4CBC,withClosure decryptSm4CBCCallBack: @escaping Type_CallBack_DecryptSM4CBC,withClosure encryptSm2CallBack: @escaping Type_CallBack_EncryptSM2,withClosure decryptSm2CallBack: @escaping Type_CallBack_DecryptSM2,withClosure generateRandomCallBack: @escaping Type_CallBack_GenerateRandom
                                    ) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDEncryptDocument_Handle {
                
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,userInfo,encryptSm4CBCCallBack,decryptSm4CBCCallBack,encryptSm2CallBack,decryptSm2CallBack,generateRandomCallBack,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("encryptDocument error:")
                    print(result)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
            }
        }

        return retBytes;
    }
    /*
     OFD 解密文档
     fileHandle：ofd 文件句柄
     mode：1 密码，2 证书
     passWord：密码 ，当 mode为1时 必填；当 mode为2时 空字符串 ""
     userName：用户名
     userType：用户类型：User 普通用户；Owner 文档管理员；
     encryptCallBack：加解密回调
     返回：ofd 完整性保护文档数据
     */
    public static func decryptDocument(fileHandle : UInt, mode:Int32,passWord:String ,userName:String ,userType:String ,
                                       withClosure encryptSm4CBCCallBack: @escaping Type_CallBack_EncryptSM4CBC,withClosure decryptSm4CBCCallBack: @escaping Type_CallBack_DecryptSM4CBC,withClosure encryptSm2CallBack: @escaping Type_CallBack_EncryptSM2,withClosure decryptSm2CallBack: @escaping Type_CallBack_DecryptSM2,withClosure generateRandomCallBack: @escaping Type_CallBack_GenerateRandom
                                    ) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDDecryptDocument_Handle {
                
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,mode,passWord,userName,userType,encryptSm4CBCCallBack,decryptSm4CBCCallBack,encryptSm2CallBack,decryptSm2CallBack,generateRandomCallBack,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("decryptDocument error:")
                    print(result)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
            }
        }

        return retBytes;
    }
}
//----------------------------------------------------------------------------------------
