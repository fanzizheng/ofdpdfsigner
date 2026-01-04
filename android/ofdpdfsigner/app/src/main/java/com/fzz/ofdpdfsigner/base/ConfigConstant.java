package com.fzz.ofdpdfsigner.base;

public class ConfigConstant {
    public static final int ONBACKPRESSED = 2;
    public static final int GOTOSTART = 1;//返回首页

    public static String ROOTDIR = "/com.fzz.ofdpdfsigner";
    public static String CACHEDIR = null;
    public static final String LOGFILENAME = "com.fzz.ofdpdfsigner.log";
    public static String LOGFILEPATH() { return CACHEDIR + ROOTDIR + "/log/"; }



}
