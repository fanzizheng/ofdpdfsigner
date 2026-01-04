//
//  SealManager.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/6.
//

import Foundation

//----------------------------------------------------------------------------------------



typealias Type_CreateSeal = @convention(c) (UnsafePointer<CChar>?,Int32,UnsafePointer<CChar>?,Int32,Int32,UnsafePointer<CChar>?,UnsafePointer<CChar>?,UnsafePointer<CChar>?,UnsafePointer<CChar>?,UnsafeRawPointer?, Int32, Type_CallBack_Sign,Type_CallBack_getUserCert,Type_CallBack_getSealCert,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_CreateSeal: Type_CreateSeal? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "createSeal"), to: Type_CreateSeal.self)

typealias Type_VerifySeal = @convention(c) (UnsafeRawPointer?, Int32, Type_CallBack_Verify,UnsafeRawPointer?) -> Int32
private var Function_VerifySeal: Type_VerifySeal? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "verifySeal"), to: Type_VerifySeal.self)

typealias Type_GetSealImageData = @convention(c) (UnsafeRawPointer?, Int32, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_GetSealImageData: Type_GetSealImageData? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "getSealImageData"), to: Type_GetSealImageData.self)

typealias Type_GetSealUserCertData = @convention(c) (UnsafeRawPointer?, Int32, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_GetSealUserCertData: Type_GetSealUserCertData? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "getSealUserCertData"), to: Type_GetSealUserCertData.self)
//----------------------------------------------------------------------------------------
public class SealManager {
    /*
     创建电子印章
     code：印章id
     type：印章类型
     name：印章名称
     format：印章图片类型
     image：印模数据
     width：印章的宽
     height：印章的高
     createTime：创建时间
     startTime：开始时间
     endTime：结束时间
     signCallback：签名回调
     getUserCertCallback：用户证书回调
     getSealCertCallback: 印章证书回调
     返回：电子印章数据
     */
    public static func createSeal(code : String,type : String,name : String,format : String,image : [UInt8]?,width : Int32,height : Int32,createTime : String,startTime : String,endTime : String,withClosure signCallback: @escaping Type_CallBack_Sign,withClosure getUserCertCallback: @escaping Type_CallBack_getUserCert,withClosure getSealCertCallback: @escaping Type_CallBack_getSealCert) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if code.isEmpty || name.isEmpty || startTime.isEmpty || format.isEmpty {
            return retBytes;
        }
        if image == nil || image!.count == 0 {
            return retBytes;
        }

        let iType : Int32 = Int32(type)!;
        
        if let function = Function_CreateSeal {
            //print("createSeal")
            let inDataPointer = image!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(image!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(code,iType,name, width,height,createTime,startTime,endTime,format,inDataPointer,inDatalen,signCallback,getUserCertCallback,getSealCertCallback,nil,&dataPtr, &datalen)
            
            if result == 0 {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            } else {
                print("createSeal error:")
                print(result)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        
        
     
        return retBytes;
    }
    
    /*
     验证电子印章
     sealData：印章数据
     verifyCallback: 签名运算回调
     返回：电子印章数据
     */
    public static func verifySeal(sealData : [UInt8]?, withClosure verifyCallback: @escaping Type_CallBack_Verify) -> Int32
    {
        var ret : Int32 = 0xFFFFFF
        if sealData == nil || sealData!.count == 0 {
            return ret;
        }
        
        if let function = Function_VerifySeal {
            //print("verifySeal")
            let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sealData!.count)
            
            ret = function(inDataPointer,inDatalen,verifyCallback,nil)
            
            if ret != 0 {
                print("verifySeal error:")
                print(ret)
            }
            
        }
        
        return ret;
    }
    
    /*
     获取电子印章中的印模数据
     sealData：印章数据
     返回：电子印章中的印模数据
     */
    public static func  getSealImageData(sealData : [UInt8]?) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if sealData == nil || sealData!.count == 0 {
            return retBytes;
        }
        if let function = Function_GetSealImageData {
            //print("getSealImageData")
            let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sealData!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(inDataPointer,inDatalen,&dataPtr, &datalen)
            
            if result == 0 {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            } else {
                print("getSealImageData error:")
                print(result)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        return retBytes;
    }
    /*
     获取电子印章中的用户证书
     sealData：印章数据
     返回：电子印章用户证书
     */
    public static func  getSealUserCertData(sealData : [UInt8]?) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if sealData == nil || sealData!.count == 0 {
            return retBytes;
        }
        if let function = Function_GetSealUserCertData {
            //print("getSealUserCertData")
            let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(sealData!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(inDataPointer,inDatalen,&dataPtr, &datalen)
            
            if result == 0 {
                retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
            } else {
                print("getSealImageData error:")
                print(result)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        return retBytes;
    }
}
//----------------------------------------------------------------------------------------
