//
//  PDF.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/5.
//

import Foundation
//----------------------------------------------------------------------------------------
typealias Type_CreatePDFObject = @convention(c) (UnsafeRawPointer?, Int32) -> UnsafeMutableRawPointer
private var Function_CreatePDFObject: Type_CreatePDFObject? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_open"), to: Type_CreatePDFObject.self)

typealias Type_FreePDFObject = @convention(c) (UnsafeMutableRawPointer) -> Void
private var Function_FreePDFObject: Type_FreePDFObject? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_close"), to: Type_FreePDFObject.self)

typealias Type_GetPDFPageCount_Handle = @convention(c) (UnsafeMutableRawPointer) -> Int32
private var Function_GetPDFPageCount_Handle: Type_GetPDFPageCount_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_getPageCount"), to: Type_GetPDFPageCount_Handle.self)

typealias Type_GetPDFPageSize_Handle = @convention(c) (UnsafeMutableRawPointer, Int32, UnsafeMutablePointer<Double>, UnsafeMutablePointer<Double>) -> Int32
private var Function_GetPDFPageSize_Handle: Type_GetPDFPageSize_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_getPageSize"), to: Type_GetPDFPageSize_Handle.self)


typealias Type_PDFIsEncryptPassward = @convention(c) (UnsafeMutableRawPointer) -> Bool
private var Function_PDFIsEncryptPassward: Type_PDFIsEncryptPassward? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_isNeedPassWord"), to: Type_PDFIsEncryptPassward.self)


typealias Type_PDFSetPassword = @convention(c) (UnsafeMutableRawPointer,UnsafePointer<CChar>?) -> Void
private var Function_PDFSetPassword: Type_PDFSetPassword? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_setPassWord"), to: Type_PDFSetPassword.self)

typealias Type_PDFEncryptDecrypt_Handle = @convention(c) (UnsafeMutableRawPointer,CBool,UnsafePointer<CChar>?,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Int32
private var Function_PDFEncryptDecrypt_Handle: Type_PDFEncryptDecrypt_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_documnetEncryptDecrypt"), to: Type_PDFEncryptDecrypt_Handle.self)
//----------------------------------------------------------------------------------------
public class PDF {
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
        
        if let function = Function_CreatePDFObject {
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
            if let function = Function_FreePDFObject {
                //print("close")
                function(fileHandle)
            }
        }
        
    }
    
    /*
     获得PDF文件的总页数
     fileHandle：文件句柄
     返回：PDF文件的总页数
     */
    public static func getPdfPageCount(fileHandle : UInt) -> Int64
    {
        var ret : Int64 = 0;
        if fileHandle == 0 {
            return ret;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_GetPDFPageCount_Handle {
                
                ret = Int64(function(handle))
            }
        }
        return ret;
    }
    
    /*
     获得PDF文件的页面宽高
     fileHandle：文件句柄
     pageNumber: 页码
     返回：PageSize 页面的宽高
     */
    public static func getPdfPageSize(fileHandle : UInt,  pageNumber : Int32) -> PageSize?
    {
        let  pageSize : PageSize = PageSize();
        if ( fileHandle == 0 ) {
            return pageSize;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_GetPDFPageSize_Handle {
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
     PDF文档是否需要密码打开文档
     fileHandle：PDF文件句柄
     返回：-1：fileHandle错误； 0：不需要密码 ； 1： 需要密码
     */
    public static func isNeedPassword(fileHandle : UInt) -> Int64
    {
        var ret : Int64 = 0;
        if fileHandle == 0 {
            return -1;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDFIsEncryptPassward {
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
     PDF文档设置密码
     fileHandle：PDF文件句柄
     passWord：密码
     返回：0：成功； 非0 失败
     */
    public static func setPassword(fileHandle : UInt,passWord : String) -> Int64
    {
        var ret : Int64 = 0;
        if fileHandle == 0 {
            return -1;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDFSetPassword {
                function(handle,passWord)
                ret = 0;
            }
        }
        return ret;
    }
    
    /*
     PDF文档加密（密码加密或直接加密文档）/解密
     注意：isEncrypt为false 并 password = “”，这时为输出为明文文档
     fileHandle：pdf文件句柄
     isEncrypt：是否加密
     password：密码
     返回：加密文档/明文文档
     */
    public static func documnetEncryptDecrypt(fileHandle : UInt,isEncrypt:Bool,passWord : String) -> [UInt8]?
    {
        var retBytes : [UInt8]? = nil;
        if fileHandle == 0 {
            return retBytes;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDFEncryptDecrypt_Handle {
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,isEncrypt,passWord,&dataPtr, &datalen)
                
                if result == 0 {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                } else {
                    print("documnetEncryptDecrypt error:")
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
