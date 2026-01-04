//
//  PDFConverter.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/5.
//

import Foundation

//----------------------------------------------------------------------------------------
typealias Type_PDFPage2Image_Handle = @convention(c) (UnsafeMutableRawPointer, UnsafePointer<CChar>?, Int32,Double, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_PDFPage2Image_Handle: Type_PDFPage2Image_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_pageToImage"), to: Type_PDFPage2Image_Handle.self)

typealias Type_PDF2Image_Handle = @convention(c) (UnsafeMutableRawPointer, UnsafePointer<CChar>?,Double, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?, UnsafeMutablePointer<UnsafeMutablePointer<CChar>?>?) -> Bool
private var Function_PDF2Image_Handle: Type_PDF2Image_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_toImage"), to: Type_PDF2Image_Handle.self)

typealias Type_PDF2ImageToZip_Handle = @convention(c) (UnsafeMutableRawPointer, UnsafePointer<CChar>?,Double, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_PDF2ImageToZip_Handle: Type_PDF2ImageToZip_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdf_toImageZip"), to: Type_PDF2ImageToZip_Handle.self)

typealias Type_PDF2OFD_Handle = @convention(c) (UnsafeMutableRawPointer, CBool, UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?) -> Bool
private var Function_PDF2OFD_Handle: Type_PDF2OFD_Handle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "pdfToOfd"), to: Type_PDF2OFD_Handle.self)

//----------------------------------------------------------------------------------------
public class PDFConverter {
    
    /*
     PDF转换图片
     fileHandle：PDF文件句柄
     imageFormat: 转换后的图片类型 "PNG","JPG","SVG"
     pageNumber：要转换的PDF文件的页码
     返回：PDF图片
     */
    public static func pdfPage2Image(fileHandle : UInt,imageFormat : String,pageNumber:Int32,scale : Double) -> [UInt8]? {
        
        var retBytes : [UInt8]? = nil;
        
        if fileHandle == 0 {
            return retBytes;
        }
        
//        if  imageFormat != "PNG" && imageFormat != "JPG" && imageFormat != "WEBP" {
//            return retBytes;
//        }
        if  imageFormat != "PNG" && imageFormat != "SVG" {
            return retBytes;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDFPage2Image_Handle {
                //print("pdfPage2Image")
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,imageFormat,pageNumber,scale, &dataPtr, &datalen)
                
                if result {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
            }
        }
        
        return retBytes;
    }
    
    /*
     pdf转换图片
     fileHandle：PDF文件句柄
     imageFormat: 转换后的图片类型 "PNG","JPG","SVG"
     返回：pfd图片数组
     */
    public static func pdf2Image(fileHandle : UInt,imageFormat : String,scale : Double) ->[Data?]?
    {
        var ret : [Data?] = [];
        if fileHandle == 0 {
            return ret;
        }
        
//        if  imageFormat != "PNG" && imageFormat != "JPG" && imageFormat != "WEBP" {
//            return ret;
//        }
        if  imageFormat != "PNG" && imageFormat != "SVG" {
            return ret;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDF2Image_Handle {
                //print("ofd2Image")
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                var stringPtr: UnsafeMutablePointer<CChar>? = nil
                
                let result = function(handle,imageFormat,scale, &dataPtr, &datalen,&stringPtr)
                
                if result {
                    if let retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen) {
                        let retData = Utils.convertToData(fromBytes: retBytes)
                        if let imageslens = Utils.convertUnsafePointerToString(cString: stringPtr) {
                            let imageslenItems = imageslens.components(separatedBy: ",").map { Int($0)! }
                            var position = 0
                            for item in imageslenItems {
                                //print(item)
                                let subdata = retData.subdata(in: position ..< (position + item))
                                ret.append(subdata)
                                position += item
                            }
                        }
                        
                    }
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
                
                if let pdataPtr = stringPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
                
            }
        }

        
        return ret;
    }
    
    /*
     PDF转换图片zip
     fileHandle：PDF文件句柄
     imageFormat: 转换后的图片类型 "PNG","JPG","SVG"
     返回：PDF图片
     */
    public static func pdf2ImageZip(fileHandle : UInt,imageFormat : String,scale : Double) -> [UInt8]? {
        
        var retBytes : [UInt8]? = nil;
        
        if fileHandle == 0 {
            return retBytes;
        }
        
//        if  imageFormat != "PNG" && imageFormat != "JPG" && imageFormat != "WEBP" {
//            return retBytes;
//        }
        if  imageFormat != "PNG" && imageFormat != "SVG" {
            return retBytes;
        }
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDF2ImageToZip_Handle {
                //print("pdfPage2Image")
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,imageFormat,scale, &dataPtr, &datalen)
                
                if result {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
                }
                
                if let pdataPtr = dataPtr {
                    Utils.freeHandle(handlePtr: pdataPtr)
                }
            }
        }
        
        return retBytes;
    }
    
    /*
     PDF转换OFD
     fileHandle：PDF文件句柄
     isIncludeStamp: true : 含印章， false ： 不包含印章
     返回：OFD
     */
    public static func pdf2Ofd(fileHandle : UInt,isIncludeStamp : Bool) -> [UInt8]? {
        
        var retBytes : [UInt8]? = nil;
        
        if fileHandle == 0 {
            return retBytes;
        }
        
        if let handle = UnsafeMutableRawPointer(bitPattern: fileHandle) {
            if let function = Function_PDF2OFD_Handle {
                //print("pdf2Ofd")
                
                var dataPtr: UnsafeMutablePointer<UInt8>? = nil
                var datalen: size_t = 0
                
                let result = function(handle,!isIncludeStamp, &dataPtr, &datalen)
                
                if result {
                    retBytes = Utils.convertUnsafePointerToArray(dataPtr: dataPtr, datalen: datalen)
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
