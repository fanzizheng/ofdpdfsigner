import com.fzz.seal.*;
import com.fzz.seal.callback.*;
import com.fzz.seal.entity.*;
import com.fzz.seal.utils.*;

import java.text.SimpleDateFormat;
import java.util.Date;

//-Djava.library.path=/Users/zizhengfan/work/cpp/ofd/build/ofdcreate-dhssdygvturgepccmhnpnyoivmcu/Build/Products/Debug
public class test_PDFConverter {
    public static void main(String agrs[]) throws Exception {


        long currtime = System.currentTimeMillis();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");
        //pdf2image_zip();
        //pdf2image();
        //pdf2image_page();
        //pdf2ofd();

        //pdf2image_zip_Handle();
        //pdf2image_Handle();
        pdf2image_page_Handle();
        //pdf2ofd_Handle();

        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

    public static void pdf2image_zip_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign.pdf");
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_enc.pdf");
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_pw.pdf");
        long handle = PDF.open(ofdata);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] imagedata = PDFConverter.pdf2ImageZip(handle, "SVG",1);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc.zip", imagedata);
            PDF.close(handle);
        }
    }

    public static void pdf2image_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign.pdf");
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_enc.pdf");
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_pw.pdf");
        long handle = PDF.open(ofdata);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[][] imagedata = PDFConverter.pdf2Image(handle,"SVG",1);

            for (int i = 0; i < imagedata.length; i++ ) {
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc_"+i+".svg",imagedata[i]);
            }
            PDF.close(handle);
        }
    }

    public static void pdf2image_page_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign.pdf");
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_enc.pdf");
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_pw.pdf");
        long handle = PDF.open(ofdata);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            long count = PDF.getPdfPageCount(handle);

            for (int i = 0; i < count; i++) {
                byte[] imagedata = PDFConverter.pdfPage2Image(handle, "SVG", i,1);
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc_page" + i + ".svg", imagedata);
            }
            PDF.close(handle);
        }
    }

    public static void pdf2ofd_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign.pdf");
        //byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_enc.pdf");
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/pdf/PDFSign_pw.pdf");
        long handle = PDF.open(ofdata);

        long isNeedPW = PDF.isNeedPassword(handle);
        if ( isNeedPW == 1 ) {
            PDF.setPassword(handle,"12345678");
        } else if ( isNeedPW == -1 ) {
            System.out.println("文件句柄错误！");
            return ;
        }

        if ( handle != 0 ) {
            byte[] imagedata = PDFConverter.pdf2Ofd(handle,false);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd",imagedata);

            ofdtoimage_Handle("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd","OFDSign_");

            imagedata = PDFConverter.pdf2Ofd(handle,true);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_stamp.ofd",imagedata);

            ofdtoimage_Handle("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign_stamp.ofd","OFDSign_stamp_");

            PDF.close(handle);



        }
    }

    public static void ofdtoimage_Handle(String filepath,String name) throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile(filepath);
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            byte[][] imagedata_1 = OFDConverter.ofd2Image(handle, "JPG",1);

            for (int i = 0; i < imagedata_1.length; i++) {
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/"+ name + i + ".jpg", imagedata_1[i]);
            }

            OFD.close(handle);
        }
    }

//    public static void pdf2image_zip() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/OFDSign.pdf");
//        byte[] imagedata = PDFConverter.pdf2ImageToZip(ofdata,"JPG");
//
//        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/doc.zip",imagedata);
//
//    }

//    public static void pdf2image() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/OFDSign.pdf");
//        byte[][] imagedata = PDFConverter.pdf2Image(ofdata,"JPG");
//
//        for (int i = 0; i < imagedata.length; i++ ) {
//            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/doc_"+i+".jpg",imagedata[i]);
//        }
//    }

//    public static void pdf2image_page() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/OFDSign.pdf");
//        long count = PDFConverter.getPDFPageCount(ofdata);
//
//
//        for (int i = 0; i < count; i++ ) {
//            byte[] imagedata = PDFConverter.pdfPage2Image(ofdata,"JPG",i);
//            fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/doc_page"+i+".jpg",imagedata);
//        }
//    }

//    public static void pdf2ofd() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/pdf/OFDSign.pdf");
//        byte[] imagedata = PDFConverter.pdf2OFD(ofdata,false);
//
//        fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/OFDSign_stamp.ofd",imagedata);
//        //imagedata = PDFConverter.pdf2OFD(ofdata,true);
//
//       // fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd",imagedata);
//
//    }
}
