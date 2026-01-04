//
//  FontManager.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/30.
//

import Foundation

//----------------------------------------------------------------------------------------
public typealias Type_CallBack_SystemFontFileNameFunc = @convention(c) (UnsafeRawPointer?, UnsafePointer<Int8>) -> Void
typealias Type_GetAllSystemFontFileName = @convention(c) (Type_CallBack_SystemFontFileNameFunc, UnsafeRawPointer?) -> Bool
private var Function_GetAllSystemFontFileName : Type_GetAllSystemFontFileName? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "getAllSystemFontFileName"), to: Type_GetAllSystemFontFileName.self)

typealias Type_AddFontCache = @convention(c) (UnsafePointer<CChar>?) -> Bool
private var Function_AddFontCache: Type_AddFontCache? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "saveFontFileNameCache"), to: Type_AddFontCache.self)
//----------------------------------------------------------------------------------------
public class FontManager {
    
    /*
     获取印章系统的全部字体文件
     systemFontFileNameFunc：回调函数，获取到的字体文件全路径
     返回：是否成功
     */
    public static func getAllSystemFontFileName(withClosure systemFontFileNameCallBack: @escaping Type_CallBack_SystemFontFileNameFunc) -> Bool {
        
        var ret = false
        
        if let function = Function_GetAllSystemFontFileName {
            //print("getAllSystemFontFileName")
            ret = function(systemFontFileNameCallBack,nil);
        }
        
        return ret
    }
    
    /*
     加入字体到缓存
     fontFileName：字体文件全路径
     返回：是否成功
     */
    public static func saveFontFileNameCache(fontFileName:String) -> Bool {
        
        var ret = false
        
        if fontFileName.isEmpty {
            return ret
        }
        
        if let function = Function_AddFontCache {
            //print("saveFontFileNameCache")
            ret = function(fontFileName);
        }
        
        return ret
    }
}
//----------------------------------------------------------------------------------------


