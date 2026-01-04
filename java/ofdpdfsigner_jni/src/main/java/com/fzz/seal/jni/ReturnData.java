package com.fzz.seal.jni;

public class ReturnData {

    private long errorCode;
    private byte[] errorDescription;
    private byte[] resultData;
    private byte[] resultData1;
    private byte[] resultData2;

    public long getErrorCode() {
        return errorCode;
    }

    public String getErrorDescription() {
        return new String(errorDescription);
    }

    public byte[] getResultData() {
        return resultData;
    }

    public byte[] getResultData1() {
        return resultData1;
    }

    public byte[] getResultData2() {
        return resultData2;
    }
}
