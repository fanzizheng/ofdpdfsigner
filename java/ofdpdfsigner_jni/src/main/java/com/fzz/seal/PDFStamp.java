package com.fzz.seal;

import com.fzz.seal.callback.ISignCallBack;
import com.fzz.seal.callback.IVerifyCallBack;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class PDFStamp {
    public static final int RIDING_LEFT = 0;
    public static final int RIDING_RIGHT = 1;
    public static final int RIDING_TOP = 2;
    public static final int RIDING_BOTTOM = 3;
    public static final int RIDING_CUTTING_RIGHT = 4;
    public static final int RIDING_CUTTING_TOP = 5;
    /*
     PDF 位置盖章
     imageData：印章数据
     pdfData：PDF数据
     pageIndex：页码 0开始
     x：开始位置
     y：开始位置
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_Pos(byte[] imageData,byte[] pdfData,double alpha, int pageIndex,double x,double y,
//                                       double stampwidth, double stampheight,
//                                       ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( imageData == null || imageData.length <= 0 || pdfData == null || pdfData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0 || pageIndex < 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.PDFSignStamp_Pos(imageData, pdfData, alpha, pageIndex, x, y,stampwidth,  stampheight,signCallBack,returnData);
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
     PDF 位置盖章
     imageData：印章数据
     pdfData：PDF数据
     pageIndex：页码 0开始
     x：开始位置
     y：开始位置
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] positionSign(long fileHandle,byte[] sealImageData,double sealAlpha, int pageNumber,double stampX,double stampY,
                                       double width, double height,boolean isLocked,
                                       ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealImageData == null || sealImageData.length <= 0 || fileHandle == 0 ||
                width < 0 || height < 0 || pageNumber == 0  || pageNumber < -1 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFSignStamp_Pos_Handle(fileHandle,sealImageData, sealAlpha, pageNumber, stampX, stampY,width,  height,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("positionSign len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        } else {
            //System.out.println("positionSign error:"+returnData.getErrorCode());
        }
        return ret;
    }
    /*
     PDF文件骑缝章签章
     imageData：印章数据
     pdfData：PDF数据
     RidingType：骑缝章类型
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_Riding(byte[] imageData,byte[] pdfData,double alpha, int RidingType,
//                                              double stampwidth, double stampheight,ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( imageData == null || imageData.length <= 0 || pdfData == null || pdfData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0  ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.PDFSignStamp_Riding(imageData, pdfData, alpha,RidingType,stampwidth,  stampheight,signCallBack,returnData);
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
     PDF文件骑缝章签章
     imageData：印章数据
     pdfData：PDF数据
     RidingType：骑缝章类型
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] ridingSign(long fileHandle,byte[] sealImageData,double sealAlpha, String ridingType,
                                          double width, double height,boolean isLocked,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealImageData == null || sealImageData.length <= 0 || fileHandle == 0 ||
                width < 0 || height < 0  ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        int iType = Integer.parseInt(ridingType);

        IJNI.PDFSignStamp_Riding_Handle(fileHandle,sealImageData, sealAlpha,iType,width,  height,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     PDF文件关键字签章
     imageData：印章数据
     pdfData：PDF数据
     keyword：关键字
     KeywordRule：关键字规则
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
//    public static byte[] signStamp_KeyWord(byte[] imageData, byte[] pdfData, double alpha,String keyword,String KeywordRule,
//                                               double stampwidth, double stampheight,ISignCallBack signCallBack)
//    {
//        byte[] ret = null;
//        if ( imageData == null || imageData.length <= 0 || pdfData == null || pdfData.length <= 0 ||
//                stampwidth < 0 || stampheight < 0 || keyword == null || keyword.length() <= 0
//                || KeywordRule == null || KeywordRule.length() <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.PDFSignStamp_KeyWord(imageData, pdfData, alpha, keyword.getBytes(StandardCharsets.UTF_8), KeywordRule.getBytes(StandardCharsets.UTF_8), stampwidth,  stampheight,signCallBack,returnData);
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
     PDF文件关键字签章
     imageData：印章数据
     pdfData：PDF数据
     keyword：关键字
     KeywordRule：关键字规则
     stampwidth：印章宽
     stampheight: 印章高
     signCallBack：签名回调
     返回：电子印章数据
     */
    public static byte[] keywordSign(long fileHandle,byte[] sealImageData, double sealAlpha,String keyWord,String keyWordRules,
                                           double width, double height,boolean isLocked,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if ( sealImageData == null || sealImageData.length <= 0 || fileHandle == 0 ||
                width < 0 || height < 0 || keyWord == null || keyWord.length() <= 0
                || keyWordRules == null || keyWordRules.length() <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFSignStamp_KeyWord_Handle(fileHandle,sealImageData, sealAlpha, keyWord.getBytes(StandardCharsets.UTF_8), keyWordRules.getBytes(StandardCharsets.UTF_8), width,  height,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     PDF 文档验证
     fileData：PDF数据
     passWord: 密码； "" 或 非""
     IVerifyCallBack：验证回调
     返回：验证结果，json数据
     */
    public static String verify(byte[] fileData, String passWord, IVerifyCallBack verifyCallBack)
    {
        String ret = "";
        if ( fileData == null || fileData.length <= 0 ) {
            return ret;
        }

        if ( passWord == null ) {
            passWord = "";
        }

        ReturnData returnData = new ReturnData();

        IJNI.PDFVerifyDocment(fileData,passWord.getBytes(StandardCharsets.UTF_8),verifyCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new String(temp);
        }
        return ret;
    }

    /*
     PDF 删除文档中全部签名数据
     fileHandle：pdf 文档句柄
     返回：删除后文档数据
     */
    public static byte[] clearSigns(long fileHandle)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFClearStamps(fileHandle,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

}
