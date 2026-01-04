
import com.fzz.seal.*;
import com.fzz.seal.callback.*;
import com.fzz.seal.entity.*;
import com.fzz.seal.utils.*;
import com.fzz.seal.*;

import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Date;

//-Djava.library.path=/Users/zizhengfan/work/cpp/ofd/build/ofdcreate-dhssdygvturgepccmhnpnyoivmcu/Build/Products/Debug
public class test_OFDStamp {
    public static void main(String agrs[]) throws Exception {



        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");
        long currtime = System.currentTimeMillis();
        //createSeal();
        //verifySeal();
//        getSealImageData();
//        getSealUserCertData();
        //Watermark_Handle();
        SignStamp_Pos_Handle();
        verifyDoc();
//        SignStamp_Riding_Handle(String.valueOf(OFDStamp.RIDING_LEFT));
//        verifyDoc();
//        SignStamp_Riding_Handle(String.valueOf(OFDStamp.RIDING_CUTTING_TOP));
//        verifyDoc();
//        SignStamp_Pos();
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_LEFT);
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_RIGHT);
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_TOP);
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_BOTTOM);
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_CUTTING_RIGHT);
//        verifyDoc();
//        SignStamp_Riding(OFDStamp.RIDING_CUTTING_TOP);
//        verifyDoc();
//        String KeywordRule = "[" +
//                    "{" +
//                        "\"pageNumber\":1," +
//                        "\"indexRules\":[" +
//                            "{" +
//                                "\"index\":1," +
//                                "\"offsetX\":10," +
//                                "\"offsetY\":20" +
//                            "}," +
//                            "{" +
//                                "\"index\":2," +
//                                "\"offsetX\":10," +
//                                "\"offsetY\":20" +
//                            "}" +
//                        "]" +
//                    "}," +
//                    "{" +
//                        "\"pageNumber\":5," +
//                        "\"indexRules\":[" +
//                            "{" +
//                                "\"index\":-1," +
//                                "\"offsetX\":10," +
//                                "\"offsetY\":20" +
//                            "}" +
//
//                        "]" +
//                    "}" +
//                "]" ;
        //SignStamp_KeyWord("资治",KeywordRule);
        //String KeywordRule = "[{\"indexRules\":[{\"index\":-1,\"offsetX\":10.0,\"offsetY\":20.0}],\"pageNumber\":-1}]";
        //SignStamp_KeyWord_Handle("二十三年",KeywordRule);
//        verifyDoc();

        ClearSigns();

        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

    public static void createSeal() throws Exception
    {
        KeyPair keyRootPair = Crypto.generateAsymKey(Crypto.SM2,0);
        KeyPair keyPair_User = Crypto.generateAsymKey(Crypto.SM2,0);
        final KeyPair keyPair_Seal = Crypto.generateAsymKey(Crypto.SM2,0);

        String RootDN = "C=CN,cn=rootCA,O=fzz";
        String DN_user = "C=CN,cn=user,O=fzz";
        String DN_seal = "C=CN,cn=stamp,O=fzz";

        byte[] rootCert = Crypto.generateRootCert(RootDN,keyRootPair.getPublicKey(),400,keyRootPair.getPrivateKey());
        final byte[] userCert = Crypto.generateCert(true,DN_user,keyPair_User.getPublicKey(),400,RootDN,keyRootPair.getPrivateKey());
        final byte[] sealCert = Crypto.generateCert(true,DN_seal,keyPair_Seal.getPublicKey(),400,RootDN,keyRootPair.getPrivateKey());

        FileOP fileOP = new FileOP();
        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.png");

        LocalDateTime currentTime = LocalDateTime.now();
        currentTime = currentTime.minus(2, ChronoUnit.DAYS);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String strCreateTime = currentTime.format(formatter);

        LocalDateTime strartTime = currentTime.plus(1, ChronoUnit.DAYS);
        String strStartTime = strartTime.format(formatter);
        LocalDateTime futureTime = currentTime.plus(365, ChronoUnit.DAYS);
        String strEndTime = futureTime.format(formatter);

        byte[] sealdata = SealManager.createSeal("11112222","06","test stamp","PNG",imagedata,300,300,strCreateTime,strStartTime,strEndTime,null,new ISignCallBack() {
            @Override
            public byte[] sign(byte[] srcdata)
            {
                try {
                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,keyPair_Seal.getPrivateKey(),srcdata);
                    return signdata;
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
                try {
                    return sealCert;
                } catch (Exception e) {
                    return null;
                }
            }

        });

        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel",sealdata);
        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer",userCert);
        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key",keyPair_User.getPrivateKey().getKey());
        System.out.println("创建印章成功！");
    }

    public static void verifySeal() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel");
        long ret = SealManager.verifySeal(imagedata, new IVerifyCallBack() {
            @Override
            public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
            {
                try {
                    Key pubkey = new Key(Key.SM2_PUB_KEY,key);
                    return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
                } catch (Exception e) {
                    return false;
                }
            }
        });

        System.out.println(ret == 0 ? "验证印章成功！" : (ret == 0xFFF504 ? "验证印章成功！但印章不在有效期": (ret == 0xFFF503 ? "验证印章失败！" : (ret == 0xFFF502 ? "印章证书 无效！": "未知错误")))   );
    }

    public static void getSealImageData() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel");
        byte[] ret = SealManager.getSealImageData(imagedata);

        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/seal.png",ret);

        System.out.println("获取电子印章中的印模数据成功！");
    }

    public static void getSealUserCertData() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] imagedata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/seal.sel");
        byte[] ret = SealManager.getSealUserCertData(imagedata);

        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/user.cer",ret);

        System.out.println("获取电子印章中的用户证书成功！");
    }

//    public static void SignStamp_Pos() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/seal.sel");
//        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/aaa1.ofd");
//
//        byte[] SignOFDData = OFDStamp.signStamp_Pos(seal,ofd,1,100, 50, 42, 42,true,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
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
//                    return null;
//            }
//
//        });
//
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/OFDSign.ofd",SignOFDData);
//
//        System.out.println("签OFD文件成功！");
//    }

    public static void Watermark_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel");

//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/seal.sel");

        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/ofd/aaa1.ofd");

        long handle = OFD.open(ofd);
        if ( handle != 0 ) {
            byte[] SignOFDData = null;
            //byte[] SignOFDData = OFDStamp.positionSign(handle,seal,-1,100, 50, 42, 42,false,new ISignCallBack() {
            for ( int i = 1; i < 3; i++ ) {
                SignOFDData = OFDStamp.positionSign(handle, seal, i, 100, 50, 42, 42, false, new ISignCallBack() {

                    @Override
                    public byte[] sign(byte[] srcdata) {
                        try {
                            Key key = new Key(Key.SM2_PRV_KEY, userpri);
                            byte[] signdata = Crypto.sign(Crypto.SM3_SM2, key, srcdata);
                            return signdata;
                        } catch (Exception e) {
                            return null;
                        }
                    }

                    @Override
                    public byte[] getUserCert() {
                        try {
                            return userCert;
                        } catch (Exception e) {
                            return null;
                        }
                    }

                    @Override
                    public byte[] getSealCert() {
                        return null;
                    }

                });
            }

            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd",SignOFDData);
            OFD.close(handle);
        }

        System.out.println("签OFD文件成功！");
    }

    public static void SignStamp_Pos_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] seal = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/seal.sel");

//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/seal.sel");

        byte[] ofd = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/ofd/aaa1.ofd");

        long handle = OFD.open(ofd);
        if ( handle != 0 ) {
            byte[] SignOFDData = null;
            //byte[] SignOFDData = OFDStamp.positionSign(handle,seal,-1,100, 50, 42, 42,false,new ISignCallBack() {
            for ( int i = 1; i < 3; i++ ) {
                SignOFDData = OFDStamp.positionSign(handle, seal, i, 100, 50, 42, 42, false, new ISignCallBack() {

                    @Override
                    public byte[] sign(byte[] srcdata) {
                        try {
                            Key key = new Key(Key.SM2_PRV_KEY, userpri);
                            byte[] signdata = Crypto.sign(Crypto.SM3_SM2, key, srcdata);
                            return signdata;
                        } catch (Exception e) {
                            return null;
                        }
                    }

                    @Override
                    public byte[] getUserCert() {
                        try {
                            return userCert;
                        } catch (Exception e) {
                            return null;
                        }
                    }

                    @Override
                    public byte[] getSealCert() {
                        return null;
                    }

                });
            }

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd",SignOFDData);
            OFD.close(handle);

            ofd2image_Handle("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd","OFDSign_");
        }

        System.out.println("签OFD文件成功！");
    }

//    public static void SignStamp_Riding(int RidingType) throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/seal.sel");
//        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/aaa1.ofd");
//
//        byte[] SignOFDData = OFDStamp.signStamp_Riding(seal,ofd,RidingType, 42, 42,true,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
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
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/OFDSign.ofd",SignOFDData);
//
//        System.out.println("签OFD文件成功！");
//    }

    public static void SignStamp_Riding_Handle(String RidingType) throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel");

//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/seal.sel");
        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/ofd/aaa1.ofd");

        long handle = OFD.open(ofd);
        if ( handle != 0 ) {
            byte[] SignOFDData = OFDStamp.ridingSign(handle,seal,RidingType, 42, 42,false,new ISignCallBack() {
                @Override
                public byte[] sign(byte[] srcdata)
                {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY,userpri);
                        byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
                        return signdata;
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

            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd",SignOFDData);
            OFD.close(handle);
        }

        System.out.println("签OFD文件成功！");
    }

//    public static void SignStamp_KeyWord(String keyword,String KeywordRule) throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/seal.sel");
//        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/aaa1.ofd");
//
//        byte[] SignOFDData = OFDStamp.signStamp_KeyWord(seal,ofd,keyword,KeywordRule, 42, 42,true,new ISignCallBack() {
//            @Override
//            public byte[] sign(byte[] srcdata)
//            {
//                try {
//                    Key key = new Key(Key.SM2_PRV_KEY,userpri);
//                    byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,key,srcdata);
//                    return signdata;
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
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/OFDSign.ofd",SignOFDData);
//
//        System.out.println("签OFD文件成功！");
//    }

    public static void SignStamp_KeyWord_Handle(String keyword,String KeywordRule) throws Exception
    {
        FileOP fileOP = new FileOP();
//        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userCert.cer");
//        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/userpri.key");
//        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/seal.sel");

        final byte[] userCert = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/userpri.key");
        byte[] seal = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/sign/ok_seal/seal.sel");
        byte[] ofd = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/ofd/aaa1.ofd");

        long handle = OFD.open(ofd);
        if ( handle != 0 ) {

            byte[] SignOFDData = OFDStamp.keywordSign(handle,seal, keyword, KeywordRule, 42, 42, false, new ISignCallBack() {
                @Override
                public byte[] sign(byte[] srcdata) {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY, userpri);
                        byte[] signdata = Crypto.sign(Crypto.SM3_SM2, key, srcdata);
                        return signdata;
                    } catch (Exception e) {
                        return null;
                    }
                }

                @Override
                public byte[] getUserCert() {
                    try {
                        return userCert;
                    } catch (Exception e) {
                        return null;
                    }
                }

                @Override
                public byte[] getSealCert() {
                    return null;
                }

            });

            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd", SignOFDData);
            OFD.close(handle);
        }
        System.out.println("签OFD文件成功！");
    }

    public static void verifyDoc() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] docdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd");
        String ret = OFDStamp.verify(docdata,new IVerifyCallBack() {
            @Override
            public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
            {
                try {
                    Key pubkey = new Key(Key.SM2_PUB_KEY,key);
                    return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
                    //return false;
                } catch (Exception e) {
                    return false;
                }
            }
        });
        System.out.println("验证文档结果：" + ret);
    }

    public static void ClearSigns() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] docdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd");
        long handle = OFD.open(docdata);

        if ( handle != 0 ) {
            byte[] SignPDFData = OFDStamp.clearSigns(handle);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_clear.ofd",SignPDFData);

            System.out.println("删除ofd文件签名成功！");
            OFD.close(handle);

            ofd2image_Handle("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_clear.ofd","OFDSign_clear_");
        }
    }

    public static void ofd2image_Handle(String filePath,String name) throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile(filePath);
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            byte[][] imagedata = OFDConverter.ofd2Image(handle, "JPG",1);

            for (int i = 0; i < imagedata.length; i++) {
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/"+name + i + ".jpg", imagedata[i]);
            }

            OFD.close(handle);
        }
    }
}
