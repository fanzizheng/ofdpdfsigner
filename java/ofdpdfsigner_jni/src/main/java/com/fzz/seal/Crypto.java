package com.fzz.seal;

import com.fzz.seal.entity.Key;
import com.fzz.seal.entity.KeyPair;
import com.fzz.seal.jni.IJNI;
import com.fzz.seal.jni.ReturnData;

import java.nio.charset.StandardCharsets;

public class Crypto {

    public static final String SM3 = "SM3";
    public static final String SM2 = "SM2";
    public static final String SM4 = "SM4";

    public static final String SM2_ENC = "SM2_ENC";
    public static final String SM4_CBC = "SM4_CBC";
    public static final String SM4_GCM = "SM4_GCM";
    public static final String SM4_CTR = "SM4_CTR";

    public static final String SM3_SM2 = "SM3withSM2Encryption";

    private static final int JNI_TYPE_SM2 = 0;
    private static final int JNI_TYPE_SM3 = 1;
    private static final int JNI_TYPE_SM4 = 2;
    private static final int JNI_TYPE_SM3_SM2 = 10;


    /*
     产生随机数
     len：产生随机数的位数
     返回：随机数
     */
    public static byte[] generateRandom(int length)
    {
        byte[] ret = null;
        if ( length <= 0 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.generateRandom(length,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     计算文摘
     algType：SM3
     sourceData：原文
     返回：文摘数据
     */
    public static byte[] generateDigest(String algType, byte[] sourceData)
    {
        byte[] ret = null;

        if ( sourceData == null || sourceData.length <= 0 ) {
            return ret;
        }
        if ( algType != SM3 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.digest(JNI_TYPE_SM3,sourceData,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);
        }
        return ret;
    }

    /*
     产生对称密钥
     algType：SM4
     length：保留，为以后产生其他密钥使用
     返回：对称密钥
     */
    public static Key generateSymKey(String algType, int length)
    {
        Key ret = null;
        if ( algType != SM4 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.generateKey(JNI_TYPE_SM4,length,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            ret = new Key(Key.SM4,returnData.getResultData());
        }
        return ret;
    }
    /*
     产生非对称密钥
     algType：SM2
     keyLength：保留，为以后产生其他密钥使用
     返回：非对称密钥
     */
    public static KeyPair generateAsymKey(String algType, int keyLength)
    {
        KeyPair ret = null;
        if ( algType != SM2 ) {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.generateKeyPair(JNI_TYPE_SM2,keyLength,returnData);

        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null && returnData.getResultData1() != null ) {
            Key keyPub = new Key(Key.SM2_PUB_KEY,returnData.getResultData());
            Key keyPri = new Key(Key.SM2_PRV_KEY,returnData.getResultData1());
            ret = new KeyPair(keyPub,keyPri);
        }
        return ret;

    }
    /*
     解密数据
     algType：SM4_CBC，SM4_GCM,SM4_CTR,SM2_ENC
     deKey：密钥
     encryptedData：加密数据,当为SM2_ENC时大小小于364
     sm4GCMData：当为SM4_GCM，为mac数据，其他为null
     返回：解密数据
     */
    public static byte[] decrypt( String algType,Key decryptKey,byte[] encryptData,byte[] macData)
    {
        byte[] ret = null;
        if ( decryptKey.getKey() == null || decryptKey.getKey().length <= 0 ) {
            return ret;
        }
        if ( encryptData == null || encryptData.length <= 0 ) {
            return ret;
        }
        int intKeyType = 0;
        int intAlgType = 0;
        if ( decryptKey.getKeyType() == Key.SM4 ) {
            intKeyType = 0;
        } else if ( decryptKey.getKeyType() == Key.SM2_PRV_KEY ) {
            intKeyType = 2;
        } else {
            return ret;
        }

        if ( algType == SM4_CBC ) {
            intAlgType = 1;
        } else if ( algType == SM4_GCM ) {
            intAlgType = 2;
        } else if ( algType == SM4_CTR ) {
            intAlgType = 3;
        } else if ( algType == SM2_ENC ) {
            intAlgType = 0;
        } else {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.decrypt(intKeyType,decryptKey.getKey(),intAlgType,encryptData,macData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }
    /*
     加密数据
     algType：SM4_CBC，SM4_GCM,SM4_CTR,SM2_ENC
     enKey：密钥
     sourceData：明文数据，当为SM2_ENC时大小小于255
     返回：加密数据，当为SM4_GCM，数组的第二个元素为mac数据
     */
    public static byte[][] encrypt(String algType,Key encryptKey, byte[] sourceData)
    {
        byte[][] ret = null;
        if ( sourceData == null || sourceData.length <= 0 ) {
            return ret;
        }
        if ( encryptKey.getKey() == null || encryptKey.getKey().length <= 0 ) {
            return ret;
        }

        int intKeyType = 0;
        int intAlgType = 0;
        if ( encryptKey.getKeyType() == Key.SM4 ) {
            intKeyType = 0;
        } else if ( encryptKey.getKeyType() == Key.SM2_PUB_KEY ) {
            intKeyType = 1;
        } else {
            return ret;
        }

        if ( algType == SM4_CBC ) {
            intAlgType = 1;
        } else if ( algType == SM4_GCM ) {
            intAlgType = 2;
        } else if ( algType == SM4_CTR ) {
            intAlgType = 3;
        } else if ( algType == SM2_ENC ) {
            intAlgType = 0;
        } else {
            return ret;
        }



        ReturnData returnData = new ReturnData();
        IJNI.encrypt(intKeyType,encryptKey.getKey(),intAlgType,sourceData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            if ( returnData.getResultData1() != null ) {
                ret = new byte[2][];
                byte[] data1 = returnData.getResultData1();
                ret[1] = new byte[data1.length];
                System.arraycopy(data1,0,ret[1],0,data1.length);
            } else {
                ret = new byte[1][];
            }
            byte[] temp = returnData.getResultData();
            ret[0] = new byte[temp.length];
            System.arraycopy(temp,0,ret[0],0,temp.length);

        }
        return ret;

    }

    /*
     SM4 CBC 加密数据
     encryptKey：密钥
     ivData: iv数据
     sourceData：明文数据
     返回：加密数据
     */
    public static byte[] encryptSM4CBC(Key encryptKey,byte[] ivData, byte[] sourceData)
    {
        byte[] ret = null;
        if ( sourceData == null || sourceData.length <= 0 || ivData == null || ivData.length <= 0) {
            return ret;
        }
        if ( encryptKey.getKey() == null || encryptKey.getKey().length <= 0 ) {
            return ret;
        }

        ReturnData returnData = new ReturnData();
        IJNI.encryptSM4CBC(encryptKey.getKey(),ivData,sourceData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }

    /*
     SM4 CBC解密数据
     decryptKey：密钥
     ivData: iv数据
     encryptedData：加密数据
     返回：解密数据
     */
    public static byte[] decryptSM4CBC(Key decryptKey,byte[] ivData,byte[] encryptData)
    {
        byte[] ret = null;
        if ( decryptKey.getKey() == null || decryptKey.getKey().length <= 0 ) {
            return ret;
        }
        if ( encryptData == null || encryptData.length <= 0 || ivData == null || ivData.length <= 0 ) {
            return ret;
        }

        ReturnData returnData = new ReturnData();
        IJNI.decryptSM4CBC(decryptKey.getKey(),ivData,encryptData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }

    /*
     签名
     algType：SM2
     prvKey：私钥
     sourceData：原文数据
     返回：签名数据
     */
    public static byte[] sign(String algType, Key privateKey, byte[] sourceData)
    {
        byte[] ret = null;
        if ( sourceData == null || sourceData.length <= 0 ) {
            return ret;
        }
        if ( privateKey.getKey() == null || privateKey.getKey().length <= 0 ) {
            return ret;
        }
        int intAlgType = 0;
        if ( algType == SM3_SM2 ) {
            if ( privateKey.getKeyType() != Key.SM2_PRV_KEY ) {
                return ret;
            }
            intAlgType = 0;
        } else {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.sign(intAlgType,privateKey.getKey(),sourceData,returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }
    /*
     验签
     algType：SM2
     pubKey：公钥
     sourceData：原文数据
     signData：签名数据
     返回：验证是否通过
     */
    public static boolean verify(String algType, Key publicKey, byte[] sourceData, byte[] signData)
    {
        boolean isTF = false;
        if ( publicKey.getKey() == null || publicKey.getKey().length <= 0 ) {
            return isTF;
        }
        if ( sourceData == null || sourceData.length <= 0 ) {
            return isTF;
        }
        if ( signData == null || signData.length <= 0 ) {
            return isTF;
        }
        int intAlgType = 0;
        if ( algType == SM3_SM2 ) {
            if ( publicKey.getKeyType() != Key.SM2_PUB_KEY ) {
                return isTF;
            }
            intAlgType = 0;
        } else {
            return isTF;
        }
        ReturnData returnData = new ReturnData();
        IJNI.verifySign(intAlgType,publicKey.getKey(),sourceData,signData,returnData);
        if ( returnData.getErrorCode() == 0 ) {
            isTF = true;
        }
        return isTF;
    }
    /*
     产生根证书
     DN：证书DN
     pubKey：公钥
     days：有效期
     rootPriKey：根证书私钥
     返回：根证书数据
     */
    public static byte[] generateRootCert(String certDN, Key publicKey, int validDays,Key rootPrivateKey)
    {
        byte[] ret = null;
        int intAlgType = 0;

        if ( publicKey.getKey() == null || publicKey.getKey().length <= 0 ) {
            return ret;
        }
        if ( rootPrivateKey.getKey() == null || rootPrivateKey.getKey().length <= 0 ) {
            return ret;
        }

        if ( publicKey.getKeyType() == Key.SM2_PUB_KEY && rootPrivateKey.getKeyType() == Key.SM2_PRV_KEY ) {
            intAlgType = 0;
        } else {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.generateRootCert(intAlgType,certDN.getBytes(StandardCharsets.UTF_8),publicKey.getKey(),validDays,rootPrivateKey.getKey(),returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }
    /*
     产生证书
     isSign：是否为签名证书
     DN：证书DN
     pubKey：公钥
     days：有效期
     rootDN: 根证书DN
     rootPriKey：根证书私钥
     返回：证书数据
     */
    public static byte[] generateCert(boolean isSignCert,String certDN, Key publicKey, int validDays,String rootCertDN,Key rootPrivateKey)
    {
        byte[] ret = null;
        int intAlgType = 0;

        if ( publicKey.getKey() == null || publicKey.getKey().length <= 0 ) {
            return ret;
        }
        if ( rootPrivateKey.getKey() == null || rootPrivateKey.getKey().length <= 0 ) {
            return ret;
        }

        if ( publicKey.getKeyType() == Key.SM2_PUB_KEY && rootPrivateKey.getKeyType() == Key.SM2_PRV_KEY ) {
            intAlgType = 0;
        } else {
            return ret;
        }
        ReturnData returnData = new ReturnData();
        IJNI.generateCert(intAlgType,isSignCert ? 1 : 0,certDN.getBytes(StandardCharsets.UTF_8),publicKey.getKey(),validDays,rootCertDN.getBytes(StandardCharsets.UTF_8),rootPrivateKey.getKey(),returnData);
        if ( returnData.getErrorCode() == 0 && returnData.getResultData() != null ) {
            byte[] temp = returnData.getResultData();
            ret = new byte[temp.length];
            System.arraycopy(temp,0,ret,0,temp.length);

        }
        return ret;
    }



}
