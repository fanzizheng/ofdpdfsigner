package com.fzz.seal;

import com.fzz.seal.callback.ISignCallBack;
import com.fzz.seal.callback.IVerifyCallBack;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;


public class SealManager {
    /*
     创建电子印章
     sealid：印章id
     sealname：印章名称
     startTime：开始时间
     days：有效天数
     imageType：印章图片类型
     imageData：印模数据
     ISignCallBack: 签名运算回调
     返回：电子印章数据
     */
    public static byte[] createSeal(String code,String type,String name,String format,byte[] image,int width,int height,String createTime,String startTime,String endTime, Object extend,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( code == null || code.length() <= 0 || name == null || name.length() <= 0 ||
                startTime == null || startTime.length() <= 0 || format == null || format.length() <= 0 || image == null || image.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        int iType = Integer.parseInt(type);

        IJNI.createSeal(code.getBytes(StandardCharsets.UTF_8),iType,name.getBytes(StandardCharsets.UTF_8),width,height,createTime.getBytes(StandardCharsets.UTF_8),startTime.getBytes(StandardCharsets.UTF_8), endTime.getBytes(StandardCharsets.UTF_8),format.getBytes(StandardCharsets.UTF_8),image,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     验证电子印章
     sealData：印章数据
     ISignCallBack: 签名运算回调
     返回：电子印章数据
     */
    public static long verifySeal(byte[] sealData, IVerifyCallBack verifyCallBack)
    {
        long ret = 0xFFFFFF;
        if ( sealData == null || sealData.length <= 0  ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.verifySeal(sealData,verifyCallBack,returnData);

        ret = returnData.getErrorCode();
        return ret;
    }
    /*
     获取电子印章中的印模数据
     sealData：印章数据
     返回：电子印章中的印模数据
     */
    public static byte[]  getSealImageData(byte[] sealData)
    {
        byte[] ret = null;
        if (  sealData == null || sealData.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.getSealImageData(sealData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     获取电子印章中的用户证书
     sealData：印章数据
     返回：电子印章用户证书
     */
    public static byte[]  getSealUserCertData(byte[] sealData)
    {
        byte[] ret = null;
        if (  sealData == null || sealData.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.getSealUserCertData(sealData,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
}
