package com.fzz.seal.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.nio.channels.FileChannel;

public class FileOP {
    public void CopyFile(String source, String target) throws Exception{
        FileChannel in = null;
        FileChannel out = null;
        FileInputStream inStream = null;
        FileOutputStream outStream = null;

        inStream = new FileInputStream(source);
        outStream = new FileOutputStream(target);
        in = inStream.getChannel();
        out = outStream.getChannel();
        in.transferTo(0, in.size(), out);

        inStream.close();
        in.close();
        outStream.flush();
        outStream.close();
        out.close();

    }

    public boolean ReName(String source, String target) throws Exception
    {
        File file = new File(source);
        if (!file.exists()) {
            return false;
        }
        File tofile = new File(target);
        if (tofile.exists()) {
            return false;
        }
        return file.renameTo(tofile);

    }

    public void CreateDir(String FilePath) throws Exception {
        File file = new File(FilePath);
        if (!file.exists()) {
            file.mkdirs();
        }
    }

    public void WriteFile(String FileName,byte[] data) throws Exception {
        if ( data == null || data.length <= 0 ) {
            return;
        }
        File file = new File(FileName);
        if ( file.exists() ) {
            file.delete();
        }

        FileOutputStream fout = new FileOutputStream(FileName);
        //FileChannel channel = fout.getChannel();
        //ByteBuffer src = ByteBuffer.wrap(data);

        //channel.write(src);
        //channel.close();
        fout.write(data);
        fout.flush();
        fout.close();
    }

    public void WriteFile(String FileName, InputStream in) throws Exception {
        File file = new File(FileName);
        file.mkdirs();
        if ( file.exists() ) {
            file.delete();
        }

        FileOutputStream fout = new FileOutputStream(FileName);

        int byteCount = 0;
        byte[] bytes = new byte[1024];
        while ((byteCount = in.read(bytes)) != -1)
        {
            fout.write(bytes, 0, byteCount);

        }

        fout.flush();
        fout.close();
    }

    public byte[] ReadFile(String FileName) throws Exception {
        File file = new File(FileName);
        if ( !file.exists() ) {
            return null;
        }

        FileInputStream fin = new FileInputStream(FileName);
        byte[] data = new byte[fin.available()];
        fin.read(data);
        fin.close();
        return data;
    }

    public byte[] ReadFile(File file) throws Exception {
        FileInputStream fin = new FileInputStream(file);
        byte[] data = new byte[fin.available()];
        fin.read(data);
        fin.close();
        return data;
    }

    public void DelFile(String FileName) throws Exception
    {
        File file = new File(FileName);
        if ( file.exists() ) {
            file.delete();
        }
    }

    public boolean isExists(String Filename) throws Exception
    {
        File file = new File(Filename);
        return file.exists() ;
    }

    public File[] listFiles(String path) throws Exception
    {
        File file = new File(path);
        return file.listFiles();
    }
}
