

import com.fzz.seal.*;
import com.fzz.seal.callback.*;
import com.fzz.seal.entity.*;
import com.fzz.seal.utils.*;

import java.text.SimpleDateFormat;
import java.util.Date;

public class test_OFDEncProcted {
    public static void main(String agrs[]) throws Exception {
        long currtime = System.currentTimeMillis();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");
        //protectOFD();
        //OFDProtectVerify();
        //EncryptDoc();
        //DecryptDoc();

        PDF_Encrypt_Decrypt_Doc();

        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

    public static void protectOFD() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd";
        //String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_enc.ofd";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = OFD.open(ofdata);
        if ( handle != 0  ) {
            byte[] ProtectOFDData = OFD.protect(handle,new ISignCallBack() {
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

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_pro.ofd", ProtectOFDData);
            OFD.close(handle);
        }
    }

    public static void OFDProtectVerify() throws Exception
    {
        FileOP fileOP = new FileOP();
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_pro.ofd";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = OFD.open(ofdata);
        if ( handle != 0 && OFD.IsProtect(handle) == 1 ) {
            String veriryString = OFD.protectionVerify(handle,new IVerifyCallBack() {
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


            OFD.close(handle);
            System.out.println(veriryString);
        }
    }

    public static void EncryptDoc() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userCert = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userCert.cer");
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_pro.ofd";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = OFD.open(ofdata);
        if ( handle != 0  ) {
            String UserInfo = "[{\"mode\":1,\"passWordCert\":\"12345678\",\"userName\":\"user 1\",\"userType\":\"User\"},{\"mode\":2,\"passWordCert\":\""+ new String(Base64.encode(userCert))+"\",\"userName\":\"user 2\",\"userType\":\"Owner\"}]";

            byte[] encOFDData = OFD.encryptDocument(handle,UserInfo,new IEncryptCallBack() {
                @Override
                public byte[] generateRandom(long len)
                {
                    return Crypto.generateRandom((int)len);
                }
                @Override
                public byte[] encryptSM4CBC(byte[] key,byte[] iv,byte[] sourceData)
                {
                    try {
                        Key sm4key = new Key(Key.SM4,key);
                        return Crypto.encryptSM4CBC(sm4key,iv,sourceData);

                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] decryptSM4CBC(byte[] key,byte[] iv,byte[] encryptData)
                {
                    return null;
                }
                @Override
                public byte[] encryptSM2(byte[] publicKey,byte[] sourceData)
                {
                    try {
                        Key pubkey = new Key(Key.SM2_PUB_KEY,publicKey);
                        byte[][] encdata = Crypto.encrypt(Crypto.SM2_ENC,pubkey,sourceData);
                        return encdata[0];
                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] decryptSM2(byte[] encryptData)
                {
                    return null;
                }

            });

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_enc.ofd", encOFDData);
            OFD.close(handle);
        }
    }

    public static void DecryptDoc() throws Exception
    {
        FileOP fileOP = new FileOP();
        final byte[] userpri = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/sign/userpri.key");
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_enc.ofd";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = OFD.open(ofdata);
        if ( handle != 0 && OFD.IsEncrypt(handle) == 1 ) {
            String UserInfo = "";
            //byte[] encOFDData = OFD.decryptDocument(handle,1,"12345678","user 1","User",new IEncryptCallBack() {
            byte[] encOFDData = OFD.decryptDocument(handle,2,"","user 2","Owner",new IEncryptCallBack() {
                @Override
                public byte[] generateRandom(long len)
                {
                    return null;
                }
                @Override
                public byte[] encryptSM4CBC(byte[] key,byte[] iv,byte[] sourceData)
                {
                    return null;
                }
                @Override
                public byte[] decryptSM4CBC(byte[] key,byte[] iv,byte[] encryptData)
                {
                    try {
                        Key sm4key = new Key(Key.SM4,key);
                        return Crypto.decryptSM4CBC(sm4key,iv,encryptData);

                    } catch (Exception e) {
                        return null;
                    }
                }
                @Override
                public byte[] encryptSM2(byte[] publicKey,byte[] sourceData)
                {
                    return null;
                }
                @Override
                public byte[] decryptSM2(byte[] encryptData)
                {
                    try {
                        Key key = new Key(Key.SM2_PRV_KEY, userpri);
                        return Crypto.decrypt(Crypto.SM2_ENC,key,encryptData,null);
                    } catch (Exception e) {
                        return null;
                    }
                }

            });

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_dec.ofd", encOFDData);
            OFD.close(handle);

            ofd2image_Handle("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_dec.ofd","OFDSign_dec_");
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

    public static void PDF_Encrypt_Decrypt_Doc() throws Exception
    {
        FileOP fileOP = new FileOP();
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign_enc.pdf";
        //String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign_pw.pdf";
        //String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/PDFSign.pdf";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = PDF.open(ofdata);
        if ( handle != 0 ) {
            long isNeedPW = PDF.isNeedPassword(handle);
            if ( isNeedPW == 1 ) {
                PDF.setPassword(handle,"12345678");
            } else if ( isNeedPW == -1 ) {
                System.out.println("文件句柄错误！");
                return ;
            }
            //密文
            //byte[] PDFData = PDF.documnetEncryptDecrypt(handle,true,"");
            //密码加密密文
            byte[] PDFData = PDF.documnetEncryptDecrypt(handle,false,"12345678");
            //明文
           // byte[] PDFData = PDF.documnetEncryptDecrypt(handle,false,"");
            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/pdf_new.pdf", PDFData);
            PDF.close(handle);
        }
    }

}
