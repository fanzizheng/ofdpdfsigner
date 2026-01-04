//
//  Key.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/31.
//

import Foundation



public class Key {
    
    public static let SM2_PRV_KEY : String = "SM2_Private"
    public static let SM2_PUB_KEY : String = "SM2_Public"
    public static let SM4 : String = "SM4"
    
    private var keyType : String = ""
    private var key : Data? = nil

    public init(keyType: String, key: Data) {
        self.keyType = keyType
        self.key = key
    }
  
    public init() {
    }
  
    public func getKey() -> Data? {
        return key
    }
  
    public func getKeyType() -> String? {
        return keyType
    }
  
    public func setKeyType(_ keyType: String) {
        self.keyType = keyType
    }
  
    public func setKey(_ key: Data) {
        self.key = key 
    }
}
