//
//  WaterMarkImage.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/11.
//

import Foundation

public class WaterMarkImage {
    
    private var image: Data? = nil
    private var width: Double = 0.0
    private var height: Double = 0.0
  
    
    public var imageData: Data? {
        get {
            return image
        }
        set {
            image = newValue
        }
    }
  
    public var imageWidth: Double {
        get {
            return width
        }
        set {
            width = newValue
        }
    }
  
    public var imageHeight: Double {
        get {
            return height
        }
        set {
            height = newValue
        }
    }
  
    
    public init() {
        
    }
  
   
}
