package com.fzz.seal;

import com.fzz.seal.callback.IEncryptCallBack;
import com.fzz.seal.callback.ISignCallBack;
import com.fzz.seal.callback.IVerifyCallBack;
import com.fzz.seal.entity.PageSize;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class OFD {
    /*
     打开OFD文件
     fileData：OFD 文件数据
     返回：文件句柄
     */
    public static long open(byte[] fileData)
    {
        long ret = 0;
        if ( fileData == null || fileData.length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.openOFD(fileData,returnData);

        ret = returnData.getErrorCode();
        return ret;
    }
    /*
     关闭OFD文件
     handle：文件句柄
     返回：无
     */
    public static void close(long handle)
    {
        if ( handle == 0 ) {
            return ;
        }
        IJNI.closeOFD(handle);
    }

    /*
     获得OFD文件的页面宽高
     handle：文件句柄
     pageNumber: 页码
     返回：PageSize 页面的宽高
     */
    public static PageSize getOfdPageSize(long fileHandle, int pageNumber)
    {
        PageSize pageSize = new PageSize();
        if ( fileHandle == 0 ) {
            return pageSize;
        }
        ReturnData returnData = new ReturnData();
        IJNI.getOFDPageSize_Handle(fileHandle,pageNumber,returnData);

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
     ofdData：ofd文件数据
     返回：OFD文件的总页数
     */
    public static long getOfdPageCount(long fileHandle)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.getOFDPageCount_Handle(fileHandle,returnData);
        if ( returnData.getErrorCode()  >= 0 ) {
            ret = returnData.getErrorCode();
        }
        return ret;
    }

    /*
     OFD文档是否被完整性保护
     fileHandle：ofd文件句柄
     返回：-1：fileHandle错误； 0：没有被完整性保护 ； 1： 被完整性保护
     */
    public static long IsProtect(long fileHandle)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return -1;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDIsProtect(fileHandle,returnData);
        long err = returnData.getErrorCode();
        if ( err == 0 ) {
            ret = 1;
        } else if ( err == 0xFFF407 ) {
            ret = 0;
        } else {
            ret = -1;
        }
        return ret;
    }

    /*
     OFD 完整性保护
     fileHandle：ofd 文件句柄
     signCallBack：签名回调
     返回：ofd 完整性保护文档数据
     */
    public static byte[] protect(long fileHandle,ISignCallBack signCallBack)
    {
        byte[] ret = null;
        if (  fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDProtect_Handle(fileHandle,signCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     OFD 文档完整性验证
     fileHandle：ofd 文件句柄
     IVerifyCallBack：验证回调
     返回：验证结果，json数据,如果为""字符串，函数执行失败了
          {"verify":false,nothavefile:[]}
          1。验证签名失败 {"verify":false,nothavefile:[]}
          2。验证签名成功，但 文档的文件有增加或减少 {"verify":false,nothavefile:[]}
          3。验证签名成功，文档的文件个数相等，但文件名称不同 {"verify":false,nothavefile:[保护前缺少的文件名]}
            比如将 /doc_0/annots/page_0/annotation.xml 改名为 /doc_0/annots/page_0/annotation_1.xml
            nothavefile中的文件名为 /doc_0/annots/page_0/annotation.xml
     */
    public static String protectionVerify(long fileHandle, IVerifyCallBack verifyCallBack)
    {
        String ret = "";
        if (  fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDProtectionVerify_Handle(fileHandle,verifyCallBack,returnData);

        if ( returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new String(temp);
        }
        return ret;
    }

    /*
     OFD文档是否被加密
     fileHandle：ofd文件句柄
     返回：-1：fileHandle错误； 0：没有加密 ； 1： 加密
     */
    public static long IsEncrypt(long fileHandle)
    {
        long ret = 0;
        if ( fileHandle == 0 ) {
            return -1;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDIsEncrypt(fileHandle,returnData);
        long err = returnData.getErrorCode();
        if ( err == 0 ) {
            ret = 1;
        } else if ( err == 0xFFF406 ) {
            ret = 0;
        } else {
            ret = -1;
        }
        return ret;
    }

    /*
     OFD 加密文档
     fileHandle：ofd 文件句柄
     userInfo：用户信息json:[{mode:1,passWordCert:"12345678",userName:"user 1",userType:"User"},
     {mode:2,passWordCert:"证书base64",userName:"user 1",userType:"Owner"}]
               mode：1 密码，2 证书
               passWordCert：密码 或 证书base64
               userName：用户名
               userType：用户类型：User 普通用户；Owner 文档管理员；
     encryptCallBack：加解密回调
     返回：ofd 加密文档数据
     */
    public static byte[] encryptDocument(long fileHandle,String userInfo,IEncryptCallBack encryptCallBack)
    {
        byte[] ret = null;
        if (  fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDEncryptDocument_Handle(fileHandle,userInfo.getBytes(StandardCharsets.UTF_8),encryptCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     OFD 解密文档
     fileHandle：ofd 文件句柄
     mode：1 密码，2 证书
     password：密码 ，当 mode为1时 必填；当 mode为2时 空字符串 ""
     username：用户名
     usertype：用户类型：User 普通用户；Owner 文档管理员；
     encryptCallBack：加解密回调
     返回：ofd 完整性保护文档数据
     */
    public static byte[] decryptDocument(long fileHandle,int mode,String passWord,String userName,String userType,IEncryptCallBack encryptCallBack)
    {
        byte[] ret = null;
        if (  fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.OFDDecryptDocument_Handle(fileHandle,mode,passWord.getBytes(StandardCharsets.UTF_8),
                userName.getBytes(StandardCharsets.UTF_8),userType.getBytes(StandardCharsets.UTF_8),encryptCallBack,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
}
