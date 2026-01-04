//
//  SystemMamager.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/30.
//

import Foundation
//----------------------------------------------------------------------------------------

typealias Type_SetWorkPath = @convention(c) (UnsafePointer<CChar>?) -> Bool
private var Function_SetWorkPath: Type_SetWorkPath? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "setWorkPath"), to: Type_SetWorkPath.self)

typealias Type_SetTempPath = @convention(c) (UnsafePointer<CChar>?) -> Bool
private var Function_SetTempPath: Type_SetTempPath? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "setTempPath"), to: Type_SetTempPath.self)
//----------------------------------------------------------------------------------------

public class SystemMamager {
    /*
     设置工作路径
     filePath：工作路径
     返回：是否成功
     */
    public static func setWorkPath(filePath:String) -> Bool {
        var ret = false
        if filePath.isEmpty {
            return ret
        }
        
        if let function = Function_SetWorkPath {
            //print("setWorkPath")
            ret = function(filePath);
        }
        
        return ret
    }
    
    /*
     设置临时路径
     filePath：临时路径
     返回：是否成功
     */
    public static func setTempPath(filePath:String) -> Bool {
        var ret = false
        if filePath.isEmpty {
            return ret
        }
        
        if let function = Function_SetTempPath {
            //print("setTempPath")
            ret = function(filePath);
        }
        
        return ret
    }
    
}
//----------------------------------------------------------------------------------------
