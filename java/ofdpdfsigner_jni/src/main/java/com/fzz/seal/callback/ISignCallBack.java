package com.fzz.seal.callback;

public interface ISignCallBack {
    public byte[] sign(byte[] srcdata);
    public byte[] getUserCert();
    public byte[] getSealCert();
}
