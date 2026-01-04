import com.fzz.seal.callback.ISystemFontFileNameCallBack;
import com.fzz.seal.entity.Key;
import com.fzz.seal.entity.KeyPair;
import com.fzz.seal.utils.FileOP;
import com.fzz.seal.utils.Hex;
import com.fzz.seal.*;

import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;

//-Djava.library.path=/Users/zizhengfan/work/cpp/ofd/build/ofdcreate-dhssdygvturgepccmhnpnyoivmcu/Build/Products/Debug
public class test_crypto {
    public static void main(String agrs[]) throws Exception {


        long currtime = System.currentTimeMillis();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");


        addFont();
        generateRandom(16);
        digest("ajfldsjfdsjafdjaafa".getBytes(StandardCharsets.UTF_8));
        SM4test();
        SM2_Enc_Dec();
        SM2_Sign();
        SM2_genCert();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

    private static void generateRandom(int len)
    {
        byte[] random = Crypto.generateRandom(len);
        System.out.print("产生随机数（" + len + "）：");
        byte[] hexstring = Hex.encode(random);
        System.out.println(new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void digest(byte[] sourceData)
    {
        byte[] digest = Crypto.generateDigest(Crypto.SM3,sourceData);
        System.out.print("计算文摘：");
        byte[] hexstring = Hex.encode(digest);
        System.out.println(new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void SM4test()
    {
        Key sm4Key = Crypto.generateSymKey(Crypto.SM4,0);
        if ( sm4Key == null ) {
            System.out.println("SM4 Key：error");
            return;
        }
        System.out.print("SM4 Key：");
        byte[] hexstring = Hex.encode(sm4Key.getKey());
        System.out.println(new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));

        String source = "积分多少路费的";
        byte[][] encdata =  Crypto.encrypt(Crypto.SM4_CBC,sm4Key,source.getBytes(StandardCharsets.UTF_8));
        hexstring = Hex.encode(encdata[0]);
        System.out.println("SM4 enc(cbc):"+new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        byte[] srcdata = Crypto.decrypt(Crypto.SM4_CBC,sm4Key,encdata[0],encdata.length == 2 ? encdata[1] : null);
        System.out.println("SM4 dec(cbc):"+new String(srcdata));

        encdata =  Crypto.encrypt(Crypto.SM4_GCM,sm4Key,source.getBytes(StandardCharsets.UTF_8));
        hexstring = Hex.encode(encdata[0]);
        System.out.println("SM4 enc(gcm):"+new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        srcdata = Crypto.decrypt(Crypto.SM4_GCM,sm4Key,encdata[0],encdata.length == 2 ? encdata[1] : null);
        System.out.println("SM4 dec(gcm):"+new String(srcdata));

        encdata =  Crypto.encrypt(Crypto.SM4_CTR,sm4Key,source.getBytes(StandardCharsets.UTF_8));
        hexstring = Hex.encode(encdata[0]);
        System.out.println("SM4 enc(ctr):"+new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        srcdata = Crypto.decrypt(Crypto.SM4_CTR,sm4Key,encdata[0],encdata.length == 2 ? encdata[1] : null);
        System.out.println("SM4 dec(ctr):"+new String(srcdata));
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void SM2_Enc_Dec()
    {
        KeyPair keyPair = Crypto.generateAsymKey(Crypto.SM2,0);
        String source = "积分多少路费的";
        byte[][] encdata =  Crypto.encrypt(Crypto.SM2_ENC,keyPair.getPublicKey(),source.getBytes(StandardCharsets.UTF_8));
        byte[] hexstring = Hex.encode(encdata[0]);
        System.out.println("SM2 enc:"+new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        byte[] srcdata = Crypto.decrypt(Crypto.SM2_ENC,keyPair.getPrivateKey(),encdata[0],encdata.length == 2 ? encdata[1] : null);
        System.out.println("SM2 dec:"+new String(srcdata));
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void SM2_Sign()
    {
        KeyPair keyPair = Crypto.generateAsymKey(Crypto.SM2,0);
        String source = "积分多少路费的";
        byte[] signdata =  Crypto.sign(Crypto.SM3_SM2,keyPair.getPrivateKey(),source.getBytes(StandardCharsets.UTF_8));
        byte[] hexstring = Hex.encode(signdata);
        System.out.println("SM2 sign:"+new String(hexstring == null ? "".getBytes(StandardCharsets.UTF_8) : hexstring));
        //source = "积分多少路费的1";
        boolean isTF = Crypto.verify(Crypto.SM3_SM2,keyPair.getPublicKey(),source.getBytes(StandardCharsets.UTF_8),signdata);
        System.out.println("SM2 verifySign:"+isTF);
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void SM2_genCert()
    {
        KeyPair keyRootPair = Crypto.generateAsymKey(Crypto.SM2,0);
        KeyPair keyPair = Crypto.generateAsymKey(Crypto.SM2,0);
        KeyPair keyPair_enc = Crypto.generateAsymKey(Crypto.SM2,0);

        String RootDN = "C=CN,cn=rootCA,O=fzz";
        String DN = "C=CN,cn=stamp,O=fzz";

        byte[] rootCert = Crypto.generateRootCert(RootDN,keyRootPair.getPublicKey(),356,keyRootPair.getPrivateKey());
        byte[] signCert = Crypto.generateCert(true,DN,keyPair.getPublicKey(),356,RootDN,keyRootPair.getPrivateKey());
        byte[] encCert = Crypto.generateCert(false,DN,keyPair_enc.getPublicKey(),356,RootDN,keyRootPair.getPrivateKey());

        try {
            FileOP fileOP = new FileOP();
            fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/root.cer", rootCert);
            fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/stamp_sign.cer", signCert);
            fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/stamp_enc.cer", encCert);
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("SM2 test cert: ok");
        System.out.println("------------------------------------------------------------------------------");
    }

    private static void addFont()
    {
        String workPath = "/Volumes/work/cpp/ofdpdfsigner/build/Qt_6_5_3_for_macOS-Debug/DocReader.app/Contents";

        SystemMamager.setWorkPath(workPath);

        FontManager.saveFontFileNameCache(workPath+"/OFDFonts/simsun.ttf");

        final Vector<String> filenames = new Vector<String>();
        FontManager.getAllSystemFontFileName (new ISystemFontFileNameCallBack() {
            @Override
            public void systemFontFileName(byte[] fullFileName)
            {
                try {
                    String gFileName = new String(fullFileName);
                    filenames.add(gFileName);

                } catch (Exception e) {

                }
            }


        });

        for( int i = 0; i < filenames.size(); i++ ) {
            System.out.println("Font name: "+filenames.get(i));
            FontManager.saveFontFileNameCache(filenames.get(i));
        }

        System.out.println("addFont: ok");
        System.out.println("------------------------------------------------------------------------------");
    }

}
