package com.fzz.ofdpdfsigner;

import androidx.appcompat.app.AppCompatActivity;
import androidx.viewpager2.widget.ViewPager2;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.fzz.ofdpdfsigner.base.BaseActivity;


import com.fzz.ofdpdfsigner.databinding.ActivityMainBinding;
import com.fzz.ofdpdfsigner.R;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.channels.FileChannel;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;


import com.fzz.seal.*;
import com.fzz.seal.callback.ISignCallBack;
import com.fzz.seal.callback.IVerifyCallBack;
import com.fzz.seal.entity.Key;
import com.fzz.seal.entity.KeyPair;


import java.util.List;

public class MainActivity extends BaseActivity {
    private ActivityMainBinding binding;
    private ViewPager2 viewPager;

    private ProgressDialog progressDialog;

    private String docType = "";
    private byte[] docData = null;

    private byte[] userCert = null;
    private byte[] userpri = null;
    private byte[] sealdata = null;

    private byte[] sealImageData = null;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        findViewById(R.id.iv_open_ofd).setOnClickListener(this);
        findViewById(R.id.iv_open_pdf).setOnClickListener(this);
        findViewById(R.id.iv_stamp_pos).setOnClickListener(this);
        findViewById(R.id.iv_stamp_riding).setOnClickListener(this);
        findViewById(R.id.iv_stamp_key).setOnClickListener(this);
        findViewById(R.id.iv_stamp_verify).setOnClickListener(this);

        viewPager = findViewById(R.id.vp_page);
        try {
            //设置临时目录
            String packageName = "com.fzz.ofdpdfsigner";
            String tempDir = Environment.getDataDirectory().getPath() + "/data/" + packageName + "/temp";
            File tempDirPaht = new File(tempDir);
            if (!tempDirPaht.exists()) {
                tempDirPaht.mkdirs();
            }
            SystemMamager.setTempPath(tempDir);

            String workDir = Environment.getDataDirectory().getPath() + "/data/" + packageName;
            copyFonts(workDir);
            SystemMamager.setWorkPath(workDir);
            //创建印章
            createSeal();
        } catch (Exception e) {

        }
    }

    private void copyFonts(String workDir) throws Exception
    {
        workDir = workDir+"/OFDFonts/";
        File fileDir = new File(workDir);
        if ( !fileDir.exists() ) {
            fileDir.mkdirs();
        }
        String[] list = getAssets().list("OFDFonts");
        if (list != null) {
            for (String file : list) {
                if (file.contains(".")) { // 假设文件有扩展名，可以区分文件和目录
                    CopyFile("OFDFonts/"+file,workDir+file);

                }
            }
        }

    }

    private void CopyFile(String source, String target) throws Exception {
        File file = new File(target);
        if ( !file.exists() ) {
            byte[] inData = ReadFile(source);
            FileOutputStream fout = new FileOutputStream(target);
            fout.write(inData);
            fout.flush();
            fout.close();
        }

    }

    @Override
    protected void onClickView(View v) {
        try {
            switch (v.getId()) {
                case R.id.iv_open_ofd:
                    //test_crypto();
                    openOFD();
                    break;
                case R.id.iv_open_pdf:
                    openPDF();
                    break;
                case R.id.iv_stamp_pos:
                    stampPos();
                    break;
                case R.id.iv_stamp_riding:
                    stampRiding();
                    break;
                case R.id.iv_stamp_key:
                    stampKeyWord();
                    break;
                case R.id.iv_stamp_verify:
                    stampVerify();
                    break;
            }
        } catch (Exception e) {

        }

    }

    public void showProgressDialog(Context context, String message) {
        progressDialog = new ProgressDialog(context);
        progressDialog.setMessage(message);
        progressDialog.setIndeterminate(true);
        progressDialog.setCancelable(false);
        progressDialog.show();
    }

    public void dismissProgressDialog() {
        if (progressDialog != null && progressDialog.isShowing()) {
            progressDialog.dismiss();
        }
    }
    private void createSeal() throws Exception
    {
        KeyPair keyRootPair = Crypto.generateAsymKey(Crypto.SM2,0);
        KeyPair keyPair_User = Crypto.generateAsymKey(Crypto.SM2,0);
        final KeyPair keyPair_Seal = Crypto.generateAsymKey(Crypto.SM2,0);

        String RootDN = "C=CN,cn=rootCA,O=fzz";
        String DN_user = "C=CN,cn=user,O=fzz";
        String DN_seal = "C=CN,cn=stamp,O=fzz";

        byte[] rootCert = Crypto.generateRootCert(RootDN,keyRootPair.getPublicKey(),356,keyRootPair.getPrivateKey());
        userCert = Crypto.generateCert(true,DN_user,keyPair_User.getPublicKey(),356,RootDN,keyRootPair.getPrivateKey());
        final byte[] sealCert = Crypto.generateCert(true,DN_seal,keyPair_Seal.getPublicKey(),356,RootDN,keyRootPair.getPrivateKey());

        sealImageData = ReadFile("seal.png");
        sealdata = SealManager.createSeal("11112222","03","test stamp","PNG",sealImageData,300,300,"2023-12-26 16:50:01","2023-12-26 16:50:01","2024-12-26 16:50:01",null,new ISignCallBack() {
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

        userpri = new byte[keyPair_User.getPrivateKey().getKey().length];
        System.arraycopy(keyPair_User.getPrivateKey().getKey(),0,userpri,0,keyPair_User.getPrivateKey().getKey().length);
    }

    private byte[] ReadFile(String FileName) {
        byte[] data = null;
        try {
            InputStream is = getAssets().open(FileName);
            data = new byte[is.available()];
            is.read(data);
            is.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return data;
    }

    private void loadPage(long handle)
    {
        if ( docType.isEmpty() ) {
            Toast.makeText(this, "文件为空", Toast.LENGTH_LONG).show();
            return;
        }

        if ( docType.equals("OFD") ) {
            long count = OFD.getOfdPageCount(handle);
            List<byte[]> imageList = new ArrayList<>();
            for (int i = 0; i < count; i++) {
                byte[] imagedata = OFDConverter.ofdPage2Image(handle, "JPG", i,1);
                if ( imagedata != null && imagedata.length >0 ) {
                    imageList.add(imagedata);
                }

            }
            viewPager.setAdapter(new ImageAdapter(imageList));
        } else if (docType.equals("PDF")) {
            if ( PDF.isNeedPassword(handle) == 1 ) {
                PDF.setPassword(handle,"12345678");
            }
            long count = PDF.getPdfPageCount(handle);
            List<byte[]> imageList = new ArrayList<>();
            for (int i = 0; i < count; i++) {
                byte[] imagedata = PDFConverter.pdfPage2Image(handle, "JPG", i,1);
                if ( imagedata != null && imagedata.length >0 ) {
                    imageList.add(imagedata);
                }

            }
            viewPager.setAdapter(new ImageAdapter(imageList));
        } else {
            Toast.makeText(this, "文件为空", Toast.LENGTH_LONG).show();
        }
    }
    private void openOFD()
    {
        showProgressDialog(this, "请稍候...");
        try {
            byte[] data = ReadFile("src.ofd");
            if ( data != null && data.length >0 ) {
                long handle = OFD.open(data);
                if ( handle != 0 ) {
//                    String certbase = new String(Base64.encode(userCert)) ;
//                    data = OFD.encryptDocument(handle, "[{\"mode\":1,\"passWordCert\":\"12345678\",\"userName\":\"user 1\",\"userType\":\"User\"},{\"mode\":2,\"passWordCert\":\""+certbase+"\",\"userName\":\"user 2\",\"userType\":\"Owner\"}]", new IEncryptCallBack() {
//                        @Override
//                        public byte[] generateRandom(long l) {
//
//                            return Crypto.generateRandom((int)l);
//                        }
//
//                        @Override
//                        public byte[] encryptSM4CBC(byte[] key, byte[] iv, byte[] sourceData) {
//                            try {
//                                Key sm4key = new Key(Key.SM4,key);
//                                return Crypto.encryptSM4CBC(sm4key,iv,sourceData);
//
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//
//                        @Override
//                        public byte[] decryptSM4CBC(byte[] key,byte[] iv,byte[] encryptData) {
//                            return null;
//                        }
//
//                        @Override
//                        public byte[] encryptSM2(byte[] publicKey,byte[] sourceData) {
//                            try {
//                                Key pubkey = new Key(Key.SM2_PUB_KEY,publicKey);
//                                byte[][] encdata = Crypto.encrypt(Crypto.SM2_ENC,pubkey,sourceData);
//                                return encdata[0];
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//
//                        @Override
//                        public byte[] decryptSM2(byte[] bytes) {
//                            return null;
//                        }
//                    });
//                    data = OFD.protect(handle,new ISignCallBack() {
//
//                        @Override
//                        public byte[] sign(byte[] srcdata) {
//                            try {
//                                Key key = new Key(Key.SM2_PRV_KEY, userpri);
//                                byte[] signdata = Crypto.sign(Crypto.SM3_SM2, key, srcdata);
//                                return signdata;
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//
//                        @Override
//                        public byte[] getUserCert() {
//                            try {
//                                return userCert;
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//
//                        @Override
//                        public byte[] getSealCert() {
//                            return null;
//                        }
//
//                    });
//
//                    String pverify = OFD.protectionVerify(handle,new IVerifyCallBack() {
//                        @Override
//                        public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
//                        {
//                            try {
//                                Key pubkey = new Key(Key.SM2_PUB_KEY,key);
//                                return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
//                                //return false;
//                            } catch (Exception e) {
//                                return false;
//                            }
//                        }
//                    });
//                    Toast.makeText(this, pverify, Toast.LENGTH_LONG).show();
//
//
//
//
////                    pverify = OFD.protectionVerify(handle,new IVerifyCallBack() {
////                        @Override
////                        public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
////                        {
////                            try {
////                                Key pubkey = new Key(Key.SM2_PUB_KEY,key);
////                                return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
////                                //return false;
////                            } catch (Exception e) {
////                                return false;
////                            }
////                        }
////                    });
////                    Toast.makeText(this, pverify, Toast.LENGTH_LONG).show();
//                    data = OFD.decryptDocument(handle, 1, "12345678", "user 1", "User", new IEncryptCallBack() {
//                        @Override
//                        public byte[] generateRandom(long l) {
//                            return new byte[0];
//                        }
//
//                        @Override
//                        public byte[] encryptSM4CBC(byte[] bytes, byte[] bytes1, byte[] bytes2) {
//                            return new byte[0];
//                        }
//
//                        @Override
//                        public byte[] decryptSM4CBC(byte[] key, byte[] iv, byte[] encryptData) {
//                            try {
//                                Key sm4key = new Key(Key.SM4,key);
//                                return Crypto.decryptSM4CBC(sm4key,iv,encryptData);
//
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//
//                        @Override
//                        public byte[] encryptSM2(byte[] bytes, byte[] bytes1) {
//                            return new byte[0];
//                        }
//
//                        @Override
//                        public byte[] decryptSM2(byte[] encryptData) {
//                            try {
//                                Key key = new Key(Key.SM2_PRV_KEY, userpri);
//                                return Crypto.decrypt(Crypto.SM2_ENC,key,encryptData,null);
//                            } catch (Exception e) {
//                                return null;
//                            }
//                        }
//                    });
//
//                    pverify = OFD.protectionVerify(handle,new IVerifyCallBack() {
//                        @Override
//                        public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
//                        {
//                            try {
//                                Key pubkey = new Key(Key.SM2_PUB_KEY,key);
//                                return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
//                                //return false;
//                            } catch (Exception e) {
//                                return false;
//                            }
//                        }
//                    });
//                    Toast.makeText(this, pverify, Toast.LENGTH_LONG).show();

                    docType = "OFD";
                    docData = data;
                    loadPage(handle);
                    OFD.close(handle);
                }

            } else {
                Toast.makeText(this, "不能读取文件", Toast.LENGTH_LONG).show();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
        dismissProgressDialog();
    }



    private void loadPDF(byte[] data)
    {
        if ( data != null && data.length >0 ) {
            long handle = PDF.open(data);
            if ( handle != 0 ) {

                //data = PDF.documnetEncryptDecrypt(handle,true,"");
//                data = PDF.documnetEncryptDecrypt(handle,true,"12345678");
//                if ( PDF.isNeedPassword(handle) == 1 ) {
//                    PDF.setPassword(handle,"12345678");
//                }
//                data = PDF.documnetEncryptDecrypt(handle,false,"");
                docType = "PDF";
                docData = data;
                loadPage(handle);
                PDF.close(handle);
            }

        } else {
            Toast.makeText(this, "不能读取文件", Toast.LENGTH_LONG).show();
        }
    }
    private void openPDF()
    {
        showProgressDialog(this, "请稍候...");
        try {
            byte[] data = ReadFile("src.pdf");

            loadPDF(data);

        } catch (Exception e) {
            e.printStackTrace();
        }
        dismissProgressDialog();
    }

    private void stampPos()
    {
        if ( docData == null || docData.length == 0 ) {
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
            return;
        }
        showProgressDialog(this, "请稍候...");
        if ( docType.equals("OFD") ) {
            long handle = OFD.open(docData);
            if ( handle != 0 ) {
                byte[] SignOFDData = null;
                //byte[] SignOFDData = OFDStamp.positionSign(handle,seal,-1,100, 50, 42, 42,false,new ISignCallBack() {

                SignOFDData = OFDStamp.positionSign(handle, sealdata, 1, 100, 50, 42, 42, false, new ISignCallBack() {

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

                Toast.makeText(this, "签OFD文件成功！", Toast.LENGTH_LONG).show();
                docData = SignOFDData;
                loadPage(handle);
                OFD.close(handle);
            }
            dismissProgressDialog();
        } else if ( docType.equals("PDF") ) {
            //需要临时目录
            long handle = PDF.open(docData);
            if ( handle != 0 ) {
                if ( PDF.isNeedPassword(handle) == 1 ) {
                    PDF.setPassword(handle,"12345678");
                }
                byte[] SignPDFData = PDFStamp.positionSign(handle,sealImageData,0.86,3,100, 50, 42, 42,false,new ISignCallBack() {
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
                Toast.makeText(this, "签pdf文件成功！", Toast.LENGTH_LONG).show();
                loadPage(handle);
                PDF.close(handle);

                docData = SignPDFData;


            }
            dismissProgressDialog();
        } else {
            dismissProgressDialog();
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
        }
    }

    private void stampRiding()
    {
        if ( docData == null || docData.length == 0 ) {
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
            return;
        }
        showProgressDialog(this, "请稍候...");
        if ( docType.equals("OFD") ) {

            long handle = OFD.open(docData);
            if ( handle != 0 ) {
                byte[] SignOFDData = OFDStamp.ridingSign(handle,sealdata,String.valueOf(OFDStamp.RIDING_LEFT), 42, 42,false,new ISignCallBack() {
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

                Toast.makeText(this, "签OFD文件成功！", Toast.LENGTH_LONG).show();
                docData = SignOFDData;
                loadPage(handle);
                OFD.close(handle);
            }

            dismissProgressDialog();
        } else if ( docType.equals("PDF") ) {
            long handle = PDF.open(docData);
            if ( handle != 0 ) {
                if ( PDF.isNeedPassword(handle) == 1 ) {
                    PDF.setPassword(handle,"12345678");
                }
                byte[] SignPDFData = PDFStamp.ridingSign(handle,sealImageData,0.86,String.valueOf(PDFStamp.RIDING_LEFT), 42, 42,false,new ISignCallBack() {
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

                Toast.makeText(this, "签PDF文件成功！", Toast.LENGTH_LONG).show();
                docData = SignPDFData;
                loadPage(handle);
                PDF.close(handle);
            }
            dismissProgressDialog();
        } else {
            dismissProgressDialog();
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
        }
    }

    private void stampKeyWord()
    {
        if ( docData == null || docData.length == 0 ) {
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
            return;
        }
        showProgressDialog(this, "请稍候...");
        String KeywordRule = "[{\"indexRules\":[{\"index\":-1,\"offsetX\":10.0,\"offsetY\":20.0}],\"pageNumber\":-1}]";
        String KeyWord = "二十三年";
        if ( docType.equals("OFD") ) {
            long handle = OFD.open(docData);
            if ( handle != 0 ) {

                byte[] SignOFDData = OFDStamp.keywordSign(handle,sealdata, KeyWord, KeywordRule, 42, 42, false, new ISignCallBack() {
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

                Toast.makeText(this, "签OFD文件成功！", Toast.LENGTH_LONG).show();
                docData = SignOFDData;
                loadPage(handle);
                OFD.close(handle);
            }
            dismissProgressDialog();
        } else if ( docType.equals("PDF") ) {
            long handle = PDF.open(docData);
            if ( handle != 0 ) {
                if ( PDF.isNeedPassword(handle) == 1 ) {
                    PDF.setPassword(handle,"12345678");
                }
                byte[] SignPDFData = PDFStamp.keywordSign(handle,sealImageData,0.86,KeyWord,KeywordRule, 42, 42,false,new ISignCallBack() {
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

                Toast.makeText(this, "签PDF文件成功！", Toast.LENGTH_LONG).show();
                docData = SignPDFData;
                loadPage(handle);
                PDF.close(handle);
            }
            dismissProgressDialog();
        } else {
            dismissProgressDialog();
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
        }
    }

    private void stampVerify()
    {
        if ( docData == null || docData.length == 0 ) {
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
            return;
        }
        showProgressDialog(this, "请稍候...");
        if ( docType.equals("OFD") ) {

            String ret = OFDStamp.verify(docData,new IVerifyCallBack() {
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

            Toast.makeText(this, ret, Toast.LENGTH_LONG).show();

//            long handle = OFD.open(docData);
//            docData = OFDStamp.clearSigns(handle);
//            loadPage(handle);
//            OFD.protect(handle,new ISignCallBack() {
//
//                @Override
//                public byte[] sign(byte[] srcdata) {
//                    try {
//                        Key key = new Key(Key.SM2_PRV_KEY, userpri);
//                        byte[] signdata = Crypto.sign(Crypto.SM3_SM2, key, srcdata);
//                        return signdata;
//                    } catch (Exception e) {
//                        return null;
//                    }
//                }
//
//                @Override
//                public byte[] getUserCert() {
//                    try {
//                        return userCert;
//                    } catch (Exception e) {
//                        return null;
//                    }
//                }
//
//                @Override
//                public byte[] getSealCert() {
//                    return null;
//                }
//
//            });
//
//            String pverify = OFD.protectionVerify(handle,new IVerifyCallBack() {
//                @Override
//                public boolean verify(int algType,byte[] key,byte[] srcdata,byte[] signdata)
//                {
//                    try {
//                        Key pubkey = new Key(Key.SM2_PUB_KEY,key);
//                        return Crypto.verify(Crypto.SM3_SM2,pubkey,srcdata,signdata);
//                        //return false;
//                    } catch (Exception e) {
//                        return false;
//                    }
//                }
//            });
//            OFD.close(handle);
//            Toast.makeText(this, pverify, Toast.LENGTH_LONG).show();
            dismissProgressDialog();
        } else if ( docType.equals("PDF") ) {
            String pdfPassWord = "";
            long handle = PDF.open(docData);
            if ( handle != 0 ) {
                if (PDF.isNeedPassword(handle) == 1) {
                    pdfPassWord = "12345678";
                }
            }
            String ret = "";
            //docData = PDFStamp.clearSigns(handle);
            //loadPDF(docData);
            ret = PDFStamp.verify(docData,pdfPassWord,new IVerifyCallBack() {
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
            Toast.makeText(this, ret, Toast.LENGTH_LONG).show();
            dismissProgressDialog();
        } else {
            dismissProgressDialog();
            Toast.makeText(this, "请先打开文件", Toast.LENGTH_LONG).show();
        }
    }
}