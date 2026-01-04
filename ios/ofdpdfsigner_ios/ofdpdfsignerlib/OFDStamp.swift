//
//  OFDStamp.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/7.
//

import Foundation

//----------------------------------------------------------------------------------------
typealias Type_OFDSignStamp_Pos_Handle = @convention(c) (UnsafeMutableRawPointer,UnsafeRawPointer?, Int32,Int32,Double,Double,Double,Double,Bool, Type_CallBack_Sign,Type_CallBack_getUserCert,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDSignStamp_Pos_Handle: Type_OFDSignStamp_Pos_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_positionSign"), to: Type_OFDSignStamp_Pos_Handle.self)

typealias Type_OFDSignStamp_Riding_Handle = @convention(c) (UnsafeMutableRawPointer,UnsafeRawPointer?, Int32,Int32,Double,Double,Bool, Type_CallBack_Sign,Type_CallBack_getUserCert,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDSignStamp_Riding_Handle: Type_OFDSignStamp_Riding_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_ridingSign"), to: Type_OFDSignStamp_Riding_Handle.self)

typealias Type_OFDSignStamp_KeyWord_Handle = @convention(c) (UnsafeMutableRawPointer,UnsafeRawPointer?, Int32,UnsafePointer<CChar>?,UnsafePointer<CChar>?,Double,Double,Bool, Type_CallBack_Sign,Type_CallBack_getUserCert,UnsafeRawPointer?, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDSignStamp_KeyWord_Handle: Type_OFDSignStamp_KeyWord_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_keywordSign"), to: Type_OFDSignStamp_KeyWord_Handle.self)

typealias Type_OFDSignStamp_ClearSigns_Handle = @convention(c) (UnsafeMutableRawPointer,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_OFDSignStamp_ClearSigns_Handle: Type_OFDSignStamp_ClearSigns_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "ofd_clearSigns"), to: Type_OFDSignStamp_ClearSigns_Handle.self)

//----------------------------------------------------------------------------------------
public class OFDStamp {
    
    public static let RIDING_LEFT : Int32 = 0;
    public static let RIDING_RIGHT : Int32 = 1;
    public static let RIDING_TOP : Int32 = 2;
    public static let RIDING_BOTTOM : Int32 = 3;
    public static let RIDING_CUTTING_RIGHT : Int32 = 4;
    public static let RIDING_CUTTING_TOP : Int32 = 5;
    
    /*
     OFD 位置盖章
     fileHandle:PDF文件句柄
     stampData：印章数据
     pageIndex：页码 0开始
     x：开始位置
     y：开始位置
     stampwidth：印章宽
     stampheight: 印章高
     isLocked：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static func positionSign(fileHandle : UInt,sealData : [UInt8]?,pageNumber : Int32,stampX : Double,stampY : Double,
                                    width : Double, height : Double,isLocked : Bool,
                                    withClosure signCallback: @escaping Type_CallBack_Sign,withClosure getUserCertCallback: @escaping Type_CallBack_getUserCert) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        if sealData == nil || sealData!.count == 0 {
            return retBytes;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDSignStamp_Pos_Handle {
                //print("createSeal")
                let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
                let inDatalen = Int32(sealData!.count)
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,inDataPointer,inDatalen, pageNumber, stampX, stampY,width,height,!isLocked, signCallback,getUserCertCallback,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("positionSign error:")
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
     OFD 文档验证
     fileData：OFD数据
     verifyCallback：验证回调
     返回：验证结果，json数据
     */
    public static func verify(fileData : [UInt8]?, withClosure verifyCallback: @escaping Type_CallBack_Verify) -> String?
    {
        var ret : String = ""
        if fileData == nil || fileData!.count == 0 {
            return ret;
        }
        
        if let function = Function_VerifyDocment {
            //print("verifySeal")
            let inDataPointer = fileData!.withUnsafeBytes({ $0 }).baseAddress
            let inDatalen = Int32(fileData!.count)
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            
            let result = function(inDataPointer,inDatalen,1,"",verifyCallback,nil,&dataPtr, &datalen)
            
            if result == 0 {
                ret = String(data: Utils.convertToData(bytes: dataPtr, lenght: Int32(datalen))!, encoding: .utf8)!
            } else {
                print("verify error:")
                print(result)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
            
        }
        
        return ret;
    }
    
    /*
     OFD文件骑缝章签章
     fileHandle:OFD文件句柄
     imageData：印章数据
     RidingType：骑缝章类型
     stampwidth：印章宽
     stampheight: 印章高
     isLocked：是否继续盖章
     signCallback：签名回调
     getUserCertCallback:用户证书
     返回：电子印章数据
     */

    public static func ridingSign(fileHandle : UInt,sealData : [UInt8]?,ridingType : String,
                                          width : Double, height : Double,isLocked : Bool,withClosure signCallback: @escaping Type_CallBack_Sign,withClosure getUserCertCallback: @escaping Type_CallBack_getUserCert)  -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        if sealData == nil || sealData!.count == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDSignStamp_Riding_Handle {
                //print("createSeal")
                let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
                let inDatalen = Int32(sealData!.count)
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let iType = Int32(ridingType)!
                
                let result = function(handle,inDataPointer,inDatalen, iType, width,height,!isLocked, signCallback,getUserCertCallback,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("positionSign error:")
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
     OFD文件骑缝章签章
     fileHandle:OFD文件句柄
     imageData：印章数据
     keyword：关键字
     KeywordRule：关键字规则
     stampwidth：印章宽
     stampheight: 印章高
     isLocked：是否继续盖章
     signCallback：签名回调
     getUserCertCallback:用户证书
     返回：电子印章数据
     */
    public static func keywordSign(fileHandle : UInt,sealData : [UInt8]?, keyWord : String,keyWordRules : String,
                                   width : Double, height : Double,isLocked : Bool,withClosure signCallback: @escaping Type_CallBack_Sign,withClosure getUserCertCallback: @escaping Type_CallBack_getUserCert) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        if sealData == nil || sealData!.count == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDSignStamp_KeyWord_Handle {
                //print("createSeal")
                let inDataPointer = sealData!.withUnsafeBytes({ $0 }).baseAddress
                let inDatalen = Int32(sealData!.count)
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
              
                
                let result = function(handle,inDataPointer,inDatalen, keyWord,keyWordRules, width,height,!isLocked, signCallback,getUserCertCallback,nil,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("positionSign error:")
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
     删除OFD文档中全部印章和数字签名
     fileHandle:OFD文件句柄
     返回：删除OFD文档中全部印章和数字签名后的文档数据
     */
    public static func clearSigns(fileHandle : UInt) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_OFDSignStamp_ClearSigns_Handle {
              
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("clearSigns error:")
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
