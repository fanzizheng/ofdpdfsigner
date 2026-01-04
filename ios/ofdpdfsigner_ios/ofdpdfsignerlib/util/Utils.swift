//
//  Utils.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/31.
//

import Foundation

//----------------------------------------------------------------------------------------
typealias Type_FZZFreeHandle = @convention(c) (UnsafeMutableRawPointer?) -> Void
private var Function_FZZFreeHandle: Type_FZZFreeHandle? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "FZZFreeHandle"), to: Type_FZZFreeHandle.self)
//----------------------------------------------------------------------------------------
public class Utils {
    
    public static func convertUnsafePointerToArray(dataPtr: UnsafePointer<UInt8>?, datalen: size_t) -> [UInt8]? {
        // 检查指针和长度是否有效
        guard let validDataPtr = dataPtr, datalen > 0 else {
            return nil // 如果指针为nil或长度为0，返回nil
        }
          
        // 使用 UnsafeBufferPointer 创建一个缓冲区来访问数据
        let buffer = UnsafeBufferPointer<UInt8>(start: validDataPtr, count: datalen)
          
        // 将 UnsafeBufferPointer 转换为 [UInt8] 数组
        let dataArray = Array(buffer)
          
        // 返回数组
        return dataArray
    }
    
    public static func convertToData(fromBytes: [UInt8]?) -> Data {
        if let bytes = fromBytes {
            return Data(bytes)
        } else {
            // 如果 fromBytes 是 nil，返回一个空的 Data 对象
            return Data()
        }
    }
    
    public static func convertToData(bytes: UnsafeRawPointer?,lenght: Int32) -> Data? {
        if bytes == nil || lenght == 0 {
            return Data()
        }
        return Data(bytes: bytes!, count: Int(lenght))
    }
    
    public static func dataToUInt8Array(data: Data) -> [UInt8] {
        return data.compactMap { $0 } // 在这里，$0 已经是 UInt8 类型，所以直接返回
    }
    
    public static func convertUnsafePointerToString(cString: UnsafePointer<CChar>?) -> String? {
        guard let cStringPtr = cString else {
            return nil
        }
        return String(cString: cStringPtr)
    }
    
    public static func freeHandle(handlePtr : UnsafeMutableRawPointer?) {
        guard let validHandlePtr = handlePtr else {
            return
        }
        
        if let function = Function_FZZFreeHandle {
            //print("freeHandle")
            function(validHandlePtr)
        }
    }
    
}
//----------------------------------------------------------------------------------------
