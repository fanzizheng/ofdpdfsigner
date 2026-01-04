package com.fzz.seal;

import com.fzz.seal.callback.ISignCallBack;
import com.fzz.seal.callback.IVerifyCallBack;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class OFDStamp {

    public static final int RIDING_LEFT = 0;
    public static final int RIDING_RIGHT = 1;
    public static final int RIDING_TOP = 2;
    public static final int RIDING_BOTTOM = 3;
    public static final int RIDING_CUTTING_RIGHT = 4;
    public static final int RIDING_CUTTING_TOP = 5;
    /*
     OFD 位置盖章
     stampData：印章数据
     ofdData：OFD数据
     pageIndex：页码 0开始
     x：开始位置
     y：开始位置
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_Pos(byte[] stampData,byte[] ofdData, int pageIndex,double x,double y,
//                                          double stampwidth, double stampheight,boolean isContinueSign,
//                                          ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( stampData == null || stampData.length <= 0 || ofdData == null || ofdData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0 || pageIndex < 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.OFDSignStamp_Pos(stampData, ofdData,  pageIndex, x, y,stampwidth,  stampheight, isContinueSign,signCallBack,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            //System.out.println("zip len : "+temp.length);
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }
    /*
     OFD 位置盖章
     stampData：印章数据
     ofdData：OFD数据
     pageIndex：页码 0开始
     x：开始位置
     y：开始位置
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] positionSign(long fileHandle,byte[] sealData, int pageNumber,double stampX,double stampY,
                                       double width, double height,boolean isLocked,
                                       ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealData == null || sealData.length <= 0 || fileHandle == 0 ||
                width < 0 || width < 0 || pageNumber <= -2 || pageNumber == 0) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDSignStamp_Pos_Handle(fileHandle,sealData,  pageNumber, stampX, stampY,width,  height, !isLocked,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     OFD文件骑缝章签章
     stampData：印章数据
     ofdData：OFD数据
     RidingType：骑缝章类型
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_Riding(byte[] stampData,byte[] ofdData, int RidingType,
//                                          double stampwidth, double stampheight,boolean isContinueSign,ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( stampData == null || stampData.length <= 0 || ofdData == null || ofdData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0  ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.OFDSignStamp_Riding(stampData, ofdData, RidingType,stampwidth,  stampheight,isContinueSign,signCallBack,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            //System.out.println("zip len : "+temp.length);
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }
    /*
     OFD文件骑缝章签章
     stampData：印章数据
     ofdData：OFD数据
     RidingType：骑缝章类型
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] ridingSign(long fileHandle,byte[] sealData, String ridingType,
                                          double width, double height,boolean isLocked,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealData == null || sealData.length <= 0 || fileHandle == 0 ||
                width < 0 || height < 0  ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        int iType = Integer.parseInt(ridingType);

        IJNI.OFDSignStamp_Riding_Handle(fileHandle,sealData, iType,width,  height,!isLocked,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     OFD文件关键字签章
     imageData：印章数据
     ofdData：OFD数据
     keyword：关键字
     KeywordRule：关键字规则
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_KeyWord(byte[] stampData, byte[] ofdData, String keyword,String KeywordRule,
//                                           double stampwidth, double stampheight,boolean isContinueSign,ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( stampData == null || stampData.length <= 0 || ofdData == null || ofdData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0 || keyword == null || keyword.length() <= 0
//                || KeywordRule == null || KeywordRule.length() <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.OFDSignStamp_KeyWord(stampData, ofdData,  keyword.getBytes(StandardCharsets.UTF_8), KeywordRule.getBytes(StandardCharsets.UTF_8), stampwidth,  stampheight,isContinueSign,signCallBack,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            //System.out.println("zip len : "+temp.length);
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }

    /*
     OFD文件关键字签章
     imageData：印章数据
     ofdData：OFD数据
     keyword：关键字
     KeywordRule：关键字规则
     stampwidth：印章宽
     stampheight: 印章高
     isContinueSign：是否继续盖章
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] keywordSign(long fileHandle,byte[] sealData, String keyword,String KeywordRule,
                                           double width, double height,boolean isLocked,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealData == null || sealData.length <= 0 || fileHandle == 0 ||
                width < 0 || height < 0 || keyword == null || keyword.length() <= 0
                || KeywordRule == null || KeywordRule.length() <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDSignStamp_KeyWord_Handle(fileHandle,sealData,  keyword.getBytes(StandardCharsets.UTF_8), KeywordRule.getBytes(StandardCharsets.UTF_8), width,  height,!isLocked,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     OFD 文档验证
     docdata：OFD数据
     IVerifyCallBack：验证回调
     返回：验证结果，json数据
     */
    public static String verify(byte[] fileData, IVerifyCallBack verifyCallBack)
    {
        String ret = "";
        if ( fileData == null || fileData.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDVerifyDocment(fileData,verifyCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new String(temp);
        }
        return ret;
    }

    /*
     OFD 删除文档中全部签名数据
     fileHandle：OFD 文档句柄
     返回：删除后文档数据
     */
    public static byte[] clearSigns(long fileHandle)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDClearStamps(fileHandle,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
}
