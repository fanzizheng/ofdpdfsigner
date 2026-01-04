package com.fzz.seal.entity;

public class KeyPair {
    private com.fzz.seal.entity.Key pubKey;

    private com.fzz.seal.entity.Key prvKey;




    public KeyPair(com.fzz.seal.entity.Key pubKey, com.fzz.seal.entity.Key prvKey) {
        this.pubKey = pubKey;
        this.prvKey = prvKey;
    }


    public com.fzz.seal.entity.Key getPublicKey() {
        return pubKey;
    }


    public com.fzz.seal.entity.Key getPrivateKey() {
        return prvKey;
    }
}
