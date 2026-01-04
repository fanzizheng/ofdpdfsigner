//
//  PageSize.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/31.
//

import Foundation

public class PageSize {
    
    private var _width: Double = 0.0
    private var _height: Double = 0.0
  
    public var width: Double {
        get {
            return _width
        }
        set {
            _width = newValue // 在Swift中，setter方法使用newValue表示新值
        }
    }
  
    public var height: Double {
        get {
            return _height
        }
        set {
            _height = newValue
        }
    }
  
    
    init(width: Double = 0.0, height: Double = 0.0) {
        self._width = width
        self._height = height
    }
}
