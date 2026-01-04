//
//  EncryptData.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/3.
//

import Foundation

public class EncryptData {
    
    
    private var encryptData : Data? = nil
    private var macData : Data? = nil

    public init() {
    }
  
    public func getEncryptData() -> Data? {
        return encryptData
    }
    
    public func getMacData() -> Data? {
        return macData
    }
  
    public func setEncryptData(_ encryptData: Data) {
        self.encryptData = encryptData
    }
    
    public func setMacData(_ macData: Data) {
        self.macData = macData
    }
}
