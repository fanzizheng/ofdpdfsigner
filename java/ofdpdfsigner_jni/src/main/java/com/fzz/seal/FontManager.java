package com.fzz.seal;

import com.fzz.seal.callback.ISystemFontFileNameCallBack;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class FontManager {
    /*
     获取印章系统的全部字体文件
     systemFontFileNameCallBack：回调函数，获取到的字体文件全路径
     返回：是否成功
     */
    public static boolean getAllSystemFontFileName(ISystemFontFileNameCallBack systemFontFileNameCallBack)
    {
        boolean ret = false;
        if ( systemFontFileNameCallBack == null ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.GetAllSystemFontFileName(systemFontFileNameCallBack,returnData);

        if ( returnData.getErrorCode() == 0  ) {
            ret = true;
        }
        return ret;
    }

    /*
     加入字体到缓存
     fontFileName：字体文件全路径
     返回：是否成功
     */
    public static boolean saveFontFileNameCache(String fontFileName)
    {
        boolean ret = false;
        if ( fontFileName == null || fontFileName.length() <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();

        IJNI.saveFontFileNameCache(fontFileName.getBytes(StandardCharsets.UTF_8),returnData);

        if ( returnData.getErrorCode() == 0  ) {
            ret = true;
        }
        return ret;
    }

}
