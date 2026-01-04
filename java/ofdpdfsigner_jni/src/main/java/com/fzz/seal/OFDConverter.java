package com.fzz.seal;

import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class OFDConverter {
//    /*
//     获得OFD文件的总页数
//     ofdData：ofd文件数据
//     返回：OFD文件的总页数
//     */
//    public static long getOFDPageCount(byte[] ofdData)
//    {
//        long ret = 0;
//        if ( ofdData == null || ofdData.length <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        IJNI.getOFDPageCount(ofdData,returnData);
//        if ( returnData.getErrorCode()  >= 0 ) {
//            ret = returnData.getErrorCode();
//        }
//        return ret;
//    }


    /*
     ofd转换图片
     ofdData：ofd文件数据
     imageType: 转换后的图片类型 "PNG","JPG","SVG"
     pageIndex：要转换的ofd文件的页码
     返回：OFD图片
     */
//    public static byte[] ofdPage2Image(byte[] ofdData,String imageType,int pageIndex)
//    {
//        byte[] ret = null;
//        if ( ofdData == null || ofdData.length <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        int type = 0;
//        if ( imageType.equals("PNG") ) {
//            type = 0;
//        } else if ( imageType.equals("JPG") ) {
//            type = 1;
//        } else if ( imageType.equals("SVG") ) {
//            type = 2;
//        }
//        IJNI.ofdPage2Image(ofdData,type,pageIndex,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }

    /*
     ofd转换图片
     ofdData：ofd文件数据
     imageType: 转换后的图片类型 "PNG","JPG","SVG"
     pageIndex：要转换的ofd文件的页码
     返回：OFD图片
     */
    public static byte[] ofdPage2Image(long fileHandle,String imageFormat,int pageNumber,double scale)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        int type = 0;
        if ( imageFormat.equals("PNG") ) {
            type = 0;
        } else if ( imageFormat.equals("JPG") ) {
            type = 1;
        } else if ( imageFormat.equals("SVG") ) {
            type = 2;
        } else {
            return ret;
        }
        IJNI.ofdPage2Image_Handle(fileHandle,type,pageNumber,scale,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     ofd转换图片
     ofdData：ofd文件数据
     imageType: 转换后的图片类型 "PNG","JPG","SVG"
     返回：OFD图片数组
     */
//    public static byte[][] ofd2Image(byte[] ofdData,String imageType)
//    {
//        byte[][] ret = null;
//        if ( ofdData == null || ofdData.length <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//        int type = 0;
//        if ( imageType.equals("PNG") ) {
//            type = 0;
//        } else if ( imageType.equals("JPG") ) {
//            type = 1;
//        } else if ( imageType.equals("SVG") ) {
//            type = 2;
//        }
//        IJNI.ofd2Image(ofdData,type,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null && returnData.getResultData1() != null ) {
//            String imageslen = new String(returnData.getResultData1());
//            String imglen[] = imageslen.split(",");
//            ret = new byte[imglen.length][];
//            byte[] imagedata = returnData.getResultData();
//            int pos = 0;
//            for ( int i = 0; i < imglen.length; i++ ) {
//                int templen = Integer.valueOf(imglen[i]).intValue();
//                ret[i] = new byte[templen];
//                System.arraycopy(imagedata,pos,ret[i],0,templen);
//                pos += templen;
//            }
//        }
//        return ret;
//    }

    /*
     ofd转换图片
     ofdData：ofd文件数据
     imageType: 转换后的图片类型 "PNG","JPG","SVG"
     返回：OFD图片数组
     */
    public static byte[][] ofd2Image(long fileHandle,String imageFormat,double scale)
    {
        byte[][] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        int type = 0;
        if ( imageFormat.equals("PNG") ) {
            type = 0;
        } else if ( imageFormat.equals("JPG") ) {
            type = 1;
        } else if ( imageFormat.equals("SVG") ) {
            type = 2;
        } else {
            return ret;
        }
        IJNI.ofd2Image_Handle(fileHandle,type,scale,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null && returnData.getResultData1() != null ) {
            String imageslen = new String(returnData.getResultData1());
            String imglen[] = imageslen.split(",");
            ret = new byte[imglen.length][];
            byte[] imagedata = returnData.getResultData();
            int pos = 0;
            for ( int i = 0; i < imglen.length; i++ ) {
                int templen = Integer.valueOf(imglen[i]).intValue();
                ret[i] = new byte[templen];
                System.arraycopy(imagedata,pos,ret[i],0,templen);
                pos += templen;
            }
        }
        return ret;
    }
    /*
     ofd转换图片
     ofdData：ofd文件数据
     imageType: 转换后的图片类型 "PNG","JPG","SVG"
     返回：OFD图片zip
     */
//    public static byte[] ofd2ImageToZip(byte[] ofdData,String imageType)
//    {
//        byte[] ret = null;
//        if ( ofdData == null || ofdData.length <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//        int type = 0;
//        if ( imageType.equals("PNG") ) {
//            type = 0;
//        } else if ( imageType.equals("JPG") ) {
//            type = 1;
//        } else if ( imageType.equals("SVG") ) {
//            type = 2;
//        }
//        //System.out.println("src ofd len : "+ofdData.length);
//        IJNI.ofd2ImageToZip(ofdData,type,returnData);
//        //System.out.println("run JNIOFD2ImageToZip end.");
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            //System.out.println("zip len : "+temp.length);
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }

    /*
         ofd转换图片
         ofdData：ofd文件数据
         imageType: 转换后的图片类型 "PNG","JPG","SVG"
         返回：OFD图片zip
         */
    public static byte[] ofd2ImageZip(long fileHandle,String imageFormat,double scale)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        int type = 0;
        if ( imageFormat.equals("PNG") ) {
            type = 0;
        } else if ( imageFormat.equals("JPG") ) {
            type = 1;
        } else if ( imageFormat.equals("SVG") ) {
            type = 2;
        } else {
            return ret;
        }
        //System.out.println("src ofd len : "+ofdData.length);
        IJNI.ofd2ImageToZip_Handle(fileHandle,type,scale,returnData);
        //System.out.println("run JNIOFD2ImageToZip end.");
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("zip len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
    /*
     OFD转换PDF
     ofdData：ofd文件数据
     isNoStamp: true : 不含印章， false ： 包含印章
     返回：pdf
     */
//    public static byte[] ofd2PDF(byte[] ofdData,boolean isNoStamp)
//    {
//        byte[] ret = null;
//        if ( ofdData == null || ofdData.length <= 0 ) {
//            return ret;
//        }
//        ReturnData returnData = new ReturnData();
//
//
//        //System.out.println("src ofd len : "+ofdData.length);
//        IJNI.ofd2PDF(ofdData,isNoStamp?1:0,returnData);
//
//        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
//            byte[] temp = returnData.getResultData();
//            //System.out.println("ofd len : "+temp.length);
//            ret = new byte[temp.length];
//            System.arraycopy(temp,0,ret,0,temp.length);
//        }
//        return ret;
//    }

    /*
     OFD转换PDF
     ofdData：ofd文件数据
     isIncludeStamp: true : 含印章， false ： 不包含印章
     返回：pdf
     */
    public static byte[] ofd2Pdf(long fileHandle,boolean isIncludeStamp,boolean isEncrypt,String passWord)
    {
        byte[] ret = null;
        if ( fileHandle == 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();


        //System.out.println("src ofd len : "+ofdData.length);
        IJNI.ofd2PDF_Handle(fileHandle,!isIncludeStamp?1:0,isEncrypt?1:0,passWord.getBytes(StandardCharsets.UTF_8),returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            //System.out.println("ofd len : "+temp.length);
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }
}
