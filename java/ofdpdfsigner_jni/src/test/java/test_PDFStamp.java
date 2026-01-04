import com.fzz.seal.*;
import com.fzz.seal.callback.*;
import com.fzz.seal.entity.*;
import com.fzz.seal.utils.*;

import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;

//-Djava.library.path=/Users/zizhengfan/work/cpp/ofd/build/ofdcreate-dhssdygvturgepccmhnpnyoivmcu/Build/Products/Debug
public class test_PDFStamp {
    public static void main(String agrs[]) throws Exception {


        long currtime = System.currentTimeMillis();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");
//        SignStamp_WaterMark();
        //SignStamp_Pos_Handle();
        //verifyDoc();
        //SignStamp_Riding_Handle(String.valueOf(PDFStamp.RIDING_LEFT));
        //verifyDoc();
        //SignStamp_Riding_Handle(String.valueOf(PDFStamp.RIDING_CUTTING_RIGHT));
//        verifyDoc();

//        SignStamp_Pos();
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_LEFT);
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_RIGHT);
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_TOP);
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_BOTTOM);
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_CUTTING_RIGHT);
//        verifyDoc();
//        SignStamp_Riding(PDFStamp.RIDING_CUTTING_TOP);
//        verifyDoc();
        String KeywordRule = "[" +
                "{" +
                "\"pageNumber\":1," +
                "\"indexRules\":[" +
                "{" +
                "\"index\":1," +
                "\"offsetX\":10," +
                "\"offsetY\":20" +
                "}," +
                "{" +
                "\"index\":2," +
                "\"offsetX\":10," +
                "\"offsetY\":20" +
                "}" +
                "]" +
                "}," +
                "{" +
                "\"pageNumber\":5," +
                "\"indexRules\":[" +
                "{" +
                "\"index\":-1," +
                "\"offsetX\":10," +
                "\"offsetY\":20" +
                "}" +

                "]" +
                "}" +
                "]" ;

        //SignStamp_KeyWord_Handle("资治",KeywordRule);
        //verifyDoc();

        ClearSigns();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

    public static void SignStamp_Pos_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] imagedata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/seal.png");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
        byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_pw.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_enc.pdf");
        long handle = PDF.open(pdf);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] SignPDFData = PDFStamp.positionSign(handle,imagedata,0.86,1,100, 50, 42, 42,false,new ISignCallBack() {
                @Override
                public byte[] sign(byte[] srcdata)
                {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY,userpri);
                        byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
                        return signdata;
                        //return null;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getUserCert()
                {
                    try {
                        return userCert;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getSealCert()
                {
                    return null;
                }

            });

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);

            System.out.println("签pdf文件成功！");
            PDF.close(handle);
        }
    }

    public static void SignStamp_Riding_Handle(String RidingType) throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] imagedata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/seal.png");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/flow-test_1721722256100.pdf");
        byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_pw.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_enc.pdf");

        long handle = PDF.open(pdf);
        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] SignPDFData = PDFStamp.ridingSign(handle,imagedata,0.86,RidingType, 42, 42,false,new ISignCallBack() {
                @Override
                public byte[] sign(byte[] srcdata)
                {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY,userpri);
                        byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
                        return signdata;
                        //return null;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getUserCert()
                {
                    try {
                        return userCert;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getSealCert()
                {
                    return null;
                }

            });

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);

            System.out.println("签pdf文件成功！");
            PDF.close(handle);
        }
    }

    public static void SignStamp_KeyWord_Handle(String keyword,String KeywordRule) throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] imagedata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/seal.png");

        byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_pw.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/aaa1_enc.pdf");
        long handle = PDF.open(pdf);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] SignPDFData = PDFStamp.keywordSign(handle,imagedata,0.86,keyword,KeywordRule, 42, 42,false,new ISignCallBack() {
                @Override
                public byte[] sign(byte[] srcdata)
                {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY,userpri);
                        byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
                        return signdata;
                        //return null;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getUserCert()
                {
                    try {
                        return userCert;
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] getSealCert()
                {
                    return null;
                }

            });

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);

            System.out.println("签pdf文件成功！");
            PDF.close(handle);
        }
    }



//    public static void SignStamp_Pos() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
//        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.png");
//        byte[] pdf = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
//
//        byte[] SignPDFData = PDFStamp.signStamp_Pos(imagedata,pdf,0.86,1,100, 50, 42, 42,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
//                    //return null;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getUserCert()
//            {
//                try {
//                    return userCert;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getSealCert()
//            {
//                return null;
//            }
//
//        });
//
//        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);
//
//        System.out.println("签pdf文件成功！");
//    }

//    public static void SignStamp_Riding(int RidingType) throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
//        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.png");
//        byte[] pdf = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
//
//        byte[] SignPDFData = PDFStamp.signStamp_Riding(imagedata,pdf,0.86,RidingType, 42, 42,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
//                    //return null;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getUserCert()
//            {
//                try {
//                    return userCert;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getSealCert()
//            {
//                return null;
//            }
//
//        });
//
//        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);
//
//        System.out.println("签pdf文件成功！");
//    }
//
//    public static void SignStamp_KeyWord(String keyword,String KeywordRule) throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
//        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.png");
//        byte[] pdf = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
//
//        byte[] SignPDFData = PDFStamp.signStamp_KeyWord(imagedata,pdf,0.86,keyword,KeywordRule, 42, 42,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
//                    //return null;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getUserCert()
//            {
//                try {
//                    return userCert;
//                } catch (Exception e) {
//                    return null;
//                }
//            }
//            @Override
//            public byte[] getSealCert()
//            {
//                return null;
//            }
//
//        });
//
//        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);
//
//        System.out.println("签pdf文件成功！");
//    }

    public static void verifyDoc() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] docdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf");
        String ret = "";
        long handle = PDF.open(docdata);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            ret = PDFStamp.verify(docdata, "12345678",new IVerifyCallBack() {
                @Override
                public boolean verify(int algType, byte[] key, byte[] srcdata, byte[] signdata) {
                    try {
                        Key pubkey = new Key(Key.SM2_PUB_KEY, key);
                        return Crypto.verify(Crypto.SM3_SM2, pubkey, srcdata, signdata);
                        //return false;
                    } catch (Exception e) {
                        return false;
                    }
                }
            });
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        } else {

            ret = PDFStamp.verify(docdata, "", new IVerifyCallBack() {
                @Override
                public boolean verify(int algType, byte[] key, byte[] srcdata, byte[] signdata) {
                    try {
                        Key pubkey = new Key(Key.SM2_PUB_KEY, key);
                        return Crypto.verify(Crypto.SM3_SM2, pubkey, srcdata, signdata);
                        //return false;
                    } catch (Exception e) {
                        return false;
                    }
                }
            });
        }
        System.out.println("验证文档结果：" + ret);
    }

    public static void SignStamp_WaterMark() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");

        byte[] pdf = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/aaa1.pdf");
        long handle = PDF.open(pdf);
        PageSize pageSize_old = new PageSize();
        WaterMarkImage imagedata = null;
        byte[] SignPDFData = null;
        if ( handle != 0 ) {
            long pageCount = PDF.getPdfPageCount(handle);
            double showWidth = 0;
            double showHeight = 0;
            for ( int i = 1; i <= pageCount; i++ ) {
                PageSize pageSize = PDF.getPdfPageSize(handle, 1);
                if ( pageSize.getWidth() != pageSize_old.getWidth() || pageSize.getHeight() != pageSize_old.getHeight() ) {
                    pageSize_old.setWidth(pageSize.getWidth());
                    pageSize_old.setHeight(pageSize.getHeight());

                    String Text[] = {"附件多少积分多少","房价多少","而扼腕发货的"};
                    String TextFontName[] = {"楷体","黑体","楷体"};
                    double FontSize[] = {24,18,16};
                    boolean isBlob[] = {false,false,false};
                    boolean isI[] = {false,false,false};
                    double R[] = {154,153,62};
                    double G[] = {124,64,78};
                    double B[] = {63,92,155};
                    double A[] = {150,150,150};
                    double LineSpacing[] = {8,8};


//
//
//                    imagedata = WaterMark.createWaterMark(true,pageSize.getWidth(),pageSize.getHeight(),0,0,1,40.f,40.f,Text,
//                            TextFontName,FontSize,isBlob,isI,R,G,B,A,8,8,-30,2);

                    Color[] color = {new Color(154,124,63,150),new Color(153,64,92,150),new Color(62,78,155,150)};
                    TextParams textParams = new TextParams();
                    textParams.setText(Text);
                    textParams.setFont(TextFontName);
                    textParams.setFontSize(FontSize);
                    textParams.setIsFontBold(isBlob);
                    textParams.setLineSpacing(LineSpacing);
                    textParams.setTextAlign("left");
                    textParams.setColor(color);

                    imagedata = WaterMark.createWaterMark(-22,2,false,null,textParams);
                    showWidth = imagedata.getWidth();
                    showHeight = imagedata.getHeight();

//                    byte[] tempImage = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/image_8.bmp");
//                    imagedata = WaterMark.createWaterMark(-22,0,true,tempImage,null);
//                    fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/image_"+i+".png",imagedata.getImage());
//
//                    showWidth = (pageSize.getWidth() * 25.4f) / 72;
//                    showHeight = (pageSize.getHeight() * 25.4f) / 72;
                }

                if ( imagedata != null && imagedata.getImage().length > 10 ) {
                    double pageWidth = (pageSize.getWidth() * 25.4f) / 72;
                    double pageHeight = (pageSize.getHeight() * 25.4f) / 72;
                    SignPDFData = PDFStamp.positionSign(handle,imagedata.getImage(),0.86,i,0, 0, showWidth, showHeight,false,new ISignCallBack() {
                        @Override
                        public byte[] sign(byte[] srcdata)
                        {
                            try {
                                Key key = new Key(Key.SM2_PRV_KEY,userpri);
                                byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
                                return signdata;
                                //return null;
                            } catch (Exception e) {
                                return null;
                            }
                        }
                        @Override
                        public byte[] getUserCert()
                        {
                            try {
                                return userCert;
                            } catch (Exception e) {
                                return null;
                            }
                        }
                        @Override
                        public byte[] getSealCert()
                        {
                            return null;
                        }

                    });
                }
            }

            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf",SignPDFData);

            System.out.println("签pdf文件成功！");
            PDF.close(handle);
        }
    }


    public static void ClearSigns() throws Exception
    {
        FileOP fileOP = new FileOP();
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign.pdf");
        byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_enc.pdf");
        //byte[] pdf = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_pw.pdf");
        long handle = PDF.open(pdf);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] SignPDFData = PDFStamp.clearSigns(handle);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign_clear.pdf",SignPDFData);

            System.out.println("签pdf文件成功！");
            PDF.close(handle);
        }
    }
}
