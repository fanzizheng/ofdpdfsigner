package com.fzz.seal.callback;

public interface IEncryptCallBack {
    public byte[] generateRandom(long len);
    public byte[] encryptSM4CBC(byte[] key,byte[] iv,byte[] sourceData);
    public byte[] decryptSM4CBC(byte[] key,byte[] iv,byte[] encryptData);
    public byte[] encryptSM2(byte[] publicKey,byte[] sourceData);
    public byte[] decryptSM2(byte[] encryptData);
}
