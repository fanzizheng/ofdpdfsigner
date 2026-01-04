//
//  KeyPair.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/5/31.
//

import Foundation

public class KeyPair {
    
    private var pubKey: Key?
    private var prvKey: Key?
  
    init() {
        
    }
  
    public func getPublicKey() -> Key? {
        return pubKey
    }
  
    public func getPrivateKey() -> Key? {
        return prvKey
    }
    
    func setPublicKey(_ key:Key) {
        self.pubKey = key
    }
  
    func setPrivateKey(_ key:Key) {
        self.prvKey = key
    }
}
