package com.fzz.seal;

import com.fzz.seal.entity.PageSize;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class PDF {

    /*
     打开PDF文件
     fileData：PDF 文件数据
     返回：文件句柄
     */
    public static long open(byte[] fileData)
    {
        long ret = 0;
        if ( fileData == null || fileData.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.openPDF(fileData,returnData);

        ret = returnData.getErrorCode();
        return ret;
    }

    /*
     关闭PDF文件
     handle：文件句柄
     返回：无
     */
    public static void close(long handle)
    {
        if ( handle == 0 ) {
            return ;
        }
        IJNI.closePDF(handle);
    }

    /*
     获得PDF文件的页面宽高
     handle：文件句柄
     pageNumber: 页码
     返回：PageSize 页面的宽高
     */
    public static PageSize getPdfPageSize(long fileHandle, int pageNumber)
    {
        PageSize pageSize = new PageSize();
        if ( fileHandle == 0 ) {
            return pageSize;
        }
        ReturnData returnData = new ReturnData();
        IJNI.getPDFPageSize_Handle(fileHandle,pageNumber,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null && returnData.getResultData1() != null ) {
            String strWidth = new String(returnData.getResultData());
            String strHeight = new String(returnData.getResultData1());

            pageSize.setWidth(Double.valueOf(strWidth).doubleValue());
            pageSize.setHeight(Double.valueOf(strHeight).doubleValue());
        }

        return pageSize;
    }

    /*
     获得OFD文件的总页数
     fileHandle：ofd文件句柄
     返回：OFD文件的总页数
     */
    public static long getPdfPageCount(long fileHandle)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.getPDFPageCount_Handle(fileHandle,returnData);
        if ( returnData.getErrorCode()  >= 0 ) {
            ret = returnData.getErrorCode();
        }
        return ret;
    }
    /*
     PDF文档是否需要密码打开文档
     fileHandle：ofd文件句柄
     返回：-1：fileHandle错误； 0：不需要密码 ； 1： 需要密码
     */
    public static long isNeedPassword(long fileHandle)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return -1;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFIsEncryptPassward(fileHandle,returnData);
        long err = returnData.getErrorCode();
        if ( err == 0 ) {
            ret = 1;
        } else if ( err == 0xFFF304 ) {
            ret = 0;
        } else {
            ret = -1;
        }
        return ret;
    }
    /*
     PDF文档设置密码
     fileHandle：ofd文件句柄
     Password：密码
     返回：0：成功； 非0 失败
     */
    public static long setPassword(long fileHandle,String Password)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return -1;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFSetPassword(fileHandle,Password.getBytes(StandardCharsets.UTF_8),returnData);
        ret = returnData.getErrorCode();
        return ret;
    }

    /*
     PDF文档加密（密码加密或直接加密文档）/解密
     注意：isEncrypt为false 并 password = “”，这时为输出为明文文档
     fileHandle：pdf文件句柄
     isEncrypt：是否加密
     password：密码
     返回：加密文档/明文文档
     */
    public static byte[] documnetEncryptDecrypt(long fileHandle,boolean isEncrypt,String password)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.PDFEncryptDecrypt(fileHandle,isEncrypt?1:0,password.getBytes(StandardCharsets.UTF_8),returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

}
