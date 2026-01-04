package com.fzz.seal;

import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class SystemMamager {
    /*
     设置工作路径
     workPath：工作路径
     返回：是否成功
     */
    public static boolean setWorkPath(String filePath)
    {
        boolean ret = false;
        if ( filePath == null || filePath.length() <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.SetWorkPath(filePath.getBytes(StandardCharsets.UTF_8),returnData);
        if ( returnData.getErrorCode() == 0  ) {
            ret = true;
        }
        return ret;
    }

    /*
     设置临时路径
     workPath：临时路径
     返回：是否成功
     */
    public static boolean setTempPath(String filePath)
    {
        boolean ret = false;
        if ( filePath == null || filePath.length() <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.SetTempPath(filePath.getBytes(StandardCharsets.UTF_8),returnData);
        if ( returnData.getErrorCode() == 0  ) {
            ret = true;
        }
        return ret;
    }
}
