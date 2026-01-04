//
//  TextParams.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/11.
//

import Foundation


public class TextParams {
    
    private var text: [String]?
      
    
    private var textAlign: String = "left"
      
    
    private var color: [ColorType]?
      
    
    private var fontName: [String]?
      
    
    private var fontSize: [Double]?
      
    
    private var isFontBold: [Bool]?
      
    
    private var lineSpacing: [Double]?
  
    // 初始化方法
    public init(text: [String]? = nil,
         textAlign: String = "left",
         color: [ColorType]? = nil,
         fontName: [String]? = nil,
         fontSize: [Double]? = nil,
         isFontBold: [Bool]? = nil,
         lineSpacing: [Double]? = nil) {
        self.text = text
        self.textAlign = textAlign
        self.color = color
        self.fontName = fontName
        self.fontSize = fontSize
        self.isFontBold = isFontBold
        self.lineSpacing = lineSpacing
    }
  
    // 计算属性或getter/setter方法
    public var textArray: [String]? {
        get { return text }
        set { text = newValue }
    }
      
    public var textAlignment: String {
        get { return textAlign }
        set { textAlign = newValue }
    }
      
    public var colorArray: [ColorType]? {
        get { return color }
        set { color = newValue }
    }
      
    public var fontNameArray: [String]? {
        get { return fontName }
        set { fontName = newValue }
    }
      
    public var fontSizeArray: [Double]? {
        get { return fontSize }
        set { fontSize = newValue }
    }
      
    public var isFontBoldArray: [Bool]? {
        get { return isFontBold }
        set { isFontBold = newValue }
    }
      
    public var lineSpacingArray: [Double]? {
        get { return lineSpacing }
        set { lineSpacing = newValue }
    }
      
    
}
