package com.fzz.seal.callback;

public interface IVerifyCallBack {
    public boolean verify(int algType,byte[] keyData,byte[] sourceData,byte[] signdata);
}
