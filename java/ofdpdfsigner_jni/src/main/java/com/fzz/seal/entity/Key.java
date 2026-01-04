package com.fzz.seal.entity;

public class Key {
    public static final String SM2_PRV_KEY = "SM2_Private";
    public static final String SM2_PUB_KEY = "SM2_Public";
    public static final String SM4 = "SM4";


    private String keyType;
    private byte[] key;

    public Key(String keyType, byte[] key) {
        this.keyType = keyType;
        this.key = key;
    }

    public Key() {

    }

    public byte[] getKey() {
        return key;
    }

    public String getKeyType() {
        return keyType;
    }

    public void setKeyType(String keyType) {
        this.keyType = keyType;
    }

    public void setKey(byte[] key) {
        this.key = new byte[key.length];
        System.arraycopy(key,0,this.key,0,key.length);
    }


}
